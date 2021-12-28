#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>

void LinkList_Init(LinkList *_linklist)
{
    *_linklist = (LinkList)malloc(sizeof(Node));
    (*_linklist)->data = 0;
    (*_linklist)->next = NULL;
    printf("Create a LinkList\r\n");
}

void LinkList_Print(LinkList _linklist)
{
    Node *node = _linklist->next;
    while (node)
    {
        printf("%d", node->data);
        if(node->next != NULL)
            printf("-->");
        node = node->next;
    }
    printf("\r\n");
}


void LinkList_Insert(LinkList _linklist, int _index, int e)
{
    LinkList p;
    p = _linklist;
    Node *new_node;
    int i = 1;
    while (p != NULL && i < _index)
    {
        p = p->next;
        i++;
    }
    new_node = (Node *)malloc(sizeof (Node));
    new_node->data = e;
    new_node->next = p->next;
    p->next = new_node;
}


void LinkList_Remove(LinkList *_linklist, int _index, int *e)
{
    LinkList p;
    Node *temp_node;
    p = *_linklist;
    int i = 1;
    while (p->next && i < _index)
    {
        p = p->next;
        i++;
    }
    temp_node = p->next;
    p->next = temp_node->next;
    *e = temp_node->data;
    free(temp_node);
}

void DLinkList_Init(DLinkList *_dlinklist)
{
    *_dlinklist = (DLinkList)malloc(sizeof(DNode));
    (*_dlinklist)->data = 0;
    (*_dlinklist)->prior = NULL;
    (*_dlinklist)->next = NULL;
    printf("Create a DLinkList\r\n");
}

void DLinkList_Print(DLinkList _dlinklist)
{
    DNode *node = _dlinklist;
    while (node)
    {
        printf("%d", node->data);
        if(node->next != NULL)
            printf("<-->");
        node = node->next;
    }
    printf("\r\n");
}

void DLinkList_Insert(DLinkList _dlinklist, int _index, int e)
{
    DLinkList p;
    p = _dlinklist;
    DNode *new_node;
    int i = 1;
    while(p != NULL && i < _index)
    {
        p = p->next;
        i++;
    }
    new_node = (DNode *)malloc(sizeof (DNode));
    new_node->data = e;
    if(p->prior == NULL)
    {
        new_node->next = p->next;
        new_node->prior = p;
        p->next = new_node;
    }else{
        new_node->prior = p->prior;
        p->prior->next = new_node;
        new_node->next = p;
        p->prior = new_node;
    }
}

void DLinkList_Remove(DLinkList *_dlinklist, int _index, int *e)
{
    DLinkList p;
    DNode *temp_node;
    p = *_dlinklist;
    int i = 1;
    while (p->next && i < _index)
    {
        p = p->next;
        i++;
    }
    temp_node = p->next;
    temp_node->prior->next = temp_node->next;
    temp_node->next->prior = temp_node->prior;
    *e = temp_node->data;
    free(temp_node);
}
