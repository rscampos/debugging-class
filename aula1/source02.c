/* Source code for the 'debugging class'. 
 * source02.c - inspect debug information such as: variables and functions. 
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 03/05/2015
 */

#include <stdio.h>
#include <stdlib.h>

int subnum(int num1, int num2){
	int static_var=10;
	int result_sub;
	result_sub = num1 - num2;
	return result_sub;
}

int addnum(int num1, int num2){
	int result_add;
	result_add = num1 + num2;
	return result_add;
}

void main(int argc, char ** argv){
	int input_num1, input_num2;
	input_num1 = atoi(argv[1]);
	input_num2 = atoi(argv[2]);
	printf("Sum: %d+%d=%d\n", input_num1, input_num2, addnum(input_num1,input_num2));
	printf("Sub: %d-%d=%d\n", input_num1, input_num2, subnum(input_num1,input_num2));
}
