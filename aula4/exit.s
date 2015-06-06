/* Source code for the 'debugging class'. 
 * exit.s - Calling the syscall exit(0). 
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 06/06/2015
 */

.text
.globl _start
_start:
	# calling the syscall exit(0)
	movl $1, %eax
	movl $0, %ebx
	int $0x80

