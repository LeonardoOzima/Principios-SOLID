#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Ingredient
{
public:
    Ingredient(const string &nome) : nome(nome) {}
    string getName() const
    {
        return nome;
    }

private:
    string nome;
};

class ItemMenu
{
public:
    ItemMenu(const string &nome) : nome(nome) {}
    void addIngredient(const Ingredient &Ingredient)
    {
        Ingredients.push_back(Ingredient);
    }
    void listarIngredients() const
    {
        cout << "Ingredientes do " << nome << ":\n";
        for (const auto &Ingredient : Ingredients)
        {
            cout << "- " << Ingredient.getName() << "\n";
        }
    }

private:
    string nome;
    vector<Ingredient> Ingredients; // Usando composição para representar Ingredients
};

int main()
{
    Ingredient queijo("Queijo");
    Ingredient tomate("Tomate");
    Ingredient alface("Alface");

    ItemMenu sandwich("Sanduíche");
    sandwich.addIngredient(queijo);
    sandwich.addIngredient(tomate);
    sandwich.addIngredient(alface);

    sandwich.listarIngredients();

    return 0;
}