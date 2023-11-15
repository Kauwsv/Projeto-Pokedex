#ifndef POKEDEX_H
#define POKEDEX_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "global.h"
#include "colecao.h"
#include "arquivo.h"

/**
 * @file pokedex.h
 * @author Kauane dos Santos Vieira
 * @author Estefane Santos de Lima
 * @author Kauane dos Santos Vieira
 * @author Isabelle Rosvadoski Nofre
 * 
 * @date 03 Nov 2023
 * @brief Contém os cabeçalhos das funções criadas em pokedex.h e todas as bibliotecas utilizadas para executar esse arquivo
 *
 * Contém os cabeçalhos da funções usadas para gerenciar a Pokedex.
 * Roda apenas no Windows
 */

void pesquisarPokemonTipo(Colecao* colecao, int* qtdPokemons);
void pesquisarPokemonGeracao(Colecao* colecao, int* qtdPokemons);
void inserirPokemonPokedex(Colecao* colecao, int* qtdPokemons);
void excluirPokemonPokedex(Colecao* colecao, int* qtdPokemons);
void alterarPokemon(Colecao* colecao, Mochila* mochila, int qtdPokemons);

#endif
