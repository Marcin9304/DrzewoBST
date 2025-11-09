#include <iostream>
#include <limits>       // Do czyszczenia bufora wejœcia
#include <string>       // Do obs³ugi nazw plików (std::string)

#include "DrzewoBST.h"      // Do³¹czamy klasê drzewa
#include "MenedzerPlikow.h" // Do³¹czamy klasê mened¿era plików

/**
 * @brief Funkcja pomocnicza do wyswietlania menu glownego.
 */
void wyswietlMenu() {
    std::cout << "\n--- MENU GLOWNE DRZEWA BST ---" << std::endl;
    std::cout << "1. Dodaj NOWY element" << std::endl;
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
 * @brief Funkcja pomocnicza do obs³ugi pod-menu wyswietlania.
 * @param drzewo Referencja do drzewa, ktore ma byc wyswietlone.
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
 * @brief G³owna funkcja programu (main).
 */
int main() {
    // Tworzymy obiekty, na ktorych bêdziemy pracowac
    DrzewoBST drzewo;
    MenedzerPlikow menedzer;

    int wybor = -1;
    bool dziala = true;

    while (dziala) {
        wyswietlMenu();
        std::cin >> wybor;

        // Prosta obsluga bledu, gdy ktos wpisze literê zamiast liczby
        if (std::cin.fail()) {
            std::cout << "Blad! Wprowadzono nie-liczbe. Sprobuj ponownie." << std::endl;
            std::cin.clear(); // Czyszczenie flagi bledu
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // Pomin reszte petli i wyswietl menu ponownie
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
        case 2: // Wyswietl drzewo
            obsluzWyswietlanie(drzewo);
            break;

        case 3: // Szukaj drogi
            std::cout << "Opcja 'Szukaj drogi' - do zaimplementowania." << std::endl;
            // Te funkcje musimy jeszcze dopisac w DrzewoBST.h i .cpp
            // a nastêpnie tutaj ja wywo³ac.
            break;

            // --- FUNKCJE MENEDZERA PLIKOW ---

        case 4: { // Zapisz tekstowo
            std::string nazwaPliku;
            std::cout << "Podaj nazwe pliku tekstowego (np. drzewo.txt): ";
            std::cin >> nazwaPliku;
            
            std::cout << "Opcja 'Zapisz tekstowo' - do zaimplementowania." << std::endl;
            // menedzer.zapiszDoPlikuTekstowego(drzewo, nazwaPliku);
            break;
        }
        case 5: { // Zapisz binarnie
            std::string nazwaPliku = "drzewo.bts"; // Domyslna nazwa
            std::cout << "Podaj nazwe pliku binarnego (domyslnie: drzewo.bts): ";
            std::cin.ignore(); // Zjedz znak nowej linii po wczytaniu liczby
            std::getline(std::cin, nazwaPliku); // Pozwol na wpisanie nazwy
            if (nazwaPliku.empty()) nazwaPliku = "drzewo.bts"; // Uzyj domyslnej, jesli pusto

            menedzer.zapiszDoPlikuBinarnego(drzewo, nazwaPliku);
            break;
        }
        case 6: { // Wczytaj tekstowo
            std::string nazwaPliku;
            std::cout << "Podaj nazwe pliku tekstowego do wczytania (np. dane.txt): ";
            std::cin >> nazwaPliku;

            if (menedzer.wczytajZPlikuTekstowego(drzewo, nazwaPliku)) {
                std::cout << "Wczytano pomyslnie." << std::endl;
            }
            else {
                std::cout << "Nie udalo sie wczytac pliku." << std::endl;
            }
            break;
        }
        case 7: { // Wczytaj binarnie
            std::string nazwaPliku = "drzewo.bts"; // Domyslna nazwa
            std::cout << "Podaj nazwe pliku binarnego do wczytania (domyslnie: drzewo.bts): ";
            std::cin.ignore(); // Zjedz znak nowej linii
            std::getline(std::cin, nazwaPliku);
            if (nazwaPliku.empty()) nazwaPliku = "drzewo.bts";

            if (menedzer.wczytajZPlikuBinarnego(drzewo, nazwaPliku)) {
                std::cout << "Wczytano pomyslnie. Stare drzewo zostalo zastapione." << std::endl;
            }
            else {
                std::cout << "Nie udalo sie wczytac pliku." << std::endl;
            }
            break;
        }
        case 8: { // Usun ca³e drzewo
            std::cout << "Usuwanie calego drzewa..." << std::endl;
            // Tworzymy nowe, puste drzewo i podmieniamy je ze starym
            // Stare drzewo (w obiekcie 'drzewo') zostanie automatycznie
            // usuniete przez swoj destruktor (ktory wywo³a usunCaleDrzewoPomocnicza)
            DrzewoBST pusteDrzewo;
            // Uzywamy std::swap, aby podmienic zawartosc
            // std::swap(drzewo, pusteDrzewo); // To wymaga³oby operatora= lub copy ctor

            // Prostsza metoda: po prostu wywo³aj wczytanie z nieistniej¹cego pliku
            // binarnego, które i tak czyœci drzewo.
            // ...albo po prostu zrob nowe drzewo:
            drzewo = DrzewoBST(); // Zakladajac, ¿e destruktor starego drzewa dobrze zwalnia pamiêc
            std::cout << "Drzewo zostalo wyczyszczone." << std::endl;
            break;
        }
        case 0: // Zakoncz program
            dziala = false;
            std::cout << "Do widzenia!" << std::endl;
            break;
        default:
            std::cout << "Niepoprawna opcja, sprobuj ponownie." << std::endl;
            break;
        }
    }

    return 0; // Zakonczenie programu
}