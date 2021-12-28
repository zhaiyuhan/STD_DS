#ifndef BTREE_H
#define BTREE_H

typedef struct _BNode
{
    int data;
    struct _BNode *lchild;
    struct _BNode *rchild;
}BNode, *BTree;

BTree BTree_Init(int _value);
void BTree_preOrder(BTree _btree);
void BTree_inOrder(BTree _btree);
void BTree_postOrder(BTree _btree);
#endif // BTREE_H
