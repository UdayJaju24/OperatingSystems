#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t wrt,mutex;
int a=1,readcount=0;

void* reader(void *arg)
{
    int num=(int)arg;

    pthread_mutex_lock(&mutex);
        readcount++;
    pthread_mutex_unlock(&mutex);

    if(readcount==1)
        pthread_mutex_lock(&wrt);

    printf("\nReader %ld enters in critical section\n",num);
    printf("\nReader %ld is reading data %d\n",num,a);

    pthread_mutex_lock(&mutex);
        readcount--;
    pthread_mutex_unlock(&mutex);

    if(readcount==0)
        pthread_mutex_unlock(&wrt);

    printf("\nReader %ld left the critical section",num);
}
void* writer(void *arg)
{
    int num=( int)arg;

    pthread_mutex_lock(&wrt);

    printf("\nWriter %d enters in critical section\n",num);
    printf("Writer %d have written data as %d",num,++a);
    sleep(1);

    pthread_mutex_unlock(&wrt);
    printf("\nWriter %ld left the critical section",num);
}
int main()
{
    pthread_t r[10],w[10];
    int now,nor;

    pthread_mutex_init(&wrt,NULL);
    pthread_mutex_init(&mutex,NULL);

    printf("Enter the number of readers and writers\n");
    scanf("%d %d",&nor,&now);

    for(int i=0;i<nor;i++)
        pthread_create(&r[i],NULL,reader,(void *)i);

    for(int j=0;j<now;j++)
        pthread_create(&w[j],NULL,writer,(void *)j);

    for(int i=0;i<nor;i++)
        pthread_join(r[i],NULL);

    for(int j=0;j<now;j++)
        pthread_join(w[j],NULL);

    return 0;
}

