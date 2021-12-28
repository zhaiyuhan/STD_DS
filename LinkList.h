#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct _Node{
    int data;
    struct _Node *next;
}Node, *LinkList;

typedef struct _DNode{
    int data;
    struct _DNode *prior;
    struct _DNode *next;
}DNode, *DLinkList;

void LinkList_Init(LinkList *_linklist);
void LinkList_Print(LinkList _linklist);
void LinkList_Insert(LinkList _linklist, int _index, int e);
void LinkList_Remove(LinkList *_linklist, int _index, int *e);

void DLinkList_Init(DLinkList *_dlinklist);
void DLinkList_Print(DLinkList _dlinklist);
void DLinkList_Insert(DLinkList _dlinklist, int _index, int e);
void DLinkList_Remove(DLinkList *_dlinklist, int _index, int *e);
#endif // LINKLIST_H
