#ifndef MOCHILA_H
#define MOCHILA_H

#include <stdio.h>
#include <stdlib.h>
#include "global.h" 
#include "colecao.h" 

/**
 * @file mochila.h
 * @author Kauane dos Santos Vieira
 * @author Estefane Santos de Lima
 * @author Kauane dos Santos Vieira
 * @author Isabelle Rosvadoski Nofre
 * 
 * @date 03 Nov 2023
 * @brief Contém os cabeçalhos das funções criadas em mochila.h, a estrutura de dados da mochila e todas as bibliotecas utilizadas para executar esse arquivo
 *
 * Contém os cabeçalhos da funções usadas para gerenciar a Mochila e a estrutura de dados Mochila.
 * Roda apenas no Windows
 */

struct Mochila { 
    int* idPokemonsMochila;
    int qtdPokemonsMochila;
    int* indicePokemonMochila;
};

void adicionarPokemonMochila(Mochila* mochila, Colecao* colecao); 
void listarPokemonsMochila(Colecao* colecao, Mochila* mochila);
void excluirPokemonMochila(Mochila* mochila, Colecao* colecao);

#endif
