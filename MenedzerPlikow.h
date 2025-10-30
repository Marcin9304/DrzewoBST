#ifndef MENEDZERPLIKOW_H
#define MENEDZERPLIKOW_H

#include <string>
#include <fstream>      // Bêdziemy potrzebowaæ do operacji na plikach
#include "DrzewoBST.h"  // Musimy znaæ definicjê klasy DrzewoBST i struktury Wezel

// WA¯NA UWAGA:
// Aby ta klasa mog³a dzia³aæ (szczególnie zapis/odczyt binarny),
// musi mieæ dostêp do prywatnego pola 'korzen' w klasie 'DrzewoBST'.
//
// Musisz edytowaæ plik "DrzewoBST.h" i wewn¹trz definicji klasy DrzewoBST
// (ale przed sekcj¹ 'private:') dodaæ jedn¹ liniê:
//
// friend class MenedzerPlikow;
//

/**
 * @class MenedzerPlikow
 * @brief Klasa odpowiedzialna za operacje zapisu i odczytu drzewa BST do/z pliku.
 *
 * Implementuje zapis i odczyt binarny (.bts) oraz odczyt
 * z pliku tekstowego zawieraj¹cego liczby.
 */
class MenedzerPlikow {
public:
    /**
     * @brief Konstruktor domyœlny.
     */
    MenedzerPlikow();

    /**
     * @brief Zapisuje strukturê drzewa do pliku binarnego (.bts).
     *
     * @param drzewo Referencja do drzewa, które ma byæ zapisane.
     * @param nazwaPliku Œcie¿ka do pliku wyjœciowego.
     */
    void zapiszDoPlikuBinarnego(DrzewoBST& drzewo, const std::string& nazwaPliku);

    /**
     * @brief Wczytuje strukturê drzewa z pliku binarnego (.bts).
     *
     * Zastêpuje obecn¹ zawartoœæ drzewa now¹ struktur¹ z pliku.
     *
     * @param drzewo Referencja do drzewa, do którego wczytujemy dane.
     * @param nazwaPliku Œcie¿ka do pliku binarnego.
     * @return true jeœli odczyt siê powiód³, false w przeciwnym razie.
     */
    bool wczytajZPlikuBinarnego(DrzewoBST& drzewo, const std::string& nazwaPliku);

    /**
     * @brief Wczytuje liczby z pliku tekstowego i dodaje je do drzewa.
     *
     * Mo¿e byæ u¿yte na pustym lub ju¿ istniej¹cym drzewie.
     * Plik tekstowy powinien zawieraæ liczby oddzielone bia³ymi znakami (spacja, enter).
     *
     * @param drzewo Referencja do drzewa, do którego maj¹ byæ dodane elementy.
     * @param nazwaPliku Œcie¿ka do pliku tekstowego (.txt).
     * @return true jeœli odczyt siê powiód³, false w przeciwnym razie.
     */
    bool wczytajZPlikuTekstowego(DrzewoBST& drzewo, const std::string& nazwaPliku);

private:
    // --- Prywatne, pomocnicze metody rekurencyjne ---
    // (Zostan¹ zaimplementowane w MenedzerPlikow.cpp)

    /**
     * @brief Pomocnicza funkcja do rekurencyjnego zapisu wêz³ów binarnie.
     * @param plik Strumieñ wyjœciowy do pliku (ofstream).
     * @param wezel Aktualnie przetwarzany wêze³.
     */
    void zapiszWezelBinarne(std::ofstream& plik, Wezel* wezel);

    /**
     * @brief Pomocnicza funkcja do rekurencyjnego odczytu wêz³ów binarnie.
     * @param plik Strumieñ wejœciowy z pliku (ifstream).
     * @return WskaŸnik na nowo utworzony wêze³ (lub nullptr).
     */
    Wezel* wczytajWezelBinarne(std::ifstream& plik);
};

#endif // MENEDZERPLIKOW_H