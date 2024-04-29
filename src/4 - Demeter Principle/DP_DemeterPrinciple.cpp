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