
/**
 * @file DrzewoBST.h
 * @brief Plik nag³ówkowy zawieraj¹cy definicjê struktury Wezel oraz klasy DrzewoBST.
 */

#ifndef DRZEWOBST_H
#define DRZEWOBST_H

 /**
  * @struct Wezel
  * @brief Struktura reprezentuj¹ca pojedynczy wêze³ w drzewie binarnym.
  *
  * Ka¿dy wêze³ przechowuje wartoœæ ca³kowit¹ oraz wskaŸniki
  * na swoje lewe i prawe dziecko.
  */
struct Wezel {
    int wartosc;       ///< Wartoœæ przechowywana w wêŸle.
    Wezel* lewy;       ///< WskaŸnik na lewe dziecko wêz³a.
    Wezel* prawy;      ///< WskaŸnik na prawe dziecko wêz³a.

    /**
     * @brief Konstruktor tworz¹cy nowy wêze³.
     * @param val Wartoœæ, która ma byæ przechowana w wêŸle.
     */
    Wezel(int val) : wartosc(val), lewy(nullptr), prawy(nullptr) {}
};

/**
 * @class DrzewoBST
 * @brief Klasa implementuj¹ca drzewo binarne poszukiwañ (BST).
 *
 * Umo¿liwia dodawanie elementów oraz ich wyœwietlanie na trzy sposoby:
 * inorder, preorder i postorder. Zarz¹dza pamiêci¹ w sposób automatyczny.
 */
class DrzewoBST {
    friend class MenedzerPlikow;
private:
    Wezel* korzen; ///< WskaŸnik na korzeñ drzewa.

    // --- Prywatne, pomocnicze metody rekurencyjne ---

    /**
     * @brief Pomocnicza funkcja rekurencyjna do dodawania nowego elementu.
     * @param wezel Aktualnie przetwarzany wêze³.
     * @param wartosc Wartoœæ do dodania.
     * @return WskaŸnik na wêze³ po operacji dodania.
     */
    Wezel* dodajElementPomocnicza(Wezel* wezel, int wartosc);

    /**
     * @brief Pomocnicza funkcja rekurencyjna do wyœwietlania drzewa metod¹ inorder.
     * @param wezel Aktualnie przetwarzany wêze³.
     */
    void wyswietlInorderPomocnicza(Wezel* wezel);

    /**
     * @brief Pomocnicza funkcja rekurencyjna do wyœwietlania drzewa metod¹ preorder.
     * @param wezel Aktualnie przetwarzany wêze³.
     */
    void wyswietlPreorderPomocnicza(Wezel* wezel);

    /**
     * @brief Pomocnicza funkcja rekurencyjna do wyœwietlania drzewa metod¹ postorder.
     * @param wezel Aktualnie przetwarzany wêze³.
     */
    void wyswietlPostorderPomocnicza(Wezel* wezel);

    /**
     * @brief Pomocnicza funkcja rekurencyjna do usuwania wszystkich wêz³ów i zwalniania pamiêci.
     * @param wezel Aktualnie przetwarzany wêze³.
     */
    void usunCaleDrzewoPomocnicza(Wezel* wezel);

public:
    /**
     * @brief Konstruktor domyœlny. Inicjalizuje puste drzewo.
     */
    DrzewoBST();

    /**
     * @brief Destruktor. Automatycznie zwalnia pamiêæ po wszystkich wêz³ach.
     */
    ~DrzewoBST();

    /**
     * @brief Dodaje nowy element do drzewa.
     * @param wartosc Wartoœæ ca³kowita do wstawienia.
     */
    void dodajElement(int wartosc);

    /**
     * @brief Wyœwietla wszystkie elementy drzewa w porz¹dku rosn¹cym (inorder).
     */
    void wyswietlInorder();

    /**
     * @brief Wyœwietla wszystkie elementy drzewa w porz¹dku preorder (korzeñ, lewe, prawe).
     */
    void wyswietlPreorder();

    /**
     * @brief Wyœwietla wszystkie elementy drzewa w porz¹dku postorder (lewe, prawe, korzeñ).
     */
    void wyswietlPostorder();
};

#endif // DRZEWOBST_H
