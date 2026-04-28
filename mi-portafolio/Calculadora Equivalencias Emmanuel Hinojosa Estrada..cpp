#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
	cout << "AUTOR EMMANUEL HINOJOSA ESTRADA\n";
	cout << "------------------\n";
	
    int opcion;
    double valor, resultado;

    cout << "--- Conversor de Unidades de Fuerza/Masa ---" << endl;
    cout << "1. Libra Masa (lbm) a Newtons (N)" << endl;
    cout << "2. Newtons (N) a Kilos (kgf)" << endl;
    cout << "3. Kilos (kg) a Libras Fuerza (lbf)" << endl;
    cout << "Seleccione una opcion (1-3): ";
    cin >> opcion;

    cout << "Ingrese el valor a convertir: ";
    cin >> valor;

    cout << fixed << setprecision(4); 

    switch(opcion) {
        case 1:
            // 1 lbm = 0.453592 kg. 1 kg = 9.81 N
            resultado = valor * 0.453592 * 9.81;
            cout << valor << " lbm equivalen a " << resultado << " N" << endl;
            break;
        case 2:
            // 1 N = 0.10197 kgf
            resultado = valor * 0.10197;
            cout << valor << " N equivalen a " << resultado << " kgf" << endl;
            break;
        case 3:
            // 1 kg = 2.20462 lbf
            resultado = valor * 2.20462;
            cout << valor << " kg equivalen a " << resultado << " lbf" << endl;
            break;
        default:
        	// este es mi salvavidas
            cout << "Opcion no valida." << endl;
    }

    return 0;
}

