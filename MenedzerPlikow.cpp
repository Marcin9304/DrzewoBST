#include "MenedzerPlikow.h"  // Do��czamy plik nag��wkowy naszej klasy
#include <iostream>          // Potrzebne do wypisywania b��d�w (std::cerr) i log�w (std::cout)
#include <fstream>           // Potrzebne do obs�ugi plik�w (std::ifstream)

// Musimy te� do��czy� definicj� DrzewaBST, 
// poniewa� u�ywamy jego metody .dodajElement()
#include "DrzewoBST.h"

/**
 * @brief Konstruktor domy�lny.
 */
MenedzerPlikow::MenedzerPlikow() {
    // Na razie nic tu nie potrzebujemy
}

// -----------------------------------------------------------------
//  IMPLEMENTACJA METODY Z ETAPU 3
// -----------------------------------------------------------------

/**
 * @brief Wczytuje liczby z pliku tekstowego i dodaje je do drzewa.
 */
bool MenedzerPlikow::wczytajZPlikuTekstowego(DrzewoBST& drzewo, const std::string& nazwaPliku) {

    // Otwieramy strumie� pliku do CZYTANIA (ifstream = input file stream)
    std::ifstream plik(nazwaPliku);

    // Zawsze sprawdzaj, czy plik si� otworzy�!
    if (!plik.is_open()) {
        std::cerr << "Blad! Nie mozna otworzyc pliku: " << nazwaPliku << std::endl;
        return false;
    }

    int wartosc;
    std::cout << "Wczytywanie danych z pliku '" << nazwaPliku << "'..." << std::endl;

    // P�tla 'while (plik >> wartosc)' b�dzie dzia�a� tak d�ugo,
    // jak d�ugo uda si� wczyta� kolejn� liczb� (int) z pliku.
    while (plik >> wartosc) {
        // U�ywamy publicznej metody z klasy kolegi, aby doda� element
        drzewo.dodajElement(wartosc);
    }

    // Zamykamy plik po zako�czeniu pracy
    plik.close();
    std::cout << "Zakonczono wczytywanie z pliku." << std::endl;

    return true;
}


// -----------------------------------------------------------------
//  ZA�LEPKI (STUBS) DLA POZOSTA�YCH METOD
//  (Musz� tu by�, aby program si� skompilowa�)
// -----------------------------------------------------------------


void MenedzerPlikow::zapiszDoPlikuBinarnego(DrzewoBST& drzewo, const std::string& nazwaPliku) {

    // Otwieramy strumie� pliku do ZAPISU (ofstream) 
    // i w trybie BINARNYM (std::ios::binary)
    std::ofstream plik(nazwaPliku, std::ios::binary);

    if (!plik.is_open()) {
        std::cerr << "Blad! Nie mozna otworzyc pliku do zapisu binarnego: " << nazwaPliku << std::endl;
        return;
    }

    std::cout << "Rozpoczynam zapis binarny do pliku '" << nazwaPliku << "'..." << std::endl;

    // Dzi�ki 'friend class' mo�emy teraz bezpiecznie odwo�a� si� do korzenia
    zapiszWezelBinarne(plik, drzewo.korzen);

    plik.close();
    std::cout << "Zakonczono zapis binarny." << std::endl;
}

bool MenedzerPlikow::wczytajZPlikuBinarnego(DrzewoBST& drzewo, const std::string& nazwaPliku) {

    // Otwieramy plik do CZYTANIA (ifstream) w trybie BINARNYM (std::ios::binary)
    std::ifstream plik(nazwaPliku, std::ios::binary);

    if (!plik.is_open()) {
        std::cerr << "Blad! Nie mozna otworzyc pliku do odczytu binarnego: " << nazwaPliku << std::endl;
        return false;
    }

    std::cout << "Rozpoczynam odczyt binarny z pliku '" << nazwaPliku << "'..." << std::endl;

    // --- KRYTYCZNA SEKCJA ---
    // 1. Usuwamy stare drzewo, aby unikn�� wycieku pami�ci.
    //    Mo�emy wywo�a� prywatn� metod� kolegi, bo jeste�my 'friend'.
    //    (Zak�adamy, �e kolega poprawnie zaimplementowa� t� funkcj�)
    drzewo.usunCaleDrzewoPomocnicza(drzewo.korzen);

    // 2. Rozpoczynamy rekurencyjn� odbudow� drzewa i ustawiamy nowy korze�.
    drzewo.korzen = wczytajWezelBinarne(plik);
    // --- Koniec sekcji krytycznej ---

    plik.close();
    std::cout << "Zakonczono odczyt binarny." << std::endl;
    return true;
}

void MenedzerPlikow::zapiszWezelBinarne(std::ofstream& plik, Wezel* wezel) {
    if (wezel == nullptr) {
        // Zapisz '0' (jako char), aby oznaczy� brak w�z�a (nullptr)
        char znacznik = 0;
        plik.write(&znacznik, sizeof(znacznik));
    }
    else {
        // Zapisz '1' (jako char), aby oznaczy� istnienie w�z�a
        char znacznik = 1;
        plik.write(&znacznik, sizeof(znacznik));

        // Zapisz W�A�CIW� warto�� w�z�a (binarnie)
        // reinterpret_cast jest konieczny przy zapisie binarnym
        plik.write(reinterpret_cast<const char*>(&wezel->wartosc), sizeof(wezel->wartosc));

        // Rekurencyjnie zapisz lewe i prawe poddrzewo (Pre-order)
        zapiszWezelBinarne(plik, wezel->lewy);
        zapiszWezelBinarne(plik, wezel->prawy);
    }
}


Wezel* MenedzerPlikow::wczytajWezelBinarne(std::ifstream& plik) {
    char znacznik;
    // Odczytaj 1-bajtowy znacznik ('0' lub '1')
    plik.read(&znacznik, sizeof(znacznik));

    // Je�li plik si� sko�czy� lub znacznik to '0' (nullptr), zako�cz ga���
    if (plik.eof() || znacznik == 0) {
        return nullptr;
    }

    // Je�li znacznik to '1', w�ze� istnieje
    int wartosc;
    // Odczytaj binarnie warto�� w�z�a (int)
    plik.read(reinterpret_cast<char*>(&wartosc), sizeof(wartosc));

    // Stw�rz nowy w�ze� z t� warto�ci�
    Wezel* nowyWezel = new Wezel(wartosc);

    // Rekurencyjnie odbuduj lewe i prawe poddrzewo
    nowyWezel->lewy = wczytajWezelBinarne(plik);
    nowyWezel->prawy = wczytajWezelBinarne(plik);

    // Zwr�� gotowy w�ze�
    return nowyWezel;
}