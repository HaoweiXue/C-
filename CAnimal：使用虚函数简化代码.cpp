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
    virtual void Show()
    {
        cout << "[Property]" << name << " " << age << " " << weight << endl;//property ÊôÐÔ 
    }
    virtual void Talk() = 0;
    ~CAnimal()
    {
        cout << "Animal destructor " << name << endl;
    }
};

class CBird: virtual public CAnimal//Ðé¼Ì³Ð 
{
protected:
    int wingSpan;
public:
    CBird(string strName="", int a=0, int w=0, int ws=0):CAnimal(strName, a, w)
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

class CHorse: virtual public CAnimal//Ðé¼Ì³Ð 
{
protected:
    int power;
public:
    CHorse(string strName="", int a=0, int w=0, int pow=0):CAnimal(strName, a, w)
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
    : CAnimal(strName, a, w), CHorse(strName, a, w, pow), CBird(strName, a, w, ws)
    {
        cout << "Pegasus constructor" << endl;
    }
    void Talk()
    {
        CHorse::Talk();
    }
    void Show()
    {
        CAnimal::Show();
        cout << "Power:" << CHorse::power << endl;
        cout << "Wingspan:" << CBird::wingSpan << endl;
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
    CBull(string strName="", int a=0, int w=0, int pow=0):CAnimal(strName, a, w)
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
        cout << "Power:" << power << endl;
    }
    void Talk()
    {
        cout << "Moo..." << endl;
        PlaySound(".\\sound\\bull.wav",NULL, SND_FILENAME|SND_SYNC);
    }
};

const int MAX_ANIM_NUM = 100;
class CZoo
{
    int size;
    CAnimal *m_animal[MAX_ANIM_NUM];//×¢ÒâÓÃ·¨ 
public:
    CZoo() { size = 0;}
    void Add(CAnimal *anim)
    {
        if(size<MAX_ANIM_NUM)
        {
            m_animal[size] = anim;
            size++;
        }
    };
    void Show();
    void Talk();
};

void CZoo::Show()
{
    for (int i=0; i<size; i++)
        m_animal[i]->Show();//
}

void CZoo::Talk()
{
     for (int i=0; i<size; i++)
        m_animal[i]->Talk();//
}

int main()
{
    CBird birdObj("Eagle", 5, 50, 2);
    CHorse horObj("Mogolia horse", 5, 1000, 10000);
    CBull bullObj1("Africa ox", 3, 2000, 20000);
    CBull bullObj2("China ox", 5, 3000, 40000);
    CPegasus pegObj("Pegasus", 5, 5000, 4, 100000);

    CZoo zoo;

    zoo.Add(&birdObj);
    zoo.Add(&horObj);
    zoo.Add(&bullObj1);
    zoo.Add(&bullObj2);
    zoo.Add(&pegObj);

    zoo.Show();

    zoo.Talk();

    return 0;
}
