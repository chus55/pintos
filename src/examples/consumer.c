#include <syscall.h>
#include <stdio.h>
#include <stdlib.h>

int 
main(int argc, char *argv[])
{
	int mutex = 0;
	int full = 1;
	int empty = 2;

	for (int i = 0; i < 5; i++)
	{
		wait_semaphore(full);
		wait_semaphore(mutex);
		printf("Consuming ... %s\n", argv[1]);
		post_semaphore(mutex);
		post_semaphore(empty);
	}
	
	return 1;
}