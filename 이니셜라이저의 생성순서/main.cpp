#include <iostream>

class T1
{
public:
    int a;
    int b;
    T1(int _val)
        :a(_val), b(a)
    {
    }
};

class T2
{
public:
    int b;
    int a;
    T2(int _val)
        :a(_val), b(a)
    {
    }
};

class T3 : public T2
{
public:
    int c;
    T3(int _val)
        :c(a), T2(_val)
    {
    }
};

int main()
{
    T1 t1(4);
    T2 t2(5);
    T3 t3(6);

    std::cout << t1.a << "\t" << t1.b << std::endl;
    std::cout << t2.a << "\t" << t2.b << std::endl;
    std::cout << t3.a << "\t" << t3.b << "\t" << t3.c << std::endl;
}