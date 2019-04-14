#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int my_double_ls(const char*name, int skip);

int my_double_ls (const char* name, int skip){
        struct dirent *d;
        DIR *dp;

        struct stat buf;
        int len=0;
        int count=0;
        int count2 =0;
        char** ptr1;
        char* ptr2;
        
	int i=0;

        if((dp=opendir(name))==NULL)
                return (-1);

        if(skip==0){
                while(d=readdir(dp)){
                        if(d->d_ino !=0)
                                printf("%s\n",d->d_name);
                        stat(d->d_name,&buf);
                        if(S_ISDIR(buf.st_mode))
                                count++;
                }
        }
        //ptr1= (char**)malloc(sizeof(char**)*count);
        rewinddir(dp);

        while(d=readdir(dp)){
                        if(d->d_ino !=0)
                              printf("%s\n", d->d_name);
                       stat(d->d_name,&buf);
                        memset(&buf,0,sizeof(struct stat));
                        if(S_ISDIR(buf.st_mode)){
                        ptr2 = (char*)malloc(sizeof(char)*strlen(d->d_name));
                        strcpy(ptr2,d->d_name);
                        ptr1[i++]=ptr2;

                        ptr1[i++]=d->d_name;
                    //    printf("%s \n",ptr1[i]);
                }

        closedir(dp);
        return 0;
        }
    if(skip==1){
                count2=0;
        while(d=readdir(dp)){
                if(!strcmp(d->d_name,".")|| !strcmp(d->d_name,".."))
                        continue;
                stat(d->d_name,&buf);
                if(!S_ISDIR(buf.st_mode))
                        count2++;
                printf("%s\n",d->d_name);
        }
        ptr1= (char**)malloc(sizeof(char**)*count2);
        rewinddir(dp);
        while(d=readdir(dp)){
                if(!strcmp(d->d_name,".")||!strcmp(d->d_name,".."))
                        continue;
                stat(d->d_name,&buf);
                memset(&buf,0,sizeof(struct stat));
                if(!S_ISDIR(buf.st_mode)){
                                ptr2 = (char*)malloc(sizeof(char)*strlen(d->d_name));
                                strcpy(ptr2,d->d_name);
                                ptr1[i++]=ptr2;
                                ptr1[i++]=d->d_name;
                                printf("%s\n",ptr1[i]);
                                printf("%s\n",d->d_name);
        //
                        }
                printf("%s\n",d->d_name);
                }
                return 0;
        }
}

int main(int argc, char**argv){
        if(argc!=3){
                printf("Usage : Directory and 0 or 1\n");
                exit(1);
        }
        int x = atoi(argv[2]);
        my_double_ls(argv[1],x);

        exit(0);
}
