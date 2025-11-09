
/**
 * @file DrzewoBST.h
 * @brief Plik nag³owkowy zawieraj¹cy definicje struktury Wezel oraz klasy DrzewoBST.
 */

#ifndef DRZEWOBST_H
#define DRZEWOBST_H

 /**
  * @struct Wezel
  * @brief Struktura reprezentujaca pojedynczy weze³ w drzewie binarnym.
  *
  * Kazdy weze³ przechowuje wartosc ca³kowita oraz wskazniki
  * na swoje lewe i prawe dziecko.
  */
struct Wezel {
    int wartosc;       ///< Wartosc przechowywana w wezle.
    Wezel* lewy;       ///< Wskaznik na lewe dziecko wezla.
    Wezel* prawy;      ///< Wskaznik na prawe dziecko wezla.

    /**
     * @brief Konstruktor tworzacy nowy wezel.
     * @param val Wartosc, ktora ma byc przechowana w wezle.
     */
    Wezel(int val) : wartosc(val), lewy(nullptr), prawy(nullptr) {}
};

/**
 * @class DrzewoBST
 * @brief Klasa implementujaca drzewo binarne poszukiwan (BST).
 *
 * Umozliwia dodawanie elementow oraz ich wyswietlanie na trzy sposoby:
 * inorder, preorder i postorder. Zarzadza pamiecia w sposob automatyczny.
 */
class DrzewoBST {
    friend class MenedzerPlikow;
private:
    Wezel* korzen; ///< Wskaznik na korzen drzewa.

    // --- Prywatne, pomocnicze metody rekurencyjne ---

    /**
     * @brief Pomocnicza funkcja rekurencyjna do dodawania nowego elementu.
     * @param wezel Aktualnie przetwarzany wezel.
     * @param wartosc Wartosc do dodania.
     * @return Wskaznik na wezel po operacji dodania.
     */
    Wezel* dodajElementPomocnicza(Wezel* wezel, int wartosc);

    /**
     * @brief Pomocnicza funkcja rekurencyjna do wyswietlania drzewa metod¹ inorder.
     * @param wezel Aktualnie przetwarzany wezel.
     */
    void wyswietlInorderPomocnicza(Wezel* wezel);

    /**
     * @brief Pomocnicza funkcja rekurencyjna do wyswietlania drzewa metoda preorder.
     * @param wezel Aktualnie przetwarzany wezel.
     */
    void wyswietlPreorderPomocnicza(Wezel* wezel);

    /**
     * @brief Pomocnicza funkcja rekurencyjna do wyswietlania drzewa metod¹ postorder.
     * @param wezel Aktualnie przetwarzany wezel.
     */
    void wyswietlPostorderPomocnicza(Wezel* wezel);

    /**
     * @brief Pomocnicza funkcja rekurencyjna do usuwania wszystkich wez³ow i zwalniania pamiêci.
     * @param wezel Aktualnie przetwarzany wezel.
     */
    void usunCaleDrzewoPomocnicza(Wezel* wezel);

public:
    /**
     * @brief Konstruktor domyslny. Ustawia korzen na nullptr.
     */
    DrzewoBST();

    /**
     * @brief Destruktor. Automatycznie zwalnia pamiec po wszystkich wezlach.
     */
    ~DrzewoBST();

    /**
     * @brief Dodaje nowy element do drzewa.
     * @param wartosc Wartosc ca³kowita do wstawienia.
     */
    void dodajElement(int wartosc);

    /**
     * @brief Wyswietla wszystkie elementy drzewa w porzadku rosnacym (inorder).
     */
    void wyswietlInorder();

    /**
     * @brief Wyswietla wszystkie elementy drzewa w porzadku preorder (korzen, lewe, prawe).
     */
    void wyswietlPreorder();

    /**
     * @brief Wyswietla wszystkie elementy drzewa w porzadku postorder (lewe, prawe, korzen).
     */
    void wyswietlPostorder();
};

#endif // DRZEWOBST_H
