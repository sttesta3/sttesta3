#include "Vector.hpp"

class Menu {
    private:
        Vector inventario;
        std::string ruta_archivo_entrada = "";
        std::string ruta_archivo_salida = "";
        size_t TAMAÑO_MAXIMO = 15;

        // METODOS DE MANEJO DE ARCHIVOS
        bool CargarArchivo();
        bool GuardarArchivo();

        void SolicitarRutaArchivoEntrada(void);
        bool SolicitarRutaArchivoSalida(void);



    public:
        Menu();
        ~Menu();

        void Juego(void);

};
