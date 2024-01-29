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

    cout << "Inizio" << endl;
    thread worker(run, 5);
    worker.join();
    //e se metto due join?
    cout << "Fine" << endl;


    return 0;
}
