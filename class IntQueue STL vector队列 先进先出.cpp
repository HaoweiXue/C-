/*
(1) 名为element的数据成员，保存队列中的int值; element的类型可以使用vector或在堆上分配的动态数组。
(2) 名为size的数据成员，保存队列中元素的个数。
(3) 默认构造函数，用默认的队列容量值初始化lntQueue对象。
(4) 进队列操作void enqueue(int value)，将value加入队列尾，一旦元素个数超过了队列容量，将队列容量翻倍。
(5) 出队列操作出int dequeue()，删除队列首元素并将其返回；原来的第二个元素变成新的队列首元素，依次类推。
(6) 判断队列是否为空的操作bool empty()，如果队列为空，返回true。
(7) 成员函数size_t getSize()，返回队列中元素的个数。
(8) 根据(1)中选择的数据结构，设计需要的拷贝控制成员。
编写测试程序，利用IntQueue将输入的整数加入队列，然后逐一移出队列井输出。
 */
#include <iostream>
#include <vector>
using namespace std;

class IntQueue
{
    size_t size;//元素个数 
    int capacity;//容量 容量不一定等于元素个数 
    vector<int> element;
public:
    IntQueue();
    IntQueue(int);
    IntQueue(const IntQueue&);
    ~IntQueue();

    void enqueue(int);
    int dequeue();
    bool empty() const;
    size_t getSize() const;
};

IntQueue::IntQueue():size(0), capacity(8), element(capacity)//用容量初始化vector 
{
}

IntQueue::IntQueue(int cap)
{
    size = 0;
    if(cap < 8)
        capacity = 8;
    else
        capacity = cap;
    element.reserve(capacity);//容量 vector reserve()设置容量 
}

IntQueue::IntQueue(const IntQueue& q)
{
    size = q.size;
    capacity = q.capacity;
    element = q.element;//vector=vector 
}

IntQueue::~IntQueue()
{
    element.clear();//vector clear()
}

void IntQueue::enqueue(int val)
{
    if (size>=capacity)
    {
        capacity = 2*capacity;
        element.reserve(capacity);//扩容 
    }
    element.insert(element.begin(), val);//vector insert （*,int） 
    size++;
}

int IntQueue::dequeue()//先en后de 
{
    int first = element.back();//vector back()
    element.pop_back();//vector pop_back()
    size--;
    return first;
}

bool IntQueue::empty() const
{
    return (size==0);//判断 
}

size_t IntQueue::getSize() const
{
    return size;
}

int main()
{
    int cap = 9;
    IntQueue q(cap);

    for(int i=0; i<(2*cap); ++i)
    {
        q.enqueue(i+1);
    }

    for(int i=0; i<cap; ++i)
    {
        q.enqueue(q.dequeue());
    }

    while(!q.empty())
        cout << q.dequeue() << " ";
    cout << endl;

    return 0;
}



