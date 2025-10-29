#include <iostream>
#include "DrzewoBST.h"

int main() {
    DrzewoBST mojeDrzewo;

    std::cout << "Dodaje elementy: 10, 5, 15, 3, 7, 20" << std::endl;
    mojeDrzewo.dodajElement(10);
    mojeDrzewo.dodajElement(5);
    mojeDrzewo.dodajElement(15);
    mojeDrzewo.dodajElement(3);
    mojeDrzewo.dodajElement(7);
    mojeDrzewo.dodajElement(20);

    mojeDrzewo.wyswietlInorder();  // Oczekiwany wynik: 3 5 7 10 15 20
    mojeDrzewo.wyswietlPreorder(); // Oczekiwany wynik: 10 5 3 7 15 20
    mojeDrzewo.wyswietlPostorder();// Oczekiwany wynik: 3 7 5 20 15 10

    return 0;
}