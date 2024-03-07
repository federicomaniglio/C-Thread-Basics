#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cstdlib>

using namespace std;

std::condition_variable cv;
std::mutex m;
long saldo = 0;

void aggiungiSoldi(int soldi) {
    this_thread::sleep_for(chrono::seconds(2));
    std::lock_guard<mutex> lg(m);
    saldo += soldi;
    cout << "Aggiunto " << soldi << " Saldo attuale: " << saldo << endl;
    cv.notify_one();
}

void prelevaSoldi(int soldi) {
    std::unique_lock<mutex> ul(m);
    cv.wait(ul, [soldi] {
        if ((saldo - soldi) >= 0)
            return true;
        else {
            cout << "Non è possibile dedurre l'importo, il saldo attuale è inferiore a " << soldi << endl;
            return false;
        }
    });

    saldo -= soldi;
    cout << "Importo dedotto: " << soldi << " Il saldo attuale è: " << saldo << endl;
}

int main() {
    srand(time(NULL));
    thread t1(prelevaSoldi, rand() % 500 + 1);
    thread t2(aggiungiSoldi, rand() % 500 + 1);

    t1.join();
    t2.join();

    return 0;
}