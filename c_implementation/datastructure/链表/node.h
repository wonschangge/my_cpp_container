#ifndef _NODE_H
#define _NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct node {
    struct node *next;                                  /* next为指向下一个结点的指针 */
    ElementType data;
};
typedef struct node Node;

void InitNode(Node *, ElementType item, Node * ptr);    /* 初始化单链表结点 */
void InsertAfter(Node *, Node *);                       /* 插入一个单链表结点 */
Node* DeleteAfter(Node *);                              /* 删除一个单链表结点 */
Node* GetNode(ElementType item, Node * ptr);            /* 创建一个单链表的结点 */
void  FreeNode(Node *);                                 /* 释放一个单链表的结点 */

#endif