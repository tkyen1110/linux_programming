#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd, nread;
    char buf[1];  
    /*open file "/dev/pts/3" for reading */
    fd = open("/dev/pts/3", O_RDONLY);

    /* read in the /dev/pts/3 */
    nread = read(fd, buf, 1);
    printf("%s\n",buf);

    /* close the file */
    close(fd);
}

