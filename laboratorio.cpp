#include "laboratorio.h"

using namespace std;

Laboratorio::Laboratorio() {}

void Laboratorio::agregarFinal(const Computadora &c)
{
    computadoras.push_back(c);
}

void Laboratorio::mostrar()
{
    cout << left;
    cout << setw(20) << "Sistema operativo";
    cout << setw(24) << "CPU";
    cout << setw(10) << "RAM(GB)";
    cout << setw(8) << "Almacenamiento(GB)";
    cout << endl;
    for (size_t i = 0; i < computadoras.size(); i++)
    {
        Computadora &c = computadoras[i];
        cout << c;
    }
}

void Laboratorio::respaldar()
{
    ofstream archivo("laboratorio.txt");
    if (archivo.is_open())
    {
        for (size_t i = 0; i < computadoras.size(); i++)
        {
            Computadora &c = computadoras[i];
            archivo << c.getSO() << endl;
            archivo << c.getCPU() << endl;
            archivo << c.getRAM() << endl;
            archivo << c.getAlmacenamiento() << endl;
        }
    }
    archivo.close();
}

void Laboratorio::respaldar_tabla()
{
    ofstream archivo("laboratorio_tabla.txt");
    if (archivo.is_open())
    {
        archivo << left;
        archivo << setw(20) << "Sistema operativo";
        archivo << setw(24) << "CPU";
        archivo << setw(10) << "RAM(GB)";
        archivo << setw(8) << "Almacenamiento(GB)";
        archivo << endl;
        for (size_t i = 0; i < computadoras.size(); i++)
        {
            Computadora &c = computadoras[i];
            archivo << c;
        }
    }
    archivo.close();
}

void Laboratorio::recuperar()
{
    ifstream archivo("laboratorio.txt");

    if (archivo.is_open())
    {
        string myStr;
        Computadora c;
        while (!archivo.eof())
        {
            getline(archivo, myStr);
            if (archivo.eof())
            {
                break;
            }
            c.setSO(myStr);

            getline(archivo, myStr);
            c.setCPU(myStr);

            getline(archivo, myStr);
            c.setRAM(stof(myStr));

            getline(archivo, myStr);
            c.setAlmacenamiento(stof(myStr));

            agregarFinal(c);
        }
    }
    archivo.close();
}

Laboratorio &operator<<(Laboratorio &l, const Computadora &c)
{
    l.agregarFinal(c);

    return l;
}

void Laboratorio::insertar(size_t pos, const Computadora &c)
{
    computadoras.insert(computadoras.begin() + pos, c);
}

void Laboratorio::inicializar(size_t n, const Computadora &c)
{
    computadoras = vector<Computadora>(n, c);
}

void Laboratorio::eliminar(size_t pos)
{
    computadoras.erase(computadoras.begin() + pos);
}

size_t Laboratorio::size() const
{
    return computadoras.size();
}

void Laboratorio::ordenar()
{
    sort(computadoras.begin(), computadoras.end());
}

void Laboratorio::eliminarFinal()
{
    computadoras.pop_back();
}

Computadora *Laboratorio::buscar(const Computadora &c)
{
    auto it = find(computadoras.begin(), computadoras.end(), c);

    if (it == computadoras.end())
    {
        return nullptr;
    }
    else
    {
        return &(*it);
    }
}