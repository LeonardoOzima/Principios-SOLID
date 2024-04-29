# Principios-SOLID

## Esta é a branch main que contém os códigos corrigidos.

## Para acessar os códigos que violam os principios, acesse a branch _incorrect_

## S - Single Responsability Principle

> File: src/1 - Single Responsability Principle/S_SingleResponsabilityPrinciple.cpp

**O que é?**
O código é um exemplo corrigido que separa as responsabilidades de cálculo e log.

**Como funciona:**
A classe Calculator lida apenas com cálculos, enquanto a classe Logger faz log das operações.

```
#include <iostream>
#include <fstream>
using namespace std;
class Logger
{
public:
    void log(const string &message)
    {
        // Grava a mensagem em um arquivo de log
        ofstream logFile("log.txt", ios::app);
        if (logFile.is_open())
        { // Verifica se o arquivo foi aberto com sucesso
            logFile << message << "\n";
            logFile.close();
        }
        else
        {
            cerr << "Erro ao abrir o arquivo de log.\n";
        }
    }
};

class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }
};

int main()
{
    Calculator calculator;
    int sum = calculator.add(5, 3);
    cout << "Resultado da soma: " << sum << "\n";

    Logger logger;
    logger.log("Operação de adição executada.");

    return 0;
}

```

## Composition Over Inheritance

> File: src/2 - Composition Over Inheritance/CoH_CompositionOverInheritance.cpp

**O que é?**
O código é um exemplo corrigido que utiliza o princípio de composição para representar os ingredientes de um item de menu. Ele consiste em duas classes: Ingredient e ItemMenu. A classe Ingredient representa um ingrediente específico, como queijo, tomate ou alface. A classe ItemMenu representa um item do menu (por exemplo, um sanduíche) e utiliza composição para manter uma lista de ingredientes associados a esse item.

**Como funciona:**
No código corrigido, a classe ItemMenu possui um atributo chamado Ingredients, que é uma coleção (vetor) de objetos Ingredient. Quando um novo ingrediente é adicionado a um item de menu, ele é inserido na lista de ingredientes usando o método addIngredient. O método listarIngredients percorre essa lista e exibe os nomes dos ingredientes associados ao item de menu. A composição permite que cada item de menu tenha sua própria lista exclusiva de ingredientes, sem herdar diretamente de uma classe base. Dessa forma, a estrutura é mais flexível e modular, facilitando a manutenção e expansão do código.

```
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
```

## Open Closed Principle

> File: src/3 - Open Closed/OC_OpenClosed.cpp

**O que é?**
O código corrigido representa uma interface de calculadora que implementa a classe OperacaoMatematica define uma interface para operações matemáticas, as classes Soma, Subtracao e newFunction implementam essa interface, cada uma representando uma operação específica.

**Como funciona:**
A classe Calculadora agora usa a interface OperacaoMatematica para executar operações sem se preocupar com a implementação específica. Novas operações podem ser adicionadas criando novas classes que implementam a interface. Essa abordagem promove a flexibilidade, reusabilidade e manutenção do sistema, seguindo o princípio aberto/fechado.

```
// Interface para operações matemáticas
class OperacaoMatematica
{
public:
    virtual double execute(double a, double b) = 0;
};

// Implementação da soma
class Soma : public OperacaoMatematica
{
public:
    double execute(double a, double b) override
    {
        return a + b;
    }
};

// Implementação da subtração
class Subtracao : public OperacaoMatematica
{
public:
    double execute(double a, double b) override
    {
        return a - b;
    }
};

// Implementação do cálculo da área do círculo
class newFunction : public OperacaoMatematica
{
public:
    double execute(double raio, double /*b*/) override
    {
        return 3.14159 * raio * raio;
    }
};

// Classe Calculadora que agora usa a interface
class Calculadora
{
public:
    double executeOperacao(OperacaoMatematica *operacao, double a, double b)
    {
        return operacao->execute(a, b);
    }
};

```

## Demeter Principle

> File: src/4 - Demeter Principle/DP_DemeterPrinciple.cpp

**O que é?**
O código apresentado é um exemplo de classes que simulam um sistema de um carro, ele inclui uma classe Velocimetro que possui um método para pegar a velocidade, uma classe Motor, e uma classe Carro que possui um atributo do tipo Motor e do tipo Velocimetro.

**Como funciona:**
A classe Carro foi refatorada para respeitar o Princípio de Demeter. Agora, o Carro possui seu próprio objeto Velocimetro, em vez de acessar o Velocimetro diretamente através do objeto Motor. O método getVelocidadeDoMotor no Carro chama o método getVelocidade do Velocimetro diretamente, sem atravessar outros objetos. Isso reduz o acoplamento entre as classes e melhora a manutenibilidade do código.

```
#include <iostream>
using namespace std;
class Velocimetro
{
public:
    int getVelocidade()
    {
        return 120; // Exemplo simplificado
    }
};

class Motor
{
public:
    // Removemos o acesso direto ao Velocimetro
};

class Carro
{
public:
    Motor motor;
    Velocimetro velocimetro; // Agora o Carro tem seu próprio Velocimetro

    int getVelocidadeDoMotor()
    {
        // Respeitando o Princípio de Demeter: Acesso direto ao Velocimetro
        return velocimetro.getVelocidade();
    }
};

int main()
{
    Carro meuCarro;
    cout << "Velocidade do motor: " << meuCarro.getVelocidadeDoMotor() << endl;
    return 0;
}

```
