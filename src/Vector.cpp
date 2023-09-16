#include "Vector.hpp"


Vector::Vector(){
    this->tamanioMaximo = 0;
    this->cantidadDatos = 0;
}

void
Vector::alta(Item* dato){
    
    if (this->cantidadDatos == this->tamanioMaximo){
        //    this->crecer();
    }

    // Creamos nueva caja y asignamos valor 
    this->datos[this->cantidadDatos] = new Item;
    this->datos[this->cantidadDatos] = dato;

    this->cantidadDatos += 1;
}

void
Vector::alta(Item* dato, size_t indice){

}

Item* 
Vector::baja(size_t indice){

}

Item*
Vector::baja(){

}

bool
Vector::vacio(){
    return (this->cantidadDatos == 0);
}

size_t 
Vector::tamanio(){
    return this->cantidadDatos;
}

Vector::~Vector(){
    while (this->cantidadDatos > 0)
        this->baja();
}
