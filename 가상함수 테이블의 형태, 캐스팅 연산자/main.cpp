#include <iostream>
#include <string>

//앗 너모 귀찮다
using namespace std;

class NormalClass
{
public:
    NormalClass() = default;
    ~NormalClass() = default;
private:
    int m_val;
    string m_str;
};

//VirtualFunctionParentClass
class VFPClass
{
public:
    VFPClass() = default;

    //소멸자의 가상함수만은 다른 가상함수와 다른 특별한 로직을 타게 된다.
    //https://dydtjr1128.github.io/effectivec++/2019/07/18/Effective-Cpp-item-7.html
    //부모 클래스 포인터에 저장된 변수를 해제할때면 부모클래스의 소멸자만 작동하게 되는데,
    //이때 부모 클래스의 소멸자가 virtual이면, 자식 클래스의 소멸자를 먼저 호출하게 된다.
    //자식클래스의 소멸자에서 메모리를 해제해주는 코드가 있다면, 부모클래스의 소멸자를 virtual로 해두는게 좋을 것이다.
    virtual ~VFPClass() = default;

    virtual void VF1()
    {
        cout << "나는 VFPClass의 VF1!" << endl;
    }

    virtual void VF2()
    {
        cout << "나는 VFPClass의 VF2!" << endl;
    }

    //순수 가상함수
    virtual void PVF1() = 0;

    void NF1()
    {
        cout << "나는 VFPClass의 NF1!" << endl;
    }
private:
    int m_val;
    string m_str;
};

class VFC1Class : public VFPClass
{
public:
    void PVF1()
    {
        cout << "나는 VFC1Class의 PFV1!" << endl;
    }
};

class VFC1CClass : public VFC1Class
{
public:
    //override 키워드가 하는 일은 아무것도 없다.
    //단지 override키워드가 붙어있는데 오버라이딩 될 부모함수가 없을 경우 컴파일이 안되게 하여
    //실수를 방지하는 코드인것. 왠만해서는 사용할때 붙여두자.
    virtual void VF2() override
    {
        cout << "나는 VFC1CClass의 VF2!" << endl;
    }
};

int main()
{
    NormalClass* normalTest = new NormalClass;
    VFPClass* test = new VFC1Class;
    VFPClass* testChild = new VFC1CClass;

    constexpr int intSize = sizeof(int);
    constexpr int strSize = sizeof(string);
    constexpr int normalSize = sizeof(NormalClass);
    constexpr int VFPSize = sizeof(VFPClass);
    constexpr int VFC1Size = sizeof(VFC1Class);

    return 0;
}