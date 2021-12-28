#include "BTree.h"
#include <stdio.h>
#include <stdlib.h>

BTree BTree_Init(int _value)
{
    BTree root = (BTree)malloc(sizeof(BNode));
    root->data = _value;
    root->lchild = NULL;
    root->rchild = NULL;
    printf("Create a BTree\r\n");
    return root;
}

void BTree_preOrder(BTree _btree)
{
    if(_btree == NULL)
    {
        return;
    }
    printf("%d ", _btree->data);
    BTree_preOrder(_btree->lchild);
    BTree_preOrder(_btree->rchild);
}

void BTree_inOrder(BTree _btree)
{
    if(_btree == NULL)
    {
        return;
    }
    BTree_preOrder(_btree->lchild);
    printf("%d ", _btree->data);
    BTree_preOrder(_btree->rchild);
}

void BTree_postOrder(BTree _btree)
{
    if(_btree == NULL)
    {
        return;
    }
    BTree_preOrder(_btree->lchild);
    BTree_preOrder(_btree->rchild);
    printf("%d ", _btree->data);
}
