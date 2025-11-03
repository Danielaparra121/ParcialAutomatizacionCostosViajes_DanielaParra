#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Función que valida que los datos no sean negativos
int validarDato(string mensaje) {
    int dato;
    do {
        cout << mensaje;
        cin >> dato;
        if (dato < 0) {
            cout << "Error: el valor no puede ser negativo. Intenta de nuevo." << endl;
        }
    } while (dato < 0);
    return dato;
}

// Función que calcula el total ganado por cada conductor
double calcularTotal(int distancia[], int costo[], int numviajes) {
    double total = 0;
    for (int i = 0; i < numviajes; i++) {
        total += distancia[i] * costo[i];
    }
    return total;
}

// Función que calcula el promedio de distancia recorrida por cada conductor
double PromedioDistancia(int distancia[], int numviajes) {
    double suma = 0;
    for (int i = 0; i < numviajes; i++) {
        suma += distancia[i];
    }
    return suma / numviajes;
}

int main() {
    int canconductor, numviajes;
    string name[10];
    double totalGanado[10];
    double promedioDistancia[10];

    cout << "Ingrese la cantidad de conductores (maximo 10): ";
    cin >> canconductor;
    cout << endl;

    if (canconductor <= 10 && canconductor > 0) {
        for (int i = 0; i < canconductor; i++) {
            int distancia[10];
            int costo[10];

            cout << "================= Conductor # " << i + 1 << " =================" << endl;

            cout << "Nombre: ";
            cin >> name[i];

            cout << "Ingresa el numero de viajes del conductor (maximo 10): ";
            cin >> numviajes;
            while (numviajes <= 0 || numviajes > 10) {
                cout << "Numero no permitido, por favor ingresa otro: ";
                cin >> numviajes;
            }
            cout << endl;

            for (int viaje = 0; viaje < numviajes; viaje++) {
                cout << "Viaje #" << viaje + 1 << endl;
                distancia[viaje] = validarDato("Distancia (km): ");
                costo[viaje] = validarDato("Costo por km ($): ");
                cout << endl;
            }

            // Llamar funciones y almacenar resultados
            totalGanado[i] = calcularTotal(distancia, costo, numviajes);
            promedioDistancia[i] = PromedioDistancia(distancia, numviajes);
        }

        cout << endl;
        cout << fixed << setprecision(2);

        // Mostrar tabla de resultados
        cout << "================= RESUMEN DE VIAJES =================" << endl;
        cout << left << setw(15) << "Conductor"
            << setw(20) << "Total Ganado ($)"
            << setw(25) << "Promedio Distancia (km)" << endl;
        cout << "--------------------------------------------------------------" << endl;
        //proceso para encontrar el de mayor ingreso 
        int Mayor = 0;
        for (int i = 0; i < canconductor; i++) {
            cout << left << setw(15) << name[i]
                << setw(20) << totalGanado[i]
                << setw(25) << promedioDistancia[i] << endl;

            if (totalGanado[i] > totalGanado[Mayor]) {
                Mayor = i;
            }
        }
        //resultado de mayor
        cout << "--------------------------------------------------------------" << endl;
        cout << "El conductor con mayor ingreso es: " << name[Mayor]
            << " con $" << totalGanado[Mayor] << endl;
    }
    else {
        cout << "Numero no permitido, por favor ingresa otro. :)" << endl;
    }

    return 0;
}
