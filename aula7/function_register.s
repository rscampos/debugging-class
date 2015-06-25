/* Source code for the 'debugging class'. 
 * function_register.s - pass arguments to functions via registers. 
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 14/06/2015
 */

.data
	hellostring:
		.ascii "Hello World!\n"

	hellostring2:
		.ascii "Hello World2!\n"

.text
.globl _start

.type PrinterFunction, @function

# Pass the ecx='string pointer' and the edx='len'
PrinterFunction:
	movl $4, %eax
	movl $1, %ebx
	int $0x80
	ret

_start:
	movl $hellostring, %ecx
	movl $13, %edx
	call PrinterFunction

	movl $hellostring2, %ecx
	movl $14, %edx
	call PrinterFunction


	# calling the syscall exit(0)
	exit:
		movl $1, %eax
		movl $0, %ebx
		int $0x80
