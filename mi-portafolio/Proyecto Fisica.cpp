#include <iostream>
#include <cmath> // Necesario para pow, sqrt, cos, M_PI

using namespace std;

// Constantes globales
const double PI = 3.14159265358979323846;
const double G_EARTH = 9.81; // Gravedad aproximada
const double K_COULOMB = 9e9; // Constante de Coulomb
const double R_GAS = 8.314;   // Constante gases ideales

// --- PROTOTIPOS DE FUNCIONES ---
void menuFisicaClasica();
void menuOscilaciones();
void menuElectromagnetismo();
void menuTermodinamica();
void menuConversiones();

// --- FUNCIONES AUXILIARES ---
double toRadians(double degrees) {
    return degrees * (PI / 180.0);
}

int main() {
    int opcion;
    do {
        cout << "\n==========================================" << endl;
        cout << "      CALCULADORA INTEGRAL DE FISICA      " << endl;
        cout << "==========================================" << endl;
		cout << "\n==========================================" << endl;
        cout << "      HECHO POR: EMMANUEL HINOJOSA ESTRADA      " << endl;
        cout << "==========================================" << endl;
        cout << "1. Fisica Clasica (Mecanica)" << endl;
        cout << "2. Oscilaciones y Ondas" << endl;
        cout << "3. Electromagnetismo" << endl;
        cout << "4. Termodinamica" << endl;
        cout << "5. Conversiones de Unidades" << endl;
        cout << "0. Salir" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: menuFisicaClasica(); break;
            case 2: menuOscilaciones(); break;
            case 3: menuElectromagnetismo(); break;
            case 4: menuTermodinamica(); break;
            case 5: menuConversiones(); break;
            case 0: cout << "Saliendo del programa..." << endl; break;
            default: cout << "Opcion no valida." << endl;
        }
    } while (opcion != 0);

    return 0;
}

// ================= FISICA CLASICA =================
void menuFisicaClasica() {
    int op;
    double d, t, v, v0, a, m, f, f1, f2, h, theta, x0;
    
    cout << "\n--- FISICA CLASICA ---" << endl;
    cout << "1. Velocidad Media (v = d/t)" << endl;
    cout << "2. Aceleracion (a = Delta v / t)" << endl;
    cout << "3. 1ra Ley Newton (Verificar Equilibrio)" << endl;
    cout << "4. 2da Ley Newton (F = ma)" << endl;
    cout << "5. 3ra Ley Newton (Accion-Reaccion)" << endl;
    cout << "6. MRUA - Velocidad Final" << endl;
    cout << "7. MRUA - Posicion" << endl;
    cout << "8. Energia Cinetica" << endl;
    cout << "9. Energia Potencial Gravitatoria" << endl;
    cout << "10. Trabajo Mecanico" << endl;
    cout << "Elija ecuacion: ";
    cin >> op;

    switch (op) {
        case 1:
            cout << "Ingrese distancia (m): "; cin >> d;
            cout << "Ingrese tiempo (s): "; cin >> t;
            if(t!=0) cout << "Velocidad media = " << d/t << " m/s" << endl;
            else cout << "Error: tiempo cero." << endl;
            break;
        case 2:
            cout << "Ingrese velocidad final (m/s): "; cin >> v;
            cout << "Ingrese velocidad inicial (m/s): "; cin >> v0;
            cout << "Ingrese tiempo (s): "; cin >> t;
            if(t!=0) cout << "Aceleracion = " << (v - v0)/t << " m/s^2" << endl;
            break;
        case 3:
            cout << "Ingrese Sumatoria de Fuerzas (N): "; cin >> f;
            if (f == 0) cout << "El cuerpo esta en REPOSO o MRU (Inercia)." << endl;
            else cout << "El cuerpo NO esta en equilibrio (Existe aceleracion)." << endl;
            break;
        case 4:
            cout << "Ingrese masa (kg): "; cin >> m;
            cout << "Ingrese aceleracion (m/s^2): "; cin >> a;
            cout << "Fuerza resultante = " << m * a << " N" << endl;
            break;
        case 5:
            cout << "Ingrese Fuerza de Accion F1 (N): "; cin >> f1;
            cout << "Fuerza de Reaccion F2 = " << -f1 << " N" << endl;
            break;
        case 6:
            cout << "Velocidad inicial (m/s): "; cin >> v0;
            cout << "Aceleracion (m/s^2): "; cin >> a;
            cout << "Tiempo (s): "; cin >> t;
            cout << "Velocidad final = " << v0 + (a*t) << " m/s" << endl;
            break;
        case 7:
            cout << "Posicion inicial (m): "; cin >> x0;
            cout << "Velocidad inicial (m/s): "; cin >> v0;
            cout << "Aceleracion (m/s^2): "; cin >> a;
            cout << "Tiempo (s): "; cin >> t;
            cout << "Posicion final = " << x0 + (v0*t) + (0.5 * a * pow(t, 2)) << " m" << endl;
            break;
        case 8:
            cout << "Masa (kg): "; cin >> m;
            cout << "Velocidad (m/s): "; cin >> v;
            cout << "Energia Cinetica = " << 0.5 * m * pow(v, 2) << " J" << endl;
            break;
        case 9:
            cout << "Masa (kg): "; cin >> m;
            cout << "Altura (m): "; cin >> h;
            cout << "Energia Potencial = " << m * G_EARTH * h << " J" << endl;
            break;
        case 10:
            cout << "Fuerza (N): "; cin >> f;
            cout << "Distancia (m): "; cin >> d;
            cout << "Angulo (grados): "; cin >> theta;
            cout << "Trabajo = " << f * d * cos(toRadians(theta)) << " J" << endl;
            break;
        default: cout << "Opcion invalida." << endl;
    }
}

// ================= OSCILACIONES Y ONDAS =================
void menuOscilaciones() {
    int op;
    double T, f, lambda, k, x, m;
    
    cout << "\n--- OSCILACIONES Y ONDAS ---" << endl;
    cout << "1. Periodo (T = 1/f)" << endl;
    cout << "2. Frecuencia (f = 1/T)" << endl;
    cout << "3. Velocidad de onda (v = lambda * f)" << endl;
    cout << "4. Ley de Hooke (F = -kx)" << endl;
    cout << "5. Periodo Resorte (T = 2pi sqrt(m/k))" << endl;
    cout << "Elija ecuacion: ";
    cin >> op;

    switch(op) {
        case 1:
            cout << "Frecuencia (Hz): "; cin >> f;
            if(f!=0) cout << "Periodo = " << 1.0/f << " s" << endl;
            break;
        case 2:
            cout << "Periodo (s): "; cin >> T;
            if(T!=0) cout << "Frecuencia = " << 1.0/T << " Hz" << endl;
            break;
        case 3:
            cout << "Longitud de onda (m): "; cin >> lambda;
            cout << "Frecuencia (Hz): "; cin >> f;
            cout << "Velocidad de onda = " << lambda * f << " m/s" << endl;
            break;
        case 4:
            cout << "Constante del resorte k (N/m): "; cin >> k;
            cout << "Desplazamiento x (m): "; cin >> x;
            cout << "Fuerza Restitutiva = " << -k * x << " N" << endl;
            break;
        case 5:
            cout << "Masa (kg): "; cin >> m;
            cout << "Constante k (N/m): "; cin >> k;
            if(k>0) cout << "Periodo = " << 2 * PI * sqrt(m/k) << " s" << endl;
            else cout << "Error: k debe ser positivo." << endl;
            break;
        default: cout << "Opcion invalida." << endl;
    }
}

// ================= ELECTROMAGNETISMO =================
void menuElectromagnetismo() {
    int op;
    double q1, q2, r, F, q, W, V, I, R;

    cout << "\n--- ELECTROMAGNETISMO ---" << endl;
    cout << "1. Ley de Coulomb (F)" << endl;
    cout << "2. Campo Electrico (E)" << endl;
    cout << "3. Voltaje (V = W/q)" << endl;
    cout << "4. Ley de Ohm (V = IR)" << endl;
    cout << "5. Potencia Electrica (P = VI)" << endl;
    cout << "Elija ecuacion: ";
    cin >> op;

    switch(op) {
        case 1:
            cout << "Carga q1 (C): "; cin >> q1;
            cout << "Carga q2 (C): "; cin >> q2;
            cout << "Distancia r (m): "; cin >> r;
            if(r!=0) cout << "Fuerza = " << (K_COULOMB * q1 * q2) / pow(r, 2) << " N" << endl;
            break;
        case 2:
            cout << "Fuerza (N): "; cin >> F;
            cout << "Carga de prueba (C): "; cin >> q;
            if(q!=0) cout << "Campo Electrico = " << F/q << " N/C" << endl;
            break;
        case 3:
            cout << "Energia/Trabajo (J): "; cin >> W;
            cout << "Carga (C): "; cin >> q;
            if(q!=0) cout << "Voltaje = " << W/q << " V" << endl;
            break;
        case 4:
            cout << "Corriente (A): "; cin >> I;
            cout << "Resistencia (Ohm): "; cin >> R;
            cout << "Voltaje = " << I * R << " V" << endl;
            break;
        case 5:
            cout << "Voltaje (V): "; cin >> V;
            cout << "Corriente (A): "; cin >> I;
            cout << "Potencia = " << V * I << " W" << endl;
            break;
        default: cout << "Opcion invalida." << endl;
    }
}

// ================= TERMODINAMICA =================
void menuTermodinamica() {
    int op;
    double Q, W, m, c, Ti, Tf, P, V, n, T, Vi, Vf;

    cout << "\n--- TERMODINAMICA ---" << endl;
    cout << "1. 1ra Ley (Delta U = Q - W)" << endl;
    cout << "2. Calor Sensible (Q = mc DeltaT)" << endl;
    cout << "3. Gas Ideal (Calculo de Presion P = nRT/V)" << endl;
    cout << "4. Trabajo Termodinamico (W = P DeltaV)" << endl;
    cout << "5. Eficiencia Termica (n = W/Q)" << endl;
    cout << "Elija ecuacion: ";
    cin >> op;

    switch(op) {
        case 1:
            cout << "Calor Q (J): "; cin >> Q;
            cout << "Trabajo W (J): "; cin >> W;
            cout << "Cambio de Energia Interna = " << Q - W << " J" << endl;
            break;
        case 2:
            cout << "Masa (kg): "; cin >> m;
            cout << "Calor especifico c (J/kg*C): "; cin >> c;
            cout << "Temp. Final (C): "; cin >> Tf;
            cout << "Temp. Inicial (C): "; cin >> Ti;
            cout << "Calor Q = " << m * c * (Tf - Ti) << " J" << endl;
            break;
        case 3:
            cout << "Moles n: "; cin >> n;
            cout << "Temperatura T (Kelvin): "; cin >> T;
            cout << "Volumen V (m3): "; cin >> V;
            if(V!=0) cout << "Presion P = " << (n * R_GAS * T) / V << " Pa" << endl;
            else cout << "Error: Volumen cero." << endl;
            break;
        case 4:
            cout << "Presion P (Pa): "; cin >> P;
            cout << "Volumen Final (m3): "; cin >> Vf;
            cout << "Volumen Inicial (m3): "; cin >> Vi;
            cout << "Trabajo W = " << P * (Vf - Vi) << " J" << endl;
            break;
        case 5:
            cout << "Trabajo W (J): "; cin >> W;
            cout << "Calor absorbido Q (J): "; cin >> Q;
            if(Q!=0) cout << "Eficiencia = " << (W/Q) * 100.0 << " %" << endl;
            break;
        default: cout << "Opcion invalida." << endl;
    }
}

// ================= CONVERSIONES =================
void menuConversiones() {
    int op;
    double val;
    cout << "\n--- TABLA DE CONVERSIONES ---" << endl;
    cout << "1.  Pulgadas a cm" << endl;
    cout << "2.  Metros a pulgadas" << endl;
    cout << "3.  Pies a metros" << endl;
    cout << "4.  Metros a pies" << endl;
    cout << "5.  Libras a kg" << endl;
    cout << "6.  Kg a libras" << endl;
    cout << "7.  Lbf a Newtons" << endl;
    cout << "8.  Newtons a lbf" << endl;
    cout << "9.  BTU a Joules" << endl;
    cout << "10. Mph a m/s" << endl;
    cout << "11. Fahrenheit a Celsius" << endl;
    cout << "12. Celsius a Fahrenheit" << endl;
    cout << "13. Atm a Pascales" << endl;
    cout << "14. Atm a Psi" << endl;
    cout << "Elija conversion: ";
    cin >> op;

    if (op >= 1 && op <= 14) {
        cout << "Ingrese valor a convertir: ";
        cin >> val;
    }

    switch(op) {
        case 1:  cout << val << " in = " << val * 2.54 << " cm" << endl; break;
        case 2:  cout << val << " m = " << val * 39.37 << " in" << endl; break;
        case 3:  cout << val << " ft = " << val * 0.3048 << " m" << endl; break;
        case 4:  cout << val << " m = " << val * 3.28 << " ft" << endl; break;
        case 5:  cout << val << " lb = " << val * 0.4536 << " kg" << endl; break;
        case 6:  cout << val << " kg = " << val * 2.205 << " lb" << endl; break;
        case 7:  cout << val << " lbf = " << val * 4.448 << " N" << endl; break;
        case 8:  cout << val << " N = " << val * 0.225 << " lbf" << endl; break;
        case 9:  cout << val << " BTU = " << val * 1055.0 << " J" << endl; break;
        case 10: cout << val << " mph = " << val * 0.447 << " m/s" << endl; break;
        case 11: cout << val << " F = " << (val - 32) * 5.0/9.0 << " C" << endl; break;
        case 12: cout << val << " C = " << (val * 9.0/5.0) + 32 << " F" << endl; break;
        case 13: cout << val << " atm = " << val * 101325.0 << " Pa" << endl; break;
        case 14: cout << val << " atm = " << val * 14.7 << " psi" << endl; break;
        default: cout << "Opcion no valida" << endl;
    }
}
