#include "headers/cache.hpp"
#include "headers/bloco.hpp"

Cache::Cache()
{
    this->bloco = new Bloco[256];
    this->tag = new string[256];
    this->sujo = new bool[256];

    for (int i = 0; i < 256; i++)
    {
        sujo[i] = false;
    }
}
bool Cache::get_sujo()
{
    return this->sujo;
}
void Cache::set_dado(int bloco, string endereco)
{
    this->bloco[bloco].set_endereco(endereco) = endereco;
}