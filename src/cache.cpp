#include <string>
#include <iostream>
#include "headers/cache.hpp"
#include "headers/bloco.hpp"

const int QTDE_BLOCOS = 256;

Cache::Cache()
{
    this->blocos = new Bloco[QTDE_BLOCOS];
}

void Cache::escrever(string tag, string index, string offset, string valor)
{
    int indexAsInt = stoi(index, nullptr, 2);
    int offsetAsInt = stoi(offset, nullptr, 2);

    cout << "Escrita: I: " << indexAsInt << ", off: " << offsetAsInt << endl;

    Bloco blocoNoIndice = Bloco();

    blocoNoIndice.set_sujo(true);
    blocoNoIndice.set_tag(tag);
    blocoNoIndice.set_valor(offsetAsInt, valor);

    this->blocos[indexAsInt] = blocoNoIndice;
}

string Cache::ler(string tag, string index, string offset)
{
    int indexAsInt = stoi(index, nullptr, 2);

    Bloco blocoNoIndice = this->blocos[indexAsInt];

    bool sujo = blocoNoIndice.is_sujo();

    //
    string valT = blocoNoIndice.get_tag();
    int offsetAsInt = stoi(offset, nullptr, 2);
    string valV = blocoNoIndice.get_valor(offsetAsInt);
    cout << "Ler: i:" << indexAsInt << ", tag: " << tag << ", off: " << offsetAsInt
         << ", tag no Bloco: " << valT << ", val: " << valV << ", Sujo:" << sujo << endl;
    //

    if (!sujo)
    {
        return "MISS";
    }
    else
    {
        string tagNoBloco = blocoNoIndice.get_tag();

        if (tag == tagNoBloco)
        {
            return "HIT";
        }
        else
        {
            return "MISS";
        }
    }
}