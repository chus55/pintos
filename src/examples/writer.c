#include <syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <random.h>


int main(int argc, char *argv[])
{
	//printf("Hola writer");
	int mutex = 0;
	int writeblock = 1;
	for (int i = 0; i < 5; i++){
		wait_semaphore(writeblock);
		unsigned long random = random_ulong() % 50;
		printf("Data written by writer is %d\n", random);
		writer(random);
		post_semaphore(writeblock);
	}
	return 1;
}