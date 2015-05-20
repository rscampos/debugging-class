/* Source code for the 'debugging class'. 
 * source04.c - conditional breakpoints.
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 20/05/2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void  loop(){
	int counter=10;
	for(counter; counter > 0; counter--)
		printf("Counter:%d\n", counter);
}

void main(int argc, char ** argv){
	loop();
}
