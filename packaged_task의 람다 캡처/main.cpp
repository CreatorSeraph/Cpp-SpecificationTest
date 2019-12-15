#include <future>
#include <iostream>
#include <functional>

//https://stackoverflow.com/questions/36958929/error-on-moving-a-packaged-task-object-to-lambda-capture
//https://github.com/progschj/ThreadPool/issues/40
//https://stackoverflow.com/questions/32486623/moving-a-lambda-once-youve-move-captured-a-move-only-type-how-can-the-lambda
//https://stackoverflow.com/questions/25330716/move-only-version-of-stdfunction

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