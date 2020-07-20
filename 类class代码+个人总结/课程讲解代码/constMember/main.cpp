#include <iostream>

using namespace std;

class CPoint2D
{
    float x, y;
public:
    CPoint2D()
    {
        x = y = 0;
    }
    CPoint2D(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    float GetX() const
    {
        return x;
    }
    float GetY() const;
    void Set(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
};

float CPoint2D::GetY() const
{
    return y;
}

int main()
{
    const CPoint2D p(1,2);

    //p.Set(3, 4);

    float x = p.GetX();
    float y = p.GetY();

    cout << x << '\t' << y << endl;
}
