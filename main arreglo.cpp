#include <iostream>
#include <algorithm>
#include <cstdlib> // Para rand()
#include <ctime>   // Para time()

using namespace std;

int particion(int arre[], int rta, int end) {
    int p = arre[end];
    int pI = rta;

    for (int i = rta; i < end; i++) {
        if (arre[i] <= p) {
            swap(arre[i], arre[pI]);
            pI++;
        }
    }

    swap(arre[pI], arre[end]);
    return pI;
}

void quicksort(int arre[], int rta, int end) {
    if (rta >= end) {
        return;
    }

    int p = particion(arre, rta, end);
    quicksort(arre, rta, p - 1);
    quicksort(arre, p + 1, end);
}

int main() {
    srand(time(0)); // Inicializar la semilla para números aleatorios

    int n = 10; // Número de elementos en el arreglo
    int arre[n];

    cout << "Arreglo original:" << endl;
    for (int i = 0; i < n; i++) {
        arre[i] = rand() % 100; // Generar números aleatorios entre 0 y 99
        cout << arre[i] << " ";
    }
    cout << endl;

    quicksort(arre, 0, n - 1);

    cout << "Arreglo ordenado:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arre[i] << " ";
    }
    cout << endl;

    return 0;
}
