/**
 * @file menu.h
 * @author Estefane de Lima dos Santos
 * @author Kauane dos Santos Vieira
 * @author Isabelle Rosvadoski Nofre
 * 
 * @date 03 Nov 2023
 * @brief Sistema de menu do jogo com declaração das funções usadas neste
 *
 * Este arquivo contém as declarações das funções usadas no menu do jogo, incluindo submenus relacionados à pokedex, coleção, mochila, etc.
 * Depende das bibliotecas windows.h e stdlib.h
 * Código feito no Windows
 */
 
#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <windows.h>
#include "colecao.h"
#include "mochila.h"
#include "pokedex.h"
#include "global.h"

/**
 * \brief Submenu relacionado à coleção de Pokémon
 *
 * \param colecao ponteiro para a estrutura de dados da Colecao
 * \param mochila ponteiro para a estrutura de dados Mochila 
 * \param qtdPokemons indica a quantidade total de Pokémon
 */
void submenuColecao(Colecao* colecao, Mochila* mochila, int qtdPokemons);

/**
 * \brief Submenu relacionado à mochila do jogador
 *
 * \param colecao ponteiro para a estrutura de dados da Colecao
 * \param mochila ponteiro para a estrutura de dados Mochila 
 */
void submenuMochila(Colecao* colecao, Mochila* mochila);

/**
 * \brief Menu principal do jogo
 *
 * \param colecao ponteiro para a estrutura de dados da Colecao
 * \param mochila ponteiro para a estrutura de dados Mochila
 * \param qtdPokemons ponteiro para a quantidade total de Pokémon 
 */
void menuDoJogo(Colecao* colecao, Mochila* mochila, int* qtdPokemons);

/**
 * \brief Submenu relacionado à Pokedex
 *
 * \param colecao ponteiro para a estrutura de dados da Colecao
 * \param mochila ponteiro para a estrutura de dados Mochila
 * \param qtdPokemons ponteiro para a quantidade total de Pokémon 
 */
void submenuPokedex(Colecao* colecao, Mochila* mochila, int* qtdPokemon);

#endif //MENU_H
