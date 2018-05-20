//
// Created by Tsang on 2018/5/14.
//

#include <iostream>
#include <queue>
#include "BinaryTree.h"
using namespace std;
template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree &bt)
{
    if (nullptr != bt.root)
    {
        this->root = clone(bt.root);
    }
    else
    {
        root = nullptr;
    }
};

template <typename T>
BinaryTree<T>::BinaryTree(const T &theElement)
{
    root = new BinaryNode(theElement);
    /*root->element = theElement;
    root->leftNode = nullptr;
    root->rightNode = nullptr;*/
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    makeEmpty();
    /* root->~BinaryNode();*/
};

template <typename T>
void BinaryTree<T>::insert(const T &theElement)
{
    insert(theElement, root);
};

template <typename T>
void BinaryTree<T>::remove(const T &theElement)
{
    remove(theElement, root);
};

template <typename T>
void BinaryTree<T>::makeEmpty()
{
    makeEmpty(root);
};

template <typename T>
bool BinaryTree<T>::isFind(const T &theElement) const
{
    isFind(theElement, root);
};

template <typename T>
void BinaryTree<T>::preOrder() const
{
    preOrder(root);
};

template <typename T>
void BinaryTree<T>::inOrder() const
{
    inOrder(root);
};

template <typename T>
void BinaryTree<T>::postOrder() const
{
    postOrder(root);
};

template <typename T>
void BinaryTree<T>::levelOrder() const
{
    levelOrder(root);
};

template <typename T>
int BinaryTree<T>::treeDepth() const
{
    treeDepth(root);
};

template <typename T>
bool BinaryTree<T>::printPath(int data) const
{
    printPath(data, root);
};

template <typename T>
typename BinaryTree<T>::BinaryNode *BinaryTree<T>::clone(const BinaryNode *r)
{
    if (nullptr == r)
    {
        return nullptr;
    }
    else
    {
        return new BinaryNode(r->element, clone(r->leftNode), clone(r->rightNode));
    }
}

template <typename T>
void BinaryTree<T>::insert(const T &theElement, BinaryNode *&t)
{
    if (nullptr == t)
    {
        t = new BinaryNode(theElement);
    }
    else if (theElement < t->element)
    {
        insert(theElement, t->leftNode);
    }
    else if (theElement > t->element)
    {
        insert(theElement, t->rightNode);
    }
    else
    { //重复的数据不添加到树中
    }
};

template <typename T>
void BinaryTree<T>::remove(const T &theElement, BinaryNode *&t)
{
    if (nullptr == t)
    {
        return;
    }
    else
    {
        if (theElement < t->element)
        {
            remove(t->leftNode);
        }
        else if (theElement > t->element)
        {
            remove(t->rightNode);
        }
        else if (nullptr != t->leftNode && nullptr != t->rightNode)
        {

            t->element = findMin(t->rightNode)->element;
            remove(t->element, t->rightNode);
        }
        else
        {
            BinaryNode *oldNode = t;
            t = (nullptr != t->leftNode) ? t->leftNode : t->rightNode;
            delete oldNode;
        }
    }
};

template <typename T>
void BinaryTree<T>::makeEmpty(BinaryNode *&t)
{
    if (nullptr != t)
    {
        makeEmpty(t->leftNode);
        makeEmpty(t->rightNode);
        std::cout << "delete: " << t->element << std::endl;
        delete t;
    }
    t = nullptr;
};

template <typename T>
bool BinaryTree<T>::isFind(const T &theElement, BinaryNode *t) const
{
    if (nullptr == t)
    {
        return false;
    }
    else if (theElement < t->element)
    {
        return isFind(theElement, t->leftNode);
    }
    else if (theElement > t->element)
    {
        return isFind(theElement, t->rightNode);
    }
    else
    {
        return true;
    }
};

template <typename T>
typename BinaryTree<T>::BinaryNode *BinaryTree<T>::findMin(BinaryNode *bNode) const
{
    if (nullptr != bNode)
    {
        while (nullptr != bNode->leftNode)
        {
            bNode = bNode->leftNode;
        }
    }

    return bNode;
}

template <typename T>
typename BinaryTree<T>::BinaryNode *BinaryTree<T>::findMax(BinaryNode *bNode) const
{
    if (nullptr != bNode)
    {
        while (nullptr != bNode->rightNode)
        {
            bNode = bNode->rightNode;
        }
    }
    return bNode;
}

template <typename T>
void BinaryTree<T>::preOrder(BinaryNode *bNode) const
{
    if (nullptr != bNode)
    {
        std::cout << bNode->element << " ";
        preOrder(bNode->leftNode);
        preOrder(bNode->rightNode);
    }
};

template <typename T>
void BinaryTree<T>::inOrder(BinaryNode *bNode) const
{
    if (nullptr != bNode)
    {
        inOrder(bNode->leftNode);
        std::cout << bNode->element << " ";
        inOrder(bNode->rightNode);
    }
};

template <typename T>
void BinaryTree<T>::postOrder(BinaryNode *bNode) const
{
    postOrder(bNode->leftNode);
    postOrder(bNode->rightNode);
    std::cout << bNode->element << " ";
};

template <typename T>
void BinaryTree<T>::levelOrder(BinaryNode *bNode) const
{
    if (bNode == NULL)
    {
        return;
    }
    queue<BinaryNode *> q;
    q.push(bNode);
    while (!q.empty())
    {
        BinaryNode *cur = q.front();
        q.pop();
        cout << cur->element << " ";
        if (cur->leftNode)
        {
            q.push(cur->leftNode);
        }
        if (cur->rightNode)
        {
            q.push(cur->rightNode);
        }
    }
}

template <typename T>
int BinaryTree<T>::treeDepth(BinaryNode *bNode) const
{
    if (bNode == NULL)
        return 0;

    int left = treeDepth(bNode->leftNode);
    int right = treeDepth(bNode->rightNode);
    return left > right ? left + 1 : right + 1;
}

template <typename T>
bool BinaryTree<T>::printPath(int data, BinaryNode *bNode) const
{
    if (bNode == NULL)
        return false;

    if (bNode->element == data || printPath(reinterpret_cast<int>(bNode->leftNode)) || printPath(reinterpret_cast<int>(bNode->rightNode)))
    {
        cout << bNode->element;
        return true;
    }

    return false;
}