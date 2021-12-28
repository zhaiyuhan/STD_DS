#include "SeqQueue.h"
#include "stdlib.h"
#include "stdio.h"

void SeqQueue_Init(SeqQueue *_seqqueue)
{
    _seqqueue->front = 0;
    _seqqueue->rear = 0;
    printf("Create a SeqQueue\r\n");
}

int SeqQueue_En(SeqQueue *_seqqueue, int e)
{
    if((_seqqueue->rear + 1)%SEQQUEUE_MAX_SIZE == _seqqueue->front)
        return SEQQUEUE_ERROR;
    _seqqueue->data[_seqqueue->rear] = e;
    _seqqueue->rear = (_seqqueue->rear + 1)%SEQQUEUE_MAX_SIZE;
    return  SEQQUEUE_SUCCESS;
}

int SeqQueue_De(SeqQueue *_seqqueue, int *e)
{
    if(_seqqueue->front == _seqqueue->rear)
        return SEQQUEUE_ERROR;
    *e = _seqqueue->data[_seqqueue->front];
    _seqqueue->front = (_seqqueue->front + 1)%SEQQUEUE_MAX_SIZE;
    return SEQQUEUE_SUCCESS;
}
