#include <iostream>
#include <shared_mutex>
#include <mutex>
#include <thread>

using namespace std;

// 创建一个shared_mutex对象
shared_mutex mutx;
int shared_data = 11;

// 使用shared lock调用
void read_data()
{
    shared_lock<shared_mutex> lock(mutx);
    cout << "Thread " << this_thread::get_id() << ": ";
    cout << shared_data << endl;
}

// 使用unique lock调用
void write_data(int n)
{
    unique_lock<shared_mutex> lock(mutx);
    shared_data = n;
    cout << "Thread " << this_thread::get_id() << ": ";
    cout << shared_data << endl;
}

int main()
{
    thread t1(read_data);
    thread t2(write_data, 128);
    thread t3(write_data, 10);
    thread t4(read_data);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}