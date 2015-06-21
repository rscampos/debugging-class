/* Source code for the 'debugging class'. 
 * function.s - studying how the instruction call works. 
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 14/06/2015
 */

.type Myfunction, @function

.data
	hellostring:
		.ascii "Hello World!\n"

.text
	# calling the syscall write
	Myfunction:
                movl $4, %eax
                movl $1, %ebx
                movl $hellostring, %ecx
                movl $22, %edx
                int $0x80
		ret

.globl _start
_start:
	
	movl $10, %eax
	call Myfunction
	movl $11, %eax	

	# calling the syscall exit(0)
	exit:
		movl $1, %eax
		movl $0, %ebx
		int $0x80
