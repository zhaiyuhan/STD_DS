#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#define SEQQUEUE_MAX_SIZE 100
#define SEQQUEUE_SUCCESS  1
#define SEQQUEUE_ERROR    0
typedef struct _SeqQueue{
    int data[SEQQUEUE_MAX_SIZE];
    int front;
    int rear;
}SeqQueue;

void SeqQueue_Init(SeqQueue *_seqqueue);
int SeqQueue_En(SeqQueue *_seqqueue, int e);
int SeqQueue_De(SeqQueue *_seqqueue, int *e);

#endif // SEQQUEUE_H
