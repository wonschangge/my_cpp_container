# LinearList.md

```
ADT LinearList
{
    Data:
        数据元素的有限序列 k[0],k[1],...,k[n-1]
        k[0]无前驱,后继为k[1]
        k[n-1]无后继,前驱为k[n-2]
        k[i]的前驱为k[i-1],后继为k[i+1](0<i<n-1)
    Operations:
        InitList
            Input:          申请表空间的长度
            Preconditions:  无
            Process:        申请一个表空间,生成一个空表
            Output:         表空间位置和范围,表长为0
            Postconditions: 表已存在
        DestroyList
            Input:          无
            Preconditions:  表已存在
            Process:        撤销一个表
            Output:         无
            Postconditions: 表不存在
        ListEmpty
            Input:          无
            Preconditions:  表已存在
            Process:        判断表是否空表
            Output:         表空间位置和范围,表长为0
            Postconditions: 无
        ListFull
            Input:          无
            Preconditions:  表已存在
            Process:        判断表是否已满
            Output:         若表已满,返回TRUE;否则返回FALSSE
            Postconditions: 无
        ListLength
            Input:          无
            Preconditions:  表已存在
            Process:        求表的结点个数
            Output:         返回表的长度
            Postconditions: 无
        GetElem
            Input:          结点序号i
            Preconditions:  表已存在
            Process:        按i读取k[i]
            Output:         若读取成功,则返回k[i]的值;否则返回NULL
            Postconditions: 无
        LocateElem
            Input:          要在表中查找的值
            Preconditions:  表已存在
            Process:        扫描表,找与查找值相等的结点
            Output:         若查找成功,则返回找到结点的序号;否则返回-1
            Postconditions: 无
        InsertElem
            Input:          新结点要插入的位置
            Preconditions:  表已存在
            Process:        将新结点按插入位置插入其中
            Output:         若插入成功,则返回TRUE;否则返回FALSE
            Postconditions: 表中增加一个结点,表长增1
        DeleteElem
            Input:          要删除结点的序号
            Preconditions:  表已存在
            Process:        删除指定序号的结点
            Output:         若删除成功,则返回TRUE;否则返回FALSE
            Postconditions: 表中减少一个结点,表长减1
}/*LinearList*/
```