#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colecao.h"
#include "mochila.h"
#include "pokedex.h"
#include "menu.h"
#include "global.h"

/**
 * @file main.c
 * @author Kauane dos Santos Vieira
 * @author Estefane de Lima dos Santos
 * @author Isabelle Rosvadoski Nofre
 * @date 15 Nov 2023
 * @brief Executa as principais operacoes do sistema de pokemons
 * Depende das bibliotecas cadastradas em todos os arquivos .h da pasta "src"
 * 
 * Código feito no Windows
 */

/**
 * \brief Executa as principais operacoes do sistema de pokemons;
 * Abre o principal arquivo HD, declara e inicializa qtdPokemons e as estruturas colecao e mochila;
 * Chama as funcoes carregaArquivo e MenuDoJogo;
 * Desaloca todos os componentes alocados dinamicamente;
 * Fecha o principal arquivo HD.
 */

int main(){
    FILE* arquivoDadosUsuario;
    int qtdPokemons = 0;
    
    Colecao colecao;
    colecao.qtdPokemonsCapturados = 0;

    Mochila mochila;
    mochila.qtdPokemonsMochila = 0;

    arquivoDadosUsuario = fopen("dadosUsuario.dat", "rb");

    carregaArquivo(arquivoDadosUsuario, &colecao, &mochila, &qtdPokemons);

    menuDoJogo(&colecao, &mochila, &qtdPokemons);

    free(colecao.dadosPokemon);
    free(colecao.idPokemonsCapturados);
    free(colecao.indicePokemonsColecao);
    free(mochila.idPokemonsMochila);
    free(mochila.indicePokemonMochila);
    fclose(arquivoDadosUsuario);

    return 0;
}//main
