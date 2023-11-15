#ifndef COLECAO_H
#define COLECAO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "global.h"
#include "mochila.h"

/**
 * @file colecao.h
 * @author Kauane dos Santos Vieira
 * @author Estefane de Lima dos Santos
 * @author Isabelle Rosvadoski Nofre
 * @date 15 Nov 2023
 * @brief Contem os cabecalhos das funções criadas em colecao.c e todas as bibliotecas utilizadas para executar esse arquivo
 *
 * Contém os cabeçalhos da funções que gerenciam coleção e as estruturas de dados Pokemon e Colecao.
 * Roda apenas no Windows
 */

typedef struct{
    int numero;
    char nome[52];
    char tipo1[22];
    char tipo2[22];
    int total;
    int hp;
    int ataque;
    int defesa;
    int ataqueEspecial;
    int defesaEspecial;
    int velocidade;
    int geracao;
    int lendario;
    char cor[22];
    float altura;
    float peso;
    int taxaCaptura;
    int proximaEvolucao;
    int preEvolucao;
} Pokemon;

struct Colecao { 
    Pokemon* dadosPokemon; 
    int* idPokemonsCapturados;
    int qtdPokemonsCapturados;
    int* indicePokemonsColecao;
};

void adicionarPokemonColecao(Colecao* colecao, int qtdPokemons); 
void listarPokemonsCapturados(Colecao* colecao);
void excluirPokemonCapturado(Colecao* colecao);
void exibirDadosUltimoPokemonCapturado(Colecao* colecao);
void pesquisarPokemonsCapturados(Colecao* colecao);

#endif
