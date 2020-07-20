#ifndef CSTACK_H
#define CSTACK_H

#include <iostream>
using namespace std;
class CPPStackExt
{
    public:
        CPPStackExt(int initSize=5);
        CPPStackExt(const CPPStackExt &scopy);
        ~CPPStackExt();
        bool isEmpty();
        bool isFull();
        void push(char c);
        char pop();
        char top();


    private:
        char*s;
        int tp;
        int size;
};

#endif // CSTACK_H
