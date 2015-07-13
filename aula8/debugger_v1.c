/* Source code for the 'debugging class'. 
 * debugger_v1.c - single-step debugging.
 * Based on http://eli.thegreenplace.net/2011/01/23/how-debuggers-work-part-1. 
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 12/07/2015
 */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/wait.h>

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
	int icounter=0;

	printf("[parent] Debugger - tracing:%d\n",child_pid);
	
	/* stop after exec() */
	wait(&wait_status);
	while(WIFSTOPPED(wait_status)){
		icounter++;
	
		/* Make the child execute another instruction */
		if (ptrace(PTRACE_SINGLESTEP, child_pid, 0, 0) < 0) {
		    perror("ptrace");
		    return;
		}

		/* Wait for child to stop on its next instruction */
		wait(&wait_status);

		if(WIFEXITED(wait_status))
			printf("[parent] child finished!\n");
	}
	printf("[parent] %d instructions executed!\n",icounter);
	
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
