#include <sys/ipc.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
int main(void) 
{
	key_t mykey;
	char key_path[]="/";
	int id=124;
	if((mykey=ftok(key_path,id))==(key_t)-1) 
	{
		fprintf(stderr,"Failed to derive key from %s: %s\n", key_path, strerror(errno));
		return -1;
	}
	fprintf(stderr, "Derived key is %lu\n", (unsigned long)mykey);
	return 0;
}
