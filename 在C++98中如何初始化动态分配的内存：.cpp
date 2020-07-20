//3. 能否用int *pa = new int [10]()初始化一个动态数组为全0？

/*答：int *pa = new int [10]()在C++ 03中出现：ISO C++03 5.3.4[expr.new]/15: "A new-expression that creates an object of type T initializes that object as follows:
If the new-initializer is of the form (), the item is value-initialized (8.5)."，但标准C++98中不建议使用，影响代码安全性

在C++ 11中支持多种初始化方式：
如：
int *pa = new int [10]{};
int *pa = new int [10]{1};
int *pa = new int [10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

那在C++98中如何初始化动态分配的内存：
三种方式：
(1) 循环逐个输出：
int* p = new int[10];
for (int i = 0; i < 10; i++)
    p[i] = 0;

(2) 使用<cstring>中的memset函数：
int* p = new int[10];
memset(p, 0, sizeof(int) * 10);

(3)使用<algorithm>中的fill_n函数： 
int* p = new int[10];
fill_n(p, 10, 0);*/

//总结：至于如何选择初始化方式，取决于不同的应用场合，一般判断的标准是：代码是否安全性？可读性是否更好？是否具备可移植性？效率高不高？

