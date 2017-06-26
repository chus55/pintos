#include <stdio.h>
#include <syscall.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int philoCount = 5;
	init_semaphore(philoCount - 1);				//lock 0, philoCount - 1
	for(int i = 0; i < philoCount; i++) {
		init_semaphore(1);						//forks
	}

	int tid[5];

	tid[0] = exec("philosopher 0");
	tid[1] = exec("philosopher 1");
	tid[2] = exec("philosopher 2");
	tid[3] = exec("philosopher 3");
	tid[4] = exec("philosopher 4");
	
	wait(tid[0]);
	wait(tid[1]);
	wait(tid[2]);
	wait(tid[3]);
	wait(tid[4]);

	return 0;
}