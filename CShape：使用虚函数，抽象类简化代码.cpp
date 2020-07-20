#include <iostream>
#include <graph2d.h>
#include <cmath>
#include <vector>

using namespace std;
using namespace graph;

class CPoint2D
{
    float x, y;
public:
    CPoint2D(float x=0, float y=0)
    {
        this->x = x;
        this->y = y;
    }
    void Translate(float x, float y)
    {
        this->x = this->x + x;
        this->y = this->y + y;
    }
    void Scale(float r)
    {
        x = r*x;
        y = r*y;
    }
    friend class CShape;//友员类 可以访问该类数据与函数 
    friend class CTriangle;
    friend class CRectangle;
    friend class CEllipse;
    friend class CDonut;
};

class CShape
{
protected:
    CPoint2D center;//前面定义，在这可使用 
    ULONG color;//UlONG color
public:
    CShape():center(CPoint2D(400,300))//同类->对象初始化对象 
    {
         color = 0xBBE0E3;
    }
    CShape(float x, float y, ULONG color):center(x, y)
    {
        this->color = color;
    }
    void Translate(float x, float y)
    {
        center.Translate(x, y);
    }
    virtual void Draw() =0;//提供接口 
    virtual void Scale(float r) = 0;
};

class CRectangle: public CShape
{
    float len;
    float wid;
public:
    CRectangle()
    {
         len = 300;
         wid = 200;
         color = 0xBBE0E3;
    }
    CRectangle(float x, float y, float len,
                        float wid, ULONG color):CShape(x, y, color)
    {
        this->len = len;
        this->wid = wid;
    }
    void Draw()
    {
        CPoint2D v1(center.x-len/2, center.y+wid/2);
        CPoint2D v2(center.x+len/2, center.y-wid/2);
        setColor(color);
        fillRectangle(v1.x, v1.y, v2.x, v2.y);
        setColor(BLACK);
        rectangle(v1.x, v1.y, v2.x, v2.y);
    }
    void Scale(float r)
    {
        center.Scale(r);
        len = len*r;
        wid = wid*r;
    }
};

class CEllipse: public CShape//椭圆 
{
protected:
    float xRadius;
    float yRadius;
public:
    CEllipse()
    {
        xRadius = 150;
        yRadius = 100;
    }
    CEllipse(float x, float y, float rx,
                  float ry, ULONG color):CShape(x, y, color)
    {
        this->xRadius = 0.5*rx;
        this->yRadius = 0.5*ry;
    }
    void Draw()
    {
        setColor(color);
        fillEllipse(center.x, center.y, xRadius, yRadius);
        setColor(BLACK);
        ellipse(center.x, center.y, xRadius, yRadius);
    }
    void Scale(float r)
    {
        center.Scale(r);
        xRadius = xRadius*r;
        yRadius = yRadius*r;
    }
};

class CDonut: public CEllipse
{
    float ratio;
public:
    CDonut()
    {
        ratio = 0.5;
    }
    CDonut(float x, float y, float rx, float ry,
                  float r, ULONG color):CEllipse(x, y, rx, ry, color)
    {
        this->ratio = r;
    }
    void Draw()
    {
        setColor(color);
        fillDonut(center.x, center.y, xRadius, yRadius, ratio);
        setColor(BLACK);
        donut(center.x, center.y, xRadius, yRadius, ratio);
    }
};

class CTriangle:public CShape
{
    float len;
    float wid;
public:
    CTriangle()
    {
        len = 300;
        wid = 200;
    }
    CTriangle(float x, float y, float len,
                    float wid, ULONG color):CShape(x, y, color)
    {
        this->len = len;
        this->wid = wid;
    }
    void Draw()
    {
        CPoint2D v1(center.x-len/2, center.y-wid/2);
        CPoint2D v2(center.x+len/2, center.y-wid/2);
        CPoint2D v3(center.x, center.y+wid/2);
        setColor(color);
        fillTriangle(v1.x, v1.y, v2.x, v2.y, v3.x, v3.y);
        setColor(BLACK);
        triangle(v1.x, v1.y, v2.x, v2.y, v3.x, v3.y);
    }
    void Scale(float r)
    {
        center.Scale(r);
        len = len*r;
        wid = wid*r;
    }
};

vector <CShape *> g_vShape;

void ReadShapes(const char *fileName)
{
    FILE *fp=NULL;//注意文件处理 
    char str[512];
    float x, y;
    float l, w, h, rx, ry, s;
    int clr;

    fp = fopen(fileName, "r");// 
    if (fp==NULL) return;//
    fscanf(fp, "%s", str);//
    while (0!=strcmp(str, "Exit"))//
    {
        if (0==strcmp(str, "Rectangle"))
        {
            cout << str << ":";
            fscanf(fp, "%f%f%f%f%x", &x, &y, &l, &w, &clr);
            cout << x << " " << y << " " << l << " " << w  << " " << clr << endl;
            g_vShape.push_back(new CRectangle(x, y, l, w, clr));
        }
        else if (0==strcmp(str, "Ellipse"))
        {
            cout << str << ":";
            fscanf(fp, "%f%f%f%f%x", &x, &y, &rx, &ry, &clr);
            cout << x << " " << y << " " << rx << " " << ry  << " " << clr << endl;
            g_vShape.push_back(new CEllipse(x, y, rx, ry, clr));
        }
        else if (0==strcmp(str, "Donut"))
        {
            cout << str << ":";
            fscanf(fp, "%f%f%f%f%f%x", &x, &y, &rx, &ry, &s, &clr);
            cout << x << " " << y << " " << rx << " " << ry << " " << s << " " << clr << endl;
            g_vShape.push_back(new CDonut(x, y, rx, ry, s, clr));
        }
        else
        {
            cout << str << ":";
            fscanf(fp, "%f%f%f%f%x", &x, &y, &l, &h, &clr);
            cout << x << " " << y << " " << l << " " << h  << " " << clr << endl;
            g_vShape.push_back(new CTriangle(x, y, l, h, clr));
        }
        fscanf(fp, "%s", str);
    }
}

void display()
{
    for(size_t i=0; i<g_vShape.size(); i++)
        g_vShape[i]->Draw();
}

void keyboard(unsigned char key)
{
    switch (key)
    {
    case 'w':
        for(size_t i=0; i<g_vShape.size(); i++)
            g_vShape[i]->Translate(0, 5);
        break;
    case 's':
        for(size_t i=0; i<g_vShape.size(); i++)
            g_vShape[i]->Translate(0, -5);
        break;
    case 'a':
        for(size_t i=0; i<g_vShape.size(); i++)
            g_vShape[i]->Translate(-5, 0);
        break;
    case 'd':
        for(size_t i=0; i<g_vShape.size(); i++)
            g_vShape[i]->Translate(5, 0);
        break;
    case 'z':
        for(size_t i=0; i<g_vShape.size(); i++)
            g_vShape[i]->Scale(1.05);
        break;
    case 'x':
        for(size_t i=0; i<g_vShape.size(); i++)
            g_vShape[i]->Scale(0.95);
        break;
    }
}

int main()
{
    ReadShapes("shapedata.txt");
    initGraph(display, keyboard);
    for(size_t i=0; i<g_vShape.size(); i++)
        delete g_vShape[i];//
    return 0;
}
