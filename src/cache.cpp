#include <string>
#include "headers/cache.hpp"
#include "headers/bloco.hpp"

const int QTDE_BLOCOS = 256;

Cache::Cache()
{
    this->blocos = new Bloco[QTDE_BLOCOS];
}

string Cache::ler(string tag, string index, string offset)
{
    int indexAsInt = stoi(index, nullptr, 2);

    Bloco blocoNoIndice = this->blocos[indexAsInt];

    bool sujo = blocoNoIndice.is_sujo();

    if (!sujo)
    {
        return "MISS_CLEAN";
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
            return "MISS_DIRTY";
        }
    }
}