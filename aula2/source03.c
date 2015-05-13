/* Source code for the 'debugging class'. 
 * source03.c - working with breakpoints.
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 13/05/2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void echoinput(char * string){
	char buffer[30];
	strcpy(buffer, string);
	printf("String: %s\n", buffer);

}

void main(int argc, char ** argv){
	echoinput(argv[1]);
	exit(0);
}
