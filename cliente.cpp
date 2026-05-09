#include <iostream>
#include <vector>
#include <arpa/inet.h>
#include <unistd.h>
#include <fstream>

#define NUM_DATOS 192
#define PUERTO 12345

// Crear socket
int crearSocket() {

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {

        std::cerr << "Error al crear el socket." << std::endl;
        exit(1);
    }

    std::cout << "Socket creado correctamente." << std::endl;

    return sockfd;
}

// Configurar servidor
void configurarServidor(sockaddr_in &servaddr) {

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PUERTO);

    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {

        std::cerr << "Direccion IP invalida." << std::endl;
        exit(1);
    }
}

// Conectar servidor
void conectarServidor(int sockfd, sockaddr_in &servaddr) {

    if (connect(sockfd,
                (struct sockaddr*)&servaddr,
                sizeof(servaddr)) == -1) {

        std::cerr << "Error al conectar con el servidor." << std::endl;
        exit(1);
    }

    std::cout << "Conexion establecida con el servidor" << std::endl;
}

// Recibir datos float
std::vector<float> recibirDatos(int sockfd) {

    std::vector<float> datos;

    float buffer;

    while (recv(sockfd, &buffer, sizeof(buffer), 0) > 0) {

        datos.push_back(buffer);
    }

    return datos;
}

// Guardar archivo
void guardarDatos(const std::vector<float>& datos) {

    std::ofstream archivo("salida.txt");

    if (!archivo.is_open()) {

        std::cerr << "Error al crear archivo." << std::endl;
        return;
    }

    for (float t : datos) {

        archivo << t << std::endl;
    }

    archivo.close();

    std::cout << "Datos guardados correctamente en el archivo: salida.txt"
              << std::endl;
}

// Imprimir datos
void imprimirDatos(const std::vector<float>& datos) {

    std::cout << "\nNumeros de punto flotante recibidos:\n"
              << std::endl;

    for (float t : datos) {

        std::cout << t << std::endl;
    }
}

// MAIN
int main() {

    std::cout << "=== INICIANDO CLIENTE DE TEMPERATURA ==="
              << std::endl;

    // Crear socket
    int sockfd = crearSocket();

    // Configurar servidor
    sockaddr_in servaddr;
    configurarServidor(servaddr);

    // Conectar
    conectarServidor(sockfd, servaddr);

    // Recibir datos
    std::vector<float> datos = recibirDatos(sockfd);

    std::cout << "Se han recibido "
              << datos.size()
              << " datos de temperatura correctamente."
              << std::endl;

    // Guardar archivo
    guardarDatos(datos);

    // Mostrar datos
    imprimirDatos(datos);

    // Cerrar socket
    close(sockfd);

    return 0;
}
