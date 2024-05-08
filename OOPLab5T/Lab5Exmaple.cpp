#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

// Визначення класу "Карта"
class Card {
private:
    int value;
    std::string suit;

public:
    Card(int val, std::string s) : value(val), suit(s) {}

    // Функція для отримання значення карти
    int getValue() const {
        return value;
    }

    // Функція для отримання масті карти
    std::string getSuit() const {
        return suit;
    }
};

// Клас "Колода"
class Deck {
protected:
    std::vector<Card> cards;

public:
    // Конструктор за замовчуванням ініціалізує впорядковану колоду
    Deck() {
        initializeDeck();
    }

    // Функція для ініціалізації впорядкованої колоди
    void initializeDeck() {
        std::vector<std::string> suits = { "Hearts", "Diamonds", "Clubs", "Spades" };
        for (const auto& suit : suits) {
            for (int value = 1; value <= 13; ++value) {
                cards.emplace_back(value, suit);
            }
        }
    }

    // Функція для перемішування колоди
    void shuffleDeck() {
        std::srand(std::time(0)); // Ініціалізація генератора випадкових чисел
        std::random_shuffle(cards.begin(), cards.end());
    }

    // Функція для виведення колоди на екран
    void displayDeck() const {
        for (const auto& card : cards) {
            std::cout << card.getValue() << " of " << card.getSuit() << std::endl;
        }
    }
};

// Клас "Пасьянс"
class Solitaire : public Deck {
public:
    // Функція для видалення крайніх карт одного кольору
    void removePairs() {
        int count = 0;
        while (count < 3) {
            for (auto it = cards.begin(); it != cards.end() - 2; ++it) {
                if (it->getSuit() == (it + 2)->getSuit()) {
                    cards.erase(it, it + 3);
                    count++;
                    break;
                }
            }
            if (count == 0)
                break;
            count = 0;
        }
    }
};

int main() {
    // Створення об'єкта колоди
    Solitaire deck;

    // Перемішування колоди
    deck.shuffleDeck();

    // Виведення випадково перемішаної колоди на екран
    std::cout << "Randomized Deck:" << std::endl;
    deck.displayDeck();

    // Видалення пар крайніх карт одного кольору та повторення 3 рази
    for (int i = 0; i < 3; ++i) {
        deck.removePairs();
    }

    // Виведення колоди після видалення пар на екран
    std::cout << "\nDeck after removing pairs:" << std::endl;
    deck.displayDeck();

    return 0;
}
