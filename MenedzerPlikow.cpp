#include "MenedzerPlikow.h"  // Do³¹czamy plik nag³ówkowy naszej klasy
#include <iostream>          // Potrzebne do wypisywania b³êdów (std::cerr) i logów (std::cout)
#include <fstream>           // Potrzebne do obs³ugi plików (std::ifstream)

// Musimy te¿ do³¹czyæ definicjê DrzewaBST, 
// poniewa¿ u¿ywamy jego metody .dodajElement()
#include "DrzewoBST.h"

/**
 * @brief Konstruktor domyœlny.
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

    // Otwieramy strumieñ pliku do CZYTANIA (ifstream = input file stream)
    std::ifstream plik(nazwaPliku);

    // Zawsze sprawdzaj, czy plik siê otworzy³!
    if (!plik.is_open()) {
        std::cerr << "Blad! Nie mozna otworzyc pliku: " << nazwaPliku << std::endl;
        return false;
    }

    int wartosc;
    std::cout << "Wczytywanie danych z pliku '" << nazwaPliku << "'..." << std::endl;

    // Pêtla 'while (plik >> wartosc)' bêdzie dzia³aæ tak d³ugo,
    // jak d³ugo uda siê wczytaæ kolejn¹ liczbê (int) z pliku.
    while (plik >> wartosc) {
        // U¿ywamy publicznej metody z klasy kolegi, aby dodaæ element
        drzewo.dodajElement(wartosc);
    }

    // Zamykamy plik po zakoñczeniu pracy
    plik.close();
    std::cout << "Zakonczono wczytywanie z pliku." << std::endl;

    return true;
}


// -----------------------------------------------------------------
//  ZAŒLEPKI (STUBS) DLA POZOSTA£YCH METOD
//  (Musz¹ tu byæ, aby program siê skompilowa³)
// -----------------------------------------------------------------


void MenedzerPlikow::zapiszDoPlikuBinarnego(DrzewoBST& drzewo, const std::string& nazwaPliku) {

    // Otwieramy strumieñ pliku do ZAPISU (ofstream) 
    // i w trybie BINARNYM (std::ios::binary)
    std::ofstream plik(nazwaPliku, std::ios::binary);

    if (!plik.is_open()) {
        std::cerr << "Blad! Nie mozna otworzyc pliku do zapisu binarnego: " << nazwaPliku << std::endl;
        return;
    }

    std::cout << "Rozpoczynam zapis binarny do pliku '" << nazwaPliku << "'..." << std::endl;

    // Dziêki 'friend class' mo¿emy teraz bezpiecznie odwo³aæ siê do korzenia
    zapiszWezelBinarne(plik, drzewo.korzen);

    plik.close();
    std::cout << "Zakonczono zapis binarny." << std::endl;
}

bool MenedzerPlikow::wczytajZPlikuBinarnego(DrzewoBST& drzewo, const std::string& nazwaPliku) {
    std::cout << "Funkcja 'wczytajZPlikuBinarnego' nie zostala jeszcze zaimplementowana." << std::endl;
    // Tê funkcjê zaimplementujemy w nastêpnych etapach
    return false;
}

void MenedzerPlikow::zapiszWezelBinarne(std::ofstream& plik, Wezel* wezel) {
    if (wezel == nullptr) {
        // Zapisz '0' (jako char), aby oznaczyæ brak wêz³a (nullptr)
        char znacznik = 0;
        plik.write(&znacznik, sizeof(znacznik));
    }
    else {
        // Zapisz '1' (jako char), aby oznaczyæ istnienie wêz³a
        char znacznik = 1;
        plik.write(&znacznik, sizeof(znacznik));

        // Zapisz W£AŒCIW¥ wartoœæ wêz³a (binarnie)
        // reinterpret_cast jest konieczny przy zapisie binarnym
        plik.write(reinterpret_cast<const char*>(&wezel->wartosc), sizeof(wezel->wartosc));

        // Rekurencyjnie zapisz lewe i prawe poddrzewo (Pre-order)
        zapiszWezelBinarne(plik, wezel->lewy);
        zapiszWezelBinarne(plik, wezel->prawy);
    }
}


Wezel* MenedzerPlikow::wczytajWezelBinarne(std::ifstream& plik) {
    // Implementacja póŸniej
    return nullptr;
}