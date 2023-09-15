#include "Vector.hpp"


Vector::Vector(){
    this->tamanioMaximo = 0;
    this->cantidadDatos = 0;
}


bool
Vector::vacio(){
    return (this->cantidadDatos == 0);
}

Vector::~Vector(){
    while (this->cantidadDatos > 0)
        this->baja();
}
