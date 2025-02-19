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


//2nd one 
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

//3rd one 
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
