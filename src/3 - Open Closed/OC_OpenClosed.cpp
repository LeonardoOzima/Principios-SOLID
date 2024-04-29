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