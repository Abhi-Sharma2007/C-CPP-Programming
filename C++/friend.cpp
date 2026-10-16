#include <iostream>
using namespace std;

class b;

class a
{
public:
    int y;

    a(int y) : y(y) {}

    void modb(b &obj);

    friend class b;
    friend void add(b &n, a &m);
};

class b
{
    int x;

public:
    void setdata(int x)
    {
        this->x = x;
    }

    friend void add(b &n, a &m);
    friend class a;

    void display()
    {
        cout << "x=" << x << endl;
    }

    void moda(a &ob)
    {
        ob.y = ob.y + 10;
        cout << "y=" << ob.y << endl;
    }
};

void a::modb(b &obj)
{
    obj.x = obj.x + 10;
    cout << "x=" << obj.x << endl;
}

void add(b &n, a &m)
{
    n.x = n.x + m.y;
    cout << "new x=" << n.x << endl;
}

int main()
{
    a ob(20);
    b obj;

    obj.setdata(10);
    obj.display();

    ob.modb(obj);
    obj.moda(ob);

    add(obj, ob);

    return 0;
}