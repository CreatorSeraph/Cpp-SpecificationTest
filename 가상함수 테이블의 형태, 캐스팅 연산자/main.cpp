#include <iostream>
#include <string>

//�� �ʸ� ������
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

    //�Ҹ����� �����Լ����� �ٸ� �����Լ��� �ٸ� Ư���� ������ Ÿ�� �ȴ�.
    //https://dydtjr1128.github.io/effectivec++/2019/07/18/Effective-Cpp-item-7.html
    //�θ� Ŭ���� �����Ϳ� ����� ������ �����Ҷ��� �θ�Ŭ������ �Ҹ��ڸ� �۵��ϰ� �Ǵµ�,
    //�̶� �θ� Ŭ������ �Ҹ��ڰ� virtual�̸�, �ڽ� Ŭ������ �Ҹ��ڸ� ���� ȣ���ϰ� �ȴ�.
    //�ڽ�Ŭ������ �Ҹ��ڿ��� �޸𸮸� �������ִ� �ڵ尡 �ִٸ�, �θ�Ŭ������ �Ҹ��ڸ� virtual�� �صδ°� ���� ���̴�.
    virtual ~VFPClass() = default;

    virtual void VF1()
    {
        cout << "���� VFPClass�� VF1!" << endl;
    }

    virtual void VF2()
    {
        cout << "���� VFPClass�� VF2!" << endl;
    }

    //���� �����Լ�
    virtual void PVF1() = 0;

    void NF1()
    {
        cout << "���� VFPClass�� NF1!" << endl;
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
        cout << "���� VFC1Class�� PFV1!" << endl;
    }
};

class VFC1CClass : public VFC1Class
{
public:
    //override Ű���尡 �ϴ� ���� �ƹ��͵� ����.
    //���� overrideŰ���尡 �پ��ִµ� �������̵� �� �θ��Լ��� ���� ��� �������� �ȵǰ� �Ͽ�
    //�Ǽ��� �����ϴ� �ڵ��ΰ�. �ظ��ؼ��� ����Ҷ� �ٿ�����.
    virtual void VF2() override
    {
        cout << "���� VFC1CClass�� VF2!" << endl;
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