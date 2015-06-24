/* Source code for the 'debugging class'. 
 * function_stack.s - Studying how pass arguments to functions via stack. 
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 24/06/2015
 */

.data
	hellostring:
		.ascii "Hello World!\n"

.text
.globl _start

.type PrinterFunction, @function

PrinterFunction:
	
	# prologue
	pushl %ebp	# save the value of ebp on the stack ('ebp-old')
	movl %esp, %ebp	# ebp points to esp (ebp -> 'ebp-old')

	movl $4, %eax
	movl $1, %ebx
	movl 8(%ebp), %ecx	# string pointer argument
	movl 12(%ebp), %edx	# len argument
	int $0x80

	# epilogue
	movl %ebp, %esp	# restore the old value of esp
	popl %ebp	# restore the old value of ebp
	ret		# return to the caller

_start:
	# similar to PrinterFunction(string,len)
	pushl $13		# len argument
	pushl $hellostring	# string pointer argument
	call PrinterFunction
	addl $8, %esp
	
	# calling the syscall exit(0)
	exit:
		movl $1, %eax
		movl $0, %ebx
		int $0x80
