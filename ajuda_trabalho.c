#include <stdio.h>
#include <stdlib.h>
#include <time.h>    // necessário para o funcionamento de time()
#include <string.h>

#define nTotalCartas (80)
#define nJogadores (6)

/// DEFINIÇÃO ESTRUTURAS NECESSÁRIAS E TIPOS ASSOCIADOS

/// Carta
typedef struct s_carta
{
    int  ordem;             // útil para ordenar cartas
    char cor;
    char face;
} t_carta;

/// Jogador
typedef struct s_jogador
{
    char    nome[18];
    t_carta vCartas[1+100];  // nunca terá mais de 100
    int     nCartas;         // quantidade de cartas que tem na mão
} t_jogador;

/// FUNÇOES NECESSÁRIAS À ORDENAÇÃO E DESORDENAÇÃO DE VETORES DE CARTAS

/// devolve a posição em que se encontra a carta com maior número de ordem no vetor b de n elementos do tipo t_carta
int posDaMaiorCarta(t_carta b[],int n)
{
    int p=1;
    for(int i=2;i<=n;i++)
        if (b[i].ordem>b[p].ordem) p=i;
    return p;
}

/// troca os elementos das posições p1 e p2 do vetor de cartas b
void troca2cartas(t_carta b[], int p1, int p2)
{
    t_carta a=b[p1];
    b[p1]=b[p2];
    b[p2]=a;
}

/// ordena o vetor b de n t_cartas por ordem crescente de numero de ordem
void ordenarCartas(t_carta b[],int n)
{
    for(int i=n;i>=2;i--)
        troca2cartas(b,posDaMaiorCarta(b,i),i);
}

/// Função para baralhar o baralho de cartas
void baralharCartas(t_carta baralho[], int nCartas){

    int  posicao, random;
    t_carta temp;
    for(posicao=1; posicao<=nCartas; posicao++){
            random = rand()%(posicao+1);

            temp = baralho[posicao];
            baralho[posicao] = baralho[random];
            baralho[random] = baralho[posicao];
    }
}

/// FUNÇÕES DE INICIALIZAÇÃO DO BARALHO E DO VETOR DE JOGADORES

/// cria baralho de 40 cartas do uno (ordenado)
void criarBaralho(t_carta b[])
{
    char faces[] = "0123456789";
    char cores[] = "RGBY";        // vermelho, verde, azul, amarelo
    for (int i=1;i<=40;i++){
        b[i].cor  =cores [(i-1)/10];
        b[i].face =faces [(i-1)%10];
        b[i].ordem=i;
    }
}

/// Função que junta dois baralhos de 40 cartas num único vetor com 80 cartas


/// cria 10 jogadores: nomes, nCartas=0
void criarJogadores(t_jogador vJogadores[])
{
    strcpy(vJogadores[ 1].nome," António ");
    strcpy(vJogadores[ 2].nome," Beatriz ");
    strcpy(vJogadores[ 3].nome," Celeste ");
    strcpy(vJogadores[ 4].nome," Daniela ");
    strcpy(vJogadores[ 5].nome," Eduardo ");
    strcpy(vJogadores[ 6].nome," Fabiana ");
    strcpy(vJogadores[ 7].nome," Gonçalo ");
    strcpy(vJogadores[ 8].nome," Hilário ");
    strcpy(vJogadores[ 9].nome," Isabela ");
    strcpy(vJogadores[10].nome," Joaquim ");
    for (int j=1;j<=10;j++) vJogadores[j].nCartas=0; // desnecessário
}

/// FUNÇÕES DE ESCRITA

/// Função que escreve uma carta


/// Função que escreve um vetor de cartas


/// Função que escreve o monte (apresenta o número de cartas que estão no monte, e não as cartas que lá estão)


/// Função que escreve a mesa (escreve as cartas que estão na mesa)


/// Função que escreve um jogador: nome + cartas da mão


/// Função que escreve todos os jogadores



/// FUNÇÕES NECESSÁRIAS AO FUNCIONAMENTO DO JOGO

/// Função para dar distribuir as cartas do baralho (80 cartas) pelos jogadores, mesa e monte


/// Função que verifica se algum jogador acabou o jogo
///(devolve o índice do jogador que tem 0 cartas - se todos têm mais que 0 cartas, devolve 0).


/// Função que verifica se uma carta "encaixa" na outra
///devolve 1 se ca carta 1 'encaixa' na carta 2 (verifica se carta 1 e carta 2 têm a mesma cor ou a mesma face)


///Função que devolve o índice do próximo jogador a jogar


/// Função que retira uma carta do monte para a mão do jogador com o indíce j


///Função para escolher a jogada
/// devolve o índice da carta que jogador j joga (à sorte de entre as possíveis)
/// devolve 0 se o jogador j não tem cartas possíveis de jogar


///Função para jogar uma carta
/// retira a carte de índice ind da mão do jogador j e coloca-a na mesa


///Função para reorganizar o Monte e a Mesa
/// retira cartas que estão na mesa (deixando 5) para o monte e rebaralha o monte


int main()
{
    srand(time(0));                          // semente dos números pseudoaleatórios
    t_jogador vJogadores[1+10];              // vetor dos jogadores
    t_carta   b1[1+40], b2[1+40], baralho[1+80];
    t_jogador monte, mesa;
//    int nTotalCartas;
//    int  nJogadores;


    criarJogadores(vJogadores);
    criarBaralho(b1);
    criarBaralho(b2);
    //juntarBaralhos(b1,b2,baralho);
    baralharCartas(baralho,nTotalCartas);

    ///Acrescentar as chamadas às funções desenvolvidas, para fazer funcionar o Jogo do UNO



 getchar();
 return 0;
}
