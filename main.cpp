#include <iostream>
#include "laboratorio.h"

using namespace std;

int main()
{

    Laboratorio laboratorio;
    string op;

    while (true)
    {
        cout << "1) Agregar Computadora" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Respaldar" << endl;
        cout << "4) Recuperar" << endl;
        cout << "5) Insertar" << endl;
        cout << "6) Inicializar" << endl;
        cout << "7) Eliminar" << endl;
        cout << "8) Ordenar" << endl;
        cout << "9) Buscar" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1")
        {
            Computadora c;
            cin >> c;

            laboratorio.agregarFinal(c);
            cin.ignore();
        }
        else if (op == "2")
        {
            laboratorio.mostrar();
        }
        else if (op == "3")
        {
            laboratorio.respaldar();
        }
        else if (op == "4")
        {
            laboratorio.recuperar();
        }
        else if (op == "5")
        {
            Computadora c;
            cin >> c;

            size_t pos;
            cout << "Posición: ";
            cin >> pos;
            cin.ignore();

            if (pos >= laboratorio.size())
            {
                cout << "Posición no válida" << endl;
            }
            else
            {
                laboratorio.insertar(pos, c);
            }
        }
        else if (op == "6")
        {
            Computadora c;
            cin >> c;

            size_t n;
            cout << "n: ";
            cin >> n;
            cin.ignore();

            laboratorio.inicializar(n, c);
        }
        else if (op == "7")
        {
            size_t pos;
            cout << "Posición: ";
            cin >> pos;
            cin.ignore();

            if (pos >= laboratorio.size())
            {
                cout << "Posición no válida" << endl;
            }
            else
            {
                laboratorio.eliminar(pos);
            }
        }
        else if (op == "8")
        {
            laboratorio.ordenar();
        }
        else if (op == "9")
        {
            Computadora c;
            cin >> c;
            cin.ignore();

            Computadora *ptr = laboratorio.buscar(c);

            if (ptr == nullptr)
            {
                cout << "No encontrado" << endl;
            }
            else
            {
                cout << *ptr << endl;
            }
        }

        else if (op == "0")
        {
            break;
        }
    }

    return 0;
}