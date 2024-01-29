#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

void run(int count) {
    while (count-- > 0)
        cout << "Prof. Maniglio" << endl;
    this_thread::sleep_for(seconds(3));
}


int main() {
    //fai partire più volte, come cambia il risultato?
    thread worker(run, 5);
    cout << "Inizio" << endl;
    worker.detach();
    //esiste il detachable?
    cout << "Fine" << endl;


    return 0;
}
