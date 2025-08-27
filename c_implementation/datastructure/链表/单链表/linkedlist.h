#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "../node.h"

enum boolean { FALSE, TRUE };
typedef enum boolean Bool;

struct linkedList {
  Node *front, *rear;      /* 指向表头和表尾的指针 */
  Node *prevPtr, *currPtr; /* 用于访问数据、插入和删除结点的指针 */
  int size;                /* 表中的结点数 */
  int position;            /* 表中当前结点位置计数 */
};
typedef struct linkedList LinkedList;

Node *GetNode(ElementType item, Node *ptr);    /* 申请结点空间的函数 */
void FreeNode(Node *p);                        /* 释放结点空间的函数 */
void InitLinkedList(LinkedList *);             /* 初始化函数 */
Bool IsEmpty(LinkedList *);                    /* 判断表是否为空 */
int NextLNode(LinkedList *);                   /* 求当前结点后继的函数 */
int SetPosition(LinkedList *, int pos);        /* 重定位当前结点 */
void InsertAt(LinkedList *, ElementType item); /* 在当前结点处插入结点的函数 */
void InsertLAfter(LinkedList *,
                  ElementType item); /* 在当前结点后插入结点的函数 */
void DeleteAt(LinkedList *);         /* 删除当前结点的函数 */
void DeleteLAfter(LinkedList *);     /* 删除当前结点后继的函数 */
ElementType GetData(LinkedList *);   /* 修改和访问数据的函数 */
void SetData(LinkedList *, ElementType item);
void Clear(LinkedList *); /* 清空链表的函数 */

#endif