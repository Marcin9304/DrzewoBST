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
    std::cout << "Funkcja 'zapiszDoPlikuBinarnego' nie zostala jeszcze zaimplementowana." << std::endl;
    // T� funkcj� zaimplementujemy w nast�pnych etapach
}

bool MenedzerPlikow::wczytajZPlikuBinarnego(DrzewoBST& drzewo, const std::string& nazwaPliku) {
    std::cout << "Funkcja 'wczytajZPlikuBinarnego' nie zostala jeszcze zaimplementowana." << std::endl;
    // T� funkcj� zaimplementujemy w nast�pnych etapach
    return false;
}

// Prywatne metody pomocnicze (te� na razie puste)
void MenedzerPlikow::zapiszWezelBinarne(std::ofstream& plik, Wezel* wezel) {
    // Implementacja p�niej
}

Wezel* MenedzerPlikow::wczytajWezelBinarne(std::ifstream& plik) {
    // Implementacja p�niej
    return nullptr;
}