#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

void contaPari(int finalNumber){
    int contatore = 0;
    for (int i = 0; i < finalNumber; ++i) {
        if(!(i%2))
            contatore++;
    }
    cout << contatore <<endl;
}
void contaDispari(int finalNumber){
    int contatore = 0;
    for (int i = 0; i < finalNumber; ++i) {
        if(i%2)
            contatore++;
    }
    cout << contatore <<endl;
}



int main() {

    auto startTime = high_resolution_clock::now();

    int numero = 2000000000;
    contaPari(numero);
    contaDispari(numero);

    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);

    cout << duration.count()/1000000 << endl;

    return 0;
}
