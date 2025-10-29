/**
 * @file DrzewoBST.cpp
 * @brief Plik �r�d�owy z implementacj� metod klasy DrzewoBST.
 */

#include "DrzewoBST.h"
#include <iostream>

 // --- Konstruktor i Destruktor ---

DrzewoBST::DrzewoBST() {
    korzen = nullptr; // Na pocz�tku drzewo jest puste, wi�c korze� wskazuje na nic.
}

DrzewoBST::~DrzewoBST() {
    usunCaleDrzewoPomocnicza(korzen); // Wywo�ujemy funkcj� czyszcz�c� ca�� pami��.
}

// --- Metody publiczne (interfejs dla u�ytkownika) ---

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

// --- Metody prywatne (wewn�trzna logika klasy) ---

Wezel* DrzewoBST::dodajElementPomocnicza(Wezel* wezel, int wartosc) {
    // Warunek bazowy rekurencji: je�li dotarli�my do pustego miejsca (li�cia),
    // tworzymy tu nowy w�ze� i zwracamy jego adres.
    if (wezel == nullptr) {
        return new Wezel(wartosc);
    }

    // Krok rekurencyjny: decydujemy, czy i�� do lewego, czy prawego poddrzewa.
    if (wartosc < wezel->wartosc) {
        wezel->lewy = dodajElementPomocnicza(wezel->lewy, wartosc);
    }
    else if (wartosc > wezel->wartosc) {
        wezel->prawy = dodajElementPomocnicza(wezel->prawy, wartosc);
    }
    // Je�li warto�� ju� istnieje w drzewie, nic nie robimy.

    return wezel; // Zwracamy wska�nik na w�ze� (niezmieniony).
}
void DrzewoBST::wyswietlInorderPomocnicza(Wezel* wezel) {
    if (wezel != nullptr) {
        wyswietlInorderPomocnicza(wezel->lewy);  // 1. Zejd� do lewego poddrzewa
        std::cout << wezel->wartosc << " ";    // 2. Odwied� korze�
        wyswietlInorderPomocnicza(wezel->prawy); // 3. Zejd� do prawego poddrzewa
    }
}

void DrzewoBST::wyswietlPreorderPomocnicza(Wezel* wezel) {
    if (wezel != nullptr) {
        std::cout << wezel->wartosc << " ";     // 1. Odwied� korze�
        wyswietlPreorderPomocnicza(wezel->lewy);  // 2. Zejd� do lewego poddrzewa
        wyswietlPreorderPomocnicza(wezel->prawy); // 3. Zejd� do prawego poddrzewa
    }
}

void DrzewoBST::wyswietlPostorderPomocnicza(Wezel* wezel) {
    if (wezel != nullptr) {
        wyswietlPostorderPomocnicza(wezel->lewy);  // 1. Zejd� do lewego poddrzewa
        wyswietlPostorderPomocnicza(wezel->prawy); // 2. Zejd� do prawego poddrzewa
        std::cout << wezel->wartosc << " ";     // 3. Odwied� korze�
    }
}