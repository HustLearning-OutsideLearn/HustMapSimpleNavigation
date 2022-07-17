#include <iostream>

struct TNode
{
    int key;
    TNode *lchild;
    TNode *rchild;
};

typedef TNode* PNode;

PNode searchNode(PNode, int);
void insertNode(PNode&, int);
void deleteT(PNode&, int);
void deleteNode(PNode &);

int main()
{

    return 0;
}

PNode searchNode(PNode T, int key)
{
    if (T == NULL || T->key == key)
        return T;
    
    if (key < T->key) return searchNode(T->lchild, key);
    if (key > T->key) return searchNode(T->rchild, key);
}

void insertNode(PNode &T, int key)
{
    if (T == NULL)
    {
        T = new TNode;
        T->lchild = NULL;
        T->rchild = NULL;
        T->key = key;
        return;
    }

    if (key < T->key) insertNode(T->lchild, key);
    if (key > T->key) insertNode(T->rchild, key);
}

void deleteT(PNode &T, int key)
{
    if (T != NULL)
    {
        if (key < T->key) deleteT(T->lchild, key);
        if (key > T->key) deleteT(T->rchild, key);
        if (key == T->key) deleteNode(T);
    }
}

void deleteNode(PNode &T)
{
    PNode temp, parent_temp;

    if (T == NULL) return;

    if (T->lchild == NULL && T->rchild == NULL)
    {
        delete T;
        return;
    }

    if (T->lchild == NULL)
    {
        temp = T->rchild;
        T->key = temp->key;
        T->rchild = temp->rchild;
        delete temp;
        return;
    }

    if (T->rchild == NULL)
    {
        temp = T->lchild;
        T->key = temp->key;
        T->lchild = temp->lchild;
        delete temp;
        return;
    }

    temp = T->rchild;

    if (temp->lchild == NULL)
    {
        T->key = temp->key;
        T->rchild = temp->rchild;
        delete temp;
    }
    else
    {
        while (temp->lchild != NULL)
        {
            parent_temp = temp;
            temp = temp->lchild;
        }

        T->key = temp->key;
        parent_temp->lchild = temp->rchild;
        delete temp;
    }
}