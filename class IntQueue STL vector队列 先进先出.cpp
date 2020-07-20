/*
(1) ��Ϊelement�����ݳ�Ա����������е�intֵ; element�����Ϳ���ʹ��vector���ڶ��Ϸ���Ķ�̬���顣
(2) ��Ϊsize�����ݳ�Ա�����������Ԫ�صĸ�����
(3) Ĭ�Ϲ��캯������Ĭ�ϵĶ�������ֵ��ʼ��lntQueue����
(4) �����в���void enqueue(int value)����value�������β��һ��Ԫ�ظ��������˶�������������������������
(5) �����в�����int dequeue()��ɾ��������Ԫ�ز����䷵�أ�ԭ���ĵڶ���Ԫ�ر���µĶ�����Ԫ�أ��������ơ�
(6) �ж϶����Ƿ�Ϊ�յĲ���bool empty()���������Ϊ�գ�����true��
(7) ��Ա����size_t getSize()�����ض�����Ԫ�صĸ�����
(8) ����(1)��ѡ������ݽṹ�������Ҫ�Ŀ������Ƴ�Ա��
��д���Գ�������IntQueue�����������������У�Ȼ����һ�Ƴ����о������
 */
#include <iostream>
#include <vector>
using namespace std;

class IntQueue
{
    size_t size;//Ԫ�ظ��� 
    int capacity;//���� ������һ������Ԫ�ظ��� 
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

IntQueue::IntQueue():size(0), capacity(8), element(capacity)//��������ʼ��vector 
{
}

IntQueue::IntQueue(int cap)
{
    size = 0;
    if(cap < 8)
        capacity = 8;
    else
        capacity = cap;
    element.reserve(capacity);//���� vector reserve()�������� 
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
        element.reserve(capacity);//���� 
    }
    element.insert(element.begin(), val);//vector insert ��*,int�� 
    size++;
}

int IntQueue::dequeue()//��en��de 
{
    int first = element.back();//vector back()
    element.pop_back();//vector pop_back()
    size--;
    return first;
}

bool IntQueue::empty() const
{
    return (size==0);//�ж� 
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



