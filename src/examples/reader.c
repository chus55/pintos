#include <syscall.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//printf("Hola reader");
	int mutex = 0;
	int writeblock = 1;
	for (int i = 0; i < 15; i++){
		wait_semaphore(mutex);
		sum_readers();

		if (get_readers() == 1){
			wait_semaphore(writeblock);
		}

		post_semaphore(mutex);

		int miData = reader();
		printf("Data read by reader: %d\n", miData);

		wait_semaphore(mutex);
		sub_readers();

		if (get_readers() == 0){
			post_semaphore(writeblock);
		}
		post_semaphore(mutex);
	}
	return 1;
}