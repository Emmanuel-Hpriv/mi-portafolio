#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout << "AUTOR EMMANUEL HINOJOSA ESTRADA\n";
	cout << "------------------\n";
	
    int opcion;
    double valor, resultado;

    cout << "--- Conversor SI (Metrico) a Ingles ---" << endl;
    cout << "1. Metros (m) a Pies (ft)" << endl;
    cout << "2. Kilogramos (kg) a Libras (lb)" << endl;
    cout << "3. Celsius (C) a Fahrenheit (F)" << endl;
    cout << "Seleccione una opcion (1-3): ";
    cin >> opcion;

    cout << "Ingrese el valor: ";
    cin >> valor;

    cout << fixed << setprecision(2);

    switch(opcion) {
        case 1:
            // 1 metro = 3.28084 pies
            resultado = valor * 3.28084;
            cout << valor << " m = " << resultado << " ft" << endl;
            break;
        case 2:
            // 1 kg = 2.20462 lb
            resultado = valor * 2.20462;
            cout << valor << " kg = " << resultado << " lb" << endl;
            break;
        case 3:
            // (C * 9/5) + 32 = F
            resultado = (valor * 1.8) + 32;
            cout << valor << " C = " << resultado << " F" << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
    }

    return 0;
}

