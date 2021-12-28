#include "SeqList.h"
#include "stdlib.h"
#include "stdio.h"

void SeqList_Init(SeqList *_seqlist)
{
    if(!_seqlist->length)
    {
        exit(0);
    }
    _seqlist->length = 0;
    printf("Create a SeqList\r\n");
}

int SeqList_Insert(SeqList *_seqlist, int _index, int e)
{
    if(_seqlist->length == SEQLIST_MAX_SIZE)
        return SEQLIST_ERROR;
    if(_index < 1 || _index > _seqlist->length + 1)
        return SEQLIST_ERROR;
    if(_index <= _seqlist->length)
    {
        for(int i = _seqlist->length - 1; i >= _index - 1; i--)
            _seqlist->data[i+1] = _seqlist->data[i];
    }
    _seqlist->data[_index - 1] = e;
    _seqlist->length++;
    return SEQLIST_SUCCESS;
}

int SeqList_Remove(SeqList *_seqlist, int _index)
{
    if(_seqlist->length == 0)
        return SEQLIST_ERROR;
    if(_index < 1 || _index > _seqlist->length)
        return SEQLIST_ERROR;
    if(_index < _seqlist->length)
    {
        for(int i = _index; i < _seqlist->length; i++)
            _seqlist->data[i-1] = _seqlist->data[i];
    }
    _seqlist->length--;
    return SEQLIST_SUCCESS;
}
