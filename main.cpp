#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>

using namespace std;

mutex mtx;
condition_variable cv;
bool ready = false;
string msg;

void writerThread() {
    this_thread::sleep_for(chrono::seconds(2));
    lock_guard<mutex> lock(mtx);
    msg = "Hello from writer!";
    ready = true;
    cv.notify_one();
}

//Acquisizione di un Mutex: Prima di utilizzare una condition variable, è necessario acquisire un mutex
//
//Controllo di una Condizione: verifica una determinata condizione.
//      Se la condizione non è soddisfatta, il thread rilascia il mutex e si blocca
//
//Attesa e Sblocco del Mutex: Il thread si blocca fino a quando non riceve una notifica
//          il thread riacquista il mutex e riprende l'esecuzione se la condizione è soddisfatta

void readerThread() {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });
    cout << "Message received: " << msg << endl;
}

int main() {
    thread writer(writerThread);
    thread reader(readerThread);
    writer.join();
    reader.join();
    return 0;
}