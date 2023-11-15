/**
 * @file global.h
 * @author Estefane de Lima dos Santos
 * @author Kauane dos Santos Vieira
 * @author Isabelle Rosvadoski Nofre
 * 
 * @date 03 Nov 2023
 * @brief Definições globais usadas no programa
 *
 * Contém definições de cores e das estrutras iniciais de "Mochila" e "Coleção".
 *
 * Código feito no Windows
 */

#ifndef GLOBAL_H
#define GLOBAL_H

#define RESET   "\033[0m"
#define GRAY    "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

/**
 * @struct Colecao
 * \brief Essa estrutura é a representção da coleção de Pokémons do jogador
 *
 * Essa estrutura armazena dados da coleção de POkémon do jogador
 */
struct Colecao;

/**
 * @struct Mochila
 * \brief Essa estrutura é a representção da mochila do jogador
 *
 * Essa estrutura armazena dados da mochila do jogador
 */
struct Mochila;

typedef struct Colecao Colecao;
typedef struct Mochila Mochila;

#endif
