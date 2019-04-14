#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char *message);

int main(int argc, char *argv[])
{
        int serv_sock, clnt_sock;
        char message[BUF_SIZE];
        int str_len, i;

        struct sockaddr_in serv_adr;
        struct sockaddr_in clnt_adr;
        socklen_t clnt_adr_sz;

        if(argc!=2) {
                printf("Usage : %s <port>\n", argv[0]);         // asking for port
                exit(1);
        }

        serv_sock=socket(PF_INET, SOCK_STREAM, 0);
        if(serv_sock==-1)
                error_handling("socket() error");

        memset(&serv_adr, 0, sizeof(serv_adr));
        serv_adr.sin_family=AF_INET;
        serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
        serv_adr.sin_port=htons(atoi(argv[1]));

        if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
                error_handling("bind() error");

        if(listen(serv_sock, 5)==-1)
                error_handling("listen() error");

        clnt_adr_sz=sizeof(clnt_adr);

        for(; ;)        // until Cntl+C is typed
        {
                clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
                if(clnt_sock==-1)
                        error_handling("accept() error");
                else    // use ntohs for port, use inet_ntoa for IP address
		 //printf("-------------server-----------------\n");
                        printf("Servers's Port\t:%d\n",ntohs(serv_adr.sin_port));//succesfully print server's port
                        //printf("Trying port without ntohs %d\n",serv_adr.sin_port);
                //      printf("Trying ip %d \n",serv_adr.sin_addr);
                        printf("Servers's IP\t:%s \n",inet_ntoa(serv_adr.sin_addr));//succesfully print server's ip using inet_ntoa

                        //printf("-------------client-----------------\n");
                        //printing client's information

                        printf("Client's port\t:%d\n",ntohs(clnt_adr.sin_port));
                        printf("Client's IP\t:%s\n",inet_ntoa(clnt_adr.sin_addr));
                        //printf("not ntohs%d \n",clnt_adr.sin_addr.s_addr);

                while((str_len=read(clnt_sock, message, BUF_SIZE))!=0)
                        write(clnt_sock, message, str_len);

                close(clnt_sock);
        }

        close(serv_sock);
        return 0;
}

void error_handling(char *message)
{
        fputs(message, stderr);
        fputc('\n', stderr);
        exit(1);
}
                                                                
