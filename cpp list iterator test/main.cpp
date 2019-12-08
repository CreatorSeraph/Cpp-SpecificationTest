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

    //list의 iterator는 Node의 포인터를 들고 있다.
    //erase시에는 node의 next를 반환한다.
    //end()함수는 사실 list의 head를 반환하고 있기 때문에
    //언제나 같은 주소값을 반환하게 된다.
    //또한 iterator의 next가 없는 노드일경우, end()를 가르키게 해두었기 때문에
    //삭제된 node를 가르키지 않는한 iterator가 잘못될 일은 없을듯

    return 0;
}