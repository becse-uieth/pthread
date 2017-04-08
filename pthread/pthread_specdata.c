#include<stdio.h>
#include<signal.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>

sig_atomic_t c;

pthread_key_t key;

void f_func(){

	printf("in %s\n",__func__);
	FILE * stream;
	stream=(FILE *)pthread_getspecific(key);
//	fprintf(stream,"this is a thread");
	fflush(stream);
}

void write_func(){

	printf("in %s\n",__func__);
	fprintf(stream,"this is a thread");
	fclose(stream);
}

void * thread_func(){
	
	FILE * stream;
	char filename[100];
	sprintf(filename,"%s",thread_self());
	stream=fopen(filename,O_CREAT|S_IRUSR|S_IWUSR|S_IROTH|S_IWOTH);
	pthread_setspecific(key,stream);
	write_file();
	f_func(key);

}


int main(){

	pthread_t tid;
	printf("IN %s\n",__func__);
	pthread_create(&tid,NULL,&thread_func,NULL);
	pthread_kill(tid,SIGINT);



	return 0;
}
