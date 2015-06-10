/* Source code for the 'debugging class'. 
 * move.s - Studying how mov instruction and data types works.
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 09/06/2015
 */

.data
        Hellostring:
                .ascii "Hello World!"
	Byte:
		.byte 13

	Int32:
		.int 29

	Int16:	
		.short 39

	Float:
		.float 10.23

	Int32Array:
		.int 10,20,30,40,50


.bss
	.comm Buffer, 10000

.text
.globl _start
_start:
	# MOV immediate value into register 
	movl $29, %eax
		
	# MOV immediate value into memory 
	movl $31, Int16
	
	# MOV data between registers 
	movl %eax, %ebx

	# MOV data from memory to the registers 
	movl Int16, %ebx

	# MOV a single byte
	movb $10, %al
	movb %al, Byte

	# MOV data into an indexed memory
	# Baseaddress(offset, index, size)
	# 'offset' and 'index' must be in registers.
	# 'size' of the array can be a numerical value
	movl $0, %ecx
	movl $2, %edi
	movl $23, Int32Array(%ecx, %edi, 4)

	# Indirect addressing using registers 
	movl $Int32, %eax
	movl (%eax), %ebx

	movl $9, (%eax)

	# exit syscall
	movl $1, %eax
	movl $0, %ebx
	int $0x80
