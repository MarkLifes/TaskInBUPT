//
// Created by Tsang on 2018/5/20.
//
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    double value;
    Node *next;
};

//Inset sort.
void insertSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}
//Bubble sort.
void bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
//Select sort.
void selectSort(vector<int> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        int tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
}
//Shell sort.
void shellSort(vector<int> &arr)
{
    for (int step = (int)arr.size() >> 1; step > 0; step >>= 1)
    {
        for (int i = step; i < arr.size(); i++)
        {
            int temp = arr[i];
            int j = i - step;
            for (; j >= 0 && arr[j] > temp; j -= step)
            {
                arr[j + step] = arr[j];
            }
            arr[j + step] = temp;
        }
    }
}
//Merge sort.
void merge_array(vector<int> &arr, int s, int m, int e, vector<int> &temp)
{
    int ls = s, rs = m, ts = s;
    while (ls != m && rs != e)
        if (arr[ls] < arr[rs])
            temp[ts++] = arr[ls++];
        else
            temp[ts++] = arr[rs++];

    while (ls < m)
        temp[ts++] = arr[ls++];

    while (rs < e)
        temp[ts++] = arr[rs++];

    for (int i = s; i < e; i++)
        arr[i] = temp[i];
}
void merge_sort(vector<int> &arr, int s, int e, vector<int> &temp)
{
    int m = (s + e) / 2;
    if (m != s)
    {
        merge_sort(arr, s, m, temp);
        merge_sort(arr, m, e, temp);
        merge_array(arr, s, m, e, temp);
    }
}
void mergeSort(vector<int> &arr)
{
    vector<int> temp(arr);
    merge_sort(arr, 0, (int)arr.size(), temp);
}
//Quick sort.
void quickSort(vector<int> &arr, int s, int e)
{
    if (s < e)
    {
        int i = s, j = e, x = arr[s];
        while (i < j)
        {
            while (i < j && arr[j] >= x)
            {
                j--;
            }
            if (i < j)
                arr[i++] = arr[j];
            while (i < j && arr[i] < x)
            {
                i++;
            }
            if (i < j)
                arr[j--] = arr[i];
        }
        arr[i] = x;
        quickSort(arr, s, i - 1);
        quickSort(arr, i + 1, e);
    }
}
//Adjust heap.
void adjustHeap(vector<int> &arr, int p, int len)
{
    int curParent = arr[p];
    int child = 2 * p + 1;
    while (child < len)
    {
        if (child + 1 < len && arr[child] < arr[child + 1])
            child++;
        if (curParent < arr[child])
        {
            arr[p] = arr[child];
            p = child;
            child = 2 * p + 1;
        }
        else
            break;
    }
    arr[p] = curParent;
}
//Heap sort.
void heapSort(vector<int> &arr)
{
    int n = (int)arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        adjustHeap(arr, i, n);
    for (int i = n - 1; i >= 0; i--)
    {
        int max = arr[0];
        arr[0] = arr[i];
        arr[i] = max;
        adjustHeap(arr, 0, i);
    }
}
//Count sort.
int *countSort(int *A, int n)
{
    // write code here
    if (A == NULL || n < 2)
    {
        return NULL;
    }
    int min = A[0];
    int max = A[0];
    for (int i = 0; i < n; i++)
    {
        min = min <= A[i] ? min : A[i];
        max = max >= A[i] ? max : A[i];
    }
    int len = max - min + 1;
    vector<int> countArr(len, 0);
    for (int i = 0; i < n; i++)
    {
        countArr[A[i] - min]++;
    }
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        while (countArr[i]-- > 0)
        {
            A[index++] = i + min;
        }
    }
    return A;
}
//Radix sort.
int maxBit(int *A, int n)
{
    int mb = 0;
    for (int i = 0; i < n; i++)
    {
        int p = A[i];
        int c = 1;
        while (p / 10)
        {
            p = p / 10;
            c++;
        }
        if (c > mb)
            mb = c;
    }
    return mb;
}
void radixSort(int *A, int n)
{
    int count[10], tmp[10];
    int mb = maxBit(A, n);
    int r = 1;
    for (int j = 0; j < mb; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            count[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            int k = A[i] / r;
            int q = k % 10;
            count[q]++;
        }
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int p = A[i] / r;
            int s = p % 10;
            tmp[count[s] - 1] = A[i];
            count[s]--;
        }
        for (int i = 0; i < n; i++)
        {
            A[i] = tmp[i];
        }
        r = r * 10;
    }
}
//Bucket sort.
void bucketSort(double *arr, int length)
{
    Node key[10];
    int number = 0;
    Node *p, *q;
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        key[i].value = 0;
        key[i].next = NULL;
    }
    for (int i = 0; i < length; i++)
    {
        Node *insert = new Node();
        insert->value = arr[i];
        insert->next = NULL;
        number = arr[i] * 10;
        if (key[number].next == NULL)
        {
            key[number].next = insert;
        }
        else
        {
            p = &key[number];
            q = key[number].next;
            while ((q != NULL) && (q->value <= arr[i]))
            {
                q = q->next;
                p = p->next;
            }
            insert->next = q;
            p->next = insert;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        p = key[i].next;
        if (p == NULL)
            continue;
        while (p != NULL)
        {
            arr[counter++] = p->value;
            p = p->next;
        }
    }
}
