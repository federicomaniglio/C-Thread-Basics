#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cstdlib>
#include <future>

using namespace std;

void calcolaPari(promise<long long>& valorePromesso, long long fine){
    long long numeriPari=0;
    for (long long i = 0; i < fine; ++i) {
        if(!(i%2))
            numeriPari++;
    }
    valorePromesso.set_value(numeriPari);
}


int main() {

    promise<long long> valorePromesso;
    future<long long> valoreFuturo = valorePromesso.get_future();

    thread t(calcolaPari, ref(valorePromesso), 9000000000);
    cout<<"Calcolo in corso..."<<endl;
    cout<< "Numeri pari: " << valoreFuturo.get()<<endl;
    t.join();

    return 0;
}