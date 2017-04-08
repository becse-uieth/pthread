#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void * add(void *r)
{
	int *b;
	b=(int *)r;
	//int *r;
	int sum;
	//sum=(int *)malloc(sizeof(int));
	sum=b[0]+b[1];
	//sum=b;
	printf("\nYou are in thread\n");
	//void *s;
	//s=(void *)sum;
	//void *zz;
	//zz=(void *)sum;
	return (void *)sum;
}
int main()
{
	int a[2];
	a[0]=10;
	a[1]=70;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_t pid;
	pthread_create(&pid, &attr, &add, (void *) a);
	//void *c;
	int c, d;
	pthread_attr_destroy(&attr);
	d = pthread_join(pid,(void *)&c);
	
	if (d != 0)
	{
		printf("thread not joined\n");
	}
	printf("in main without result\n");
	

	//b=(int *)c;
	printf("in main  %d\n",c);
//	pthread_attr_destroy(&attr);
	return 0;
}

