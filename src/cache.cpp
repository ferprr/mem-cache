#include "headers/cache.hpp"
#include "headers/bloco.hpp"

const int QTDE_BLOCOS = 4096;

Cache::Cache()
{
    this->blocos = new Bloco[QTDE_BLOCOS];
}