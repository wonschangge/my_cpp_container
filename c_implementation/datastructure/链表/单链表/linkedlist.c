#include "linkedlist.h"

/* 单链表初始化函数（建立一个空链表） */
void InitLinkedList(LinkedList *L) {
  L->front = NULL;
  L->rear = NULL;
  L->prevPtr = NULL;
  L->currPtr = NULL;
  L->size = 0;
  L->position = -1;
}

/* 判断表是否为空的函数 */
Bool IsEmpty(LinkedList *L) { return L->size ? FALSE : TRUE; }

/* 将后继结点设置为当前结点的函数 */
int NextLNode(LinkedList *L) {
  /* 若当前结点存在，则将其后继结点设置为当前结点 */
  if (L->position >= 0 && (L->position < L->size)) {
    L->position++;
    L->prevPtr = L->currPtr;
    L->currPtr = (L->currPtr)->next;
  } else {
    L->position = L->size; /* 否则将当前位置设为表尾后 */
  }
  return L->position; /* 返回新位置 */
}

/* 重置链表当前结点位置的函数 */
int SetPosition(LinkedList *L, int pos) {
  if (!L->size)
    return -1;                        /* 若链表为空，则返回 */
  if (pos < 0 || (pos > L->size - 1)) /* 若位置越界，则返回 */
  {
    printf("position error");
    return -1;
  }

  L->currPtr = L->front; /* 寻找对应结点 */
  L->prevPtr = NULL;
  L->position = 0;

  for (int k = 0; k < pos; k++) {
    L->position++;
    L->prevPtr = L->currPtr;
    L->currPtr = (L->currPtr)->next;
  }
  return L->position; /* 返回当前结点位置 */
}

/* 链表中在当前结点处插入新结点的函数 */
void InsertAt(LinkedList *L, ElementType item) {
  Node *newNode;
  if (!L->size) {
    newNode = GetNode(item, L->front); /* 在空表中插入 */
    L->front = L->rear = newNode;
    L->position = 0;
  } else if (!L->prevPtr) {
    newNode = GetNode(item, L->front); /* 在表头结点处插入 */
    L->front = newNode;
  } else {
    newNode = GetNode(item, L->currPtr); /* 在链表的中间位置插入 */
    InsertAfter(L->prevPtr, newNode);
  }

  L->size++;            /* 增加链表大小 */
  L->currPtr = newNode; /* 新插入的结点为当前结点 */
}

/* 链表中在当前结点后插入新结点的函数 */
void InsertLAfter(LinkedList *L, ElementType item) {
  Node *newNode;
  if (!L->size) {
    newNode = GetNode(item, NULL); /* 在空表中插入 */
    L->front = L->rear = newNode;
    L->position = 0;
  } else if (L->currPtr == L->rear || !L->currPtr) {
    newNode = GetNode(item, NULL); /* 在表尾结点插入 */
    InsertAfter(L->rear, newNode);
    L->prevPtr = L->rear;
    L->rear = newNode;
    L->position = L->size;
  } else {
    newNode = GetNode(item, (L->currPtr)->next); /* 在链表的中间位置插入 */
    InsertAfter(L->currPtr, newNode);
    L->prevPtr = L->currPtr;
    L->position++;
  }

  L->size++;            /* 增加链表的大小 */
  L->currPtr = newNode; /* 新插入的结点为当前结点 */
}

/* 链表中删除当前结点的函数 */
void DeleteAt(LinkedList *L) {
  Node *oldNode;
  if (!L->currPtr) /* 若表为空或已到表尾之后，则给出错误提示并返回 */
  {
    printf("DeleteAt: current position is invali!\n");
    return;
  }

  if (!L->prevPtr) {
    oldNode = L->front; /* 删除的是表头结点 */
    L->front = (L->currPtr)->next;
  } else {
    oldNode = DeleteAfter(L->prevPtr); /* 删除的是表中结点 */
  }

  if (oldNode == L->rear) {
    L->rear = L->prevPtr; /* 删除的是表尾结点，则修改表尾指针 */
  }
  L->currPtr = oldNode->next; /* 后继结点作为新的当前结点 */
  FreeNode(oldNode);          /* 释放原当前结点 */
}

/* 链表中删除当前结点后继的函数 */
void DeleteLAfter(LinkedList *L) {
  Node *oldNode;
  if (!L->currPtr || L->currPtr == L->rear) {
    Node *oldNode;
    if (!L->currPtr ||
        L->currPtr == L->rear) /* 若表为空或已到表尾，则给出错误提示并返回 */
    {
      printf("DeleteAfter: current position is invalid!\n");
      return;
    }
    oldNode =
        DeleteAfter(L->currPtr); /* 保存被删除结点的指针并从链表中删除该结点 */

    if (oldNode == L->rear) {
      L->rear = L->currPtr; /* 删除的是表尾结点 */
    }
    FreeNode(oldNode); /* 释放被删除结点 */
    L->size--;         /* 链表大小减1 */
  }
}

/* 链表中获取当前结点数据的函数 */
ElementType GetData(LinkedList *L) {
  if (!L->size || !L->currPtr) /* 若表为空或已到达表尾之后，则出错 */
  {
    printf("Data:   current node does not exist!\n"); /* 给出出错信息并退出 */
    exit(1);
  }
  return L->currPtr->data;
}

/* 链表中修改当前结点数据的函数 */
void SetData(LinkedList *L, ElementType item) {
  if (!L->size || !L->currPtr) /* 若表为空或已到达表尾之后，则出错 */
  {
    printf("Data:   current node not exist!\n");
    exit(1);
  }
  L->currPtr->data = item; /* 修改当前结点的值 */
}

/* 链表中清空链表的函数 */
void Clear(LinkedList *L) {
  Node *currNode = L->front, *nextNode;
  while (currNode) {
    nextNode = currNode->next; /* 保存后继结点指针 */
    FreeNode(currNode);        /* 释放当前结点 */
    currNode = nextNode;       /* 原后继结点成为当前结点 */
  }
  L->front = L->rear = L->prevPtr = L->currPtr = NULL;
  L->size = 0;
  L->position = -1; /* 修改空链表数据 */
}
