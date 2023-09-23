#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
    int fd;
    char data[]="Hello, Indra\n";
    fd=open("file.txt",O_WRONLY|O_CREAT,0644);
    if(fd==-1)
    {
        perror("open");
        return 1;
    }
    int bytes_written = write(fd,data,sizeof(data));
    if(bytes_written == -1)
    {
        perror("write");
        return 1;
    }
    close(fd);
    printf("%d", bytes_written);
    return 0;
}