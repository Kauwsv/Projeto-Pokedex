#include "arquivo.h"

/**
 * @file arquivo.c
 * @author Kauane dos Santos Vieira
 * @author Estefane de Lima dos Santos
 * @author Isabelle Rosvadoski Nofre
 * @date 15 Nov 2023
 * @brief Manipula os arquivos externos utilizados no programa
 * Todas as bibliotecas utilizadas nesse arquivo foram inseridas em arquivo.h
 *
 * Codigo feito no Windows
 */

/**
 * \brief verifica se o sistema foi aberto pela primeira vez e escolhe qual arquivo deve ser carregado
 *
 * \param arquivoDadosUsuario pode ser do tipo .dat se esse arquivo existir ou .csv caso seja a primeira vez que o sistema for executado
 * \param colecao estrutura que armazena os dados dos pokemons e a relacao de pokemons capturados pelo usuario
 * \param mochila estrutura que armazena a relacao de pokemons que o usuario possui na mochila
 * \param qtdPokemons quantidade total de pokemons cadastrados no sistema
 * 
 * consiste na primeira funcao executada pelo programa e verifica se existe um arquivo utilizavel do tipo .dat; 
 * se nao existir, significa que o sistema nunca foi aberto. Desse modo, apresenta uma mensagem de boas-vindas, abre o arquivo pokedex.csv, atualiza qtdPokemons para 721 e carrega os dados desse arquivo nas estruras colecao e mochila; 
 * se existir, significa que o sistema ja foi aberto e existem dados que foram criados na ultima vez em que ele foi executado. Desse modo, abre o arquivo .dat, atualiza qtdPokemons para o ultimo valor cadastrado no sistema e carrega os dados armazenados nesse arquivo nas estruturas colecao e mochila.
 */

void carregaArquivo(FILE* arquivoDadosUsuario, Colecao* colecao, Mochila* mochila, int* qtdPokemons){
    char nomeUsuario[22];

    if(arquivoDadosUsuario == NULL){
        printf("\nOla! Qual o seu nome? ");
        fgets(nomeUsuario, 22, stdin);
        nomeUsuario[strcspn(nomeUsuario, "\n")] = '\0';
        setbuf(stdin, NULL);

        for(int i = 0; i < strlen(nomeUsuario); i++){
            nomeUsuario[i] = toupper(nomeUsuario[i]);
        }

        printf("\n#########################################################################################\n");
        printf("#          ==================================================================           #\n");
        printf("#                                SEJA BEM-VINDO(A) %-10s                           #\n", nomeUsuario);
        printf("#          ==================================================================           #\n");
        printf(RED);
        printf("#             	                                .::.                                    #\n"); 
        printf("#                                           .;:**'            AMC           	        #\n");
        printf("#                                           `                  0                        #\n");
        printf("#               .:XHHHHk.              db.   .;;.     dH  MX   0                        #\n");
        printf("#             oMMMMMMMMMMM       ~MM  dMMP :MMMMMR   MMM  MR      ~MRMN                 #\n");
        printf("#             QMMMMMb  \"MMX       MMMMMMP !MX' :M~   MMM MMM  .oo. XMMM 'MMM            #\n");
        printf("#               `MMMM.  )M> :X!Hk. MMMM   XMM.o\"  .  MMMMMMM X?XMMM MMM>!MMP            #\n");
        printf(RESET);
        printf(GRAY);
        printf("#                'MMMb.dM! XM M'?M MMMMMX.`MMMMMMMM~ MM MMM XM `\" MX MMXXMM             #\n", RESET);
        printf(WHITE);
        printf("#                 ~MMMMM~ XMM. .XM XM`\"MMMb.~*?**~ .MMX M t MMbooMM XMMMMMP             #\n");
        printf("#                  ?MMM>  YMMMMMM! MM   `?MMRb.    `\"\"\"   !L\"MMMMM XM IMMM              #\n");
        printf("#                   MMMX   \"MMMM\"  MM       ~*:           !Mh.\"\"\" dMI IMMP              #\n");
        printf("#                   'MMM.                                             IMX               #\n");
        printf("#                    ~M!M                                             IMP               #\n");
        printf("#                                                   Console edition :p                  #\n"); 
        printf("#########################################################################################\n");
        printf(RESET); 

        fclose(arquivoDadosUsuario);
        (*qtdPokemons) = 721;

        arquivoDadosUsuario = fopen("pokedex.csv", "r+");

        if(arquivoDadosUsuario == NULL){
            perror("Erro ao abrir arquivo");
            exit(1);
        }

        fscanf(arquivoDadosUsuario, "%*[^\n]\n");
        colecao->dadosPokemon = (Pokemon*) malloc((*qtdPokemons) * sizeof(Pokemon));

        for(int i = 0; i < 721; i++){
            fscanf(arquivoDadosUsuario, "%d ,%s ,%s ,%s ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%s ,%f ,%f ,%d", &colecao->dadosPokemon[i].numero, colecao->dadosPokemon[i].nome, colecao->dadosPokemon[i].tipo1, colecao->dadosPokemon[i].tipo2, &colecao->dadosPokemon[i].total, &colecao->dadosPokemon[i].hp, &colecao->dadosPokemon[i].ataque, &colecao->dadosPokemon[i].defesa, &colecao->dadosPokemon[i].ataqueEspecial, &colecao->dadosPokemon[i].defesaEspecial, &colecao->dadosPokemon[i].velocidade, &colecao->dadosPokemon[i].geracao, &colecao->dadosPokemon[i].lendario, colecao->dadosPokemon[i].cor, &colecao->dadosPokemon[i].altura, &colecao->dadosPokemon[i].peso, &colecao->dadosPokemon[i].taxaCaptura);
        }//for

    }else{

        fread(qtdPokemons, sizeof(int), 1, arquivoDadosUsuario);
        fread(&colecao->qtdPokemonsCapturados, sizeof(int), 1, arquivoDadosUsuario);
        fread(&mochila->qtdPokemonsMochila, sizeof(int), 1, arquivoDadosUsuario);

        colecao->dadosPokemon = (Pokemon*) malloc((*qtdPokemons) * sizeof(Pokemon));
        colecao->idPokemonsCapturados = (int*) malloc(colecao->qtdPokemonsCapturados * sizeof(int));
        colecao->indicePokemonsColecao = (int*) malloc(colecao->qtdPokemonsCapturados * sizeof(int));
        mochila->idPokemonsMochila = (int*) malloc(mochila->qtdPokemonsMochila * sizeof(int));
        mochila->indicePokemonMochila = (int*) malloc(mochila->qtdPokemonsMochila * sizeof(int));
        
        fread(colecao->dadosPokemon, sizeof(Pokemon), (*qtdPokemons), arquivoDadosUsuario);
        fread(colecao->idPokemonsCapturados, sizeof(int), colecao->qtdPokemonsCapturados, arquivoDadosUsuario);
        fread(colecao->indicePokemonsColecao, sizeof(int), colecao->qtdPokemonsCapturados, arquivoDadosUsuario);
        fread(mochila->idPokemonsMochila, sizeof(int), mochila->qtdPokemonsMochila, arquivoDadosUsuario);
        fread(mochila->indicePokemonMochila, sizeof(int), mochila->qtdPokemonsMochila, arquivoDadosUsuario);
    }

    return;
}//carregaArquivo

/**
 * \brief atualiza arquivo .dat sempre que o programa for finalizado pelo menu
 *
 * \param colecao estrutura que armazena os dados dos pokemons e a relacao de pokemons capturados pelo usuario
 * \param mochila estrutura que armazena a relacao de pokemons que o usuario possui na mochila
 * \param qtdPokemons quantidade total de pokemons cadastrados no sistema
 * 
 * abre o arquivo dadosUsuario.dat e salva a quantidade total de pokemons cadastrados no sistema, alem dos dados atuais das estruturas colecao e mochila, a fim de que tais dados sejam utilizados na proxima vez em que o sistema for executado;
 * vale ressaltar que os dados serao salvos em formato BINARIO no HD do computador, com o intuito de que eles nao sejam perdidos ao finalizar o programa pelo menu.
 */
void atualizaArquivo(Colecao* colecao, Mochila* mochila, int* qtdPokemons){
    FILE* dadosUsuarioBin;

    dadosUsuarioBin = fopen("dadosUsuario.dat", "wb"); 

    if(dadosUsuarioBin == NULL){
        perror("Erro ao abrir arquivo binario");
        exit(1);
    }

    fwrite(qtdPokemons, sizeof(int), 1, dadosUsuarioBin);
    fwrite(&colecao->qtdPokemonsCapturados, sizeof(int), 1, dadosUsuarioBin);
    fwrite(&mochila->qtdPokemonsMochila, sizeof(int), 1, dadosUsuarioBin);
    fwrite(colecao->dadosPokemon, sizeof(Pokemon), (*qtdPokemons), dadosUsuarioBin);
    fwrite(colecao->idPokemonsCapturados, sizeof(int), colecao->qtdPokemonsCapturados, dadosUsuarioBin);
    fwrite(colecao->indicePokemonsColecao, sizeof(int), colecao->qtdPokemonsCapturados, dadosUsuarioBin);
    fwrite(mochila->idPokemonsMochila, sizeof(int), mochila->qtdPokemonsMochila, dadosUsuarioBin);
    fwrite(mochila->indicePokemonMochila, sizeof(int), mochila->qtdPokemonsMochila, dadosUsuarioBin);

    fclose(dadosUsuarioBin);
    return;
}//atualizaArquivo

/**
 * \brief cria arquivo .csv sempre que o usuario selecionar a opcao "criar arquivo CSV" no menu
 *
 * \param colecao estrutura que armazena os dados dos pokemons e a relacao de pokemons capturados pelo usuario
 * \param mochila estrutura que armazena a relacao de pokemons que o usuario possui na mochila
 * \param qtdPokemons quantidade total de pokemons cadastrados no sistema
 * 
 * cria/atualiza arquivo dadosUsuario.csv com todos os dados dos pokemons cadastrados na pokedex, na mochila e na colecao, respectivamente; 
 * vale ressaltar que esse arquivo sera salvo em formato TEXTO no HD do computador e o usuario pode acessa-lo e visualizar os dados em formato de tabela.
 */
void criarArquivoCSV(Colecao* colecao, Mochila* mochila, int* qtdPokemons){
    FILE* dadosUsuarioCSV;
    
    dadosUsuarioCSV = fopen("dadosUsuario.csv", "w+");
    char headerPrincipal[][22] = {"ID", "NOME", "TIPO1", "TIPO2", "TOTAL", "HP", "ATAQUE", "DEFESA", "ATAQUE ESPECIAL", "DEFESA ESPECIAL", "VELOCIDADE", "GERACAO", "LENDARIO", "COR", "ALTURA", "PESO", "TAXA DE CAPTURA"};
    if(dadosUsuarioCSV == NULL){
        perror("Ops, erro ao carregar arquivo!\n");
        exit(1);
    }

    fprintf(dadosUsuarioCSV, "====================================================================================================================== SUA POKEDEX ===============================================================================================================\n");
    fprintf(dadosUsuarioCSV, "%-10s ,%-20s ,%-10s ,%-10s ,%-10s ,%-10s ,%-10s ,%-10s ,%-20s ,%-20s ,%-10s ,%-10s ,%-10s ,%-10s ,%-10s ,%-10s ,%-20s\n", headerPrincipal[0], headerPrincipal[1], headerPrincipal[2], headerPrincipal[3], headerPrincipal[4], headerPrincipal[5], headerPrincipal[6], headerPrincipal[7], headerPrincipal[8], headerPrincipal[9], headerPrincipal[10], headerPrincipal[11], headerPrincipal[12], headerPrincipal[13], headerPrincipal[14], headerPrincipal[15], headerPrincipal[16]);
    
    for(int i = 0; i < (*qtdPokemons); i++){
        fprintf(dadosUsuarioCSV, "%-10d ,%-20s ,%-10s ,%-10s ,%-10d ,%-10d ,%-10d ,%-10d ,%-20d ,%-20d ,%-10d ,%-10d ,%-10d ,%-10s ,%-10.2f ,%-10.2f ,%-20d\n", colecao->dadosPokemon[i].numero, colecao->dadosPokemon[i].nome, colecao->dadosPokemon[i].tipo1, colecao->dadosPokemon[i].tipo2, colecao->dadosPokemon[i].total, colecao->dadosPokemon[i].hp, colecao->dadosPokemon[i].ataque, colecao->dadosPokemon[i].defesa, colecao->dadosPokemon[i].ataqueEspecial, colecao->dadosPokemon[i].defesaEspecial, colecao->dadosPokemon[i].velocidade, colecao->dadosPokemon[i].geracao, colecao->dadosPokemon[i].lendario, colecao->dadosPokemon[i].cor, colecao->dadosPokemon[i].altura, colecao->dadosPokemon[i].peso, colecao->dadosPokemon[i].taxaCaptura);  
    }

    fprintf(dadosUsuarioCSV, "\n=================================================================================================================== SUA MOCHILA =================================================================================================================\n");
    fprintf(dadosUsuarioCSV, "%-10s ,%-20s ,%-10s ,%-10s ,%-10s ,%-10s ,%-10s ,%-10s ,%-20s ,%-20s ,%-10s ,%-10s ,%-10s ,%-10s ,%-10s ,%-10s ,%-20s\n", headerPrincipal[0], headerPrincipal[1], headerPrincipal[2], headerPrincipal[3], headerPrincipal[4], headerPrincipal[5], headerPrincipal[6], headerPrincipal[7], headerPrincipal[8], headerPrincipal[9], headerPrincipal[10], headerPrincipal[11], headerPrincipal[12], headerPrincipal[13], headerPrincipal[14], headerPrincipal[15], headerPrincipal[16]);

    for(int i = 0; i < (mochila->qtdPokemonsMochila); i++){
        fprintf(dadosUsuarioCSV, "%-10d ,%-20s ,%-10s ,%-10s ,%-10d ,%-10d ,%-10d ,%-10d ,%-20d ,%-20d ,%-10d ,%-10d ,%-10d ,%-10s ,%-10.2f ,%-10.2f ,%-20d\n", colecao->dadosPokemon[mochila->indicePokemonMochila[i]].numero, colecao->dadosPokemon[mochila->indicePokemonMochila[i]].nome, colecao->dadosPokemon[mochila->indicePokemonMochila[i]].tipo1, colecao->dadosPokemon[mochila->indicePokemonMochila[i]].tipo2, colecao->dadosPokemon[mochila->indicePokemonMochila[i]].total, colecao->dadosPokemon[mochila->indicePokemonMochila[i]].hp, colecao->dadosPokemon[mochila->indicePokemonMochila[i]].ataque, colecao->dadosPokemon[mochila->indicePokemonMochila[i]].defesa, colecao->dadosPokemon[mochila->indicePokemonMochila[i]].ataqueEspecial, colecao->dadosPokemon[mochila->indicePokemonMochila[i]].defesaEspecial, colecao->dadosPokemon[mochila->indicePokemonMochila[i]].velocidade, colecao->dadosPokemon[mochila->indicePokemonMochila[i]].geracao, colecao->dadosPokemon[mochila->indicePokemonMochila[i]].lendario, colecao->dadosPokemon[mochila->indicePokemonMochila[i]].cor, colecao->dadosPokemon[mochila->indicePokemonMochila[i]].altura, colecao->dadosPokemon[mochila->indicePokemonMochila[i]].peso, colecao->dadosPokemon[mochila->indicePokemonMochila[i]].taxaCaptura);
    }

    fprintf(dadosUsuarioCSV, "\n=================================================================================================================== SUA COLECAO =================================================================================================================\n");
    fprintf(dadosUsuarioCSV, "%-10s ,%-20s ,%-10s ,%-10s ,%-10s ,%-10s ,%-10s ,%-10s ,%-20s ,%-20s ,%-10s ,%-10s ,%-10s ,%-10s ,%-10s ,%-10s ,%-20s\n", headerPrincipal[0], headerPrincipal[1], headerPrincipal[2], headerPrincipal[3], headerPrincipal[4], headerPrincipal[5], headerPrincipal[6], headerPrincipal[7], headerPrincipal[8], headerPrincipal[9], headerPrincipal[10], headerPrincipal[11], headerPrincipal[12], headerPrincipal[13], headerPrincipal[14], headerPrincipal[15], headerPrincipal[16]);

    for(int i = 0; i < (colecao->qtdPokemonsCapturados); i++){
        fprintf(dadosUsuarioCSV, "%-10d ,%-20s ,%-10s ,%-10s ,%-10d ,%-10d ,%-10d ,%-10d ,%-20d ,%-20d ,%-10d ,%-10d ,%-10d ,%-10s ,%-10.2f ,%-10.2f ,%-20d\n", colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].numero, colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].nome, colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].tipo1, colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].tipo2, colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].total, colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].hp, colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].ataque, colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].defesa, colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].ataqueEspecial, colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].defesaEspecial, colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].velocidade, colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].geracao, colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].lendario, colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].cor, colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].altura, colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].peso, colecao->dadosPokemon[colecao->indicePokemonsColecao[i]].taxaCaptura);
    }

    fclose(dadosUsuarioCSV);
    
    return;
}//criarArquivoCSV
    
