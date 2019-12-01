#include <chrono>
#include <iostream>

int main()
{
    using namespace std::chrono;
    using std::clog;
    using std::cout;
    using std::endl;

    constexpr int loopCount = 10000;

    std::streambuf* buf = nullptr;
    auto legucyBuf = clog.rdbuf(buf);

    high_resolution_clock timer;
    auto startTime = timer.now();

    for (int i = 0; i < loopCount; ++i)
        clog << "hi";

    duration<double> sec = (timer.now() - startTime);

    cout << sec.count() << "ÃÊ °æ°ú" << endl;

    return 0;
}