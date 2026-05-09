# Práctica 3 - Cliente TCP para Recepción de Datos Térmicos

## Introducción
Esta práctica consiste en desarrollar un cliente TCP en C++ capaz de conectarse a un servidor Python que simula una cámara térmica. El cliente recibe datos de temperatura en formato de punto flotante (`float`) a través de sockets TCP/IP, procesa la información y la almacena en un archivo de salida.

---

## Descripción del problema
El objetivo principal es implementar una comunicación cliente-servidor mediante sockets utilizando TCP/IP.

El servidor (`ServidorCamara.py`) actúa como una cámara térmica simulada. El cliente debe realizar las siguientes tareas:
* Crear un socket TCP y conectarse al servidor.
* Recibir e interpretar los datos como `float`.
* Mostrar los resultados por pantalla.
* Guardar la información en `salida.txt`.
* Gestionar posibles errores de conexión.

---

## Estructura del proyecto
```text
Practica_3/
│
├── ServidorCamara.py   # Servidor TCP (simulador térmico)
├── cliente.cpp         # Cliente TCP en C++
├── ejecutar.sh         # Script de compilación y ejecución
├── salida.txt          # Archivo de datos recibidos
└── README.md           # Documentación del proyecto
```

---

## Requisitos del sistema
Para ejecutar la práctica se necesita:
* Sistema operativo Linux o WSL (Windows Subsystem for Linux).
* Compilador g++.
* Python 3.
* Terminal compatible con Bash.

### Instalación
```bash
sudo apt update
sudo apt install g++ python3
```

---

## Ejecución

1. **Dar permisos al script:**
   ```bash
   chmod +x ejecutar.sh
   ```

2. **Lanzar el servidor:** (En una terminal)
   ```bash
   python3 ServidorCamara.py
   ```

3. **Ejecutar el cliente:** (En otra terminal)
   ```bash
   ./ejecutar.sh
   ```

---

## Funcionamiento
1. El servidor Python escucha conexiones en la dirección IP 127.0.0.1 y el puerto 12345.
2. El cliente C++ solicita la conexión al servidor.
3. El servidor envía los datos térmicos simulados en formato binario.
4. El cliente recibe los datos, los interpreta como tipo float y los almacena en un vector dinámico.
5. Finalmente, los datos se muestran por terminal y se vuelcan en el archivo salida.txt.

---

## Resultado esperado
Al ejecutar el cliente, se mostrará una salida similar a la siguiente:

```bash
Socket creado correctamente.
Conexion establecida con el servidor.
Se han recibido 192 datos de temperatura correctamente.

Numeros de punto flotante recibidos:
3.82047e-37
1.00825e-34
...
```

---

## Autor
* Ismael Fernández Jorreto
