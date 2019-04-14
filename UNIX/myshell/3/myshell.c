#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#define CMD_ARG         10
#define CMD_LIST        10
#define MAX_GRP 10
#ifndef TRUE
#define TRUE    1
#endif
#ifndef FALSE
#define FALSE   0
#endif
const char *prompt = "myshell>";
char* cmdgrp[MAX_GRP];
char* cmdargs[CMD_ARG];
char cmdline[BUFSIZ];
char* cmdlist[CMD_LIST];
void zombiehandler(int sig);
void fatal(char *msg);
void execute_cmdgrp(char* cmdgrp);
void parredirect(char* cmd);
void execcmdline(char* cmd);
void execute_cmd(char *cmdlist);
int makeargv(char *s, const char *delimiters, char** argvp, int MAX_LIST);
struct sigaction act;
static int status;
static int isbackground=0;
typedef struct {
    char* name;
    char* desc;
    int ( *func )( int argc, char* argv[] );
} COMMAND;
int cmd_cd( int argc, char* argv[] ){ //cd : change directory
    if( argc == 1 )
        chdir( getenv( "HOME" ) );
    else if( argc == 2 ){
        if( chdir( argv[1] ) )
            printf( "No directory! fail\n" );
    }
    else
        printf( "Usage : cd  (dir)\n" );
    return TRUE;
}
int cmd_exit( int argc, char* argv[] ){
    printf("Exit\n");
    exit(0);
    return TRUE;
}
static COMMAND builtin_cmds[] ={
    { "cd", "changing  directory", cmd_cd },
    { "exit", "exit shell", cmd_exit },
    { "quit", "quit shell", cmd_exit },

};
void fatal(char *msg){
        perror(msg);
        exit(1);
}
int main(int argc, char**argv){
        int i;
        sigset_t set;
        sigfillset(&set);
        sigdelset(&set,SIGCHLD);
        sigprocmask(SIG_SETMASK,&set,NULL);
        act.sa_flags = SA_RESTART;
        sigemptyset(&act.sa_mask);
        act.sa_handler = zombiehandler;
        sigaction(SIGCHLD, &act, 0);
    while (1) {
        fputs(prompt, stdout);
        fgets(cmdline, BUFSIZ, stdin);
        cmdline[ strlen(cmdline) -1] ='\0';
                execcmdline(cmdline);
        }
        return 0;
}
void zombiehandler(int sig){
    pid_t pid ;
    int stat ;
    while ((pid = waitpid(-1, &stat, WNOHANG)) > 0)
        printf("Child %d : terminated\n", pid) ;
}

int makeargv(char *s, const char *deli, char** argv, int MAX_LIST){
        int numtokens = 0;
        char *snew = NULL;
        int i = 0;
        if( (s==NULL) || (deli ==NULL) ){
                return -1;
        }

        snew = s+strspn(s, deli);
        argv[numtokens]=strtok(snew, deli);
        if( argv[numtokens] !=NULL)
                for(numtokens=1; (argv[numtokens]=strtok(NULL, deli)) != NULL; numtokens++){
                        if(numtokens == (MAX_LIST-1)) return -1;
                }
        if( numtokens > MAX_LIST)
                return -1;
        return numtokens;
}
void execute_cmdgrp(char *cmdgrp){
        int count = 0;
        int i=0;
        int pfd[2];
        sigset_t set;
        setpgid(0,0);
        if(!isbackground)
        tcsetpgrp(STDIN_FILENO, getpid());
        sigfillset(&set);
        sigprocmask(SIG_UNBLOCK,&set,NULL);

        if((count = makeargv(cmdgrp, "|", cmdlist, CMD_LIST)) <= 0)
                fatal("makeargv cmdgrp error");
        for(i=0; i<count-1; i++){
                pipe(pfd);
                switch(fork()){
                case -1: fatal("fork() error!");
                case  0:
                        close(pfd[0]);
                        dup2(pfd[1], STDOUT_FILENO);
                        execute_cmd(cmdlist[i]);
            default:
                        close(pfd[1]);
                        dup2(pfd[0], STDIN_FILENO);
                }
        }
        execute_cmd(cmdlist[i]);

}

void parredirect(char* cmd){
        char *prg;
        int cmdlen = strlen(cmd);
        int fd, i;

        for(i = cmdlen-1;i >= 0;i--){
                switch(cmd[i]){
                        case '<':
                                prg = strtok(&cmd[i+1], " \t");
                                if( (fd = open(prg, O_RDONLY | O_CREAT, 0644)) < 0)
                                        fatal("file open() error");
                                dup2(fd, STDIN_FILENO);
                                close(fd);
                                cmd[i] = '\0';
                                break;
                        case '>':
                                prg = strtok(&cmd[i+1], " \t");
                if( (fd = open(prg,  O_CREAT| O_WRONLY | O_TRUNC, 0644)) < 0)
                                        fatal("file open() error");
                dup2(fd, STDOUT_FILENO);
                close(fd);
                cmd[i] = '\0';
                                break;
                        default:
break;
                }
        }

}


void execute_cmd(char *cmdlist){
    parredirect(cmdlist);

    if(makeargv(cmdlist, " \t", cmdargs, CMD_ARG) <= 0)
                fatal("makeargv cmdargs error");

    execvp(cmdargs[0], cmdargs);
    fatal("exec()");
}
int parse_background(char *cmd){
        int i;

    for(i=0; i < strlen(cmd); i++)
        if(cmd[i] == '&'){
            cmd[i] = ' ';
            return 1;
        }
        return 0;
}
void execcmdline(char* cmd){
    int count = 0;
int numtokens = 0;
    int i=0;
int j=0, pid;
    char* cmdvec[CMD_ARG];
    char cmdgrptemp[BUFSIZ];


    count = makeargv(cmd, ";", cmdgrp, MAX_GRP);

    for(i=0; i<count; ++i)
    {
        memcpy(cmdgrptemp, cmdgrp[i], strlen(cmdgrp[i]) + 1);
        numtokens = makeargv(cmdgrp[i], " \t", cmdvec, MAX_GRP);

        for( j = 0; j < sizeof( builtin_cmds ) / sizeof( COMMAND ); j++ ){            if( strcmp( builtin_cmds[j].name, cmdvec[0] ) == 0 ){
                builtin_cmds[j].func( numtokens , cmdvec);
                return;
            }
        }

                isbackground = parse_background(cmdgrptemp);

        switch(pid=fork())
        {
            case -1:
                fatal("fork() error");
            case  0:
                execute_cmdgrp(cmdgrptemp);
            default:
                if(isbackground)
break;
                waitpid(pid, NULL, 0);
                tcsetpgrp(STDIN_FILENO, getpgid(0));
                fflush(stdout);
        }
    }
}

