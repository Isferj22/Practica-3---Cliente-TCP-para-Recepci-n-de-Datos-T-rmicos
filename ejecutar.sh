#!/bin/bash
# La línea anterior (shebang) indica al sistema que este archivo debe ejecutarse usando el intérprete Bash.

# Compilación:
# g++: Invoca al compilador de C++.
# cliente.cpp: Es el archivo fuente que contiene el código que acabamos de comentar.
# -o cliente: Indica el nombre del archivo ejecutable resultante (en este caso, "cliente").
g++ cliente.cpp -o cliente

# Ejecución:
# ./cliente: Ejecuta el programa binario recién compilado que se encuentra en el directorio actual.
./cliente
