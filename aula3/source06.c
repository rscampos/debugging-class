/* Source code for the 'debugging class'. 
 * source06.c - modify registers and memory.
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 20/05/2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void neverexecute(){
	printf("Never execute\n");
	exit(0);
}

void echoinput(char * string){
	char buffer[30];
	strcpy(buffer, string);
	printf("String: %s\n", buffer);

}

int addnum(int num1, int num2){
        int result_add;
        result_add = num1 + num2;
        return result_add;
}

void main(int argc, char ** argv){
	int input_num1, input_num2, result;
	echoinput(argv[1]);
	input_num1 = atoi(argv[2]);
	input_num2 = atoi(argv[3]);
	result	   = addnum(input_num1,input_num2);
	printf("Sum: %d+%d=%d\n", input_num1, input_num2, result);	
	exit(0);
}
