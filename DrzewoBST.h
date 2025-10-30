
/**
 * @file DrzewoBST.h
 * @brief Plik nag��wkowy zawieraj�cy definicj� struktury Wezel oraz klasy DrzewoBST.
 */

#ifndef DRZEWOBST_H
#define DRZEWOBST_H

 /**
  * @struct Wezel
  * @brief Struktura reprezentuj�ca pojedynczy w�ze� w drzewie binarnym.
  *
  * Ka�dy w�ze� przechowuje warto�� ca�kowit� oraz wska�niki
  * na swoje lewe i prawe dziecko.
  */
struct Wezel {
    int wartosc;       ///< Warto�� przechowywana w w�le.
    Wezel* lewy;       ///< Wska�nik na lewe dziecko w�z�a.
    Wezel* prawy;      ///< Wska�nik na prawe dziecko w�z�a.

    /**
     * @brief Konstruktor tworz�cy nowy w�ze�.
     * @param val Warto��, kt�ra ma by� przechowana w w�le.
     */
    Wezel(int val) : wartosc(val), lewy(nullptr), prawy(nullptr) {}
};

/**
 * @class DrzewoBST
 * @brief Klasa implementuj�ca drzewo binarne poszukiwa� (BST).
 *
 * Umo�liwia dodawanie element�w oraz ich wy�wietlanie na trzy sposoby:
 * inorder, preorder i postorder. Zarz�dza pami�ci� w spos�b automatyczny.
 */
class DrzewoBST {
    friend class MenedzerPlikow;
private:
    Wezel* korzen; ///< Wska�nik na korze� drzewa.

    // --- Prywatne, pomocnicze metody rekurencyjne ---

    /**
     * @brief Pomocnicza funkcja rekurencyjna do dodawania nowego elementu.
     * @param wezel Aktualnie przetwarzany w�ze�.
     * @param wartosc Warto�� do dodania.
     * @return Wska�nik na w�ze� po operacji dodania.
     */
    Wezel* dodajElementPomocnicza(Wezel* wezel, int wartosc);

    /**
     * @brief Pomocnicza funkcja rekurencyjna do wy�wietlania drzewa metod� inorder.
     * @param wezel Aktualnie przetwarzany w�ze�.
     */
    void wyswietlInorderPomocnicza(Wezel* wezel);

    /**
     * @brief Pomocnicza funkcja rekurencyjna do wy�wietlania drzewa metod� preorder.
     * @param wezel Aktualnie przetwarzany w�ze�.
     */
    void wyswietlPreorderPomocnicza(Wezel* wezel);

    /**
     * @brief Pomocnicza funkcja rekurencyjna do wy�wietlania drzewa metod� postorder.
     * @param wezel Aktualnie przetwarzany w�ze�.
     */
    void wyswietlPostorderPomocnicza(Wezel* wezel);

    /**
     * @brief Pomocnicza funkcja rekurencyjna do usuwania wszystkich w�z��w i zwalniania pami�ci.
     * @param wezel Aktualnie przetwarzany w�ze�.
     */
    void usunCaleDrzewoPomocnicza(Wezel* wezel);

public:
    /**
     * @brief Konstruktor domy�lny. Inicjalizuje puste drzewo.
     */
    DrzewoBST();

    /**
     * @brief Destruktor. Automatycznie zwalnia pami�� po wszystkich w�z�ach.
     */
    ~DrzewoBST();

    /**
     * @brief Dodaje nowy element do drzewa.
     * @param wartosc Warto�� ca�kowita do wstawienia.
     */
    void dodajElement(int wartosc);

    /**
     * @brief Wy�wietla wszystkie elementy drzewa w porz�dku rosn�cym (inorder).
     */
    void wyswietlInorder();

    /**
     * @brief Wy�wietla wszystkie elementy drzewa w porz�dku preorder (korze�, lewe, prawe).
     */
    void wyswietlPreorder();

    /**
     * @brief Wy�wietla wszystkie elementy drzewa w porz�dku postorder (lewe, prawe, korze�).
     */
    void wyswietlPostorder();
};

#endif // DRZEWOBST_H
