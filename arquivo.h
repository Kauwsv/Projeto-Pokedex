#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "global.h" 
#include "colecao.h"

/**
 * @file arquivo.h
 * @author Kauane dos Santos Vieira
 * @author Estefane de Lima dos Santos
 * @author Isabelle Rosvadoski Nofre
 * @date 15 Nov 2023
 * @brief Contem os cabecalhos das funcoes criadas em arquivo.c e todas as bibliotecas utilizadas para executar esse arquivo
 *
 * Roda apenas no Windows
 */

void carregaArquivo(FILE* arquivoDadosUsuario, Colecao* colecao, Mochila* mochila, int* qtdPokemons);
void atualizaArquivo(Colecao* colecao, Mochila* mochila, int* qtdPokemons);
void criarArquivoCSV(Colecao* colecao, Mochila* mochila, int* qtdPokemons);

#endif
