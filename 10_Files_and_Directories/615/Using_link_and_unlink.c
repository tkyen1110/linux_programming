#include <stdio.h>
#include <unistd.h>
int main(void)
{    
	if(link("583/mkdir-rmdir.c", "hardfile1") == -1) 
		perror("Failed to create a hard link \n");      
	if(symlink("583/mkdir-rmdir.c", "symfile2") == -1)        
		perror("Failed to create a soft link \n");
	// unlink("hardfile1");
	// unlink("symfile2");
	return 0;
}

