#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
using namespace std::chrono;

int fotoscattate = 0;
mutex m;

//Race condition
void cabinaFotografica(string nome) {
    m.lock();
    cout << nome + " entra per farsi una foto" << endl;
    this_thread::sleep_for(milliseconds(500));
    cout << nome + " si scatta una foto" << endl;
    fotoscattate++;
    this_thread::sleep_for(milliseconds(500));
    cout << nome + " esce dalla cabina" << endl;
    cout << "Foto scattate: " << fotoscattate << endl;
    m.unlock();
}


int main() {

    thread worker1(cabinaFotografica, "Alice");
    thread worker2(cabinaFotografica, "Bob");

    worker1.join();
    worker2.join();

    return 0;
}
