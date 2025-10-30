#ifndef MENEDZERPLIKOW_H
#define MENEDZERPLIKOW_H

#include <string>
#include <fstream>      // B�dziemy potrzebowa� do operacji na plikach
#include "DrzewoBST.h"  // Musimy zna� definicj� klasy DrzewoBST i struktury Wezel

// WA�NA UWAGA:
// Aby ta klasa mog�a dzia�a� (szczeg�lnie zapis/odczyt binarny),
// musi mie� dost�p do prywatnego pola 'korzen' w klasie 'DrzewoBST'.
//
// Musisz edytowa� plik "DrzewoBST.h" i wewn�trz definicji klasy DrzewoBST
// (ale przed sekcj� 'private:') doda� jedn� lini�:
//
// friend class MenedzerPlikow;
//

/**
 * @class MenedzerPlikow
 * @brief Klasa odpowiedzialna za operacje zapisu i odczytu drzewa BST do/z pliku.
 *
 * Implementuje zapis i odczyt binarny (.bts) oraz odczyt
 * z pliku tekstowego zawieraj�cego liczby.
 */
class MenedzerPlikow {
public:
    /**
     * @brief Konstruktor domy�lny.
     */
    MenedzerPlikow();

    /**
     * @brief Zapisuje struktur� drzewa do pliku binarnego (.bts).
     *
     * @param drzewo Referencja do drzewa, kt�re ma by� zapisane.
     * @param nazwaPliku �cie�ka do pliku wyj�ciowego.
     */
    void zapiszDoPlikuBinarnego(DrzewoBST& drzewo, const std::string& nazwaPliku);

    /**
     * @brief Wczytuje struktur� drzewa z pliku binarnego (.bts).
     *
     * Zast�puje obecn� zawarto�� drzewa now� struktur� z pliku.
     *
     * @param drzewo Referencja do drzewa, do kt�rego wczytujemy dane.
     * @param nazwaPliku �cie�ka do pliku binarnego.
     * @return true je�li odczyt si� powi�d�, false w przeciwnym razie.
     */
    bool wczytajZPlikuBinarnego(DrzewoBST& drzewo, const std::string& nazwaPliku);

    /**
     * @brief Wczytuje liczby z pliku tekstowego i dodaje je do drzewa.
     *
     * Mo�e by� u�yte na pustym lub ju� istniej�cym drzewie.
     * Plik tekstowy powinien zawiera� liczby oddzielone bia�ymi znakami (spacja, enter).
     *
     * @param drzewo Referencja do drzewa, do kt�rego maj� by� dodane elementy.
     * @param nazwaPliku �cie�ka do pliku tekstowego (.txt).
     * @return true je�li odczyt si� powi�d�, false w przeciwnym razie.
     */
    bool wczytajZPlikuTekstowego(DrzewoBST& drzewo, const std::string& nazwaPliku);

private:
    // --- Prywatne, pomocnicze metody rekurencyjne ---
    // (Zostan� zaimplementowane w MenedzerPlikow.cpp)

    /**
     * @brief Pomocnicza funkcja do rekurencyjnego zapisu w�z��w binarnie.
     * @param plik Strumie� wyj�ciowy do pliku (ofstream).
     * @param wezel Aktualnie przetwarzany w�ze�.
     */
    void zapiszWezelBinarne(std::ofstream& plik, Wezel* wezel);

    /**
     * @brief Pomocnicza funkcja do rekurencyjnego odczytu w�z��w binarnie.
     * @param plik Strumie� wej�ciowy z pliku (ifstream).
     * @return Wska�nik na nowo utworzony w�ze� (lub nullptr).
     */
    Wezel* wczytajWezelBinarne(std::ifstream& plik);
};

#endif // MENEDZERPLIKOW_H