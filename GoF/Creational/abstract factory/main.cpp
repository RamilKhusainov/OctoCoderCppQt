#include <iostream>

using namespace std;
// паттерн абстрактная фабрика

//абстрактный продукт1
class Button {
public:
    virtual void type () = 0;
};

//конкретный продукт 1.1
class WinButton: public Button {
    virtual void type ()
    {
        cout << "windows button\n";
    }
};
//конкретный  продукт 1.2
class LinuxButton: public Button {
public:
    virtual void type (){
        cout <<"Linux button\n";
    }
};

//абстрактный продукт2
class ScrollBar {
public:
    virtual void type () = 0;

};
//конкретный  продукт 2.1
class WinScroll: public ScrollBar {
public:
     void type ()
    {
        cout <<"windows scrollbar \n";
    }
};
//конкретный  продукт 2.2
class LinuxScroll: public ScrollBar {
public:
     void type ()
    {
        cout <<"linux scrollbar \n";
    }
};

//абстрактная фабрика
class AbsFactory {
public:
    virtual Button* createButton () = 0;
    virtual ScrollBar* createScrollBar () = 0;
};

//конкретная фабрика1
class WinFactory: public AbsFactory{
public:

    Button* createButton()
    {
        return new WinButton;
    }

    ScrollBar* createScrollBar()
    {
        return new WinScroll;
    }
};

//конкретная фабрика2
class LinuxFactory: public AbsFactory{
public:

    Button* createButton()
    {
        return new LinuxButton;
    }

    ScrollBar* createScrollBar()
    {
        return new LinuxScroll;
    }
};

int main ()
{
    Button* button;
    ScrollBar* scrollbar;
    AbsFactory* absFactory;

    absFactory = new WinFactory;
    button = absFactory->createButton();
    button->type();
    scrollbar = absFactory->createScrollBar();
    scrollbar->type();

    absFactory = new LinuxFactory;
    button = absFactory->createButton();
    button->type();
    scrollbar = absFactory->createScrollBar();
    scrollbar->type();



    return 1;
}
