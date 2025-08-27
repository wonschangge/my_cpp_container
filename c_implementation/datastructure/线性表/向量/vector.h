#ifndef _Vector_H
#define _Vector_H

#include <stdio.h>
#include <stdlib.h>

enum boolean { FALSE, TRUE };
typedef enum boolean Bool;

typedef int ElementType;

struct vector {
  ElementType *elements;
  int ArraySize;
  int VectorLength;
};
typedef struct vector Vector;

void GetArray(Vector *);              /* 申请向量的存储空间 */
void InitVector(Vector *, int sz);    /* 初始化一个空向量 */
ElementType GetNode(Vector *, int i); /* 取向量的第i个表目 */
void FreeVector(Vector *);            /* 释放向量存储空间 */
int Find(Vector *, ElementType);      /* 在向量中查找 */

/* 插入和删除 */
Bool Insert(Vector *, ElementType x, int i); /* 在第i个位置插入值为x的新结点 */
Bool Remove(Vector *, int i);                /* 删除向量的第i个条目 */

/* 向量求集合的“并运算”和“交运算” */
Vector * Union(Vector *, Vector *);
Vector * Intersection(Vector *, Vector *);


#endif