#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "headers/hierarquia.hpp"
#include "headers/cache.hpp"

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
    Hierarquia hier = Hierarquia();

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

            string dadoLido = hier.ler(enderecoMemoriaParaLeitura);
            cout << linha << " " << dadoLido << endl;
        }
        else if (operacao == "1")
        {
            int enderecoMemoriaParaEscrita = stringToInt(vetEntrada[0]);
            string dadoEscrita = vetEntrada[2];

            //cout << "Escrita: " << enderecoMemoriaParaEscrita << " --> " << dadoEscrita << endl;

            hier.escrever(enderecoMemoriaParaEscrita, dadoEscrita);
            cout << linha << " W" << endl;
        }
    }
}

void executarComArquivo(string caminhoArquivo, string printarInput)
{
    ofstream arquivoSaida("result.txt");

    ifstream arquivo;
    arquivo.open(caminhoArquivo);

    if (arquivo.is_open())
    {

        Hierarquia hier = Hierarquia();
        string linha;

        while (getline(arquivo, linha))
        {
            if (printarInput == "s")
            {
                cout << linha << endl;
            }

            string *vetEntrada = separaStringPorEspaco(3, linha);

            string operacao = vetEntrada[1];

            if (operacao == "0")
            {
                int enderecoMemoriaParaLeitura = stringToInt(vetEntrada[0]);

                //cout << "Leitura: " << enderecoMemoriaParaLeitura << endl;

                string dadoLido = hier.ler(enderecoMemoriaParaLeitura);
                cout << linha << " " << dadoLido << endl;
                arquivoSaida << linha << " " << dadoLido << endl;
            }
            else if (operacao == "1")
            {
                int enderecoMemoriaParaEscrita = stringToInt(vetEntrada[0]);
                string dadoEscrita = vetEntrada[2];

                //cout << "Escrita: " << enderecoMemoriaParaEscrita << " --> " << dadoEscrita << endl;

                hier.escrever(enderecoMemoriaParaEscrita, dadoEscrita);
                cout << linha << " W" << endl;
                arquivoSaida << linha << " W" << endl;
            }
        }
        arquivo.close();
        arquivoSaida.close();
    }
    else
    {
        cout << "Erro ao abrir arquivo." << endl;
        return;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        executarComInputsSobDemanda();
    }
    else if (argc == 3)
    {
        string caminhoArquivo = argv[1];
        string printarInput = argv[2];

        executarComArquivo(caminhoArquivo, printarInput);
    }
    else if (argc == 2)
    {
        string caminhoArquivo = argv[1];
        string printarInput = "n";

        executarComArquivo(caminhoArquivo, printarInput);
    }
    else
    {
        cout << "N??mero incorreto de par??metros. Envie nada OU o caminho para o arquivo E uma flag \"s\" ou \"n\" para printar os inputs na tela ou n??o." << endl;
    }

    //system("pause");

    return 0;
}
