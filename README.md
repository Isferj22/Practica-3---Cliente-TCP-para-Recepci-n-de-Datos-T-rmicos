# Práctica 3 - Cliente TCP para Recepción de Datos Térmicos

## Introducción

Esta práctica consiste en desarrollar un cliente TCP en C++ capaz de conectarse a un servidor Python que simula una cámara térmica. El cliente recibe datos de temperatura en formato de punto flotante (`float`) a través de sockets TCP/IP y los procesa mostrando la información recibida por terminal y almacenándola en un archivo de salida.

---

# Descripción del problema

El objetivo principal de la práctica es implementar una comunicación cliente-servidor mediante sockets utilizando TCP/IP.

El servidor (`ServidorCamara.py`) actúa como una cámara térmica simulada que envía datos de temperatura al cliente. El cliente debe:

- Crear un socket TCP.
- Conectarse al servidor.
- Recibir los datos enviados.
- Interpretar los datos como números de punto flotante (`float`).
- Mostrar los datos recibidos por pantalla.
- Guardar los datos en un archivo de salida (`salida.txt`).
- Gestionar posibles errores de conexión.

La práctica permite comprender el funcionamiento básico de las comunicaciones en red mediante sockets y el intercambio de datos binarios entre aplicaciones escritas en distintos lenguajes.

---

# Estructura del proyecto

El proyecto está compuesto por los siguientes archivos:

Practica_3/
│
├── ServidorCamara.py
├── cliente.cpp
├── ejecutar.sh
├── salida.txt
└── README.md

# Descripcion de archivos

- ServidorCamara.py: Servidor TCP encargado de generar y enviar datos térmicos simulados
- cliente.cpp: Cliente TCP implementado en C++ que recibe y procesa los datos enviados por el servidor
- ejecutar.sh: Script Bash utilizado para compilar y ejecutar automáticamente el cliente
- salida.txt: Archivo generado automáticamente donde se almacenan los datos recibidos
- README.md: Documento descriptivo del proyecto y guía de uso

# Requisitos del sistema

Para ejecutar correctamente la práctica se necesita:

- Sistema operativo Linux o WSL (Windows Subsystem for Linux)
- Compilador g++
- Python 3
- Terminal compatible con Bash

Instalacion:
1- Actualizar paquetes:
    sudo apt update
2- Instalar compilador y Python:
    sudo apt install g++ python3

Permisos necesarios:
- Dar permisos de ejecucion al script de bash: chmod +x ejecutar.sh

# Ejecucion de la practica

1- Ejecutar el servidor: python3 ServidorCamara.py
2- Dar permisos al script: chmod +x ejecutar.sh
3- Ejecutar el cliente (en otra terminal sin cerrar la anterior): /ejecutar.sh

# Funcionamiento

El funcionamiento del sistema es el siguiente:

1- El servidor Python crea un socket TCP y queda escuchando conexiones entrantes
2- El cliente C++ crea su propio socket TCP
3- El cliente se conecta al servidor mediante la dirección IP 127.0.0.1 y el puerto 12345
4- El servidor envía datos térmicos simulados en formato float
5- El cliente recibe los datos y los almacena en un vector dinámico
6- Los datos recibidos se muestran por pantalla
7- Finalmente, los datos se guardan en el archivo salida.txt

# Resultado esperado

Al ejecutar correctamente la practica debe mostrar una salida similar a:

Socket creado correctamente.
Conexion establecida con el servidor.
Se han recibido 192 datos de temperatura correctamente.

Numeros de punto flotante recibidos:

3.82047e-37
1.00825e-34
2.65846e-32
...

Ademas, se generara automaticamente el archivo: salida.txt, conteniendo todos los datos reciidos

# Autor
Ismael Fernandez Jorreto
