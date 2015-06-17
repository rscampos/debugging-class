/* Source code for the 'debugging class'. 
 * loop.s - Studying how loop works. 
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 14/06/2015
 */

.data
	hellostring:
		.ascii "Hello World!\n"
.text
.globl _start
_start:
	# calling the syscall write(1,"Hello World!\n",13)
	
	xorl %eax, %eax
	jz PrintHello
	jmp exit 
	
	PrintHello:
		movl $10, %ecx
		loopblock:
			movl $4, %eax
			movl $1, %ebx
			movl $hellostring, %ecx
			movl $22, %edx
			int $0x80
			loop loopblock
			jmp exit

	# calling the syscall exit(0)
	exit:
		movl $1, %eax
		movl $0, %ebx
		int $0x80
