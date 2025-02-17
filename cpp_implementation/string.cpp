#include <stddef.h>

class String
{
public:
    String(const char *str = NULL) // 普通构造函数
    {

    }
    String(const String &other); // 拷贝构造函数
    ~ String(void) // 析构函数
    {
        delete [] ;
        // 由于 m_data 是内部数据类型，也可以写成 delete m_data;
    }
    String & operate =(const String &other) // 赋值函数
    {

    }
private:
    char *m_data; // 用于保存字符串
};