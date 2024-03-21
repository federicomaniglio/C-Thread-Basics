#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cstdlib>
#include <future>

using namespace std;

long long calcolaPari(long long fine) {
    cout << this_thread::get_id() << endl;
    long long numeriPari = 0;
    for (long long i = 0; i < fine; ++i) {
        if (!(i % 2))
            numeriPari++;
    }
    return numeriPari;
}


int main() {
    cout << this_thread::get_id() << endl;
    future<long long> valoreFuturo = async(launch::async, calcolaPari, 9000000000);

    cout << "Calcolo in corso..." << endl;
    cout << "Numeri pari: " << valoreFuturo.get() << endl;


    return 0;
}