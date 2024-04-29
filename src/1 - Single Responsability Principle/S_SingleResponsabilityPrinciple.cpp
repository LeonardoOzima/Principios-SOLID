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
