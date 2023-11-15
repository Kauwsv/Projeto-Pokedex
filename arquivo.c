#include "colecao.h"

/**
 * @file colecao.c
 * @author Kauane dos Santos Vieira
 * @author Estefane de Lima dos Santos
 * @author Isabelle Rosvadoski Nofre
 * @date 15 Nov 2023
 * @brief Manipula todos os dados armazenados na estrutura colecao
 * Todas as bibliotecas utilizadas nesse arquivo foram inseridas em colecao.h
 *
 * Codigo feito no Windows
 */

/**
 * \brief insere um novo pokemon capturado na estrutura colecao
 *
 * \param colecao estrutura que armazena os dados dos pokemons e a relacao de pokemons capturados pelo usuario
 * \param qtdPokemons quantidade total de pokemons cadastrados no sistema
 * 
 * solicita ao usuario o ID do pokemon a ser adicionado na colecao;
 * verifica se o ID informado consta no banco de dados da colecao, a fim de evitar duplicidade;
 * verifica se o ID informado consta no vetor dadosPokemon, com o intuito de evitar adicionar pokemons inexistentes;
 * caso o ID informado seja valido e nao duplicado, utiliza buffers para salvar os dados anteriores da colecao, redimensiona o tamanho da colecao e adiciona os dados referentes ao novo pokemon capturado, utilizando o ID e a posicao que ele ocupa no vetor dadosPokemon.
 */

void adicionarPokemonColecao(Colecao* colecao, int qtdPokemons){
    int idPokemonCapturado;
    int encontrouPokemon = 0;

    printf("Digite o ID do pokemon que deseja adicionar em Colecao: ");
    scanf("%d", &idPokemonCapturado);

    for(int i = 0; i < colecao->qtdPokemonsCapturados; i++){
        if(idPokemonCapturado == colecao->idPokemonsCapturados[i]){
            printf("\nOps, esse pokemon ja foi capturado!\n");
            return;
        }//if
    }//for

    int* bufferIndice = (int*) malloc(sizeof(int) * (colecao->qtdPokemonsCapturados + 1));

    if(bufferIndice == NULL){
        perror("Erro ao alocar buffer do indice");
        exit(1);
    }//if

    for(int i = 0; i < colecao->qtdPokemonsCapturados; i++){
        bufferIndice[i] = colecao->indicePokemonsColecao[i];
    }

    for(int i = 0; i < qtdPokemons; i++){
        if(idPokemonCapturado == colecao->dadosPokemon[i].numero){
            colecao->qtdPokemonsCapturados++;
            bufferIndice[colecao->qtdPokemonsCapturados - 1] = i; 
            encontrouPokemon++;
            break;
        }
    }
    
    if(encontrouPokemon == 0){
        printf("\nID nao encontrado! O pokemon nao consta no sistema.\n");
        return;
    }

    colecao->indicePokemonsColecao = bufferIndice;

    int* buffer = (int*) malloc((colecao->qtdPokemonsCapturados) * sizeof(int)); 

    if(buffer == NULL){
        perror("Erro ao alocar buffer");
        exit(1);
    }//if

    for(int i = 0; i < (colecao->qtdPokemonsCapturados - 1); i++){
        buffer[i] = colecao->idPokemonsCapturados[i];
    }//for

    buffer[colecao->qtdPokemonsCapturados - 1] = idPokemonCapturado;
    
    colecao->idPokemonsCapturados = buffer; 

    printf("\n%s adicionado a colecao com sucesso!\n", colecao->dadosPokemon[colecao->indicePokemonsColecao[colecao->qtdPokemonsCapturados - 1]].nome);

    return;
}//adicionarPokemonColecao

/**
 * \brief lista todos os pokemons capturados
 *
 * \param colecao estrutura que armazena os dados dos pokemons e a relacao de pokemons capturados pelo usuario
 * 
 * verifica se existem pokemons cadastrados na colecao;
 * se nao existirem, apresenta uma mensagem informativa;
 * se existirem, lista o ID e o nome dos pokemons capturados, de maneira ordenada e iterativa.
 */
void listarPokemonsCapturados(Colecao* colecao){
    if(colecao->qtdPokemonsCapturados == 0){
        printf("\nVoce ainda nao possui pokemons capturados.\n");
        return;
    }else{
        printf("\n====== POKEMONS CAPTURADOS ======\n");

        for(int i = 0; i < colecao->qtdPokemonsCapturados; i++){
            printf("%d. %s\n", colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].numero, colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].nome);
        }//for
    }

    return;
}//listarPokemonsCapturados

/**
 * \brief procura por um pokemon capturado por meio de seu ID
 *
 * \param colecao estrutura que armazena os dados dos pokemons e a relacao de pokemons capturados pelo usuario
 * 
 * solicita ao usuario o ID do pokemon a ser procurado na colecao;
 * verifica se o ID informado existe no banco de dados da colecao;
 * se ele existir, exibe todos os dados referentes a esse pokemon;
 * caso contrario, apresenta uma mensagem informativa.
 */

void pesquisarPokemonsCapturados(Colecao* colecao){
    int IDPokemonCapturado;

    printf("Digite o  do Pokemon Capturado que deseja buscar:");
    scanf("%d", &IDPokemonCapturado);

    for(int i = 0; i < colecao->qtdPokemonsCapturados; i++){
        if(IDPokemonCapturado == (colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].numero)){
            Pokemon *pokemonCapturado = &colecao->dadosPokemon[colecao->indicePokemonsColecao[i]];
    
            if (pokemonCapturado == NULL){
                printf("Erro ao exibir dados do Pokemon!\n");
                return;
            }//if
            
            printf("====== DADOS DO POKEMON CAPTURADO ======\n");
            printf("Nome: %s\n", pokemonCapturado->nome);
            printf("Tipo: %s e %s\n", pokemonCapturado->tipo1, pokemonCapturado->tipo2);
            printf("Total: %d\n", pokemonCapturado->total);
            printf("HP: %d\n", pokemonCapturado->hp);
            printf("Ataque: %d\n", pokemonCapturado->ataque);
            printf("Defesa: %d\n", pokemonCapturado->defesa);
            printf("Ataque Especial: %d\n", pokemonCapturado->ataqueEspecial);
            printf("Defesa Especial: %d\n", pokemonCapturado->defesaEspecial);
            printf("Velocidade: %d\n", pokemonCapturado->velocidade);    
            printf("Geracao: %d\n", pokemonCapturado->geracao);
            printf("Lendario: %d\n", pokemonCapturado->lendario);
            printf("Cor: %s\n", pokemonCapturado->cor);
            printf("Altura: %.2fm\n", pokemonCapturado->altura);
            printf("Peso: %.2fKg\n", pokemonCapturado->peso);
            printf("=========================================\n");
            return;
        }//if
    }//for

    printf("\nO numero buscado nao corresponde a nenhum pokemon capturado!\n");

    return;
}//pesquisarPokemonsCapturados

/**
 * \brief exclui um pokemon capturado da estrutura colecao
 *
 * \param colecao estrutura que armazena os dados dos pokemons e a relacao de pokemons capturados pelo usuario
 * 
 * solicita ao usuario o ID do pokemon a ser excluido da colecao;
 * verifica se o ID informado existe no banco de dados da colecao;
 * se ele existir, cria um buffer para armazenar apenas os pokemons capturados com ID diferente daquele informado pelo usuario, realoca o tamanho da colecao e atualiza a relacao dos pokemons capturados;
 * caso contrario, apresenta uma mensagem informativa.
 */
void excluirPokemonCapturado(Colecao* colecao){
    int IDpokemon;
    int contador = 0;
    int novoIndice = 0;

    printf("Digite o ID do Pokemon que voce deseja excluir: ");
    scanf("%d", &IDpokemon);

    for(int i = 0; i < colecao->qtdPokemonsCapturados; i++){
        if(IDpokemon == colecao->idPokemonsCapturados[i]){
            printf("\n%s excluido com sucesso!\n", colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].nome);
            contador++;
            break;
        }//if
    }//for

    if(contador == 1){
        int* buffer = (int*) malloc ((colecao->qtdPokemonsCapturados - 1) * sizeof(int));
        int* bufferIndice = (int*) malloc((colecao->qtdPokemonsCapturados - 1) * sizeof(int));
        
        for(int i = 0; i < colecao->qtdPokemonsCapturados; i++){
            if (IDpokemon != colecao->idPokemonsCapturados[i]){ 
                buffer[novoIndice] = colecao->idPokemonsCapturados[i];
                bufferIndice[novoIndice] = colecao->indicePokemonsColecao[i];
                novoIndice++;
            }//if
        }//for

        colecao->idPokemonsCapturados = buffer;
        colecao->indicePokemonsColecao = bufferIndice;

        colecao->qtdPokemonsCapturados--;

        return;
    }else{
        printf("\nOps! O pokemon selecionado nao pertence a sua colecao.\n");
    }//else

}//excluirPokemonCapturado
