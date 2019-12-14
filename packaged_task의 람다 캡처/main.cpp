#include <future>
#include <iostream>
#include <functional>

int main()
{
    using namespace std;

    std::packaged_task<int()> newTaskPtr([]() {return 4; });

    std::future<int> func_result = newTaskPtr.get_future();

    std::function<void()> result = [newTaskPtr = std::move(newTaskPtr)]() mutable{
        newTaskPtr();
    };

    std::function<void()> newFunc = std::move(result);
}