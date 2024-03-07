#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex ml;
int buffer = 0;

void task(string threadNumber, int loopFor) {
    ml.lock();
    for (int i = 0; i < loopFor; ++i) {
        buffer++;
        cout << threadNumber << buffer << endl;
    }
    ml.unlock();

}

int main() {
    thread t1(task, "TO ", 10);
    thread t2(task, "T1 ", 10);
    t1.join();
    t2.join();
    return 0;
}

