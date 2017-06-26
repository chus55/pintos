#include <stdio.h>
#include <syscall.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	init_semaphore(1);				//mutex 0, 1
	init_semaphore(1);				//writeblock 1, 1

	int tid[10];

	tid[0] = exec("writer 1");
	tid[1] = exec("reader 1");
	tid[2] = exec("reader 2");
	tid[3] = exec("writer 2");
	tid[4] = exec("reader 3");
	tid[5] = exec("reader 4");
	tid[6] = exec("writer 3");
	tid[7] = exec("reader 5");
	tid[8] = exec("reader 6");
	tid[9] = exec("reader 7");
	
	wait(tid[0]);
	wait(tid[1]);
	wait(tid[2]);
	wait(tid[3]);
	wait(tid[4]);
	wait(tid[5]);
	wait(tid[6]);
	wait(tid[7]);
	wait(tid[8]);
	wait(tid[9]);

	return 0;
}