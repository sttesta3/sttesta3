#ifndef MENU_H
#define MENU_H

#include <fstream>
#include <iostream>
#include <string.h>
#include "Vector.hpp"

class Menu {
    private:
        Vector inventario;
        std::string ruta_archivo_entrada = "";
        std::string ruta_archivo_salida = "";
        std::string entrada_usuario = "";

        // Pre:
        // Post: Devuelve un size_t segun la entrada del usuario
        size_t AnalizarEntradaUsuario();

        // Pre: 
        // Post: Imprime mensaje y solicita input, guardando el mismo en this->entrada_usuario
       void SolicitarEntradaUsuario(std::string mensaje);
        // METODOS DE INTERACCIÓN CON INVENTARIO

        // Pre:
        // Post: Solicita entrada y carga en inventario
        void Alta();
        // Pre:
        // Post: Solicita entrada y elimina primer aparicion en inventario
        void Baja();
        // Pre:
        // Post: Imprime inventario
        void Consulta();

        // METODOS DE MANEJO DE ARCHIVOS

        // Pre:
        // Post: Carga archivo en inventario del menu
        void CargarArchivo();
        // Pre:
        // Post: Guarda archivo de partida
        void GuardarArchivo();

        // Pre:
        // Post: Guarda en variable del menu el nombre del archivo. Si no existe devuelve false
        bool SolicitarRutaArchivoEntrada(void);
        // Pre:
        // Post: Guarda en variable del menu el nombre del archivo. Si no existe devuelve false
        bool SolicitarRutaArchivoSalida(void);

    public:
        Menu();
        ~Menu();

        // Pre:
        // Post: Corre el juego completo 
        void Juego(void);

};

#endif // MENU_H
