#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int contatore = 0;
int contatoreLock = 0;

// cambia il tipo di oggi
timed_mutex m;

void incrementa(int numThread) {
        if(m.try_lock_for(chrono::seconds(1))) {
            contatore++;
            this_thread::sleep_for(chrono::seconds(2));
            cout << "Thread " << numThread << " entrato" <<endl;
            m.unlock();
        } else
            cout << "Thread " << numThread << " non entrato" <<endl;

}

int main() {
    thread worker1(incrementa, 1);
    thread worker2(incrementa, 2);
    worker1.join();
    worker2.join();
    cout << contatore << endl;
    return 0;
}