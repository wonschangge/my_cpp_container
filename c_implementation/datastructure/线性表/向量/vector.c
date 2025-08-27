#include "vector.h"
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>

void GetArray(Vector * V)
{
    V->elements = (ElementType *)malloc(sizeof(ElementType) * V->ArraySize);
}

/* 初始化函数，建立一个最大长度为sz的数组 */
void InitVector(Vector * V, int sz)
{
    if (sz <= 0)
        printf("Invalid Array Size\n");
    else {
        V->ArraySize = sz;
        V->VectorLength = 0;
        GetArray(V);
    };
}

/**
 * 取向量中第i个结点的值 
 *
 * 若第i个结点存在，则返回第i个结点的值；否则返回NULL
 */
ElementType GetNode(Vector * V, int i)
{
    if (i<0 || i >= V->VectorLength)
        return NULL;

    return V->elements[i];
}

 /* 释放向量存储空间 */
void FreeVector(Vector * V)
{
    free(V->elements);
}

/**
 * 查找值为x的结点 
 *
 * 若找到，则返回结点序号；否则返回-1
 */
int Find(Vector * V, ElementType x)
{
    for (int i = 0; i < V->VectorLength; i++)
        if (x == V->elements[i])
            return i;
    return -1;
}

/**
 * 在向量第i位置插入值为x的新结点 
 *
 * 若插入成功，则返回TRUE；否则返回FALSE
 */
Bool Insert(Vector * V, ElementType x, int i)
{
    if (V->VectorLength == V->ArraySize)
    {
        printf("overflow\n"); /* 向量的存储空间已满 */
        return FALSE;
    }

    if (i < 0 || i > V->VectorLength)
    {
        printf("position error\n"); /* 插入位置错误 */
        return FALSE;
    }

    for (int j=V->VectorLength-1; j>=i; j--)
        V->elements[j+1] = V->elements[j]; /* 后移 */
    V->elements[i] = x; /* 插入 */
    V->VectorLength++; /* 向量长度+1 */
    
}

/**
 * 删除向量的第i个条目 
 *
 * 若删除成功，则返回TRUE；否则返回FALSE
 */
Bool Remove(Vector * V, int i)
{
    if (V->VectorLength == 0) /* 空向量 */
    {
        printf("Vector is empty\n");
        return FALSE;
    }
    else if (i < 0 || i > (V->VectorLength - 1)) /* 删除位置错误 */
    {
        printf("position error\n");
        return FALSE;
    }
    else {
        for (int j = i; j < V->VectorLength - 1; j++)
            V->elements[j] = V->elements[j+1];  /* 前移 */
    }

    V->VectorLength--; /* 向量长度减1 */
    return  TRUE;
}

/* 把向量Va,Vb合并到Vc中,重复元素只留一个 */
Vector * Union(Vector * Va, Vector * Vb)
{
    ElementType x;
    Vector * Vc = (Vector *)malloc(sizeof(Vector));

    int n = Va->VectorLength;
    int m = Vb->VectorLength;
    InitVector(Vc, m + n);

    int j = 0;
    for (int i = 0; i < n; i++){
        x = GetNode(Va, i); /* 从Va中取一结点 */
        Insert(Vc, x, j);
        j++;
    }

    for (int i = 0; i < m; i++) {
        x = GetNode(Vb, i); /* 从Va中取一结点 */
        if(Find(Va, x) == -1) {
            Insert(Vc, x, j);
            j++;
        }
    }

    return Vc;
}
Vector * Intersection(Vector *, Vector *);
