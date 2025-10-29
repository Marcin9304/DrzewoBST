/**
 * @file DrzewoBST.cpp
 * @brief Plik Ÿród³owy z implementacj¹ metod klasy DrzewoBST.
 */

#include "DrzewoBST.h"
#include <iostream>

 // --- Konstruktor i Destruktor ---

DrzewoBST::DrzewoBST() {
    korzen = nullptr; // Na pocz¹tku drzewo jest puste, wiêc korzeñ wskazuje na nic.
}

DrzewoBST::~DrzewoBST() {
    usunCaleDrzewoPomocnicza(korzen); // Wywo³ujemy funkcjê czyszcz¹c¹ ca³¹ pamiêæ.
}

// --- Metody publiczne (interfejs dla u¿ytkownika) ---

void DrzewoBST::dodajElement(int wartosc) {
    korzen = dodajElementPomocnicza(korzen, wartosc);
}

void DrzewoBST::wyswietlInorder() {
    std::cout << "Drzewo (inorder): ";
    wyswietlInorderPomocnicza(korzen);
    std::cout << std::endl;
}

void DrzewoBST::wyswietlPreorder() {
    std::cout << "Drzewo (preorder): ";
    wyswietlPreorderPomocnicza(korzen);
    std::cout << std::endl;
}

void DrzewoBST::wyswietlPostorder() {
    std::cout << "Drzewo (postorder): ";
    wyswietlPostorderPomocnicza(korzen);
    std::cout << std::endl;
}

// --- Metody prywatne (wewnêtrzna logika klasy) ---

Wezel* DrzewoBST::dodajElementPomocnicza(Wezel* wezel, int wartosc) {
    // Warunek bazowy rekurencji: jeœli dotarliœmy do pustego miejsca (liœcia),
    // tworzymy tu nowy wêze³ i zwracamy jego adres.
    if (wezel == nullptr) {
        return new Wezel(wartosc);
    }

    // Krok rekurencyjny: decydujemy, czy iœæ do lewego, czy prawego poddrzewa.
    if (wartosc < wezel->wartosc) {
        wezel->lewy = dodajElementPomocnicza(wezel->lewy, wartosc);
    }
    else if (wartosc > wezel->wartosc) {
        wezel->prawy = dodajElementPomocnicza(wezel->prawy, wartosc);
    }
    // Jeœli wartoœæ ju¿ istnieje w drzewie, nic nie robimy.

    return wezel; // Zwracamy wskaŸnik na wêze³ (niezmieniony).
}