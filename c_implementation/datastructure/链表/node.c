#include "node.h"

void InitNode(Node *N, ElementType item, Node *ptr) {
  N->data = item;
  N->next = ptr;
}
void InsertAfter(Node *N, Node *p) {
  p->next = N->next; /* 将当前结点的后继结点连接到结点p之后 */
  N->next = p;       /* 将结点p作为当前结点的后继结点 */
}

Node *DeleteAfter(Node *P) {
  Node *ptr = P->next; /* 保存当前结点的后继结点 */

  if (ptr == NULL)
    return NULL;       /* 若没有后继结点,则返回空指针 */
  P->next = ptr->next; /* 当前结点指向其原来的后继结点,即ptr的后继 */
  return ptr;          /* 返回指向被删除结点的指针 */
}

Node *GetNode(ElementType item, Node *nextPtr) {
  Node *newNode;

  /* 申请单链表结点空间 */
  newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Memory allocation failure!\n");
    exit(1);
  }
  InitNode(newNode, item, nextPtr);
  return newNode;
}

void FreeNode(Node *ptr) {
  if (!ptr) /* 若 ptr 为空, 则给出相应提示并返回 */
  {
    printf("FreeNode:invalid node pointer!\n");
    return;
  }
  free(ptr); /* 释放结点占用的内存空间 */
}