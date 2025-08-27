#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/* 线性表的初始化 */
void InitList(LinearList *L, int sz) {
  if (sz > 0) {
    L->MaxSize = sz;
    L->Last = 0;
    L->data = (ElementType *)malloc(sizeof(ElementType) * L->MaxSize);
  }
}

/* 释放线性表的存储空间 */
void FreeList(LinearList *L) { free(L->data); }

/* 判断线性表是否为空 */
Bool ListEmpty(LinearList *L) { return (L->Last <= 0) ? TRUE : FALSE; }

/* 判断线性表是否为满 */
Bool ListFull(LinearList *L) { return (L->Last >= L->MaxSize) ? TRUE : FALSE; }

/* 求线性表的长度 */
int ListLength(LinearList *L) { return L->Last; }

/* 取线性表的第i个表目 */

ElementType GetElem(LinearList *L, int i) {
  if (i < 0 || i >= L->Last)
    return NULL;
  return L->data[i];
}

/**
 * 在线性表中查找
 *
 * 查找表中值为 x 的结点。
 * 若查找成功，则返回该结点的序号；否则返回 -1
 * 若表中值为x的结点有多个，找到的是最前面的一个
 */
int LocateElem(LinearList *L, ElementType x) {
  for (int i = 0; i < L->Last; i++)
    if (L->data[i] == x)
      return i; /* 查找成功 */
  return -1;    /* 查找失败 */
}

/**
 * 在表中第i个位置插入值为x的结点
 *
 * 若插入成功，则返回TRUE；否则返回FALSE
 */
Bool InsertElem(LinearList *L, ElementType x, int i) {
  if (i < 0 || i > L->Last || L->Last == L->MaxSize)
    return FALSE; /* 插入位置不合理，插入失败 */

  for (int j = L->Last - 1; j >= i; j--)
    L->data[j + 1] = L->data[j]; /* 后移 */

  L->data[i] = x; /* 插入 */
  L->Last++;      /* 表长增1 */
  return TRUE;
}

/**
 * 删除表中第i个结点
 *
 * 若删除成功，则返回TRUE；否则返回FALSE
 */
Bool DeleteElem(LinearList *L, int i) {
  if (i < 0 || i >= L->Last || L->Last == 0)
    return FALSE; /* 第i个结点不存在，删除失败 */

  for (int j = i; j < L->Last - 1; j++)
    L->data[j] = L->data[j + 1]; /* 前移 */
  L->Last--;                     /* 表长减1 */
  return TRUE;
}

/* 打印线性表的条目 */
void printout(LinearList *L) {
  for (int i = 0; i < L->Last; i++)
    printf("%d ", L->data[i]);
  printf("\n");
}

/* 线性表测试用例 */
int main() {
  LinearList *L = (LinearList *)malloc(sizeof(LinearList));

  InitList(L, 5);
  InsertElem(L, 10, 0);
  InsertElem(L, 20, 0);
  InsertElem(L, 30, 0);
  InsertElem(L, 40, 0);
  InsertElem(L, 50, 0);

  if (InsertElem(L, 60, 0))
    printout(L);
  else if (ListFull(L))
    printf("List is full, failed to insert\n");

  printout(L);
  DeleteElem(L, 1);
  DeleteElem(L, 1);
  printf("After twice deletions the list is ");
  printout(L);

  printf("The location of data 20 is %d\n", LocateElem(L, 20));
  printf("The 3rd value is %d\n", GetElem(L, 2));
  FreeList(L);

  return 0;
}