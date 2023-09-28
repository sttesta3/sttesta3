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


template <typename Item>
class Vector {
private:
    Item** datos;
    size_t cantidadDatos;
    size_t tamanioMaximo;

    void crecer(void);
    void reducir(void);

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

template <typename Item>
void Vector<Item>::crecer(){
    size_t nuevo_tamanio = (this->tamanioMaximo == 0) ? 1 : 2 * this->tamanioMaximo;
    Item** nuevo_vector = new Item* [ nuevo_tamanio ];

    // COPIAR ELEMENTOS. SETEAR A NULL LOS DEMAS
    for (size_t i = 0; i < this->tamanioMaximo; i++)
        nuevo_vector[i] = this->datos[i];
    for (size_t i = this->tamanioMaximo; i < nuevo_tamanio; i++)
        nuevo_vector[i] = nullptr;
    
    // Si existe vector original, eliminalo
    if (this->tamanioMaximo != 0)
        delete [] this->datos;

    this->datos = nuevo_vector;
    this->tamanioMaximo = nuevo_tamanio;
}

template <typename Item>
void Vector<Item>::reducir(){
    size_t nuevo_tamanio = (this->tamanioMaximo == 1) ? 0 : this->tamanioMaximo / 2 ;
    Item** nuevo_vector = nullptr;
    
    if (nuevo_tamanio != 0)
        nuevo_vector = new Item* [ nuevo_tamanio ];

    // COPIAR ELEMENTOS hasta la mitad
    for (size_t i = 0; i < nuevo_tamanio; i++)
        nuevo_vector[i] = this->datos[i];

    delete [] this->datos;

    this->datos = nuevo_vector;
    this->tamanioMaximo = nuevo_tamanio;
}

template <typename Item>
Vector<Item>::Vector(){
    this->tamanioMaximo = 0;
    this->cantidadDatos = 0;
    this->datos = nullptr;
}

template <typename Item> 
void Vector<Item>::alta(Item* dato, size_t indice){
    //EXCEPCIONES
    if (indice < 0 || indice > this->cantidadDatos)
        throw VectorException();
    
    // CODIGO DE IMPLEMENTACION
    // SI ES NECESARIO, AGRANDAR VECTOR 
    if ( this->cantidadDatos == this->tamanioMaximo )
        this->crecer();

    // DESPLAZAR LOS VECTORES PARA DEJAR INDICE LIBRE
    for (size_t i = this->cantidadDatos; i > indice; i--)
        this->datos[i] = this->datos[i - 1];

    this->datos[indice] = dato;
    this->cantidadDatos += 1;
}

template <typename Item> 
void Vector<Item>::alta(Item* dato){
    return this->alta(dato, this->cantidadDatos);
}

template <typename Item>
Item* Vector<Item>::baja(size_t indice){
    // EXCEPCIONES 
    if (this->cantidadDatos == 0)
        throw VectorException();
    else if (indice < 0 || indice >= this->cantidadDatos)
        throw VectorException();

    Item* resultado = this->datos[indice];
    for (size_t i = indice; i < this->cantidadDatos - 1; i++)
        this->datos[i] = this->datos[i + 1];
    this->datos[this->cantidadDatos - 1] = nullptr;

    this->cantidadDatos -= 1;

    // Si es necesario, reducir el vector 
    if ((this->cantidadDatos * 2 == this->tamanioMaximo) || this->cantidadDatos == 0) 
        this->reducir();
    
    return resultado;
}

template <typename Item>
Item* Vector<Item>::baja(){
    return this->baja(this->cantidadDatos - 1);
}

template <typename Item>
bool Vector<Item>::vacio(){
    return (this->cantidadDatos == 0);
}

template <typename Item>
size_t Vector<Item>::tamanio(){
    return this->cantidadDatos;
}

template <typename Item>
Item*&  Vector<Item>::operator[](size_t indice){
    if (indice < 0 || indice >= this->cantidadDatos)
        throw VectorException();
    return this->datos[indice];
}

template <typename Item>
Vector<Item>::~Vector(){
    while (this->cantidadDatos > 0){
        this->baja();
    }
}

#endif