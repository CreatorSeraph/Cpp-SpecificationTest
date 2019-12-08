#include <iostream>
#include <algorithm>
#include <list>

int main()
{
    using namespace std;

    std::list<int> data = { 0,1,2,3,4,5,6,7,8,9 };

    auto iter0 = data.end();
    auto iter1 = next(data.begin(), 4);
    auto iter2 = data.emplace(data.end(), 10);
    auto iter3 = data.erase(next(data.begin(), 5));

    data.insert(data.end(), { 11,12,13,14,15 });
    auto iter4 = data.erase(iter2);
    auto iter5 = data.end();
    auto iter6 = data.erase(iter1);

    data.clear();
    auto iter7 = data.end();

    //list�� iterator�� Node�� �����͸� ��� �ִ�.
    //erase�ÿ��� node�� next�� ��ȯ�Ѵ�.
    //end()�Լ��� ��� list�� head�� ��ȯ�ϰ� �ֱ� ������
    //������ ���� �ּҰ��� ��ȯ�ϰ� �ȴ�.
    //���� iterator�� next�� ���� ����ϰ��, end()�� ����Ű�� �صξ��� ������
    //������ node�� ����Ű�� �ʴ��� iterator�� �߸��� ���� ������

    return 0;
}