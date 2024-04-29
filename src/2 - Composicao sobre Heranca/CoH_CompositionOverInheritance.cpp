#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ItemMenu
{
public:
    ItemMenu(const string &nome) : nome(nome) {}
    void addingredient(const string &ingredient)
    {
        ingredients.push_back(ingredient);
    }
    void listingredients() const
    {
        cout << "ingredientes do " << nome << ":\n";
        for (const auto &ingredient : ingredients)
        {
            cout << "- " << ingredient << "\n";
        }
    }

private:
    string nome;
    vector<string> ingredients; // Violação: Usando herança para representar ingredients
};

int main()
{
    ItemMenu sandwich("Sanduíche");
    sandwich.addingredient("Queijo");
    sandwich.addingredient("Tomate");
    sandwich.addingredient("Alface");

    sandwich.listingredients();

    return 0;
}