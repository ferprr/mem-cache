#include <string>
#include "headers/bloco.hpp"

const int QTDE_PALAVRAS = 4;

Bloco::Bloco()
{
    this->palavras = new string[QTDE_PALAVRAS];
    this->sujo = false;
    this->tag = "";
    for(int i=0; i<4; i++){
        palavras[i]= "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    }
}

void Bloco::set_sujo(bool novoSujo)
{
    this->sujo = novoSujo;
}

bool Bloco::is_sujo()
{
    return this->sujo;
}

void Bloco::set_tag(string novaTag)
{
    this->tag = novaTag;
}
string Bloco::get_tag()
{
    return this->tag;
}

void Bloco::set_valor(int offset, string valor)
{
    this->palavras[offset] = valor;
}

string Bloco::get_valor(int offset)
{
    return this->palavras[offset];
}