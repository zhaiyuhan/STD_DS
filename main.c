#include "SeqList.h"
#include "SeqStack.h"
#include "SeqQueue.h"
#include "LinkList.h"
#include "BTree.h"

#include <stdio.h>
#include <stdlib.h>
void SeqList_test()
{
    SeqList test_seqlist;
    SeqList_Init(&test_seqlist);
    SeqList_Insert(&test_seqlist, 1, 1);
    SeqList_Insert(&test_seqlist, 2, 2);
    SeqList_Insert(&test_seqlist, 3, 3);
    printf("The length of SeqList is %d\r\n", test_seqlist.length);
    SeqList_Remove(&test_seqlist, 2);
    for(int i = 0; i < test_seqlist.length; i++)
        printf("The %dst data is %d\r\n", i+1, test_seqlist.data[i]);
}

void SeqStack_test()
{
    SeqStack test_seqstack;
    int _element;
    SeqStack_Init(&test_seqstack);
    SeqStack_Push(&test_seqstack, 1);
    SeqStack_Push(&test_seqstack, 2);
    SeqStack_Push(&test_seqstack, 3);
    SeqStack_Pop(&test_seqstack, &_element);
    printf("Pop the data is %d \r\n", _element);
    for(int i = 0; i < test_seqstack.top+1; i++)
        printf("The %dst data is %d\r\n", i+1, test_seqstack.data[i]);
}

void SeqQueue_test()
{
    SeqQueue test_seqqueue;
    int _element;
    SeqQueue_Init(&test_seqqueue);
    SeqQueue_En(&test_seqqueue, 1);
    SeqQueue_En(&test_seqqueue, 2);
    SeqQueue_En(&test_seqqueue, 3);
    SeqQueue_De(&test_seqqueue, &_element);
    printf("The length of SeqQueue is %d\r\n", (test_seqqueue.rear - test_seqqueue.front + SEQQUEUE_MAX_SIZE)%SEQQUEUE_MAX_SIZE);
    printf("Pop the data is %d \r\n", _element);
    for(int i = test_seqqueue.front; i < test_seqqueue.rear; i++)
        printf("The %dst data is %d\r\n", i+1, test_seqqueue.data[i]);
}

void LinkList_test()
{
    LinkList test_linklist;
    int _element;
    LinkList_Init(&test_linklist);
    for(int i = 1; i <= 10; i++)
        LinkList_Insert(test_linklist, i, i);
    LinkList_Insert(test_linklist, 2, 0);
    LinkList_Remove(&test_linklist, 2, &_element);
    printf("The deleted data is %d\r\n", _element);
    LinkList_Print(test_linklist);
}

void DLinkList_test()
{
    DLinkList test_dlinklist;
    int _element;
    DLinkList_Init(&test_dlinklist);
    for(int i = 1; i <= 10; i++)
        DLinkList_Insert(test_dlinklist, i, i);
    DLinkList_Print(test_dlinklist);
    DLinkList_Remove(&test_dlinklist, 5, &_element);
    printf("The deleted data is %d\r\n", _element);
    DLinkList_Print(test_dlinklist);
}

void BTree_test()
{
    BTree test_btree;
    test_btree = BTree_Init(0);
    BNode *node[10];
    for(int i = 0; i < 10; i++)
    {
        node[i] = (BNode*)malloc(sizeof(BNode));
        node[i]->data = i+1;
        node[i]->lchild = NULL;
        node[i]->rchild = NULL;
    }
    test_btree->lchild = node[0];
    test_btree->rchild = node[1];
    node[0]->lchild = node[2];
    node[0]->rchild = node[3];
    node[1]->lchild = node[4];
    node[1]->rchild = node[5];

    BTree_preOrder(test_btree);
    printf("preOrder \r\n");
    BTree_inOrder(test_btree);
    printf("inOrder \r\n");
    BTree_postOrder(test_btree);
    printf("postOrder \r\n");
}

int main()
{
    SeqList_test();
    SeqStack_test();
    SeqQueue_test();
    LinkList_test();
    DLinkList_test();
    BTree_test();
    return 0;
}
