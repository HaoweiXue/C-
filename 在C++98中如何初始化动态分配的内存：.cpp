//3. �ܷ���int *pa = new int [10]()��ʼ��һ����̬����Ϊȫ0��

/*��int *pa = new int [10]()��C++ 03�г��֣�ISO C++03 5.3.4[expr.new]/15: "A new-expression that creates an object of type T initializes that object as follows:
If the new-initializer is of the form (), the item is value-initialized (8.5)."������׼C++98�в�����ʹ�ã�Ӱ����밲ȫ��

��C++ 11��֧�ֶ��ֳ�ʼ����ʽ��
�磺
int *pa = new int [10]{};
int *pa = new int [10]{1};
int *pa = new int [10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

����C++98����γ�ʼ����̬������ڴ棺
���ַ�ʽ��
(1) ѭ����������
int* p = new int[10];
for (int i = 0; i < 10; i++)
    p[i] = 0;

(2) ʹ��<cstring>�е�memset������
int* p = new int[10];
memset(p, 0, sizeof(int) * 10);

(3)ʹ��<algorithm>�е�fill_n������ 
int* p = new int[10];
fill_n(p, 10, 0);*/

//�ܽ᣺�������ѡ���ʼ����ʽ��ȡ���ڲ�ͬ��Ӧ�ó��ϣ�һ���жϵı�׼�ǣ������Ƿ�ȫ�ԣ��ɶ����Ƿ���ã��Ƿ�߱�����ֲ�ԣ�Ч�ʸ߲��ߣ�

