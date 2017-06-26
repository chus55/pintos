#include <stdio.h>
#include <syscall.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int buffer_size = 5;
	init_semaphore(1);				//mutex	0, 1
	init_semaphore(0);				//full	1, 0
	init_semaphore(buffer_size);	//empty	2, buffer_size

	int tid[4];

	tid[0] = exec("producer 1");
	tid[1] = exec("producer 2");

	tid[2] = exec("consumer 1");
	tid[3] = exec("consumer 2");
	
	wait(tid[0]);
	wait(tid[1]);
	wait(tid[2]);
	wait(tid[3]);

	return 0;
}