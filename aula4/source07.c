/* Source code for the 'debugging class'. 
 * source07.c - Examine stack and others memory segments. 
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 27/05/2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addnum(int num1, int num2){
        int result_add;
        result_add = num1 + num2;
        return result_add;
}

void main(int argc, char ** argv){
	int input_num1, input_num2, result;
	char buffer[50];

	input_num1 = atoi(argv[1]);
	input_num2 = atoi(argv[2]);

	gets(buffer);
	puts(buffer);
	
	result = addnum(input_num1,input_num2);
	printf("Sum: %d+%d=%d\n", input_num1, input_num2, result);	
	
	exit(0);
}
