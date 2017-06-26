#include <syscall.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//printf("Hola philosopher");
	int philoCount = 5;
	int lock = 0;
	int forks[philoCount];
	for(int i = 0; i < philoCount; i++){
		forks[i] = i+1;
	}
	/*char* charPhilo = argv[1];
	int philoActual = &charPhilo - '0';*/
	int philoActual = (int)(argv[1][0] - '0');
	for (int i = 0; i < 7; i++){
		printf("Philosopher number %d is thinking.\n", philoActual);
		wait_semaphore(lock);
		wait_semaphore(forks[philoActual]);
		wait_semaphore(forks[philoActual + 1] % philoCount);
		printf("Philosopher number %d is eating.\n", philoActual);
		post_semaphore(forks[philoActual]);
		post_semaphore(forks[philoActual + 1] % philoCount);
		post_semaphore(lock);
	}
	return 1;
}