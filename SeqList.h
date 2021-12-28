#ifndef SEQLIST_H
#define SEQLIST_H

#define SEQLIST_MAX_SIZE 100
#define SEQLIST_SUCCESS  1
#define SEQLIST_ERROR    0
typedef struct _SeqList{
    int data[SEQLIST_MAX_SIZE];
    int length;
}SeqList;

void SeqList_Init(SeqList *_seqlist);
int SeqList_Insert(SeqList *_seqlist, int _index, int e);
int SeqList_Remove(SeqList *_seqlist, int _index);
#endif // SEQLIST_H
