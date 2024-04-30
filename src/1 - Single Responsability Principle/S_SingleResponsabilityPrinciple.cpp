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
    cout << "Resultado da soma: " << sum << "\n";
    return 0;
}