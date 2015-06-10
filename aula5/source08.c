/* Source code for the 'debugging class'. 
 * source08.c - Examine 'core dump' files.
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 08/06/2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int addnum(int num1, int num2){
        int result_add;
        result_add = num1 + num2;
        return result_add;
}

void main(int argc, char ** argv){
	unsigned int * addr = 0x10203040;
	sleep(3);
	printf("Reading 0x%x ...\n",(unsigned int) addr);
	printf("0x%x\n",(unsigned int) *addr);
}
