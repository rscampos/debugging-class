/* Source code for the 'debugging class'. 
 * jump_conditional.s - Studying how conditional jump works. 
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 14/06/2015
 */

.data
	zeroflag_set:
		.asciz "Zero flag is set!\n"
	zeroflag_notset:
		.ascii "Zero flag is not set!\n"
.text
.globl _start
_start:
	
	movl $10, %eax
	xorl %eax, %eax
	jz ZeroFlagSet	

	ZeroFlagNotSet:
		movl $4, %eax
		movl $1, %ebx
		movl $zeroflag_notset, %ecx
		movl $22, %edx
		int $0x80
		jmp exit

	ZeroFlagSet:
		movl $4, %eax
		movl $1, %ebx
		movl $zeroflag_set, %ecx
		movl $18, %edx
		int $0x80

	# calling the syscall exit(0)
	exit:
		movl $1, %eax
		movl $0, %ebx
		int $0x80
