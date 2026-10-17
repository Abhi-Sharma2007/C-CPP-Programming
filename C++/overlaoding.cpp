#include <iostream>
using namespace std;

class Number
{
public:
    int x;

    Number(int a = 0)
    {
        x = a;
    }

    // Binary arithmetic +
    Number operator+(Number n)
    {
        return Number(x + n.x);
    }

    // Binary arithmetic -
    Number operator-(Number n)
    {
        return Number(x - n.x);
    }

    // Relational ==
    bool operator==(Number n)
    {
        return x == n.x;
    }

    // Unary minus
    Number operator-()
    {
        return Number(-x);
    }

    // Unary Boolean NOT
    bool operator!()
    {
        return x == 0;
    }

    // Binary Boolean AND
    bool operator&&(Number n)
    {
        return (x != 0 && n.x != 0);
    }

    // Binary Boolean OR
    bool operator||(Number n)
    {
        return (x != 0 || n.x != 0);
    }

    // Prefix increment
    Number operator++()
    {
        ++x;
        return *this;
    }

    // Postfix increment
    Number operator++(int)
    {
        Number temp = *this;
        x++;
        return temp;
    }

    // Display
    void display()
    {
        cout << x << endl;
    }
};

int main()
{
    Number a(10), b(0), c;

    cout << "Addition: ";
    c = a + b;
    c.display();

    cout << "Subtraction: ";
    c = a - b;
    c.display();

    cout << "Equality: ";
    cout << (a == b) << endl;

    cout << "Unary minus: ";
    c = -a;
    c.display();

    cout << "Unary NOT: ";
    cout << !b << endl;

    cout << "Binary AND: ";
    cout << (a && b) << endl;

    cout << "Binary OR: ";
    cout << (a || b) << endl;

    cout << "Prefix increment: ";
    c = ++a;
    c.display();

    cout << "Postfix increment: ";
    c = a++;
    c.display();

    return 0;
}