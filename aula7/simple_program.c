/* Source code for the 'debugging class'. 
 * simple_program.c - how 'cdecl' calling convention works. 
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 24/06/2015
 */
#include<stdio.h>

int add(int a, int b){
	int c;
	c = a+b;
	return c;	
}

void main(){
	int a=13;
	int b=37;
	int d;
	d=add(a,b);
	printf("Valor:%d\n", d);
}
