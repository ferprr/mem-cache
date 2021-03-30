#include <string>
#include "headers/bloco.hpp"

const int QTDE_PALAVRAS = 4;

Bloco::Bloco()
{
    this->palavras = new string[QTDE_PALAVRAS];
    this->sujo = false;
    this->tag = "";
}

bool Bloco::is_sujo()
{
    return this->sujo;
}

string Bloco::get_tag()
{
    return this->tag;
}