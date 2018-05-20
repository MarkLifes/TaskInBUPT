//
// Created by Tsang on 2018/5/20.
//
#include "stdafx.h"
#include <stdlib.h>

Node *Create(int value)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = value;
    head->next = NULL;
    return head;
}

bool Destroy_List(Node *head)
{
    Node *temp;
    while (head)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
    head = NULL;
    return true;
}

bool Append(Node *head, int value)
{
    Node *n = Create(value);
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = n;
    return 0;
}

void Print_List(Node *head)
{
    Node *temp = head->next;
    while (temp)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

bool Insert_List(Node *head, int locate, int value)
{
    Node *temp = head;
    Node *p;
    Node *n = Create(value);
    if (locate < 0)
        return false;
    while (locate--)
    {
        if (temp->next == NULL)
        {
            temp->next = Create(value);
            return true;
        }
        temp = temp->next;
    }
    p = temp->next;
    temp->next = n;
    n->next = p;
    return true;
}

bool Delete_List(Node *head, int locate)
{
    Node *temp = head;
    Node *p;
    if (locate < 0)
        return false;
    while (locate--)
    {
        if (temp == NULL)
        {
            return false;
        }
        temp = temp->next;
    }
    p = temp->next->next;
    free(temp->next);
    temp->next = NULL;
    temp->next = p;
    return true;
}

int Size_List(Node *head)
{
    Node *temp = head;
    int size = 0;
    while (temp->next)
    {
        temp = temp->next;
        size++;
    }
    return size;
}
//Bubble sort.
bool Bubble_Sort(Node *head)
{
    int t = 0;
    int size = Size_List(head);
    for (Node *temp = head->next; temp->next != NULL; temp = temp->next)
    {
        for (Node *p = head->next; p->next != NULL; p = p->next)
        {
            if (p->data > p->next->data)
            {
                t = p->data;
                p->data = p->next->data;
                p->next->data = t;
            }
        }
    }
    return 0;
}
bool Select_Sort(Node *head)
{
    int t = 0;
    int size = Size_List(head);
    for (Node *temp = head->next; temp != NULL; temp = temp->next)
    {
        for (Node *p = temp; p != NULL; p = p->next)
        {
            if (temp->data > p->data)
            {
                printf("换%d和%d\n", temp->data, p->data);
                t = temp->data;
                temp->data = p->data;
                p->data = t;
            }
        }
    }
    return 0;
}
//Insert sort.
bool Insert_Sort(Node *head)
{
    int t = 0;
    int size = Size_List(head);
    for (Node *temp = head->next->next; temp != NULL; temp = temp->next)
    {
        for (Node *p = head; p->next != NULL; p = p->next)
        {
            if (p->next->data > temp->data)
            {
                printf("换%d和%d\n", temp->data, p->next->data);
                t = temp->data;
                temp->data = p->next->data;
                p->next->data = t;
            }
        }
    }
    return 0;
}