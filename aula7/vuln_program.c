/* Source code for the 'debugging class'. 
 * vuln_program.c - buffer overflow stack-based example. 
 * Raphael Campos Silva <raphaelcampos.rp@gmail.com>
 * 24/06/2015
 */
#include<stdio.h>

void never_execute(){
	printf("Extra point for you!\n");
	exit(0);
}

void vuln(char ** argv){
	char buffer[8];
	printf("%s\n",argv[1]);
	strcpy(buffer, argv[1]);
}

void main(int argc, char ** argv){
	vuln(argv);
}
