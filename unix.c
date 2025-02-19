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