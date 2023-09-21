#include "Vector.hpp"


Vector::Vector(){
    this->tamanioMaximo = 0;
    this->cantidadDatos = 0;
    this->datos = nullptr;
}

void 
Vector::crecer(void){
//    std::cout << "DEBUG: por crecer vector" << std::endl;
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

void 
Vector::reducir(void){
//    std::cout << "DEBUG: POR REDUCIR VECTOR" << std::endl;
    size_t nuevo_tamanio = (this->tamanioMaximo == 1) ? 0 : this->tamanioMaximo / 2 ;
    Item** nuevo_vector = nullptr;
    
    if (nuevo_tamanio != 0)
        nuevo_vector = new Item* [ this->tamanioMaximo / 2 ];

    // COPIAR ELEMENTOS hasta la mitad
    for (size_t i = 0; i < nuevo_tamanio; i++)
        nuevo_vector[i] = this->datos[i];

    delete [] this->datos;

    this->datos = nuevo_vector;
    this->tamanioMaximo = nuevo_tamanio;
}

void
Vector::alta(Item* dato){
    this->alta(dato, this->cantidadDatos);
}

void
Vector::alta(Item* dato, size_t indice){
    // SI ES NECESARIO, AGRANDAR VECTOR 
    if (this->cantidadDatos == this->tamanioMaximo)
        this->crecer();

    // DESPLAZAR LOS VECTORES PARA DEJAR INDICE LIBRE
    for (size_t i = this->cantidadDatos; i > indice; i--)
        this->datos[i] = this->datos[i - 1];

    this->datos[indice] = dato;
    this->cantidadDatos += 1;

//    std::cout << "DEBUG dato cargado en DIR: " << this->datos[indice] << std::endl;
//    this->datos[indice]->listarInformacion(); std::cout << std::endl;
}   

Item*
Vector::baja(){
    return this->baja(this->cantidadDatos - 1);
}

Item* 
Vector::baja(size_t indice){
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

bool
Vector::vacio(){
    return (this->cantidadDatos == 0);
}

size_t 
Vector::tamanio(){
    return this->cantidadDatos;
}

Item*& 
Vector::operator[](size_t indice){
    return this->datos[indice];
}

Vector::~Vector(){
    while (this->cantidadDatos > 0){
        this->baja();
    }
}

