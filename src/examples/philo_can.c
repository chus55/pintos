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

	tid[0] = exec("philo 0");
	tid[1] = exec("philo 1");
	tid[2] = exec("philo 2");
	tid[3] = exec("philo 3");
	tid[4] = exec("philo 4");
	
	wait(tid[0]);
	wait(tid[1]);
	wait(tid[2]);
	wait(tid[3]);
	wait(tid[4]);

	return 0;
}