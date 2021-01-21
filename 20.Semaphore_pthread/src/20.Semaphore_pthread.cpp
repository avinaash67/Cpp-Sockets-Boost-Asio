//============================================================================
// Name        : Semaphore_pthread.cpp
// Author      : Avinaash
// Version     :
// Copyright   : Your copyright notice
// Description : https://www.youtube.com/watch?v=TYnNKdf7cZM&t=53s
//============================================================================

#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

void *myfunc1 (void *ptr);
void *myfunc2 (void *ptr);

char buf[20];

sem_t mutex;

int main(int argc, char *argv[]) {

	pthread_t thread1;
	pthread_t thread2;

	char *msg1 = "Thread 1";
	char *msg2 = "Thread 2";

	sem_init(&mutex, 0, 1);

	pthread_create (&thread1, NULL, &myfunc1, (void*)msg1);
	pthread_create (&thread2, NULL, &myfunc2, (void*)msg2);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	sem_destroy(&mutex);


	return 0;
}

void *myfunc1(void* ptr){
	char *msg = (char*) ptr;
	printf("%s\n",msg);

	sem_wait(&mutex);
	sprintf(buf,"%s","buffer accessed\n");
	sem_post(&mutex);

	pthread_exit(0);
}

void *myfunc2(void* ptr){
	char *msg = (char*) ptr;
	printf("%s\n",msg);
	printf("%s\n",buf);

	pthread_exit(0);
}
