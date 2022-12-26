#include <stdio.h>
#include <stdlib.h>
#include <time.h>    // necess�rio para o funcionamento de time()
#include <string.h>

#define nTotalCartas (80)
#define nJogadores (6)

/// DEFINI��O ESTRUTURAS NECESS�RIAS E TIPOS ASSOCIADOS

/// Carta
typedef struct s_carta
{
    int  ordem;             // �til para ordenar cartas
    char cor;
    char face;
} t_carta;

/// Jogador
typedef struct s_jogador
{
    char    nome[18];
    t_carta vCartas[1+100];  // nunca ter� mais de 100
    int     nCartas;         // quantidade de cartas que tem na m�o
} t_jogador;

/// FUN�OES NECESS�RIAS � ORDENA��O E DESORDENA��O DE VETORES DE CARTAS

/// devolve a posi��o em que se encontra a carta com maior n�mero de ordem no vetor b de n elementos do tipo t_carta
int posDaMaiorCarta(t_carta b[],int n)
{
    int p=1;
    for(int i=2;i<=n;i++)
        if (b[i].ordem>b[p].ordem) p=i;
    return p;
}

/// troca os elementos das posi��es p1 e p2 do vetor de cartas b
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

/// Fun��o para baralhar o baralho de cartas
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

/// FUN��ES DE INICIALIZA��O DO BARALHO E DO VETOR DE JOGADORES

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

/// Fun��o que junta dois baralhos de 40 cartas num �nico vetor com 80 cartas


/// cria 10 jogadores: nomes, nCartas=0
void criarJogadores(t_jogador vJogadores[])
{
    strcpy(vJogadores[ 1].nome," Ant�nio ");
    strcpy(vJogadores[ 2].nome," Beatriz ");
    strcpy(vJogadores[ 3].nome," Celeste ");
    strcpy(vJogadores[ 4].nome," Daniela ");
    strcpy(vJogadores[ 5].nome," Eduardo ");
    strcpy(vJogadores[ 6].nome," Fabiana ");
    strcpy(vJogadores[ 7].nome," Gon�alo ");
    strcpy(vJogadores[ 8].nome," Hil�rio ");
    strcpy(vJogadores[ 9].nome," Isabela ");
    strcpy(vJogadores[10].nome," Joaquim ");
    for (int j=1;j<=10;j++) vJogadores[j].nCartas=0; // desnecess�rio
}

/// FUN��ES DE ESCRITA

/// Fun��o que escreve uma carta


/// Fun��o que escreve um vetor de cartas


/// Fun��o que escreve o monte (apresenta o n�mero de cartas que est�o no monte, e n�o as cartas que l� est�o)


/// Fun��o que escreve a mesa (escreve as cartas que est�o na mesa)


/// Fun��o que escreve um jogador: nome + cartas da m�o


/// Fun��o que escreve todos os jogadores



/// FUN��ES NECESS�RIAS AO FUNCIONAMENTO DO JOGO

/// Fun��o para dar distribuir as cartas do baralho (80 cartas) pelos jogadores, mesa e monte


/// Fun��o que verifica se algum jogador acabou o jogo
///(devolve o �ndice do jogador que tem 0 cartas - se todos t�m mais que 0 cartas, devolve 0).


/// Fun��o que verifica se uma carta "encaixa" na outra
///devolve 1 se ca carta 1 'encaixa' na carta 2 (verifica se carta 1 e carta 2 t�m a mesma cor ou a mesma face)


///Fun��o que devolve o �ndice do pr�ximo jogador a jogar


/// Fun��o que retira uma carta do monte para a m�o do jogador com o ind�ce j


///Fun��o para escolher a jogada
/// devolve o �ndice da carta que jogador j joga (� sorte de entre as poss�veis)
/// devolve 0 se o jogador j n�o tem cartas poss�veis de jogar


///Fun��o para jogar uma carta
/// retira a carte de �ndice ind da m�o do jogador j e coloca-a na mesa


///Fun��o para reorganizar o Monte e a Mesa
/// retira cartas que est�o na mesa (deixando 5) para o monte e rebaralha o monte


int main()
{
    srand(time(0));                          // semente dos n�meros pseudoaleat�rios
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

    ///Acrescentar as chamadas �s fun��es desenvolvidas, para fazer funcionar o Jogo do UNO



 getchar();
 return 0;
}
