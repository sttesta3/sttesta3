# TP1 - AYP2 (75.14 / 95.15) - Curso Juarez
- "El inventario de James"
- Autor: Testa Santiago Tomas ( 108.301 - 43.853.430 )
##  AVISO SOBRE TEST
- Se adapto tests/VectorTests.cpp para que utilice el template de Vector (TESTS OK)
## Aclaraciones
- Para interactuar con el menu solo se tomarán las palabras ALTA, BAJA, CONSULTA (en mayusculas)
- Se acepta cualquier nombre de item. Pero solo se aceptan tipos CURATIVO, PUZZLE, MUNICION
- Se acepta input de usuario con espacios (ej. "liquido desconocido" es un nombre de item válido)
- Ruta predefinida para archivo de carga/guardado ubicada al inicio de include/Menu.hpp. Si no existe pregunta al usuario si decide cargar/guardar y solicita dicho archivo. 
- Si intentamos cargar un archivo de mas de 15 lineas, solo se cargaran los items de las primeras quince lineas. El resto del archivo se descartará (avisando al usuario)