#include <iostream>
#include <conio.h>
using namespace std;
// паттерн адаптер (адаптер класса)

class Rectangle {
public:
    virtual void draw () = 0;

};

//}

// адаптируемый класс

class oldRectangle {
public:
    int high_left_x, high_left_y, length, height;

    oldRectangle(int, int, int, int);
    void oldDraw ();
};

oldRectangle::oldRectangle(int x, int y, int l, int h)
{
    high_left_x = x;
    high_left_y = y;
    length = l;
    height = h;

}
void oldRectangle::oldDraw()
{
    cout << "top left x coordinate: "<< high_left_x<< "\ntop left y coordinate:  "<< high_left_y<<"\nlenght of the window: " << length<< "\nheight of the window: " << height;
}


// класс адаптер
class adapter: public Rectangle, private oldRectangle {

public:

    adapter(int lx,int ly,int rx,int ry):oldRectangle(lx,ly,rx-lx,ry-ly) {};

    void draw ()
    {
        oldDraw();
    }

};


int main()
{
    int lx = 10, ly = 10, rx = 100, ry = 50;
    Rectangle *rectangle = new adapter(lx,ly,rx,ry);
    rectangle->draw();
    _getch();
  return 1;
}
