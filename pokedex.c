#include "pokedex.h"

/**
 * @file pokedex.c
 * @author Kauane dos Santos Vieira
 * @author Estefane de Lima dos Santos
 * @author Isabelle Rosvadoski Nofre
 * 
 * @date 15 Nov 2023
 * Depende da biblioteca pokedex.h
 * 
 * Arquivo referente as funções da pokedex
 * 
 * Código feito no Windows
 */

/**
 * \brief Altera dados do Pokemon em colecao->dadosPokemon
 *
 * \param colecao estrutura que contém pokemon capturados pelo ID e a relação de todos os pokemon do jogo
 * \param mochila estrutura que contém pokemon capturados que acompanharão o jogador
 *
 * Pede para o usuário o ID do pokemon que ele deseja alterar, em seguida verifica se o pokemon esta na mochila,
 * caso esteja, não permite alteração e retorna a função. Caso não esteja na mochila, a função percorre os IDs em 
 * dadosPokemons e salva o indice caso encontre o ID correspondente. Assim, diz ao jogador o nome do pokemon do ID
 * solicitado, perguntndo novamente se ele deseja altera-lo. Caso sim, a função pede novos dados ao usuário referente 
 * ao pokemon, salvando as alterações.
 */

void alterarPokemon(Colecao* colecao, Mochila* mochila, int qtdPokemons){
    int opcao;
    int idPokemonAlterar;
    int indicePokemon = -1;

    printf("Digite o id do pokemon que voce deseja alterar: "); 
    scanf("%d", &idPokemonAlterar);
    printf("\n");
    
    for(int i = 0; i < mochila->qtdPokemonsMochila; i++){
        if(idPokemonAlterar == mochila->idPokemonsMochila[i]){
            printf("\nOps, voce nao pode alterar nenhum pokemon que esteja em sua mochila!\n");
            return;
        }
    }//for

    for(int i = 0; i < qtdPokemons; i++){
        if(idPokemonAlterar == colecao->dadosPokemon[i].numero){
            indicePokemon = i;
            break;
        }
    }

    if(indicePokemon == -1){
        printf("\nID invalido! Pokemon nao consta no sistema.\n");
        return;
    }

    printf("\nO pokemon escolhido foi %s, deseja mesmo altera-lo?\n", colecao->dadosPokemon[indicePokemon].nome);
    printf("1 - sim\n");
    printf("2 - nao\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);

    if(opcao == 1){
        Pokemon pokemon;
        
        printf("\nDigite o nome do pokemon: ");
        fgets(pokemon.nome, 52, stdin);
        pokemon.nome[strcspn(pokemon.nome, "\n")] = '\0';
        setbuf(stdin, NULL);
        
        printf("Digite o tipo1 do pokemon: ");
        fgets(pokemon.tipo1, 22, stdin);
        pokemon.tipo1[strcspn(pokemon.tipo1, "\n")] = '\0';
        setbuf(stdin, NULL);
          
        printf("Digite o tipo2 do pokemon: ");
        fgets(pokemon.tipo2, 22, stdin);
        pokemon.tipo2[strcspn(pokemon.tipo2, "\n")] = '\0';
        setbuf(stdin, NULL);
        
        printf("Digite o valor total do pokemon: ");
        scanf("%d", &pokemon.total);
        
        printf("Digite o hp do pokemon: ");
        scanf("%d", &pokemon.hp);
        
        printf("Digite o valor de ataque do pokemon: ");
        scanf("%d", &pokemon.ataque);
        
        printf("Digite o valor de defesa do pokemon: ");
        scanf("%d", &pokemon.defesa);
        
        printf("Digite o valor do ataque especial do pokemon: ");
        scanf("%d", &pokemon.ataqueEspecial);
        
        printf("Digite o valor da defesa especial do pokemon: ");
        scanf("%d", &pokemon.defesaEspecial);

        printf("Digite a velocidade do pokemon: ");
        scanf("%d", &pokemon.velocidade);
        
        printf("Digite a geracao do pokemon: ");
        scanf("%d", &pokemon.geracao);
        
        do{
            printf("Digite 1 se o pokemon for lendario ou 0 caso ele nao seja: ");
            scanf("%d", &pokemon.lendario);
            setbuf(stdin, NULL);

            if(pokemon.lendario != 1 && pokemon.lendario != 0){
                printf("Ops, o valor digitado precisa ser 0 ou 1!\n");
            }
        }while(pokemon.lendario != 1 && pokemon.lendario != 0);
        
        printf("Digite a cor do pokemon: ");
        fgets(pokemon.cor, 52, stdin);
        pokemon.cor[strcspn(pokemon.cor, "\n")] = '\0';
        setbuf(stdin, NULL);
        
        printf("Digite a altura do pokemon: ");
        scanf("%f", &pokemon.altura);
        
        printf("Digite o peso do pokemon: ");
        scanf("%f", &pokemon.peso);
        
        printf("Digite a taxa de captura do pokemon: ");
        scanf("%d", &pokemon.taxaCaptura);
        
        colecao->dadosPokemon[indicePokemon] = pokemon;
                
    }else if(opcao == 2){
        printf("Pokemon nao alterado\n");
    }else{
        printf("Opcao invalida! Tente Novamente...\n");
    }

    return;
}//alterarPokemon

/**
 * \brief Pesquisa Pokemon pelo tipo
 *
 * \param colecao estrutura que contém pokemon capturados pelo ID e a relação de todos os pokemon do jogo
 * \param qtdPokemons quantidade de pokemon constantes no sistema
 *
 * Pede para o usuário o tipo do pokemon que deseja buscar, depois percorre toda a lista de pokemon comparando cada
 * tipo com o solicitado. Caso encontre tipos correspondentes, a função exibe os dados de cada pokemon referente em cores
 * no terminal, exibindo ao final a quantidade de pokemon encontrados daquele mesmo tipo.
 */

void pesquisarPokemonTipo(Colecao* colecao, int* qtdPokemons){
    int encontrouPokemon = 0;
    char tipoPokemon[22];
    char codigoCor[9];
    Pokemon pokemon;

    printf("Digite o tipo do pokemon que deseja buscar: ");
    fgets(tipoPokemon, 22, stdin);
    tipoPokemon[strcspn(tipoPokemon, "\n")] = '\0';
    setbuf(stdin, NULL);

    for(int i = 0; i < (*qtdPokemons); i++){
       if((strcasecmp(tipoPokemon, colecao->dadosPokemon[i].tipo1) == 0) || (strcasecmp(tipoPokemon, colecao->dadosPokemon[i].tipo2) == 0)){
            encontrouPokemon++;; 
            pokemon = colecao->dadosPokemon[i];
            if(strcasecmp(tipoPokemon, "normal") == 0){
                strcpy(codigoCor, "\033[37m");
            }else if(strcasecmp(tipoPokemon, "lutador") == 0){
                strcat(codigoCor, "\033[33m");
            }else if(strcasecmp(tipoPokemon, "voador") == 0){
                strcpy(codigoCor, "\033[36m");
            }else if(strcasecmp(tipoPokemon, "venenoso") == 0){
                strcpy(codigoCor, "\033[34m");
            }else if(strcasecmp(tipoPokemon, "terra") == 0){
                strcpy(codigoCor, "\033[32m");
            }else if(strcasecmp(tipoPokemon, "pedra") == 0){
                strcpy(codigoCor, "\033[30m");
            }else if(strcasecmp(tipoPokemon, "bug") == 0){
                strcpy(codigoCor, "\033[36m");
            }else if(strcasecmp(tipoPokemon, "ghost") == 0){
                strcpy(codigoCor, "\033[37m");
            }else if(strcasecmp(tipoPokemon, "aço") == 0){
                strcpy(codigoCor, "\033[30m");
            }else if(strcasecmp(tipoPokemon, "fire") == 0){
                strcpy(codigoCor, "\033[31m");
            } else if(strcasecmp(tipoPokemon, "water") == 0){
                strcpy(codigoCor, "\033[34m");
            }else if(strcasecmp(tipoPokemon, "planta") == 0){
                strcpy(codigoCor, "\033[32m");
            }else if(strcasecmp(tipoPokemon, "electric") == 0){
                strcpy(codigoCor, "\033[33m");
            }else if(strcasecmp(tipoPokemon, "psychic") == 0){
                strcpy(codigoCor, "\033[36m");
            }else if(strcasecmp(tipoPokemon, "gelo") == 0){
                strcpy(codigoCor, "\033[34m");
            }else if(strcasecmp(tipoPokemon, "dragon") == 0){
                strcpy(codigoCor, "\033[31m");
            }else if(strcasecmp(tipoPokemon, "sombrio") == 0){
                strcpy(codigoCor, "\033[35m");
            }else if(strcasecmp(tipoPokemon, "fada") == 0){
                strcpy(codigoCor, "\033[34m");
            }else{
                strcpy(codigoCor, "\033[35m");
            }

            printf(codigoCor);
            printf("\n======= DADOS DO POKEMON =======\n");
            printf("Numero: %d\n", pokemon.numero);
            printf("Nome: %s\n", pokemon.nome);
            printf("Tipo: %s e %s\n", pokemon.tipo1, pokemon.tipo2);
            printf("Total: %d\n", pokemon.total);
            printf("HP: %d\n", pokemon.hp);
            printf("Ataque: %d\n", pokemon.ataque);
            printf("Defesa: %d\n", pokemon.defesa);
            printf("Ataque Especial: %d\n", pokemon.ataqueEspecial);
            printf("Defesa Especial: %d\n", pokemon.defesaEspecial);
            printf("Velocidade: %d\n", pokemon.velocidade);    
            printf("Geracao: %d\n", pokemon.geracao);
            printf("Lendario: %d\n", pokemon.lendario);
            printf("Cor: %s\n", pokemon.cor);
            printf("Altura: %.2fm\n", pokemon.altura);
            printf("Peso: %.2fKg\n", pokemon.peso);
            printf("=================================\n");
            printf(RESET);
       }
    }

    if(encontrouPokemon == 0){
        printf("\nOps, nao existem pokemons desse tipo cadastrados no sistema!\n");
    }else{
        printf("\nForam encontrados %d pokemons desse tipo.\n", encontrouPokemon);
    }

    return;
}//pesquisarPokemonTipo

/**
 * \brief Pesquisa Pokemon por geração
 *
 * \param colecao estrutura que contém pokemon capturados pelo ID e a relação de todos os pokemons do jogo
 * \param qtdPokemons quantidade de pokemon constantes no sistema
 *
 * Pede para o usuário a geração (int) do pokemon que deseja buscar, depois percorre toda a lista de pokemons comparando cada
 * geração com a solicitada. Caso encontre gerações equivalentes, a funçã exibe os dados de cada pokemon referente em cores
 * no terminal, exibindo ao final a quantidade de pokemons encontrados daquela mesma geração.
 */

void pesquisarPokemonGeracao(Colecao* colecao, int* qtdPokemons){
    int encontrouPokemon = 0;
    int geracaoPokemon;
    Pokemon pokemon;

    printf("Digite a geracao do pokemon que deseja buscar: ");
    scanf("%d", &geracaoPokemon);

    for(int i = 0; i < (*qtdPokemons); i++){
       if(geracaoPokemon == colecao->dadosPokemon[i].geracao){
            encontrouPokemon++; 
            pokemon = colecao->dadosPokemon[i];

            printf("\n====== DADOS DO POKEMON ======\n");
            printf("Numero: %d\n", pokemon.numero);
            printf("Nome: %s\n", pokemon.nome);
            printf("Tipo: %s e %s\n", pokemon.tipo1, pokemon.tipo2);
            printf("Total: %d\n", pokemon.total);
            printf("HP: %d\n", pokemon.hp);
            printf("Ataque: %d\n", pokemon.ataque);
            printf("Defesa: %d\n", pokemon.defesa);
            printf("Ataque Especial: %d\n", pokemon.ataqueEspecial);
            printf("Defesa Especial: %d\n", pokemon.defesaEspecial);
            printf("Velocidade: %d\n", pokemon.velocidade);    
            printf("Geracao: %d\n", pokemon.geracao);
            printf("Lendario: %d\n", pokemon.lendario);
            printf("Cor: %s\n", pokemon.cor);
            printf("Altura: %.2fm\n", pokemon.altura);
            printf("Peso: %.2fKg\n", pokemon.peso);
            printf("=================================\n");
        } 
    }

    if(encontrouPokemon == 0){
        printf("\nOps, nao existem pokemons dessa geracao cadastrados no sistema!\n");
    }else{
        printf("\nForam encontrados %d pokemons dessa geracao.\n", encontrouPokemon);
    }

    return;
}//pesquisarPokemonTipo

/**
 * \brief  Adiciona novo pokemon no sistema
 *
 * \param colecao estrutura que contém pokemon capturados pelo ID e a relação de todos os pokemon do jogo
 * \param qtdPokemons quantidade de pokemon constantes no sistema
 *
 * Cria um buffer do tipo Pokemon para salvar os dados de pokemon anteriores no sistema, em seguida garante que o ID do 
 * novo pokemon seja um número acima do maior ID constante na lista. Em seguida pede ao usuário os dados do novo pokemon,
 * que são salvos na última posição de memória do buffer, o qual é igualado por fim a dados pokemon, atualizando o sistema. 
 * E, finalmente, é incrementado a quantidade de pokemon.
 */

void inserirPokemonPokedex(Colecao* colecao, int* qtdPokemons){
    Pokemon* buffer = (Pokemon*) malloc((*qtdPokemons + 1) * sizeof(Pokemon));

    int maiorID = 0;
    
    buffer = colecao->dadosPokemon;

    Pokemon pokemon;

    for(int i = 0; i < (*qtdPokemons); i++){
        if(colecao->dadosPokemon[i].numero >= maiorID){
            maiorID = colecao->dadosPokemon[i].numero;
        }//if
    }//for

    pokemon.numero = maiorID + 1;

    printf("\nDigite o nome do pokemon: ");
    fgets(pokemon.nome, 52, stdin);
    pokemon.nome[strcspn(pokemon.nome, "\n")] = '\0';
    setbuf(stdin, NULL);
    
    printf("Digite o tipo1 do pokemon: ");
    fgets(pokemon.tipo1, 22, stdin);
    pokemon.tipo1[strcspn(pokemon.tipo1, "\n")] = '\0';
    setbuf(stdin, NULL);
        
    printf("Digite o tipo2 do pokemon: ");
    fgets(pokemon.tipo2, 22, stdin);
    pokemon.tipo2[strcspn(pokemon.tipo2, "\n")] = '\0';
    setbuf(stdin, NULL);
    
    printf("Digite o valor total do pokemon: ");
    scanf("%d", &pokemon.total);
    
    printf("Digite o hp do pokemon: ");
    scanf("%d", &pokemon.hp);
    
    printf("Digite o valor de ataque do pokemon: ");
    scanf("%d", &pokemon.ataque);
    
    printf("Digite o valor de defesa do pokemon: ");
    scanf("%d", &pokemon.defesa);
    
    printf("Digite o valor do ataque especial do pokemon: ");
    scanf("%d", &pokemon.ataqueEspecial);
    
    printf("Digite o valor da defesa especial do pokemon: ");
    scanf("%d", &pokemon.defesaEspecial);

    printf("Digite a velocidade do pokemon: ");
    scanf("%d", &pokemon.velocidade);
    
    printf("Digite a geracao do pokemon: ");
    scanf("%d", &pokemon.geracao);
    
    do{
        printf("Digite 1 se o pokemon for lendario ou 0 caso ele nao seja: ");
        scanf("%d", &pokemon.lendario);
        setbuf(stdin, NULL);

        if(pokemon.lendario != 1 && pokemon.lendario != 0){
            printf("Ops, o valor digitado precisa ser 0 ou 1!\n");
        }
    }while(pokemon.lendario != 1 && pokemon.lendario != 0);
    
    printf("Digite a cor do pokemon: ");
    fgets(pokemon.cor, 22, stdin);
    pokemon.cor[strcspn(pokemon.cor, "\n")] = '\0';
    setbuf(stdin, NULL);
    
    printf("Digite a altura do pokemon: ");
    scanf("%f", &pokemon.altura);
    
    printf("Digite o peso do pokemon: ");
    scanf("%f", &pokemon.peso);
    
    printf("Digite a taxa de captura do pokemon: ");
    scanf("%d", &pokemon.taxaCaptura);

    buffer[*qtdPokemons] = pokemon;

    colecao->dadosPokemon = buffer;
    (*qtdPokemons)++;

    return;
}

/**
 * \brief Exclui um pokemon do sistema
 *
 * \param colecao estrutura que contém pokemon capturados pelo ID e a relação de todos os pokemon do jogo
 * \param qtdPokemons quantidade de pokemon constantes no sistema
 *
 * Pede ao usuário o ID do pokemon que deseja excluir, assim percorre toda a lista de pokemon comparando os IDs. Caso 
 * encontre um ID correspondente salva o indice do pokemon e incrementa a variável encontrouPokemon (inicializada em zero).
 * Em seguida diz ao usuário o nome do pokemon solicitado e pergunta de realmente deseja exclui-lo. Caso sim, o buffer é
 * alimentado com todos os pokemon da lista, pulando apenas o pokemon solicitado para exclusão. Assim, os dados pokemon 
 * recebem o buffer e quantidade de pokemon é decrementada. Caso encontrouPokemon seja 0, o pokemon solicitado não consta 
 * no sistema e a função é retornada
 */

void excluirPokemonPokedex(Colecao* colecao, int* qtdPokemons){
    int existePokemon = 0;
    int idPokemonExcluir;
    int indicePokemon;
    int indice = 0;
    int opcao; 
    
    Pokemon* buffer = (Pokemon*) malloc((*qtdPokemons - 1) * sizeof(Pokemon));

    printf("\nDigite o ID do pokemon que deseja excluir: ");
    scanf("%d", &idPokemonExcluir);

    for(int i = 0; i < *qtdPokemons; i++){
        if(idPokemonExcluir == colecao->dadosPokemon[i].numero){
            indicePokemon = i;
            existePokemon++;
        }
    }

    if(existePokemon == 0){
        printf("\nEsse Pokemon nao consta no sistema ou ja foi excluido.\n");
        return;
    }else{
        printf("\nO ID corresponde a %s, deseja mesmo exclui-lo?\n", colecao->dadosPokemon[indicePokemon].nome);
        printf("1 - Sim;\n");
        printf("2 - Nao.\n");
        printf("=================\n");
        printf("Digite sua opcao:");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                printf("\nExcluindo %s...\n", colecao->dadosPokemon[indicePokemon].nome);
                break;
            case 2:
                return;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }//switch
    }//else

    for(int i = 0; i < *qtdPokemons; i++){
        if(colecao->dadosPokemon[i].numero != (idPokemonExcluir)){
            buffer[indice] = colecao->dadosPokemon[i];
            indice++;
        }
    }

    colecao->dadosPokemon = buffer;
    (*qtdPokemons)--;

    return;
}
