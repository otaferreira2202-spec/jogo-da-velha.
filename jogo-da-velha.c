#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions_jogo-da-velha.h"

int main(int argc, char *argv[])
{
    char tabuleiro[TAMANHO][TAMANHO];
    char caractereJogador1, caractereVez;
    int automatico;
    int linha, coluna;
    int vencedor;

    srand((unsigned int) time(NULL));

    inicializarTabuleiro(tabuleiro);

    caractereJogador1 = definirCaractereJogador(argc, argv);
    automatico = modoAutoSolicitado(argc, argv);

    caractereVez = caractereJogador1;
    vencedor = 0;

    while (!vencedor && !tabuleiroCompleto(tabuleiro))
    {
        if (caractereVez == caractereJogador1 && !automatico)
        {
            lerJogadaHumano(tabuleiro, &linha, &coluna);
        }
        else
        {
            gerarJogadaAleatoria(tabuleiro, &linha, &coluna);
        }

        jogar(tabuleiro, linha, coluna, caractereVez);
        imprimirTabuleiro(tabuleiro);

        if (verificarVitoria(tabuleiro, caractereVez))
        {
            vencedor = (caractereVez == caractereJogador1) ? 1 : 2;
        }

        caractereVez = outroCaractere(caractereVez);
    }

    if (vencedor)
    {
        printf("O jogador %d ganhou\n", vencedor);
    }
    else
    {
        printf("O jogo terminou sem vencedores\n");
    }

    printf("Criado por Otavio Augusto Sampaio Ferreira\n");

    return 0;
}
