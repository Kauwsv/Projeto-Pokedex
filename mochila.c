#include "mochila.h"

/**
 * @file mochila.c
 * @author Kauane dos Santos Vieira
 * @author Estefane de Lima dos Santos
 * @author Isabelle Rosvadoski Nofre
 * 
 * @date 15 Nov 2023
 * Depende da biblioteca mochila.h
 * 
 * Código feito no Windows
 */

/**
 * \brief Adiciona Pokemon na mochila
 *
 * \param mochila estrutura que contém pokemon capturados que acompanharão o jogador
 * \param colecao estrutura que contém pokemon capturados pelo ID e a relação de todos os pokemons do jogo
 *
 * Pede para o usuário o ID do pokemon que ele deseja adicionar na mochila, em seguida verifica se a quantidade de pokemon
 * na mochila é menor que 6, caso seja, testa se o pokemon já não está na mochila comparando os IDs. Em seguida, aloca 
 * dinamicamente um buffer para salvar todos os pokemon anteriores na mochila. Ainda, compara pelo ID se o pokemon esta na 
 * coleção, caso sim, atribui este a última posição de memória do buffer, incrementando a quantidade de pokemon na mochila e o encontrouPokemon.
 * Assim, salva as alterações do buffer em mochila->indicePokemonMochila, seguindo a mesma lógica para mochila->idPokemonMochila. Caso
 * a mochila esteja cheia (quantidade maior ou igual a 6), avisa ao usuário que não há espaço e retorna a função.
 */

void adicionarPokemonMochila(Mochila* mochila, Colecao* colecao){
    int idPokemonCapturado;
    
    int encontrouPokemon = 0;

    printf("Digite o ID de um Pokemon 'capturado': ");
    scanf("%d", &idPokemonCapturado);

    if(mochila->qtdPokemonsMochila < 6){

        for(int i = 0; i < mochila->qtdPokemonsMochila; i++){
            if(idPokemonCapturado == mochila->idPokemonsMochila[i]){
                printf("\nOps, esse pokemon ja foi armazenado!\n");
                return;
            }//if
        }//for

        int* bufferIndice = (int*) malloc(sizeof(int) * (mochila->qtdPokemonsMochila + 1));

        if(bufferIndice == NULL){
            perror("Erro ao alocar buffer do indice");
            exit(1);
        }//if

        for(int i = 0; i < mochila->qtdPokemonsMochila; i++){
            bufferIndice[i] = mochila->indicePokemonMochila[i];
        }

        for(int i = 0; i < colecao->qtdPokemonsCapturados; i++){
            if(idPokemonCapturado == colecao->idPokemonsCapturados[i]){
                mochila->qtdPokemonsMochila++;
                bufferIndice[mochila->qtdPokemonsMochila - 1] = colecao->indicePokemonsColecao[i]; 
                printf("\n%s foi adicionado com sucesso!\n", colecao->dadosPokemon[bufferIndice[mochila->qtdPokemonsMochila - 1]].nome);
                encontrouPokemon++;
                break;
            }//if
        }//for

        if(encontrouPokemon == 0){
            printf("\nOpcao invalida! O Pokemon solicitado nao esta na colecao.\n");
            return;
        }

        mochila->indicePokemonMochila = bufferIndice;

        int* buffer = (int*) malloc((mochila->qtdPokemonsMochila) * sizeof(int));

        if(buffer == NULL){
            perror("Erro ao alocar buffer");
            exit(1);
        }//if

        for(int i = 0; i < (mochila->qtdPokemonsMochila - 1); i++){
            buffer[i] = mochila->idPokemonsMochila[i];
        }//for

        buffer[mochila->qtdPokemonsMochila - 1] = idPokemonCapturado;

        mochila->idPokemonsMochila = buffer;

        return;
        
    } 
    
    printf("\nOps, sua mochila esta cheia! Se voce deseja adicionar um novo pokemon, por favor, exclua um de seus mascotes!\n");
    
    return;
    
}//adicionarPokemonMochila

/**
 * \brief Exclui Pokemon da mochila
 *
 * \param mochila estrutura que contém pokemon capturados que acompanharão o jogador
 *
 * Pede para o usuário o ID do pokemon que ele deseja excluir da mochila, em seguida verifica se o pokemon esta de fato na 
 * mochila. Caso esteja, aloca um buffer dinamicamente com um espaço a menos que a quantidade de pokemon na mochila, o qual 
 * recebe o ID de pokemon na mochila, pulando apenas o ID solicitado pelo usuário para exclusão. Assim a quantidade de pokemon
 * na mochila é decrementada e mochila->idPokemonMochila recebe buffer atualizado.
 */

void excluirPokemonMochila(Mochila* mochila, Colecao* colecao){
    int IDpokemon;
    int contador = 0;
    int novoIndice = 0;

    printf("Digite o numero do Pokemon que voce deseja excluir da mochila: ");
    scanf("%d", &IDpokemon);

    for(int i = 0; i < mochila->qtdPokemonsMochila; i++){
        if(IDpokemon == mochila->idPokemonsMochila[i]){
            printf("\n%s foi excluido com sucesso!\n", colecao->dadosPokemon[mochila->indicePokemonMochila[i]].nome);
            contador++;
            break;
        }//if
    }//for

    if(contador == 1){
        int* buffer = (int*) malloc((mochila->qtdPokemonsMochila - 1) * sizeof(int));
        int* bufferIndice = (int*) malloc((mochila->qtdPokemonsMochila - 1) * sizeof(int));
        
        for(int i = 0; i < mochila->qtdPokemonsMochila; i++){
            if (IDpokemon != mochila->idPokemonsMochila[i]){ 
                buffer[novoIndice] = mochila->idPokemonsMochila[i];
                bufferIndice[novoIndice] = mochila->indicePokemonMochila[i];
                novoIndice++;
            }//if
        }//for

        mochila->idPokemonsMochila = buffer;
        mochila->indicePokemonMochila = bufferIndice;

        mochila->qtdPokemonsMochila--;

        return;
    }else{
        printf("\nOps! O pokemon selecionado nao pertence a sua mochila.\n");
    }//else

    return;
}//excluirPokemonMochila

/**
 * \brief Exclui Pokemon da mochila
 *
 * \param colecao estrutura que contem pokemon capturados pelo ID e a relação de todos os pokemon do jogo
 * \param mochila estrutura que contém pokemon capturados que acompanharão o jogador
 *
 * Exibe uma lista de todos os pokemon que que estão na mochila por meio de um laço de repetição. Caso a qauntidade de 
 * pokemon na mochila seja zero, exibe mensagem que não há pokemon na mochila.
 */

void listarPokemonsMochila(Colecao* colecao, Mochila* mochila){
    printf("\n====== POKEMONS NA MOCHILA ======\n");

    if(mochila->qtdPokemonsMochila == 0){
        printf("\nOps, nao ha pokemons na mochila!\n");
        return;
    }//if

    for(int i = 0; i < mochila->qtdPokemonsMochila; i++){
        printf("%d. %s\n", colecao->dadosPokemon[mochila->indicePokemonMochila[i]].numero, colecao->dadosPokemon[mochila->indicePokemonMochila[i]].nome);
    }//for

    return;
}//listarPokemonsMochila
