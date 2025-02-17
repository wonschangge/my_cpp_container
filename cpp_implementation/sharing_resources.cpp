// 共享资源
// 两个不同的线程可以访问同一内存地址的资源称为共享资源。
// 值得注意的是对地址的强调。
// 在前面所示的示例中，多个线程访问同一数组，这不是共享资源，
// 因为没有两个线程从同一内存地址读取或写入。
// 该数组可能只是四个独立的整数指针，数组本身并不能使其成为共享资源。

// 与并发不同，当需要线程对同一数据或对象执行工作时，会使用共享资源。
// 这意味着对象未分配在线程自己的堆栈上，并且只有一个对象对其他线程可见。
// 使这一点难以理解的是，尽管两个线程都可以访问某些资源，
// 但它们永远看不到其他线程访问该资源。

// 现实生活中共享资源的一个很好的例子是夜间的机场跑道。
// 跑道上有闪烁的灯光，可以帮助引导飞机在准备着陆时与其对齐。
// 但由于黑暗和飞行速度的原因，其他飞机在夜间看到彼此是非常困难的。
// 如果一架飞机试图与另一架飞机同时降落在跑道上，那将是灾难性的。
// 飞机避免此类碰撞的唯一方法是通过空中交通管制进行协调。

// 线程以相同的方式运行，因为它们依赖同步机制来协调对资源的访问，
// 例如不同时写入它们。
// 我们将在这里讨论的机制（可能是最常见的一种）是互斥体。
// 互斥体（称为std::mutex类型）允许线程获取锁。
// 锁是一种控制形式，一次只允许一个线程执行一段代码。让我们看一下这个例子。

#include <thread>
#include <mutex>
#include <queue>
#include <iostream>

template<class T>
class SafeQueue {
public:
    // 在上面的示例中，当调用线程在与队列关联的互斥锁上构造锁时，
    // 类的push()和pop()方法都会发生。
    // 此锁最好用作 RAII 样式对象，它仅在某些代码范围内有效。
    // 一旦程序完成该范围，锁保护对象就会被销毁，
    // 从而允许另一个线程构造并获取互斥体上的锁。
    // 此模式继续满足一次只有一个线程可以修改队列的条件。
    void push(const T& val) {
        std::lock_guard<std::mutex> lock(_m);
        _q.push(val);
    }

    bool pop(T& val) {
        std::lock_guard<std::mutex> lock(_m);
        if (!_q.empty()) {
            val = _q.front();
            _q.pop();
            return true;
        } else {
            return false;
        }
    }

    void print() {
        std::lock_guard<std::mutex> lock(_m);
        std::cout << "queue size: " << _q.size() << std::endl;
        for (int i = 0; i < _q.size(); i++) {
            std::cout << _q.front() << " ";
            _q.pop();
        }
        std::cout << std::endl;
    }
private:
    std::mutex _m;
    std::queue<T> _q;
};

void producer(SafeQueue<int> &queue, int start, int count) {
    for (int i = start; i < start + count; i++) {
        queue.push(i);
        std::cout << "Produced: " << i << std::endl;
    }
}

void consumer(SafeQueue<int>& q, int count) {
    for (int i = 0; i < count; ++i) {
        int val;
        if (q.pop(val)) {
            std::cout << "Consumed: " << val << std::endl;
        } else {
            std::cout << "Queue is empty" << std::endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    SafeQueue<int> queue;

    std::thread prod1(producer, std::ref(queue), 0, 5);
    std::thread prod2(producer, std::ref(queue), 5, 5);
    std::thread cons1(consumer, std::ref(queue), 10);
    
    prod1.join();
    prod2.join();
    cons1.join();

    queue.print();

    return 0;
}