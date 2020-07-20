#include <iostream>
using namespace std;

const float PI = 3.1416;

class CCircle
{
    float x, y;
    unsigned long clr;
    float r;
public:
    CCircle(float _x=0, float _y=0, float _r=0, unsigned long _clr=0x00FF00): x(_x), y(_y), clr(_clr), r(_r)
    {
    }
    double GetArea()
    {
        return PI*r*r;
    }
    double GetPerimeter()
    {
        return 2*PI*r;
    }
    void Move(float dx, float dy)
    {
        x += dx;
        y += dy;
    }
    void Scale(float s)
    {
        r = s*r;
    }
    void Draw()
    {
        cout << "Circle:" << x << "," << y << ", " << r << endl;
    }
};

int main()
{
    CCircle myCircle(300.0f, 400.0f, 1.5f, 0xFF0000);

    myCircle.Move(3.0f, 4.0f);
    myCircle.Scale(2.0f);

    myCircle.Draw();

    cout << myCircle.GetPerimeter() << ", " << myCircle.GetArea() << endl;

    return 0;
}
