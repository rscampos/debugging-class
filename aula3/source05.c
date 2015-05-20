/* Source code for the 'debugging class'. 
 * source05.c - print struct and array. Use ptype in gdb.
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 20/05/2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct mem{
	unsigned int addr_start;
	unsigned int addr_end;
};

struct process{
	unsigned int pid;
	unsigned int state;
	struct mem *vm;
};

void main(int argc, char ** argv){
	int vetor[5] = {10, 20, 30, 40, 50};
	struct process proc;
	proc.pid = 20;
	proc.state = 3;
	proc.vm->addr_start = 0x12345678;
	proc.vm->addr_end = 0x12345678;
	printf("Done!\n");
}
