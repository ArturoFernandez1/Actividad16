#ifndef LABORATORIO_H
#define LABORATORIO_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "computadora.h"

class Laboratorio
{
private:
    std::vector<Computadora> computadoras;

public:
    Laboratorio();
    void agregarFinal(const Computadora &c);
    void mostrar();
    void respaldar();
    void respaldar_tabla();
    void recuperar();
    friend Laboratorio &operator<<(Laboratorio &l, const Computadora &c);

    void insertar(size_t pos, const Computadora &c);
    void inicializar(size_t n, const Computadora &c);
    void eliminar(size_t pos);
    size_t size() const;
    void ordenar();
    void eliminarFinal();
    Computadora *buscar(const Computadora &c);
};

#endif