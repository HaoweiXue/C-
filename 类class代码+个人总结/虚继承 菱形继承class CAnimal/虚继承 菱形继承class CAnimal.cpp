#include <iostream>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

class CAnimal
{
    string name;
    int age;
    int weight;
public:
    CAnimal(string strName="", int a=0, int w=0)
    {
        name = strName;
        age = a;
        weight = w;
        cout << "Animal constructor " << name << endl;
    }
    void Show()
    {
        cout << name << " " << age << " " << weight << endl;
    }
    ~CAnimal()
    {
        cout << "Animal destructor " << name << endl;
    }
};

class CBird: virtual public CAnimal
{
    int wingSpan;
public:
    CBird(int ws=0, string strName="", int a=0, int w=0):CAnimal(strName, a, w)
    {
        wingSpan = ws;
        cout << "Bird constructor " << endl;
    }
    void Show()
    {
        CAnimal::Show();
        cout << "Wingspan:" << wingSpan << endl;
    }
    void Fly()
    {
        cout << "I can fly! I can fly!!" << endl;
    }
    void Talk()
    {
        cout << "Chirp..." << endl;
        PlaySound(".\\sound\\eagle.wav",NULL, SND_FILENAME|SND_SYNC);
    }
    ~CBird()
    {
        cout << "Bird destructor " << endl;
    }
};

class CHorse: virtual public CAnimal
{
    int power;
public:
    CHorse(int pow=0, string strName="", int a=0, int w=0):CAnimal(strName, a, w)
    {
        power = pow;
        cout << "Horse constructor " << endl;
    }
    void Show()
    {
        CAnimal::Show();
        cout << "Power:" << power << endl;
    }
    void Run()
    {
        cout << "I can run! I run because I love to!!" << endl;
    }
    void Talk()
    {
        cout << "Whinny!..." << endl;
        PlaySound(".\\sound\\horse.wav",NULL, SND_FILENAME|SND_SYNC);
    }
    ~CHorse()
    {
        cout << "Horse destructor "  << endl;
    }
};

class CPegasus: public CHorse, public CBird
{
public:
    CPegasus(string strName="", int a=0, int w=0, int ws=0, int pow=0)
    : CAnimal(strName, a, w), CHorse(pow, strName, a, w), CBird(ws, strName, a, w)
    {
        cout << "Pegasus constructor" << endl;
    }
    void Talk()
    {
        CHorse::Talk();
    }
    void Show()
    {
        CBird::Show();
        CHorse::Show();
    }
    ~CPegasus()
    {
        cout << "Pegasus destructor" << endl;
    }
};

class CBull: public CAnimal
{
    int power;
public:
    CBull(int pow=0, string strName="", int a=0, int w=0):CAnimal(strName, a, w)
    {
        power = pow;
        cout << "Bull constructor " << endl;
    }
    ~CBull()
    {
        cout << "Bull destructor" << endl;
    }
    void Show()
    {
        CAnimal::Show();
        cout << power << endl;
    }
    void Talk()
    {
        cout << "Moo..." << endl;
        PlaySound(".\\sound\\bull.wav",NULL, SND_FILENAME|SND_SYNC);
    }
};


int main()
{
    //CBird birdObj(2, "Eagle", 5, 50);
    //CHorse horObj(10000, "Mogolia horse", 5, 1000);
    //CBull bullObj(20000, "Africa ox", 3, 2000);
    CPegasus pegObj("Pegasus", 5, 5000, 4, 100000);


    return 0;
}
