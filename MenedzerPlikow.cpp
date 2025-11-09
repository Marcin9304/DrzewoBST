#include "MenedzerPlikow.h"  // Do³¹czamy plik nag³ówkowy naszej klasy
#include <iostream>          // Potrzebne do wypisywania b³êdów (std::cerr) i logów (std::cout)
#include <fstream>           // Potrzebne do obs³ugi plików (std::ifstream)

// Musimy te¿ do³¹czyæ definicjê DrzewaBST, 
// poniewa¿ u¿ywamy jego metody .dodajElement()
#include "DrzewoBST.h"

/**
 * @brief Konstruktor domyslny.
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

    // Otwieramy strumien pliku do CZYTANIA (ifstream = input file stream)
    std::ifstream plik(nazwaPliku);

    // Zawsze sprawdzaj, czy plik siê otworzyl!
    if (!plik.is_open()) {
        std::cerr << "Blad! Nie mozna otworzyc pliku: " << nazwaPliku << std::endl;
        return false;
    }

    int wartosc;
    std::cout << "Wczytywanie danych z pliku '" << nazwaPliku << "'..." << std::endl;

    // Petla 'while (plik >> wartosc)' bedzie dzialac tak dlugo,
    // jak dlugo uda siê wczytac kolejna liczbe (int) z pliku.
    while (plik >> wartosc) {
        // Uzywamy publicznej metody z klasy kolegi, aby dodac element
        drzewo.dodajElement(wartosc);
    }

    // Zamykamy plik po zakoñczeniu pracy
    plik.close();
    std::cout << "Zakonczono wczytywanie z pliku." << std::endl;

    return true;
}


// -----------------------------------------------------------------
//  ZASLEPKI (STUBS) DLA POZOSTALYCH METOD
//  (Musza tu byc, aby program siê skompilowa³)
// -----------------------------------------------------------------


void MenedzerPlikow::zapiszDoPlikuBinarnego(DrzewoBST& drzewo, const std::string& nazwaPliku) {

    // Otwieramy strumien pliku do ZAPISU (ofstream) 
    // i w trybie BINARNYM (std::ios::binary)
    std::ofstream plik(nazwaPliku, std::ios::binary);

    if (!plik.is_open()) {
        std::cerr << "Blad! Nie mozna otworzyc pliku do zapisu binarnego: " << nazwaPliku << std::endl;
        return;
    }

    std::cout << "Rozpoczynam zapis binarny do pliku '" << nazwaPliku << "'..." << std::endl;

    // Dzieki 'friend class' mozemy teraz bezpiecznie odwolac sie do korzenia
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
    // 1. Usuwamy stare drzewo, aby uniknac wycieku pamiêci.
    //    Mo¿emy wywo³ac prywatna metode kolegi, bo jestesmy 'friend'.
    
    drzewo.usunCaleDrzewoPomocnicza(drzewo.korzen);

    // 2. Rozpoczynamy rekurencyjna odbudowe drzewa i ustawiamy nowy korzen.
    drzewo.korzen = wczytajWezelBinarne(plik);
    // --- Koniec sekcji krytycznej ---

    plik.close();
    std::cout << "Zakonczono odczyt binarny." << std::endl;
    return true;
}

void MenedzerPlikow::zapiszWezelBinarne(std::ofstream& plik, Wezel* wezel) {
    if (wezel == nullptr) {
        // Zapisz '0' (jako char), aby oznaczyc brak wezla (nullptr)
        char znacznik = 0;
        plik.write(&znacznik, sizeof(znacznik));
    }
    else {
        // Zapisz '1' (jako char), aby oznaczyc istnienie wezla
        char znacznik = 1;
        plik.write(&znacznik, sizeof(znacznik));

        // Zapisz WLASCIWA wartoœæ wezla (binarnie)
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

    // Jesli plik siê skonczy³ lub znacznik to '0' (nullptr), zakoncz galaz
    if (plik.eof() || znacznik == 0) {
        return nullptr;
    }

    // Jeœli znacznik to '1', wezel istnieje
    int wartosc;
    // Odczytaj binarnie wartosc wezla (int)
    plik.read(reinterpret_cast<char*>(&wartosc), sizeof(wartosc));

    // Stwórz nowy wezel z ta wartoscia
    Wezel* nowyWezel = new Wezel(wartosc);

    // Rekurencyjnie odbuduj lewe i prawe poddrzewo
    nowyWezel->lewy = wczytajWezelBinarne(plik);
    nowyWezel->prawy = wczytajWezelBinarne(plik);

    // Zwroc gotowy wezel
    return nowyWezel;
}