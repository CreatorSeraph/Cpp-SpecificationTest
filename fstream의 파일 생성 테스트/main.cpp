#include <fstream>
#include <iostream>

int main()
{
    std::wofstream fileTest(L"./Data/test.txt");//폴더가 없으면 파일이 열리지 않는것으로 밝혀져...
    if(fileTest.is_open())
        fileTest << L"아 이게 열리나?";

    return 0;
}