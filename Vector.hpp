#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <exception>
#include "Item.hpp"

class VectorException : public std::exception {
    // Excepcion especifica y exclusivamente para errores dentro del VectorTemplate.
    // Usar de la forma "throw VectorException();" cuando una precondicion no se cumpla.

    // Ejemplo:
    //     if (condicion_de_error()){
    //         throw VectorException();
    //     }
};

class Vector {
private:
    Item** datos;
    size_t cantidadDatos;
    size_t tamanioMaximo;
public:
    // Constructor.
    Vector();

    // Pre: -
    // Post: Agrega el dato al final del vector.
    void alta(Item* dato);

    // Pre: El indice debe ser menor o igual que la cantidad de datos.
    // Post: Agrega el dato antes del dato en la posicion indicada, moviendo todos los elementos siguientes. Si el
    // indice es igual a la cantidad de datos, simplemente agrega al final.
    void alta(Item* dato, size_t indice);

    // Pre: El vector no puede estar vacio.
    // Post: Elimina el ultimo dato.
    Item* baja();

    // Pre: El vector no puede estar vacio. El indice debe ser menor que la cantidad de datos.
    // Post: Elimina el dato en la posicion indicada, moviendo todos los elementos siguientes. Si el indice es igual a
    // la cantidad de datos - 1, simplemente elimina el ultimo dato.
    Item* baja(size_t indice);

    // Pre: -
    // Post: Devuelve true si el vector esta vacio (es decir, si no hay datos).
    bool vacio();

    // Pre: -
    // Post: Devuelve la cantidad de datos del vector.
    size_t tamanio();

    // Pre: El vector no puede estar vacio. El indice debe ser menor que la cantidad de datos.
    // Post: Devuelve una referencia al dato deseado.
    Item*& operator[](size_t indice);

    // Destructor.
    ~Vector();
};

#endif