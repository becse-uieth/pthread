#include<stdio.h>
#include<pthread.h>

//int sum;
void * add(void *a){
	int *b;
	b=(int *)a;
	int sum;
	sum=b[0]+b[1];
	printf("in function\n");
	return (void *)sum;
}
int main(){

	int c;
	pthread_t tid;
	int a[2]={3,5};
	pthread_create(&tid,NULL,&add,a);
	pthread_join(tid,(void *)&c);
//	int *d;
//	d=(int *)c;
//	printf("%d\n",*d);
	printf("%d\n",(int *)c);
	return 0;
}































/*
void* add(void  *abc){
	printf("id is %d\n",pthread_sell());
}

int main()
{
	pthread_t tid;
	pthread_create(&tid,NULL,&add,NULL);
	pthread_join(tid,NULL);
	return 0;
}
*/
