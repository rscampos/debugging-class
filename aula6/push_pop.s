/* Source code for the 'debugging class'. 
 * push_pop.s - studying how the push and pop instructions works. 
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 14/06/2015
 */

.data
	hellostring:
		.ascii "Hello World!\n"
.text
.globl _start
_start:
	
	PrintHello:
		movl $4, %eax
		movl $1, %ebx
		# You can't do this "movl $hellostring, %ecx"
		pushl $hellostring
		popl %ecx
		movl $13, %edx
		int $0x80

	# calling the syscall exit(0)
	exit:
		movl $1, %eax
		movl $0, %ebx
		int $0x80
