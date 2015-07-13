/* Source code for the 'debugging class'. 
 * debugger_v3.c - insert breakpoint int3.
 * Based on http://eli.thegreenplace.net/2011/01/27/how-debuggers-work-part-2-breakpoints. 
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 12/07/2015
 */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/user.h>

void run_target(char * program_name){
	printf("[child] Program:%s\n", program_name);

	/* Allow tracing of this process */
	if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0) {
		perror("ptrace");
		return;
	}
	execl(program_name,program_name,0);
}

void run_debugger(pid_t child_pid){
	int wait_status;
	unsigned instruction;
	unsigned addr_breakpoint = 0x08048088;
	unsigned char opcode;
	unsigned char opcode_int3 = 0xCC;
	struct user_regs_struct regs;

	printf("[parent] Debugger - tracing:%d\n",child_pid);
	
	/* stop after exec() */
	wait(&wait_status);
	if(WIFSTOPPED(wait_status)){

		printf("[parent] Breakpoint at 0x%08x\n",addr_breakpoint);
		
		/* Step 1) Breaking at the address and get the instruction */
		instruction = ptrace(PTRACE_PEEKTEXT, child_pid, addr_breakpoint, 0);	
		printf("[parent] BEFORE\t=> ADDR:0x%08x INSTRUCTION:0x%08x\n",addr_breakpoint, instruction);

		/* Step 2) Replace the instruction with int3 opcode */
		opcode = (char) instruction;
		instruction &= 0xFFFFFF00;
		instruction += 0xCC;
		printf("[parent] AFTER\t=> ADDR:0x%08x INSTRUCTION:0x%08x\n",addr_breakpoint, instruction);
		printf("[parent] Replacing the opcode '0x%02x' by '0x%02x'.\n",opcode, opcode_int3);
		ptrace(PTRACE_POKETEXT, child_pid, addr_breakpoint, instruction);	

		/* Step 3) Continue the execution untill hit the breakpoint */
		ptrace(PTRACE_CONT, child_pid, 0, 0);	
		wait(&wait_status);
		printf("[parent] Breakpoint was hit!\n");
                ptrace(PTRACE_GETREGS, child_pid, 0, &regs);
		printf("[parent] Registers: EAX=0x%08x EBX=0x%08x ECX=0x%08x EDX=0x%08x\n", regs.eax, regs.ebx, regs.ecx, regs.edx);
		
		/* Step 4) Decrement EIP and put the opcode back */
		regs.eip -=1;
                instruction = ptrace(PTRACE_PEEKTEXT, child_pid, regs.eip, 0);
		instruction &= 0xFFFFFF00;
		instruction += opcode;
		ptrace(PTRACE_POKETEXT, child_pid, regs.eip, instruction);	
		ptrace(PTRACE_SETREGS, child_pid, 0, &regs);

		/* Step 5) Continue the execution untill the program finish */
		ptrace(PTRACE_CONT, child_pid, 0, 0);
		wait(&wait_status);
                if(WIFEXITED(wait_status))
                        printf("[parent] child finished!\n");

	}
	
}

int main(int argc, char **argv){
	pid_t child_pid, my_pid;
	printf("[parent] Debbuging process: %s\n", argv[1]);

	/* fork() returns child pid on success */
	child_pid	= fork();
	my_pid		= getpid();

	if(child_pid == 0){ /* child */
		printf("[child] My pid:%d\n", my_pid);
		run_target(argv[1]);
	}else if (child_pid > 0){ /* parent */
		printf("[parent] child pid: %d\n", child_pid);
		printf("[parent] My pid:%d\n", my_pid);
		run_debugger(child_pid);
	}else{
		perror("fork");
        	return -1;
	}
}
