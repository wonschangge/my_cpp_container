# 抽象数据类型

ADT(Abstract Data Type), 抽象数据的组织和与之相关的操作

示例描述:

```
ADT ADT_Name
{
    Data:                   /*数据说明*/
        数据元素之间逻辑关系的描述
    Operations:             /*操作说明*/
        Operation1
            Input:          对输入数据的说明
            Preconditions:  执行操作前系统应满足的状态
            Process:        对数据执行的操作
            Output:         对返回数据的说明
            Postconditions: 执行操作后系统的状态
        Operation2
            ...
}/*ADT*/
```