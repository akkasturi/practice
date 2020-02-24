#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_WORKER BACKLOG
#define FALSE 0
#define TRUE 1
#define FAILURE -1
#define SUCCESS 1

typedef struct{
  pthread_t worker_thread;
  int       free;
  int       new_fd;
}thread_instance_t;


typedef struct {
  int i;
  char str[50];
  int j;
}msg_t;


void *worker_handler(void *ptr);
