#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdlib> // <--- NUEVA LIBRERIA necesaria para 'atof'

using namespace std;

// Función corregida compatible con Dev-C++ antiguo
double procesarCarga(string entrada) {
    size_t posX = entrada.find('x');
    size_t posHat = entrada.find('^');

    if (posX != string::npos && posHat != string::npos) {
        // Extrae el coeficiente (ej: 9)
        // Usamos .c_str() para convertir el string a formato compatible con atof
        string parteCoef = entrada.substr(0, posX);
        double coeficiente = atof(parteCoef.c_str());
        
        // Extrae el exponente (ej: 19)
        string parteExp = entrada.substr(posHat + 1);
        double exponente = atof(parteExp.c_str());
        
        return coeficiente * pow(10, exponente);
    }
    
    // Si es número normal, lo convertimos directamente
    return atof(entrada.c_str());
}

int main() {
    const double K = 9e9; // 9x10^9 N·m²/C²
    string inputQ1, inputQ2;
    double q1, q2, r, fuerza;

    cout << "===============================================" << endl;
    cout << "   CALCULADORA LEY DE COULOMB (CORREGIDA)      " << endl;
    cout << "   Formato aceptado: 9x10^19 o 0.0005          " << endl;
    cout << "===============================================" << endl;

    cout << "-> Ingrese carga q1 (C): ";
    cin >> inputQ1;
    q1 = procesarCarga(inputQ1);

    cout << "-> Ingrese carga q2 (C): ";
    cin >> inputQ2;
    q2 = procesarCarga(inputQ2);

    cout << "-> Ingrese distancia r (m): ";
    cin >> r;

    if (r <= 0) {
        cout << "\n[!] Error: La distancia debe ser mayor a 0 m." << endl;
    } else {
        fuerza = K * (abs(q1 * q2) / pow(r, 2));

        cout << "\n-------------- RESULTADOS ---------------------" << endl;
        
        if ((q1 > 0 && q2 < 0) || (q1 < 0 && q2 > 0)) {
            cout << "INTERACCION: ATRACCION" << endl;
        } else if (q1 == 0 || q2 == 0) {
            cout << "INTERACCION: NULA" << endl;
        } else {
            cout << "INTERACCION: REPULSION" << endl;
        }

        cout << fixed << setprecision(2);
        cout << "MAGNITUD: " << fuerza << " N" << endl;
        
        // Mostramos notación científica si el número es muy grande
        if (fuerza > 1000000) {
             cout << "NOTACION CIENTIFICA: " << scientific << setprecision(2) << fuerza << " N" << endl;
        }
        cout << "-----------------------------------------------" << endl;
    }

    return 0;
}
