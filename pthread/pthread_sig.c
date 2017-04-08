#include<stdio.h>
#include<signal.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>

sig_atomic_t c;

void sig_func(int);

void * thread_func(){

	printf("__func__\n");
	struct sigaction sa;
	memset(&sa,sizeof(sa),0);
	sleep(2);
	sa.sa_handler=&sig_func;
	sigaction(SIGINT,&sa,NULL);
	printf("This is thread %d\n",pthread_self());
}

void sig_func(int signum){

	printf("__func__\n");
	printf("signal occoured\n");
}

int main(){

	pthread_t tid;
	printf("IN %s\n",__func__);
	pthread_create(&tid,NULL,&thread_func,NULL);
	pthread_kill(tid,SIGINT);



	return 0;
}
