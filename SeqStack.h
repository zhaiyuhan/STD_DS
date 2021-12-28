#ifndef SEQSTACK_H
#define SEQSTACK_H

#define SEQSTACK_MAX_SIZE 100
#define SEQSTACK_SUCCESS  1
#define SEQSTACK_ERROR    0
typedef struct _SeqStack{
    int data[SEQSTACK_MAX_SIZE];
    int top;
}SeqStack;

void SeqStack_Init(SeqStack *_seqstack);
int SeqStack_Pop(SeqStack *_seqstack, int *e);
int SeqStack_Push(SeqStack *_seqstack, int e);

#endif // SEQSTACK_H
