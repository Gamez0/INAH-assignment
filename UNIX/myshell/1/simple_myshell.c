#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_CMD_ARG 10

const char *prompt = "myshell> ";
char* cmdvector[MAX_CMD_ARG];
char  cmdline[BUFSIZ];

struct COMMAND{
        char* name;
        char* desc;
        int(*func)(int argc, char* argv[]);
};

int cmd_exit(int argc, char* argv[]);
int cmd_cd(int argc,char* argv[]);

struct COMMAND builtin_cmds[] ={
        {"cd",  "change directory",     cmd_cd},
        {"exit",        "exit this shell",      cmd_exit}
};

int cmd_cd(int argc, char* argv[]){
        printf("hello");
        if(argc==1)
                chdir(getenv("HOME"));
        else if(argc==2){
                if(chdir(argv[1]))
                        printf("No directory\n");
        }
}

int cmd_exit(int argc, char* argv[]){
        return 0;
}

void fatal(char *str){
        perror(str);
        exit(1);
}

int makelist(char *s, const char *delimiters, char** list, int MAX_LIST){
  int i = 0;
  int numtokens = 0;
  char *snew = NULL;

  if( (s==NULL) || (delimiters==NULL) ) return -1;

  snew = s + strspn(s, delimiters);     /* delimiters¸¦ skip */
  if( (list[numtokens]=strtok(snew, delimiters)) == NULL )
    return numtokens;

  numtokens = 1;

  while(1){
     if( (list[numtokens]=strtok(NULL, delimiters)) == NULL)
        break;
     if(numtokens == (MAX_LIST-1)) return -1;
     numtokens++;
  }
  return numtokens;
}
int isBackground(char *cmd){
        int t;
        for(t=0;t<strlen(cmd);t++){
                if(cmd[t]=='&'){
                        //cmd[t]=' ';
                        return 1;
                }
        }
        return 0;
}
int main(int argc, char**argv){
  int i=0;
  int k=0;
  int numtoken=0;
  char *backp;
  int inbackground=0;
  pid_t pid;
  int token_count;
  while (1) {
        /*k=0;
        for(i=1;i<argc;i++){
                if((backp = strchr(argv[i],'&'))==NULL){
                        k=1;
                        argv[i]=' ';
                }
        }
        if(k==1){
                inbackground =0;
        }
        else if(k==0){
                inbackground =1;
                *backp=0;
        }*/

        fputs(prompt, stdout);
        fgets(cmdline, BUFSIZ, stdin);
        cmdline[ strlen(cmdline) -1] ='\0';

        //token_count = makelist(cmdline,"\t",cmdvector,MAX_CMD_ARG);
        //if(token_count==0)
        //      continue;
        numtoken = makelist(cmdline," \t", cmdvector, MAX_CMD_ARG);
        for(i=0;i<numtoken;i++){
        if(strcmp(cmdvector[i],"&")==0){
                //printf("background");
                //printf("%d %s\n",i,cmdvector[i]);
                inbackground=1;
                cmdvector[i]='\0';
        }
        }
 if(strcmp(cmdvector[0],"cd")==0){
                chdir(cmdvector[1]);
                continue;
        }
        else if(strcmp(cmdvector[0],"exit")==0){
                break;
        }
        switch(pid=fork()){
        case 0:
                //makelist(cmdline, " \t", cmdvector, MAX_CMD_ARG);
                //if(strcmp(cmdvector[0],"cd")==0){
                //      chdir(cmdvector[1]);
                //      continue;
                //}
                execvp(cmdvector[0], cmdvector);
                fatal("main()");
        case -1:
                fatal("main()");
        default:
                if(!inbackground){
                        waitpid(pid,NULL,0);
                        inbackground=0;
                }
                else
                        break;
                //tcsetpgrp(STDIN_FILENO,getpgid(0));
                //fflush(stdout);
                //wait(NULL);

        }
  }
  return 0;
}
                                            