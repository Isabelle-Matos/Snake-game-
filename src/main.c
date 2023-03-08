#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "cobra.h"



int main() {
    int k = 0;
    Cobra *luana = cria_cobra();
    Coordenada *m = (Coordenada*)malloc(sizeof(Coordenada));

    srand(time(NULL));
    m->x = (rand() % 469) +160;
    m->y = (rand() % 469);
    m->x-=m->x%10;
    m->y-=m->y%10;

    Jogador *jogador = cria_jogador();
    abre_janela(640, 480);
    int tela = 0;

    while (janela_esta_aberta()) {
        if(!som_esta_tocando("assets/jogo.mp3")) toca_som("assets/jogo.mp3");

        if(jogador->tela ==0){
            menu(jogador);
        }
        if(jogador->tela == 1){
            inserir_nome(jogador);
        }
        if(jogador->tela == 2){
            dificuldade(jogador, luana);
        }
        if(jogador->tela == 3){
            desenha_imagem(400,240,"assets/fundo.gif");
            desenha_maca(m);
            cor(VERDE_CLARO);
            desenha(luana, jogador);
            comeu_maca(luana, m, jogador);
            confere(luana, jogador);
            if(tecla_acabou_de_ser_apertada(ESC)){
                janela_deve_fechar();
            }

            if(luana->tamanho_cobra >1){
 
            if(tecla_acabou_de_ser_apertada('W') && luana->c[0].y == luana->c[1].y){
                luana->direcao = 3;
            }
            if(tecla_acabou_de_ser_apertada('S') && luana->c[0].y == luana->c[1].y){
                luana->direcao = 4;
            }
            if(tecla_acabou_de_ser_apertada('D') && luana->c[0].x == luana->c[1].x){
                luana->direcao = 1;
            }
            if(tecla_acabou_de_ser_apertada('A') && luana->c[0].x == luana->c[1].x){
                luana->direcao = 2;
            }

        }
            else{ 

            if(tecla_acabou_de_ser_apertada('W') && luana->direcao!=4){
                luana->direcao = 3;
            }
            if(tecla_acabou_de_ser_apertada('S') && luana->direcao!=3){
                luana->direcao = 4;
            }
            if(tecla_acabou_de_ser_apertada('D') && luana->direcao!=2){
                luana->direcao = 1;
            }
            if(tecla_acabou_de_ser_apertada('A') && luana->direcao!=1){
                luana->direcao = 2;
            }

        }

        
        if(k==luana->velo){
                anda(luana);
                k = 0;
            }
                k++;
    } 

        if(jogador->tela==4){
            para_som("assets/jogo.mp3");
            if(!som_esta_tocando("assets/game-over.mp3")) toca_som("assets/game-over.mp3");
            gameover(jogador, luana);
        }
        if(jogador->tela==5){
            placar(jogador);
        }
    }
    fecha_janela();
    desaloca(luana, jogador);

    return 0;
}
