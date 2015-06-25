/* Source code for the 'debugging class'. 
 * function_memory.s - pass arguments to functions via memory. 
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 14/06/2015
 */

.data
	hellostring:
		.ascii "Hello World!\n"

	hellostring2:
		.ascii "Hello World2!\n"

.bss
	.lcomm string_pointer, 4
	.lcomm string_len, 4

.text
.globl _start

.type PrinterFunction, @function

# Pass the ecx='string pointer' and the edx='len'
PrinterFunction:
	movl $4, %eax
	movl $1, %ebx
	movl string_pointer, %ecx
	movl string_len, %edx
	int $0x80
	ret

_start:
	movl $hellostring, string_pointer
	movl $13, string_len
	call PrinterFunction

	movl $hellostring2, string_pointer
	movl $14, string_len
	call PrinterFunction


	# calling the syscall exit(0)
	exit:
		movl $1, %eax
		movl $0, %ebx
		int $0x80
