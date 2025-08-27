enum boolean { FALSE, TRUE };
typedef enum boolean Bool;

typedef int ElementType;

struct linearList {
  ElementType *data;
  int MaxSize;
  int Last;
};
typedef struct linearList LinearList;

void InitList(LinearList *, int sz);         /* 线性表的初始化 */
void FreeList(LinearList *);                 /* 释放线性表的存储空间 */
Bool ListEmpty(LinearList *);                /* 判断线性表是否为空 */
Bool ListFull(LinearList *);                 /* 判断线性表是否为满 */
int ListLength(LinearList *);                /* 求线性表的长度 */
ElementType GetElem(LinearList *, int i);    /* 取线性表的第i个表目 */
int LocateElem(LinearList *, ElementType x); /* 在线性表中查找 */
Bool InsertElem(LinearList *, ElementType x,
                int i);               /* 在表中第i个位置插入值为x的结点 */
Bool DeleteElem(LinearList *, int i); /* 删除表中第i个结点 */
void printout(LinearList *);          /* 打印线性表的条目 */