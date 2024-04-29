# Principios-SOLID

## Esta é a branch com as correções do código.

## S - Single Responsability Principle

> File: src/1 - Single Responsability Principle/S_SingleResponsabilityPrinciple.cpp

**O que é?**
Um exemplo de classe que realiza cálculos e também faz log das operações.

**Problema:**
A classe Calculator tem duas responsabilidades, o que dificulta a manutenção.

```
#include <iostream>
#include <fstream>

class Logger
{
public:
    void log(const std::string &message)
    {
        // Grava a mensagem em um arquivo de log
        std::ofstream logFile("log.txt", std::ios::app);
        logFile << message << "\n";
        logFile.close();
    }
};

class Calculator
{
public:
    int add(int a, int b)
    {
        int result = a + b;
        Logger logger;
        logger.log("Operação de adição executada.");
        return result;
    }
};

int main()
{
    Calculator calculator;
    int sum = calculator.add(5, 3);
    std::cout << "Resultado da soma: " << sum << "\n";
    return 0;
}

```

## Composition Over Inheritance

> File: src/2 - Composition Over Inheritance/CoH_CompositionOverInheritance.cpp

**O que é?**
O código apresentado define uma classe chamada ItemMenu, que representa um item de menu com ingredientes. Essa classe permite adicionar ingredientes e listar os ingredientes associados a um item específico.

**Problema:**
A utilização de herança para representar os ingredientes no ItemMenu é inadequada. A classe ItemMenu deveria se concentrar apenas na lógica relacionada ao menu, enquanto a gestão dos ingredientes deveria ser tratada por meio de composição. Essa abordagem mais modular facilitaria a manutenção e permitiria maior flexibilidade na evolução do código.

```
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

```

## Open Closed Principle

> File: src/3 - Open Closed/OC_OpenClosed.cpp

**O que é?**
O código apresentado define uma classe chamada Calculadora que realiza operações matemáticas simples, como soma e subtração. Além disso, foi adicionada uma nova funcionalidade para calcular a área de um círculo com base no raio fornecido.

**Problema:**
A classe Calculadora possui métodos específicos para soma, subtração e a nova funcionalidade de cálculo da área do círculo. Se desejarmos adicionar mais operações matemáticas no futuro (por exemplo, multiplicação, divisão), teríamos que modificar a classe Calculadora, o que não é desejável.

```
class Calculadora
{
public:
    double sum(double a, double b)
    {
        return a + b;
    }

    double sub(double a, double b)
    {
        return a - b;
    }

    // Adicionando uma nova funcionalidade
    double newFunction(double raio)
    {
        return 3.14159 * raio * raio;
    }
};

```

## Demeter Principle

> File: src/4 - Demeter Principle/DP_DemeterPrinciple.cpp

**O que é?**
O código apresentado é um exemplo de classes que simulam um sistema de um carro, ele inclui uma classe Velocimetro que possui um método para pegar a velocidade, uma classe Motor que possui um atributo do tipo Velocimetro, e uma classe Carro que possui um atributo do tipo Motor.

**Problema:**
O método getVelocidadeDoMotor() da classe Carro acessa indiretamente a velocidade do motor através do objeto Motor e, por sua vez, através do objeto Velocimetro. Isso cria um acoplamento forte entre as classes, tornando o código menos flexível e mais difícil de manter.

```
#include <iostream>

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
    Velocimetro velocimetro;
};

class Carro
{
public:
    Motor motor;

    int getVelocidadeDoMotor()
    {
        // Violação do Princípio de Demeter: Acesso indireto através de outro objeto
        return motor.velocimetro.getVelocidade();
    }
};

int main()
{
    Carro meuCarro;
    std::cout << "Velocidade do motor: " << meuCarro.getVelocidadeDoMotor() << std::endl;
    return 0;
}

```
