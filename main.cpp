#include <iostream>
#include <limits>       // Bêdziemy potrzebowaæ do czyszczenia bufora wejœcia

#include "DrzewoBST.h"      // Do³¹czamy klasê drzewa
#include "MenedzerPlikow.h" // Do³¹czamy klasê mened¿era plików

/**
 * @brief Funkcja pomocnicza do wyœwietlania menu g³ównego.
 */
void wyswietlMenu() {
    std::cout << "\n--- MENU GLOWNE DRZEWA BST ---" << std::endl;
    std::cout << "1. Dodaj element" << std::endl;
    std::cout << "2. Wyswietl drzewo (Inorder, Preorder, Postorder)" << std::endl;
    std::cout << "3. Szukaj drogi do elementu" << std::endl;
    std::cout << "4. Zapisz drzewo do pliku (tekstowo)" << std::endl;
    std::cout << "5. Zapisz drzewo do pliku (binarnie)" << std::endl;
    std::cout << "6. Wczytaj drzewo z pliku (tekstowo)" << std::endl;
    std::cout << "7. Wczytaj drzewo z pliku (binarnie)" << std::endl;
    std::cout << "8. Usun cale drzewo" << std::endl;
    std::cout << "0. Zakoncz program" << std::endl;
    std::cout << "Wybierz opcje: ";
}

/**
 * @brief Funkcja pomocnicza do obs³ugi pod-menu wyœwietlania.
 * @param drzewo Referencja do drzewa, które ma byæ wyœwietlone.
 */
void obsluzWyswietlanie(DrzewoBST& drzewo) {
    int wybor;
    std::cout << "\n  --- Sposob wyswietlania ---" << std::endl;
    std::cout << "  1. Inorder (rosnaco)" << std::endl;
    std::cout << "  2. Preorder (korzen, lewe, prawe)" << std::endl;
    std::cout << "  3. Postorder (lewe, prawe, korzen)" << std::endl;
    std::cout << "  Wybierz: ";
    std::cin >> wybor;

    switch (wybor) {
    case 1:
        std::cout << "Drzewo (Inorder): ";
        drzewo.wyswietlInorder();
        break;
    case 2:
        std::cout << "Drzewo (Preorder): ";
        drzewo.wyswietlPreorder();
        break;
    case 3:
        std::cout << "Drzewo (Postorder): ";
        drzewo.wyswietlPostorder();
        break;
    default:
        std::cout << "Niepoprawna opcja wyswietlania." << std::endl;
        break;
    }
}

/**
 * @brief G³ówna funkcja programu (main).
 */
int main() {
    // Tworzymy obiekty, na których bêdziemy pracowaæ
    DrzewoBST drzewo;
    MenedzerPlikow menedzer;

    int wybor = -1;
    bool dziala = true;

    while (dziala) {
        wyswietlMenu();
        std::cin >> wybor;

        // Prosta obs³uga b³êdu, gdy ktoœ wpisze literê zamiast liczby
        if (std::cin.fail()) {
            std::cout << "Blad! Wprowadzono nie-liczbe. Sprobuj ponownie." << std::endl;
            std::cin.clear(); // Czyszczenie flagi b³êdu
            // Ignorowanie reszty b³êdnych danych w buforze wejœcia
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // Pomiñ resztê pêtli i wyœwietl menu ponownie
        }

        switch (wybor) {
        case 1: { // Dodaj element
            int wartosc;
            std::cout << "Podaj wartosc do dodania: ";
            std::cin >> wartosc;
            drzewo.dodajElement(wartosc);
            std::cout << "Dodano " << wartosc << std::endl;
            break;
        }
        case 2: // Wyœwietl drzewo
            obsluzWyswietlanie(drzewo);
            break;

            // --- ZAŒLEPKI DLA FUNKCJI DO ZAIMPLEMENTOWANIA ---
        case 3:
            std::cout << "Opcja 'Szukaj drogi' - do zaimplementowania." << std::endl;
            break;
        case 4:
            std::cout << "Opcja 'Zapisz tekstowo' - do zaimplementowania." << std::endl;
            // Tutaj wywo³asz: menedzer.zapiszDoPlikuTekstowego(drzewo, "nazwa.txt");
            break;
        case 5:
            std::cout << "Opcja 'Zapisz binarnie' - do zaimplementowania." << std::endl;
            // Tutaj wywo³asz: menedzer.zapiszDoPlikuBinarnego(drzewo, "drzewo.bts");
            break;
        case 6:
            std::cout << "Opcja 'Wczytaj tekstowo' - do zaimplementowania." << std::endl;
            // Tutaj wywo³asz: menedzer.wczytajZPlikuTekstowego(drzewo, "nazwa.txt");
            break;
        case 7:
            std::cout << "Opcja 'Wczytaj binarnie' - do zaimplementowania." << std::endl;
            // Tutaj wywo³asz: menedzer.wczytajZPlikuBinarnego(drzewo, "drzewo.bts");
            break;
        case 8:
            std::cout << "Opcja 'Usun cale drzewo' - do zaimplementowania." << std::endl;
            // Tutaj przyda³aby siê funkcja: drzewo.usunCaleDrzewo();
            // (Jeœli Twój kolega jej nie zrobi³, destruktor za³atwi sprawê przy wyjœciu)
            break;
        case 0: // Zakoñcz program
            dziala = false;
            std::cout << "Do widzenia!" << std::endl;
            break;
        default:
            std::cout << "Niepoprawna opcja, sprobuj ponownie." << std::endl;
            break;
        }
    }

    return 0; // Zakoñczenie programu
}