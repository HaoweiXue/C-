#include "CStack.h"
bool CPPStackExt::isEmpty(){
    return (tp==-1);
}
bool CPPStackExt::isFull(){
    return (tp==(size-1));
}
void CPPStackExt::push(char c){
    if(isFull()){
        char*p=new char [2*size];
        for(int i=0;i<size;i++)
            p[i]=s[i];
        delete []s;
        s=p;
        size=2*size;
    }
    tp++;
    s[tp]=c;
}

char CPPStackExt::pop(){
    int oldtp=tp;
    tp--;
    return s[oldtp];
}
char CPPStackExt::top(){
    return s[tp];
}
CPPStackExt::CPPStackExt(int initSize){
    tp=-1;
    size=initSize;
    s=new char[size];
}
CPPStackExt::CPPStackExt(const CPPStackExt&scopy){
    tp=scopy.tp;
    size=scopy.size;
    s=new char [size];
    for(int i=0;i<=tp;i++){

        s[i]=scopy.s[i];
    }
}
CPPStackExt::~CPPStackExt(){
    if(s!=NULL){
        delete []s;
        s=NULL;
    }
}
