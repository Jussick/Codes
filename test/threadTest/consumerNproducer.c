//C file
/***********************************************
#
#      Filename: consumerNproducer.c
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 使用线程条件锁防止死锁，例子：生产者消费者问题
#        Create: 2019-07-08 19:32:01
#**********************************************/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
 
#define CONSUMERS_COUNT 2   
#define PRODUCERS_COUNT 1
 
pthread_mutex_t g_mutex ;
pthread_cond_t g_cond ;
 
pthread_t g_thread[CONSUMERS_COUNT + PRODUCERS_COUNT] ;
int share_variable = 0 ;// this is the share variable, shared by consumer and producer
 
void* consumer( void* arg )
{
   int *num = (int *)arg ;
   while ( 1 ) 
   {
      /******* critical section begin *******/
      pthread_mutex_lock( &g_mutex ) ;
 
      // if share_variable == 0, means consumer shell stop here
      while ( share_variable == 0 )
      {
         printf( "consumer %d begin wait a condition...\n", *num ) ;
         // put a thread blocked ont a condition variable( here is g_cond),
         // and unlock the mutex( here is g_mutex )
         pthread_cond_wait( &g_cond, &g_mutex ) ;
      }
      // here means n != 0 and consumer can goes on
      // consumer consumed shared variable, so the number of shared variable shell minus
      printf( "consumer %d end wait a condition...\n", *num ) ;
      printf( "consumer %d begin consume product\n", *num ) ;
      -- share_variable ;
 
      pthread_mutex_unlock( &g_mutex ) ;
      /******** critial section end *********/
      sleep( 1 ) ;
   }

}
void* producer( void* arg )
{
   int *num = (int*)arg ;
   while ( 1 )
   {
      /******* critical section begin *******/
      pthread_mutex_lock( &g_mutex ) ;
 
      // produce a shared variable
      printf( "producer %d begin produce product...\n", *num ) ;
      ++ share_variable ;
      printf( "producer %d end produce product...\n", *num ) ;
      // unblock threads blocked on a condition variable( here is g_cond )
      pthread_cond_signal( &g_cond ) ;
      printf( "producer %d notified consumer by condition variable...\n", *num ) ;
      pthread_mutex_unlock( &g_mutex ) ;
 
      /******** critial section end *********/
      sleep( 2 ) ;
   }
   
}
int main( void )
{
   // initiate mutex
   pthread_mutex_init( &g_mutex, NULL ) ;
   // initiate condition
   pthread_cond_init( &g_cond, NULL ) ;
 
   //pthread_attr_t pAttr;
   //pthread_attr_init(&pAttr);
   //pthread_attr_setdetachstate(&pAttr, PTHREAD_CREATE_DETACHED);
   // initiate consumer threads
   int i;
   for ( i = 0; i < CONSUMERS_COUNT; ++ i )
   {
      printf("in consumer i=%d\n", i);
      pthread_create( &g_thread[i], NULL, consumer, (void*)&i ) ;
   }
   sleep( 1 ) ;
// initiate producer threads
   for ( ; i < CONSUMERS_COUNT+PRODUCERS_COUNT; ++ i )
   {
      printf("in producer i=%d\n", i);
      pthread_create( &g_thread[i], NULL, producer, (void*)&i ) ;
   }
   //pthread_join(g_thread[CONSUMERS_COUNT], NULL);
   for ( i = 0; i < CONSUMERS_COUNT + PRODUCERS_COUNT; ++ i ) 
   {
      pthread_join( g_thread[i], NULL ) ;
   }
 
   pthread_mutex_destroy( &g_mutex ) ;
   pthread_cond_destroy( &g_cond ) ;
}

