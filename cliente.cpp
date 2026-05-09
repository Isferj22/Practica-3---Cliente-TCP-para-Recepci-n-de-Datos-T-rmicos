#include <iostream>
#include <vector>
#include <arpa/inet.h> // Librería para funciones de red (sockets, conversion de IPs)
#include <unistd.h>    // Librería para funciones del sistema (close)
#include <fstream>     // Librería para manejo de archivos

// Definimos el espacio de nombres estándar para evitar usar 'std::' constantemente
using namespace std;

#define NUM_DATOS 192
#define PUERTO 12345

/**
 * Crea un socket TCP.
 * AF_INET: Indica el dominio de direcciones IPv4.
 * SOCK_STREAM: Indica que el protocolo será orientado a conexión (TCP).
 */
int crearSocket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        cerr << "Error al crear el socket." << endl;
        exit(1);
    }

    cout << "Socket creado correctamente." << endl;
    return sockfd;
}

/**
 * Configura la estructura de dirección del servidor.
 * htons: Convierte el número de puerto de formato "host" a "network byte order".
 * inet_pton: Convierte la dirección IP de texto (string) a formato binario de red.
 */
void configurarServidor(sockaddr_in &servaddr) {
    servaddr.sin_family = AF_INET;       // Protocolo IPv4
    servaddr.sin_port = htons(PUERTO);   // Puerto configurado en formato de red

    // Intentamos asignar la IP local 127.0.0.1 (localhost)
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        cerr << "Direccion IP invalida." << endl;
        exit(1);
    }
}

/**
 * Intenta establecer la conexión con el servidor.
 * El socket pasa de estado cerrado a establecido si el servidor acepta la petición.
 */
void conectarServidor(int sockfd, sockaddr_in &servaddr) {
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        cerr << "Error al conectar con el servidor." << endl;
        exit(1);
    }

    cout << "Conexion establecida con el servidor" << endl;
}

/**
 * Recibe datos del servidor de forma iterativa.
 * recv: Lee bytes del socket. Mientras devuelva un valor > 0, significa que hay datos.
 * Guardamos cada 'float' recibido en un vector dinámico.
 */
vector<float> recibirDatos(int sockfd) {
    vector<float> datos;
    float buffer;

    // Leemos del socket el tamaño exacto de un float en cada iteración
    while (recv(sockfd, &buffer, sizeof(buffer), 0) > 0) {
        datos.push_back(buffer);
    }

    return datos;
}

/**
 * Crea un flujo de salida para guardar los datos en un archivo de texto.
 * Cada valor del vector se escribe en una línea nueva.
 */
void guardarDatos(const vector<float>& datos) {
    ofstream archivo("salida.txt");

    if (!archivo.is_open()) {
        cerr << "Error al crear archivo." << endl;
        return;
    }

    // Recorremos el vector usando un bucle 'range-based'
    for (float t : datos) {
        archivo << t << endl;
    }

    archivo.close(); // Cerramos el flujo para asegurar que se escriban los datos
    cout << "Datos guardados correctamente en el archivo: salida.txt" << endl;
}

/**
 * Muestra por consola todos los elementos almacenados en el vector.
 */
void imprimirDatos(const vector<float>& datos) {
    cout << "\nNumeros de punto flotante recibidos:\n" << endl;

    for (float t : datos) {
        cout << t << endl;
    }
}

/**
 * Función principal que orquestra el flujo del cliente:
 * 1. Inicialización -> 2. Conexión -> 3. Recepción -> 4. Almacenamiento -> 5. Cierre
 */
int main() {
    cout << "=== INICIANDO CLIENTE DE TEMPERATURA ===" << endl;

    // 1. Crear el punto de comunicación (socket)
    int sockfd = crearSocket();

    // 2. Definir a qué servidor nos queremos conectar
    sockaddr_in servaddr;
    configurarServidor(servaddr);

    // 3. Realizar el 'handshake' de conexión
    conectarServidor(sockfd, servaddr);

    // 4. Capturar el flujo de datos entrante
    vector<float> datos = recibirDatos(sockfd);

    cout << "Se han recibido " << datos.size() << " datos de temperatura correctamente." << endl;

    // 5. Procesar los datos (Archivo y Consola)
    guardarDatos(datos);
    imprimirDatos(datos);

    // 6. Liberar el recurso del socket al finalizar
    close(sockfd);

    return 0;
}
