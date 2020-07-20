#include <iostream>
#include <graph2d.h>//
#include <cmath>
#include <vector>

using namespace std;
using namespace graph;//

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
    friend class CTriangle;
    friend class CRectangle;
    friend class CEllipse;
    friend class CDonut;
};

class CRectangle
{
    CPoint2D center;
    float len;
    float wid;
    ULONG color;
public:
    CRectangle():center(CPoint2D(400,300)),  len(300), wid(200), color(0xBBE0E3) {}
    CRectangle(CPoint2D w, float len, float wid, ULONG color = 0xBBE0E3):center(w)//用对象初始化对象 
    {
        this->len = len;
        this->wid = wid;
        this->color = color;
    }
    void Translate(float x, float y)
    {
        center.Translate(x, y);
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

class CEllipse
{
    CPoint2D center;
    float xRadius;
    float yRadius;
    ULONG color;
public:
    CEllipse():center(CPoint2D(400,300)),  xRadius(150), yRadius(100), color(0xBBE0E3) {}
    CEllipse(CPoint2D w, float len, float wid, ULONG color = 0xBBE0E3):center(w)
    {
        this->xRadius = 0.5*len;
        this->yRadius = 0.5*wid;
        this->color = color;
    }
    void Translate(float x, float y)
    {
        center.Translate(x, y);
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

class CDonut
{
    CPoint2D center;
    float xRadius;
    float yRadius;
    float ratio;
    ULONG color;
public:
    CDonut():center(CPoint2D(400,300)),  xRadius(150), yRadius(100), ratio(0.5), color(0xBBE0E3) {}
    CDonut(CPoint2D w, float rx, float ry, float r, ULONG color = 0xBBE0E3):center(w)
    {
        this->xRadius = rx;
        this->yRadius = ry;
        this->ratio = r;
        this->color = color;
    }
    void Translate(float x, float y)
    {
        center.Translate(x, y);
    }
    void Draw()
    {
        setColor(color);
        fillDonut(center.x, center.y, xRadius, yRadius, ratio);
        setColor(BLACK);
        donut(center.x, center.y, xRadius, yRadius, ratio);
    }
    void Scale(float r)
    {
        center.Scale(r);
        xRadius = xRadius*r;
        yRadius = yRadius*r;
    }
};

class CTriangle
{
    CPoint2D center;
    float len;
    float wid;
    ULONG color;
public:
    CTriangle():center(CPoint2D(400,300)),  len(300), wid(200), color(0xBBE0E3) {}
    CTriangle(CPoint2D w, float len, float wid, ULONG color = 0xBBE0E3):center(w)
    {
        this->len = len;
        this->wid = wid;
        this->color = color;
        cout << len << ", " << wid << endl;
    }
    void Translate(float x, float y)
    {
        center.Translate(x, y);
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

vector <CTriangle> g_vTri;
vector <CRectangle> g_vRect;
vector <CEllipse> g_vEllip;
vector <CDonut> g_vDon;

bool ReadShapes()
{
    float length, width, r, rx, ry, wx, wy;
    ULONG objCol;
    string sel;

    cin >> sel;
    while (sel != "Exit")
    {
        if (sel == "Triangle")
        {
            cin >> wx >> wy >> length >> width >> hex >> objCol >> dec;
            g_vTri.push_back(CTriangle(CPoint2D(wx, wy), length, width, objCol));
        }
        else if (sel == "Rectangle")
        {
            cin >> wx >> wy >> length >> width >> hex >> objCol >> dec;
            g_vRect.push_back(CRectangle(CPoint2D(wx, wy), length, width, objCol));
        }
        else if(sel == "Ellipse")
        {
            cin >> wx >> wy >> rx >> ry >> hex >> objCol >> dec;
           g_vEllip.push_back(CEllipse(CPoint2D(wx, wy), rx, ry, objCol));
        }
        else if(sel == "Donut")
        {
            cin >> wx >> wy >> rx >> ry >> r >> hex >> objCol >> dec;
            g_vDon.push_back(CDonut(CPoint2D(wx, wy), rx, ry, r, objCol));
        }
        else
        {
            cout << "Error reading!" << endl;
            return false;
        }
        cin >> sel;
    }

    return true;
}

void display()
{
    for(size_t i=0; i<g_vRect.size(); i++)
        g_vRect[i].Draw();
    for(size_t i=0; i<g_vEllip.size(); i++)
        g_vEllip[i].Draw();
    for(size_t i=0; i<g_vDon.size(); i++)
        g_vDon[i].Draw();
    for(size_t i=0; i<g_vTri.size(); i++)
        g_vTri[i].Draw();
}

void keyboard(unsigned char key)
{
    switch (key)
    {
    case 'w':
        for(size_t i=0; i<g_vTri.size(); i++)
            g_vTri[i].Translate(0, 5);
        for(size_t i=0; i<g_vRect.size(); i++)
            g_vRect[i].Translate(0, 5);
        for(size_t i=0; i<g_vEllip.size(); i++)
            g_vEllip[i].Translate(0, 5);
        for(size_t i=0; i<g_vDon.size(); i++)
            g_vDon[i].Translate(0, 5);
        break;
    case 's':
        for(size_t i=0; i<g_vTri.size(); i++)
            g_vTri[i].Translate(0, -5);
        for(size_t i=0; i<g_vRect.size(); i++)
            g_vRect[i].Translate(0, -5);
        for(size_t i=0; i<g_vEllip.size(); i++)
            g_vEllip[i].Translate(0, -5);
        for(size_t i=0; i<g_vDon.size(); i++)
            g_vDon[i].Translate(0, -5);
        break;
    case 'a':
        for(size_t i=0; i<g_vTri.size(); i++)
            g_vTri[i].Translate(-5, 0);
        for(size_t i=0; i<g_vRect.size(); i++)
            g_vRect[i].Translate(-5, 0);
        for(size_t i=0; i<g_vEllip.size(); i++)
            g_vEllip[i].Translate(-5, 0);
        for(size_t i=0; i<g_vDon.size(); i++)
            g_vDon[i].Translate(-5, 0);
        break;
    case 'd':
        for(size_t i=0; i<g_vTri.size(); i++)
            g_vTri[i].Translate(5, 0);
        for(size_t i=0; i<g_vRect.size(); i++)
            g_vRect[i].Translate(5, 0);
        for(size_t i=0; i<g_vEllip.size(); i++)
            g_vEllip[i].Translate(5, 0);
        for(size_t i=0; i<g_vDon.size(); i++)
            g_vDon[i].Translate(5, 0);
        break;
    case 'z':
        for(size_t i=0; i<g_vTri.size(); i++)
            g_vTri[i].Scale(1.05);
        for(size_t i=0; i<g_vRect.size(); i++)
            g_vRect[i].Scale(1.05);
        for(size_t i=0; i<g_vEllip.size(); i++)
            g_vEllip[i].Scale(1.05);
        for(size_t i=0; i<g_vDon.size(); i++)
            g_vDon[i].Scale(1.05);
        break;
    case 'x':
        for(size_t i=0; i<g_vTri.size(); i++)
            g_vTri[i].Scale(0.95);
        for(size_t i=0; i<g_vRect.size(); i++)
            g_vRect[i].Scale(0.95);
        for(size_t i=0; i<g_vEllip.size(); i++)
            g_vEllip[i].Scale(0.95);
        for(size_t i=0; i<g_vDon.size(); i++)
            g_vDon[i].Scale(0.95);
        break;
    }
}

/*
Rectangle	400	400	800	400	0xC0E8F2
Rectangle	400	100	800	200	0xB8BD95
Rectangle	407	354	30	100	0x8C1926
Ellipse	403	425	15	15	0xFFEEEE
Ellipse	360	480	20	20	0xFFEEEE
Ellipse	300	550	30	30	0xFFEEEE
Rectangle	474	181	236	200	0xDECA8F
Triangle	474	340	340	180	0x9E6120
Rectangle	412	227	30	30	0xB5C9EE
Rectangle	550	227	30	30	0xB5C9EE
Rectangle	412	130	30	30	0xB5C9EE
Rectangle	550	130	30	30	0xB5C9EE
Rectangle	474	167	80	20	0xF9B06B
Rectangle	462	128	25	55	0x8C1926
Rectangle	486	128	25	55	0x8C1926
Rectangle	474	94	80	12	0x9F9E99
Rectangle	474	82	100	12	0x9F9E99
Ellipse	444	45	50	15	0x9F9E99
Ellipse	322	31	55	18	0x9F9E99
Ellipse	181	22	65	15	0x9F9E99
Rectangle	154	78	10	15	0x814000
Triangle	154	103	95	50	0x002800
Triangle	154	131	85	45	0x002800
Triangle	154	156	70	40	0x002800
Triangle	154	184	50	50	0x002800
Rectangle	254	78	10	15	0x814000
Triangle	254	103	95	50	0x002800
Triangle	254	131	85	45	0x002800
Triangle	254	156	70	40	0x002800
Triangle	254	184	50	50	0x002800
Donut	474	490	80	60	0.5	0x814000
Exit
*/

int main()
{
    ReadShapes();
    initGraph(display, keyboard);
    return 0;
}
