#include <fstream>
#include <iostream>

int main()
{
    std::wofstream fileTest(L"./Data/test.txt");//������ ������ ������ ������ �ʴ°����� ������...
    if(fileTest.is_open())
        fileTest << L"�� �̰� ������?";

    return 0;
}