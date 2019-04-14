#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

enum { BUFFERSZ = 1 << 16 };    /* 65K buffer size */

void writeliteral (int fildes, const char *s);

int main () {
	
    char buf[BUFFERSZ] = "";
    unsigned  i = 0, nlines = 0;
    ssize_t n = 0;
    long  cnt=0;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int fd = open ("test.txt", O_RDONLY);

    if (fd == -1) {               /* validate file open for reading */
        writeliteral (STDERR_FILENO, "error: infile open failed.\n");
        return 1;
    }

    while ((n = read (fd, buf, sizeof buf)) > 0){  /* read 65k chars */
       cnt+=n;
	    for (i = 0; i < n; i++)            /* count newlines in buf */
           	 if (buf[i] == '\n')
               		 nlines++;
    }
    if (buf[i - 1] != '\n')       /* account for non-POSIX line end */
        nlines++;
	
   
    close (fd); /* close file */
	
    printf("this is the line of the file : %d\n",nlines);
    printf("this is the num of the char : %ld\n",cnt);
    /* open outfile for writing, create if it doesn't exist */
   // if ((fd = open (argv[2], O_WRONLY | O_CREAT, mode)) == -1) {
   //     writeliteral (STDERR_FILENO, "error: outfile open failed.\n");
     //   return 1;
    //}
   // write (fd, &nlines, sizeof nlines);  /* write nlines to outfile */

   // close (fd); /* close file */

    return 0;
}

/** write a string literal to 'fildes' */
void writeliteral (int fildes, 