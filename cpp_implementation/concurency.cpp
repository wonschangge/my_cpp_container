// 并发线程
// 让我们看一下每个线程获取指向整数的指针的示例，并且线程递增该整数，然后停止。
// 每个线程都会运行，直到将数字增加数百倍。
// 然后，这些线程（通常称为“工作”线程）与主线程连接。所有线程同时工作。

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
    
    // 如果您不熟悉多线程，则此代码的某些部分可能没有意义。
    // join()方法可能就是其中之一。
    // 关于启动新线程需要了解的一个重要细节是，它们的工作和功能完全
    // 独立于主线程（从main()开始的线程）。
    // 因为它们是完全独立的，所以我们必须决定等待它们完成分配的工作的时间点。

    // 可以将join()想象成类似于两个人如何分开去做各自独立的任务，
    // 然后稍后“加入”在一起。如果您正在旅行或与朋友一起去某个地方，
    // 您不想顶部就放弃他们吧！理想情况下，您应该等待他们再次赶上。
    // 同样的逻辑也适用于线程。
    // 每当创建其他线程时，就有义务指示您希望中央主线程如何根据它们进行操作。
    t1.join();
    t2.join();
    t3.join();

    for (int i = 0; i < 3; ++i)
        std::cout << "Number Slot " << (int)i << " is " << (int)numbers[i] << std::endl;
    
    delete[] numbers;
    return 0;
}