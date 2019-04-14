#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){


	int fd = creat("./exercise2-3.txt",0644);
	fd = open(./exercise2-3.txt",O_RDWR,0644);

} 
