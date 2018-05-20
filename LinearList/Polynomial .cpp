//
// Created by Tsang on 2018/5/20.
//
#include <iostream>
#include <cstdio>

using namespace std;

struct Node
{
    double coef;
    int expn;
    Node *next;
};

void CreatPolynomial(Node *&head, int n)
{
    head = (Node *)malloc(sizeof(Node));
    head->coef = 0;
    head->expn = 0;
    head->next = NULL; 
    cout << "请输入各项系数及指数：" << endl;
    Node *p = head;
    for (int i = 0; i < n; i++)
    {
        p->next = (Node *)malloc(sizeof(Node));
        p = p->next;
        cin >> p->coef >> p->expn;
        p->next = NULL;
    }
}

void PrintPolynomial(Node *&head)
{
    if (head->next == NULL)
        putchar('0');
    else
    {
        for (Node *p = head->next; p != NULL; p = p->next)
        {
            if (p != head->next && p->coef > 0)
                putchar('+');

            if (p->coef == 1)
            {
                if (p->expn == 0)
                    putchar('1');
            }
            else if (p->coef == -1)
                putchar('-');
            else
                cout << p->coef;

            switch (p->expn)
            {

            case 0:
                break;

            case 1:
                putchar('x');
                break;

            default:
                p->expn < 0 ? printf("x^(%d)", p->expn) : printf("x^%d", p->expn);
                break;
            }
        }
    }
    cout << endl;
}

void Free(Node *&head)
{
    Node *q = NULL;
    for (Node *p = head; p != NULL; p = q)
    {
        q = p->next;
        free(p);
    }
}

char cmp(int a, int b)
{
    if (a > b)
        return '>';
    if (a < b)
        return '<';
    return '=';
}

void AddPolynomial(Node *&pA, Node *&pB)
{
    Node *ha = pA;
    Node *hb = pB;
    Node *qa = ha->next;
    Node *qb = hb->next;
    while (qa && qb)
    {
        double sum = 0;
        int a = qa->expn;
        int b = qb->expn;
        switch (cmp(a, b))
        {

        case '<':
            ha = qa;
            qa = qa->next;
            break;

        case '=':
            sum = qa->coef + qb->coef;
            if (sum != 0.0)
            {
                qa->coef = sum;
                ha = qa;
            }
            else
            {
                if (ha->next != qa)
                    cout << "Error: ha->next != qa" << endl;
                ha->next = ha->next->next;
                free(qa);
            }
            if (hb->next != qb)
                cout << "Error: hb->next != qb" << endl;
            hb->next = hb->next->next;
            free(qb);
            qb = hb->next;
            qa = ha->next;
            break;

        case '>':
            hb->next = hb->next->next;
            qb->next = ha->next;
            ha->next = qb;

            qb = hb->next;
            ha = ha->next;
            break;

        default:
            cout << "Error!" << endl;
            break;
        }
    }
    if (qb)
        ha->next = qb;
    free(hb);
}
