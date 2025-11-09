#ifndef MENEDZERPLIKOW_H
#define MENEDZERPLIKOW_H

#include <string>
#include <fstream>      // Bedziemy potrzebowac do operacji na plikach
#include "DrzewoBST.h"  // Musimy znac definicje klasy DrzewoBST i struktury Wezel


/**
 * @class MenedzerPlikow
@brief Klasa zarzadzajaca plikami.
 *
 * Implementuje zapis i odczyt binarny (.bts) oraz odczyt
 * z pliku tekstowego zawierajacego liczby.
 */
class MenedzerPlikow {
public:
    /**
     * @brief Konstruktor domyslny.
     */
    MenedzerPlikow();

    /**
     * @brief Zapisuje strukture drzewa do pliku binarnego (.bts).
     *
     * @param drzewo Referencja do drzewa, ktore ma byc zapisane.
     * @param nazwaPliku Sciezka do pliku wyjsciowego.
     */
    void zapiszDoPlikuBinarnego(DrzewoBST& drzewo, const std::string& nazwaPliku);

    /**
     * @brief Wczytuje strukture drzewa z pliku binarnego (.bts).
     *
     * Zastepuje obecna zawartosc drzewa nowa struktura z pliku.
     *
     * @param drzewo Referencja do drzewa, do ktorego wczytujemy dane.
     * @param nazwaPliku Œciezka do pliku binarnego.
     * @return true jeœli odczyt siê powiodl, false w przeciwnym razie.
     */
    bool wczytajZPlikuBinarnego(DrzewoBST& drzewo, const std::string& nazwaPliku);

    /**
     * @brief Wczytuje liczby z pliku tekstowego i dodaje je do drzewa.
     *
     * Moze byc uzyte na pustym lub ju¿ istniej¹cym drzewie.
     * Plik tekstowy powinien zawierac liczby oddzielone bialymi znakami (spacja, enter).
     *
     * @param drzewo Referencja do drzewa, do ktorego maj¹ byc dodane elementy.
     * @param nazwaPliku Sciezka do pliku tekstowego (.txt).
     * @return true jesli odczyt siê powiodl, false w przeciwnym razie.
     */
    bool wczytajZPlikuTekstowego(DrzewoBST& drzewo, const std::string& nazwaPliku);

private:
    // --- Prywatne, pomocnicze metody rekurencyjne ---
    // (Zostana zaimplementowane w MenedzerPlikow.cpp)

    /**
     * @brief Pomocnicza funkcja do rekurencyjnego zapisu wez³ow binarnie.
     * @param plik Strumien wyjsciowy do pliku (ofstream).
     * @param wezel Aktualnie przetwarzany wezel.
     */
    void zapiszWezelBinarne(std::ofstream& plik, Wezel* wezel);

    /**
     * @brief Pomocnicza funkcja do rekurencyjnego odczytu wez³ow binarnie.
     * @param plik Strumien wejsciowy z pliku (ifstream).
     * @return Wskaznik na nowo utworzony wezel (lub nullptr).
     */
    Wezel* wczytajWezelBinarne(std::ifstream& plik);
};

#endif // MENEDZERPLIKOW_H