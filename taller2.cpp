#include <iostream>
#include <string>
#include <malloc.h>

struct nodo {
    int numerotelefono;
    std::string name;
    nodo* next;
};

void push(nodo*& top, int numerotelefono, const std::string& name) {
    bool exists = false;

    nodo* current = top;
    while (current != nullptr) {
        if (current->numerotelefono == numerotelefono) {
            exists = true;
            break;
        }
        current = current->next;
    }

    if (!exists) {
        nodo* newnodo = (nodo*)malloc(sizeof(nodo));
        newnodo->numerotelefono = numerotelefono;
        newnodo->name = name;
        newnodo->next = top;
        top = newnodo;
    } else {
        std::cout << "El número de teléfono ya existe en la agenda." << std::endl;
    }
}

void viewer(const nodo* top) {
    const nodo* current = top;
    while (current != nullptr) {
        std::cout << "Numero telefono: " << current->numerotelefono << " - Name: " << current->name << std::endl;
        current = current->next;
    }
}

void pop(nodo*& top) {
    if (top != nullptr) {
        nodo* temp = top;
        top = top->next;
        free(temp);
    } else {
        std::cout << "La agenda de llamadas está vacía." << std::endl;
    }
}

int main() {
    nodo* top = nullptr;
    int choice;
    int numerotelefono;
    std::string name;

    do {
        std::cout << "1. Registrar un número de teléfono." << std::endl;
        std::cout << "2. Mostrar la lista de llamadas realizadas." << std::endl;
        std::cout << "3. Eliminar la última llamada realizada." << std::endl;
        std::cout << "4. Salir." << std::endl;
        std::cout << "Seleccione una opción: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Ingrese el número de teléfono: ";
                std::cin >> numerotelefono;
                std::cout << "Ingrese el nombre del contacto: ";
                std::cin >> name;
                push(top, numerotelefono, name);
                break;
            case 2:
                viewer(top);
                break;
            case 3:
                pop(top);
                break;
            case 4:
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cout << "Opción no válida." << std::endl;
                break;
        }
    } while (choice != 4);

  
    while (top != nullptr) {
        pop(top);
    }

    return 0;
}