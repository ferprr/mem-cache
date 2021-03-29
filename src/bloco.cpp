#include <string>
#include "headers/bloco.hpp"

const int QTDE_PALAVRAS = 4;

Bloco::Bloco()
{
    this->palavras = new string[QTDE_PALAVRAS];
}