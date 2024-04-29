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