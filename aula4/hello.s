/* Source code for the 'debugging class'. 
 * hello.s - Hello World in assembly. 
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 06/06/2015
 */

.data
	hellostring:
		.ascii "Hello World!\n"
.text
.globl _start
_start:

	# calling the syscall write(1,"Hello World!\n",13)
	movl $4, %eax
	movl $1, %ebx
	movl $hellostring, %ecx
	movl $13, %edx
	int $0x80

	# calling the syscall exit(0)
	movl $1, %eax
	movl $0, %ebx
	int $0x80

