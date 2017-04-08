#include<stdio.h>
#include<signal.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>

sig_atomic_t c;

void sig_func(int signum){

	printf("__func__\n");
	printf("signal occoured\n");
}

void * thread_func(){
	int old_state;
//	pthread_setcancelstate( PTHREAD_CANCEL_DISABLE,&o_s);
	pthread_setcancletype( PTHREAD_CANCEL_ASYNCHRONOUS,&old_state);
	int a,b;
	c=a+b;
	printf("sum =%d",c);
//	pthread_setcancelstate(o_s,NULL);
}


int main(){

	pthread_t tid;
	printf("IN %s\n",__func__);
	pthread_create(&tid,NULL,&thread_func,NULL);
	pthread_kill(tid,SIGINT);



	return 0;
}
