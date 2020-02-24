#include "workers.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define MSG_SIZE sizeof(msg_t) 

void create_msg(char *buf, int new_fd);

void* worker_handler(void *data)
{
  thread_instance_t *thread= (thread_instance_t*)data;
  int new_fd = thread->new_fd;
  char buf[MSG_SIZE];

  pthread_detach(pthread_self());

  create_msg(buf,new_fd);

  //process, dummy work.
  FILE *fptr;
  char file_name[100];
  snprintf(file_name,100,"file_%lu_%d",pthread_self(),rand()%9999);

  fptr = fopen(file_name, "w");
  if(fptr)
  {
    unsigned int j = 0;
    for(;j< 10000000;j++)
    {
      fprintf(fptr, "%s","dummy dummy dummy dummy dummy mummy " );
    }
    fclose(fptr);
  }

  if (send(new_fd, buf, MSG_SIZE, 0) == -1){
    perror("send");
    close(new_fd);
    thread->free = TRUE;
    exit(0);
  }
    
  close(new_fd);
  thread->free = TRUE;

  return NULL;
}


void create_msg(char *buf, int new_fd)
{
  char *t_buf = buf;

  msg_t m = { 10, "hello from thread: ", 0 };

  m.j =  pthread_self();

  memcpy(t_buf,(void*)&m.i,sizeof(int));
  t_buf += sizeof(m.i);

  memcpy(t_buf,m.str,sizeof(m.str));

  t_buf += sizeof(m.str);

  memcpy(t_buf,(void*)&m.j,sizeof(m.j));
}
