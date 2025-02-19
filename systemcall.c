#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int pid;
    pid=fork();
    if(pid<0){
        printf("fork failed");
        exit(1);
    }
    else if(pid==0){
        execlp("/bin/date","date",NULL);
        exit(0);
    }
    else {
        printf("process id is-%d\n",getpid());
        wait(NULL);
        exit(0);

    }
    return 0;
}

//3.2

#include<stdio.h>
#include<sys/stat.h>
int main()
{
struct stat sfile;
stat("hello.txt",&sfile);
printf("\nst_mode=%o\n",sfile.st_mode);
printf("\n File st_uid %d\n",sfile.st_uid);
printf("\n File st_size %ld\n",sfile.st_size);
return 0;
}


//3.3
#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
struct dirent *dptr;

int main()
{
char buff[256];
DIR *dirp;
printf("Enter directory name:");
scanf("%s",buff);
if((dirp=opendir(buff))==NULL)
{
printf("Error");
exit(1);
}
while(dptr=readdir(dirp))
{
printf("%s\n",dptr->d_name);
}
closedir(dirp);
return 0;
}
