#ifndef COBRA_H
#define COBRA_H

typedef struct
{
    int num;
    int tela;
    int pontos;
    char apelido[5];
}Jogador;

typedef struct
{
    int x;
    int y;
}Coordenada;

typedef struct
{
    int tamanho_cobra;
    int direcao;
    int velo;
    Coordenada *c;
}Cobra;

Cobra* cria_cobra();
Jogador* cria_jogador();
void menu(Jogador *jogador);
void inserir_nome(Jogador *Jogador);
void dificuldade(Jogador *jogador, Cobra *luana);
void placar(Jogador *jogador);
void gameover(Jogador *jogador, Cobra *luana);
void reinicia(Cobra *luana, Jogador *jogador);
void desenha(Cobra *luana, Jogador *jogador);
void desenha_maca(Coordenada *m);
void anda(Cobra *luana);
void comeu_maca(Cobra *luana, Coordenada *m, Jogador *jogador);
void altera_coordenada(Coordenada *m);
void confere(Cobra *luana, Jogador *jogador);
void arquivo(Jogador *jogador);
void desaloca(Cobra *c, Jogador *jogador);
#endif



