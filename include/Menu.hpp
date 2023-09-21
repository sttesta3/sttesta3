#ifndef MENU_H
#define MENU_H

#include "Vector.hpp"

class Menu {
    private:
        Vector inventario;
        std::string ruta_archivo_entrada = "";
        std::string ruta_archivo_salida = "";
        std::string entrada_usuario = "";

        size_t TAMAÑO_MAXIMO = 15;


        size_t AnalizarEntradaUsuario();

        // METODOS DE INTERACCIÓN CON INVENTARIO
        void Alta();
        void Baja();
        void Consulta();

        // METODOS DE MANEJO DE ARCHIVOS
        void CargarArchivo();
        void GuardarArchivo();

        bool SolicitarRutaArchivoEntrada(void);
        bool SolicitarRutaArchivoSalida(void);

        
    public:
        Menu();
        ~Menu();

        void Juego(void);

};

#endif // MENU_H
