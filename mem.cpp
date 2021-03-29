#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string *separaStringPorEspaco(int tamanho, string str)
{
    istringstream iss(str);

    string *strVet = new string[tamanho];

    int indexTotal = 0;
    do
    {
        string subStr;
        iss >> subStr;

        strVet[indexTotal] = subStr;
        indexTotal++;

        if (indexTotal == tamanho)
            break;
    } while (iss);

    return strVet;
}

int stringToInt(string s)
{
    stringstream strStream(s);
    int strAsInt;
    strStream >> strAsInt;
    return strAsInt;
}

void executarComInputsSobDemanda()
{
    string linha;
    //Memoria memoria;

    while (getline(cin, linha))
    {
        if (linha.empty())
        {
            break;
        }

        string *vetEntrada = separaStringPorEspaco(3, linha);

        string operacao = vetEntrada[1];

        if (operacao == "0")
        {
            int enderecoMemoriaParaLeitura = stringToInt(vetEntrada[0]);

            //cout << "Leitura: " << enderecoMemoriaParaLeitura << endl;

            //TODO:
            //string dadoLido = memoria.ler(enderecoMemoriaParaLeitura);
        }
        else if (operacao == "1")
        {
            int enderecoMemoriaParaEscrita = stringToInt(vetEntrada[0]);
            string dadoEscrita = vetEntrada[2];

            //cout << "Escrita: " << enderecoMemoriaParaEscrita << " --> " << dadoEscrita << endl;

            //TODO:
            //bool hitOuMiss = memoria.escreverNaCache(enderecoMemoriaParaEscrita);
        }
    }
}

int main()
{

    executarComInputsSobDemanda();

    return 0;
}