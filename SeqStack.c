#include "SeqStack.h"
#include <stdio.h>
#include <stdlib.h>
void SeqStack_Init(SeqStack *_seqstack)
{
    _seqstack->top = -1;
    printf("Create a SeqStack\r\n");
}

int SeqStack_Pop(SeqStack *_seqstack, int *e)
{
    if(_seqstack->top == -1)
        return SEQSTACK_ERROR;
    *e = _seqstack->data[_seqstack->top];
    _seqstack->top--;
    return SEQSTACK_SUCCESS;
}

int SeqStack_Push(SeqStack *_seqstack, int e)
{
    if(_seqstack->top == SEQSTACK_MAX_SIZE - 1)
        return SEQSTACK_ERROR;
    _seqstack->top++;
    _seqstack->data[_seqstack->top] = e;
    return SEQSTACK_SUCCESS;
}
