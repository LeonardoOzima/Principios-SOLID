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