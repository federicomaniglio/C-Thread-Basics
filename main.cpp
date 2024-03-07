#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int contatore = 0;
int contatoreLock = 0;

mutex m;

void incrementa() {
    for (int i = 0; i < 100000; ++i) {
        if(m.try_lock()) {
            contatore++;
            m.unlock();
        } else
            contatoreLock++;
    }
}

int main() {
    thread worker1(incrementa);
    thread worker2(incrementa);
    worker1.join();
    worker2.join();
    cout << contatore << endl;
    cout << contatoreLock << endl;
    cout << contatore + contatoreLock << endl;

    return 0;
}