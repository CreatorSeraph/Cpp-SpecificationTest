#include <iostream>
#include <functional>

using namespace std;

class Base
{
public:
    virtual void TestFunc()
    {
        cout << "Base - TestFunc()" << endl;
    }
};

class Child1 : public Base
{
public:
    virtual void TestFunc() override
    {
        cout << "Child1 - TestFunc()" << endl;
    }
};

int main()
{
    auto funcPtr = &Base::TestFunc;
    function<void(Base*)> func = funcPtr;

    auto child = new Child1;
    func(child);

    return 0;
}