#include "menu.h"

/**
 * @file menu.c
 * @author Estefane de Lima dos Santos
 * @author Kauane dos Santos Vieira
 * @author Isabelle Rosvadoski Nofre
 * 
 * @date 03 Nov 2023
 * @brief Funções do menu e submenus do jogo
 * 
 * Esse arquivo contém as funções usadas para gerenciar o menu do jogo, incluindo submenus relacionados à pokedex, coleção, mochila, etc.
 * 
 * Código feito no Windows
 */

/**
 * \brief Submenu relacionado à Pokedex
 *
 * \param colecao ponteiro para a estrutura de dados da Colecao
 * \param mochila ponteiro para a estrutura de dados Mochila
 * \param qtdPokemons ponteiro para a quantidade total de Pokémon 
 *
 * Essa função aprensenta um submenu de Pokedex com as opções:
 * opção 1(case 1): alterar Pokémon; opção 2(case 2): pesquisar Pokémon por tipo e geração; opção 3(case 3); inserir novo Pokémon e opção 4(case 4): excluir Pokemon.
 * Caso o usuário digite uma opção inválida, é apresentada uma mensagem avisado-o(default).
 */
void submenuPokedex(Colecao* colecao, Mochila* mochila, int* qtdPokemons){
    int opcao;

    printf(RED);
    printf("\n#######################################\n");
    printf("#           SUBMENU POKEDEX           #\n");
    printf("#######################################\n");
    printf(RESET);
    printf(WHITE);
    printf("1 - Alterar Pokemon.\n");
    printf("2 - Pesquisar Pokemon por Tipo.\n");
    printf("3 - Pesquisar Pokemon por Geracao.\n");
    printf("4 - Inserir novo Pokemon.\n");
    printf("5 - Excluir Pokemon.\n");
    printf(RESET);
    printf(GRAY);
    printf("=======================================\n");
    printf(RESET);
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);

    switch(opcao){
        case 1:
            system("cls");
            Beep(700, 200);
            alterarPokemon(colecao, mochila, (*qtdPokemons));
            break;

        case 2:
            system("cls");
            Beep(700, 200);
            pesquisarPokemonTipo(colecao, qtdPokemons);
            break;

        case 3:
            system("cls");
            Beep(700, 200);
            pesquisarPokemonGeracao(colecao, qtdPokemons);
            break;
        
        case 4:
            system("cls");
            Beep(700, 200);
            inserirPokemonPokedex(colecao, qtdPokemons);
            break;

        case 5:
            system("cls");
            Beep(700, 200);
            excluirPokemonPokedex(colecao, qtdPokemons);
            break;
        
        default:
            system("cls");
            Beep(700, 200);
            printf("%s%s%s\n", RED, "\nOps, o valor que voce digitou nao coincide com nenhuma das opcoes!\n", RESET);
            break;
    }//switch

}

/**
 * \brief Submenu relacionado à Pokedex
 *
 * \param colecao ponteiro para a estrutura de dados da Colecao
 * \param mochila ponteiro para a estrutura de dados Mochila
 * \param qtdPokemons ponteiro para a quantidade total de Pokémon 
 *
 * Essa função aprensenta um submenu de coleção com as opções:
 * listar os Pokémon capturados, pesquisar Pokémon, excluir Pokémon capturados e adcionar Pokémon capturados.
 * Caso o usuário digite uma opção inválida, é apresentada uma mensagem avisado-o.
 */
void submenuColecao(Colecao* colecao, Mochila* mochila, int qtdPokemons){
    int opcao;

    printf(RED);
    printf("\n#######################################\n");
    printf("#           SUBMENU COLECAO           #\n");
    printf("#######################################\n");
    printf(RESET);
    printf(WHITE);
    printf("1 - Listar Pokemons Capturados.\n");
    printf("2 - Pesquisar Pokemons Capturados.\n");
    printf("3 - Excluir Pokemons Capturados.\n");
    printf("4 - Adicionar Pokemons Capturados.\n");
    printf(RESET);
    printf(GRAY);
    printf("=======================================\n");
    printf(RESET);
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);

    switch(opcao){
        case 1:
            system("cls");
            Beep(700, 200);
            listarPokemonsCapturados(colecao); 
            break;
        
        case 2:
            system("cls");
            Beep(700, 200);
            pesquisarPokemonsCapturados(colecao); 
            break;
        
        case 3:
            system("cls");
            Beep(700, 200);
            excluirPokemonCapturado(colecao);
            break;
        
        case 4:
            system("cls");
            Beep(700, 200);
            adicionarPokemonColecao(colecao, qtdPokemons);
            break;
        
        default:
            system("cls");
            Beep(700, 200);
            printf("%s%s%s\n", RED, "\nOps, o valor que voce digitou nao coincide com nenhuma das opcoes!\n", RESET);
            break;  
    }//switchColecao
}

/**
 * \brief Submenu relacionado à mochila do jogador
 *
 * \param colecao ponteiro para a estrutura de dados da Colecao
 * \param mochila ponteiro para a estrutura de dados Mochila
 *
 * Essa função aprensenta um submenu da mochila do jogador com as opções:
 * adicionar Pokémon na mochila, excluir Pokémon e listar Pokémon
 * Caso o usuário digite uma opção inválida, é apresentada uma mensagem avisado-o. 
 */
void submenuMochila(Colecao* colecao, Mochila* mochila){

    int opcao;
  
    printf(RED);
    printf("\n#######################################\n");
    printf("#           SUBMENU MOCHILA           #\n");
    printf("#######################################\n");
    printf(RESET);
    printf(WHITE);
    printf("1 - Adicionar Pokemon na Mochila\n");
    printf("2 - Excluir Pokemon da Mochila\n");
    printf("3 - Listar Pokemons da Mochila\n");
    printf(RESET);
    printf(GRAY);
    printf("=======================================\n");
    printf(RESET);
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);

    switch(opcao){
        case 1:
            system("cls");
            Beep(700, 200);
            adicionarPokemonMochila(mochila, colecao);
            break;
            
        case 2:
            system("cls");
            Beep(700, 200);
            excluirPokemonMochila(mochila, colecao);
            break;
            
        case 3:
            system("cls");
            Beep(700, 200);
            listarPokemonsMochila(colecao, mochila);
            break;
        
        default:
            system("cls");
            Beep(700, 200);
            printf("%s%s%s\n", RED, "\nOps, o valor que voce digitou nao coincide com nenhuma das opcoes!\n", RESET);
            break;
    }//switchMochila

}

/**
 * \brief Menu principal do jogo
 *
 * \param colecao ponteiro para a estrutura de dados da Colecao
 * \param mochila ponteiro para a estrutura de dados Mochila
 * \param qtdPokemons ponteiro para a quantidade total de Pokémon
 * 
 * Essa função permite que o usuário navegue entre as ferramentas do jogo, sendo:
 * Pokedex, Coleção, Mochila, Loja, Perfil do Usuário, Configurações, Mapa de níveis, Criar arquivo CSV e Finalizar programa.
 * Caso o usuário digite uma opção inválida, é apresentada uma mensagem avisado-o. 
 */
void menuDoJogo(Colecao* colecao, Mochila* mochila, int* qtdPokemons){
    int opcao;

    do{
        printf(RED);
        printf("\n##########################\n");
        printf("#      MENU DO JOGO      #\n");
        printf("##########################\n");
        printf(RESET);
        printf(WHITE);
        printf("1 - Pokedex.\n");
        printf("2 - Colecao.\n");
        printf("3 - Mochila.\n");
        printf("4 - Loja.\n");
        printf("5 - Perfil do Usuario.\n");
        printf("6 - Configuracoes.\n");
        printf("7 - Mapa de Niveis.\n");
        printf("8 - Criar Arquivo CSV.\n");
        printf("9 - Finalizar Programa.\n");
        printf(RESET);
        printf(GRAY);
        printf("==========================\n");
        printf(RESET);
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        setbuf(stdin, NULL);

        switch(opcao){
        case 1:
            system("cls");
            Beep(700, 200);
            submenuPokedex(colecao, mochila, qtdPokemons);
            break;
        case 2:
            system("cls");
            Beep(700, 200);
            submenuColecao(colecao, mochila, (*qtdPokemons));
            break;
            
        case 3:
            system("cls");
            Beep(700, 200);
            submenuMochila(colecao, mochila);
            break;

        case 4:
            system("cls");
            Beep(700, 200);
            printf("\n%s%s%s\n", CYAN, "Em breve...", RESET);
            break;

        case 5:
            system("cls");
            Beep(700, 200);
            printf("\n%s%s%s\n", CYAN, "Em breve...", RESET);
            break;

        case 6:
            system("cls");
            Beep(700, 200);
            printf("\n%s%s%s\n", CYAN, "Em breve...", RESET);
            break;

        case 7:
            system("cls");
            Beep(700, 200);
            printf("\n%s%s%s\n", CYAN, "Em breve...", RESET);
            break;
        
        case 8:
            system("cls");
            Beep(700, 200);
            printf("\n%s%s%s\n", CYAN, "Criando arquivo .csv...", RESET);
            criarArquivoCSV(colecao, mochila, qtdPokemons);
            break;

        case 9:
            system("cls");
            Beep(700, 200);
            printf("\n%s%s%s\n", GREEN, "Salvando dados...", RESET);
            atualizaArquivo(colecao, mochila, qtdPokemons);
            printf("\n%s%s%s\n", RED, "Finalizando programa!", RESET);
            break;

        default:
            system("cls");
            Beep(700, 200);
            printf("\n%s%s%s\n", RED, "Ops, o valor que voce digitou nao coincide com nenhuma das opcoes!", RESET);
            break;
            
        }//switch
    }while(opcao != 9);

    return;
}
