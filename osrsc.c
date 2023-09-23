#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#define bsize 1024

int main()
{
    int fd;
    char buf[bsize];
    fd=open("file.txt",O_RDONLY);
    if(fd==-1)
    {
        perror("open");
        return 1;
    }
    int bytes_read = read(fd,buf,bsize);
    if(bytes_read == -1)
    {
        perror("read");
        return 1;
    }
    close(fd);
    write(1,buf,bytes_read);
    return 0;
}