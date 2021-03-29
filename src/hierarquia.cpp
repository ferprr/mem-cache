#include <string>
#include "headers/hierarquia.hpp"

const int QTDE_MEMORIA_DADOS = 4096;

Hierarquia::Hierarquia()
{
    this->memoria_dados = new string[QTDE_MEMORIA_DADOS];
    this->memoria_cache = new Cache();
}

void Hierarquia::escreverNaCache(int endereco, string dado)
{
    //this->cache.set_dado(int endereco, string dado);

    //chama metodo converter endereco e buscar valores offset, index e tag
    //verificar se na cache, bloco com index==index está sujo
    //se estiver limpo: colocar dado na posição do index + offset na cache
    //se não: devemos pegar o valor que estiver na posição do index + offset + tag na cache
    //colocar valor encontrado acima na memória de dados e colocar dado na posição do index + offset na cache
}