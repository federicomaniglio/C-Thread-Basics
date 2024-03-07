#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex ml;
int buffer = 0;

//gestisce più tipologie di mutex (es. timed mutex)
//consente di acquisire e rilasciare il mutex nello stesso scope

//Locking Strategies
//TYPE              EFFECTS(S)
//1. defer_lock     do not acquire ownership of the mutex.
//2. try_to_lock    try to acquire ownership of the mutex without blocking.
//3. adopt_lock     assume the calling thread already has ownership of the mutex.




void task(string threadNumber, int loopFor) {
    unique_lock<mutex> lock(ml, defer_lock);
    lock.lock();
    for (int i = 0; i < loopFor; ++i) {
        buffer++;
        cout << threadNumber << buffer << endl;
    }
}

int main() {
    thread t1(task, "TO ", 10);
    thread t2(task, "T1 ", 10);
    t1.join();
    t2.join();
    return 0;
}

