// 分离线程
// 您总是必须加入线程吗？
// 不，实际上，还有另一种选择。
// 就像朋友的例子一样，朋友可能想走自己的路回家，而不是和你见面。
// 对于线程来说，这称为分离。
// 分离线程意味着允许它独立于主线程工作并完成其工作。
// 但是，这可能很危险。以下面的示例为例，它与join()的示例非常相似。

#include <thread>
#include <iostream>

void workFunc(int* ptr, size_t times)
{
    while (times--) {
        *ptr += 1;
    }
}

int main(int argc, char const *argv[])
{
    int* numbers = new int[3];

    std::thread t1(workFunc, numbers, 500);
    std::thread t2(workFunc, numbers + 1, 600);
    std::thread t3(workFunc, numbers + 2, 700);
    
    // 这里的第一个风险是在删除后使用堆分配的内存。
    // 与join()不同， detach()不会使调用线程停止或等待任何事情。
    // 这意味着一旦对detach()第三次调用结束，调用线程将删除numbers数组。
    // 如果创建的线程尚未完成其工作，它们将写入已删除的数组，这会损坏内存。

    // 这里的第二个风险是，如果创建的线程的工作尚未完成，
    // 即使在主线程完成后，它们也可以继续运行。
    // 或者他们可能会在主线结束后立即被杀死。
    // 根据 C++ 标准，这是未定义的行为。
    // 无论特定编译器可以保证什么，都应该避免未定义的行为。 
    // detach()有有效的用例，
    // 但它们中的任何一个都需要线程之间某种其他形式的同步才能可靠。
    t1.detach();
    t2.detach();
    t3.detach();

    delete[] numbers;
    return 0;
}