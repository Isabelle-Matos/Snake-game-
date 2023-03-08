#include "cobra.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <jogo.h>
#include <string.h>

Cobra *cria_cobra()
{
    Cobra *luana = (Cobra *)malloc(sizeof(Cobra));
    luana->tamanho_cobra = 1;
    Coordenada *co = (Coordenada *)malloc(2304*sizeof(Coordenada));
    luana->c = co;
    luana->c[0].x = 320;
    luana->c[0].y = 240;
    luana->velo = 10;
    luana->direcao = 1;
    return luana;
}
Jogador *cria_jogador()
{
    Jogador *jogador = (Jogador *)malloc(sizeof(Jogador));
    jogador->pontos = 0;
    jogador->tela = 0;
    return jogador;
}
void menu(Jogador *jogador)
{

    desenha_imagem(320, 240, "assets/nova_cobra.gif");
    cor(15,15,15,150);
    desenha_retangulo(20,20,200,410);
    fonte("assets/Milky Honey.ttf", 50.00);
    cor(BRANCO);
    desenha_texto(30, 80, "Snake");
    fonte("assets/Milky Honey.ttf", 30.00);
    // verifica se o mouse esta em cima de jogar
    if (mouse_x > 30 && mouse_x < 100 && mouse_y > 120 && mouse_y < 160)
    {
        fonte("assets/Milky Honey.ttf", 40.00);
        if (botao_mouse_acabou_de_ser_apertado(BOTAO_ESQUERDO) == true)
        {

            jogador->tela = 1;
        }
    }
    desenha_texto(30, 160, "Jogar");
    fonte("assets/Milky Honey.ttf", 30.00);
    // verifica se o mouse esta em cima de scores
    if (mouse_x > 30 && mouse_x < 120 && mouse_y > 180 && mouse_y < 200)
    {
        fonte("assets/Milky Honey.ttf", 40.00);

        if (botao_mouse_acabou_de_ser_apertado(BOTAO_ESQUERDO) == true)
        {
            jogador->tela = 5;
        }
    }

    desenha_texto(30, 200, "Scores");
    fonte("assets/Milky Honey.ttf", 20.00);
    if (mouse_x > 30 && mouse_x < 120 && mouse_y > 400 && mouse_y < 420)
    {
        fonte("assets/Milky Honey.ttf", 30.00);
        if (botao_mouse_acabou_de_ser_apertado(BOTAO_ESQUERDO) == true)
        {
            fecha_janela();
        }
    }
    desenha_texto(30, 420, "Sair");
}
void inserir_nome(Jogador *jogador)
{

    printf("Insira o nome com ate 4 caracteres:\n");
    scanf("%s", jogador->apelido);
    jogador->tela = 2;
}
void dificuldade(Jogador *jogador, Cobra *luana)
{
    desenha_imagem(320, 240, "assets/nova_cobra.gif");
    cor(15,15,15,150);
    desenha_retangulo(20,20,200,410);
    cor(BRANCO);
    fonte("assets/Milky Honey.ttf", 30.00);
    // verifica se o mouse esta em cima de hard
    if (mouse_x > 30 && mouse_x < 100 && mouse_y > 120 && mouse_y < 160)
    {
        fonte("assets/Milky Honey.ttf", 40.00);
        if (botao_mouse_acabou_de_ser_apertado(BOTAO_MEIO) == true)
        {
            luana->velo = 5;
            jogador->tela = 3;
        }
    }
    desenha_texto(30, 160, "Hard");
    fonte("assets/Milky Honey.ttf", 30.00);
    // verifica se o mouse esta em cima de medium
    if (mouse_x > 30 && mouse_x < 120 && mouse_y > 180 && mouse_y < 200)
    {
        fonte("assets/Milky Honey.ttf", 40.00);
        if (botao_mouse_acabou_de_ser_apertado(BOTAO_MEIO) == true)
        {

            luana->velo = 10;
            jogador->tela = 3;
        }
    }
    desenha_texto(30, 200, "Medium");
    fonte("assets/Milky Honey.ttf", 30.00);
    // verifica se o mouse esta em cima de easy
    if (mouse_x > 30 && mouse_x < 120 && mouse_y > 220 && mouse_y < 240)
    {
        fonte("assets/Milky Honey.ttf", 40.00);
        if (botao_mouse_acabou_de_ser_apertado(BOTAO_MEIO) == true)
        {

            luana->velo = 15;
            jogador->tela = 3;
        }
    }
    desenha_texto(30, 240, "Easy");
}
void placar(Jogador *jogador)
{
    desenha_imagem(320, 240, "assets/nova_cobra.gif");
    FILE *arq = fopen("src/placar.txt", "r");
    int i = 0, j = 0;
    char buf[50];
    int pontos[5];
    char nomes[5][6];
    char c[5][50];

    if (arq == NULL)
    {
        printf("ERRO\n");
        exit(1);
    }
    fgets(buf, 50, arq);
    while (!feof(arq))
    {
        strcpy(nomes[i], strtok(buf, ","));
        pontos[i] = atoi(strtok(NULL, ","));
        sprintf(c[i], "%d", pontos[i]);
        i++;
        fgets(buf, 50, arq);
    }
    fclose(arq);
    cor(15,15,15,150);
    desenha_retangulo(20,20,200,410);
    cor(BRANCO);
    fonte("assets/Milky Honey.ttf", 50.00);
    desenha_texto(30, 80, "Top 5");
    for (int k = 200; k <= 340; k += 40)
    {

        fonte("assets/Milky Honey.ttf", 30.00);
        desenha_texto(30, k, nomes[j]);
        desenha_texto(160, k, c[j]);
        j++;
        if (j == 5)
            break;
    }

    fonte("assets/Milky Honey.ttf", 20.00);
    if (mouse_x > 30 && mouse_x < 80 && mouse_y > 400 && mouse_y < 420)
    {
        fonte("assets/Milky Honey.ttf", 30.00);
        if (botao_mouse_acabou_de_ser_apertado(BOTAO_DIREITO) == true)
        {

            jogador->tela = 0;
        }
    }
    desenha_texto(30, 420, "Voltar");
}
void gameover(Jogador *jogador, Cobra *luana)
{
    desenha_imagem(320, 240, "assets/nova_cobra.gif");
    fonte("assets/Milky Honey.ttf", 50.00);
    desenha_texto(30, 80, "Continuar?");
    fonte("assets/Milky Honey.ttf", 30.00);
    // verifica se o mouse esta em cima de jogar
    if (mouse_x > 30 && mouse_x < 100 && mouse_y > 120 && mouse_y < 160)
    {
        fonte("assets/Milky Honey.ttf", 40.00);
        if (botao_mouse_acabou_de_ser_apertado(BOTAO_DIREITO) == true)
        {
            jogador->num = 1;
            reinicia(luana, jogador);
        }
    }
    desenha_texto(30, 160, "Sim");
    fonte("assets/Milky Honey.ttf", 30.00);
    // verifica se o mouse esta em cima de scores
    if (mouse_x > 30 && mouse_x < 120 && mouse_y > 180 && mouse_y < 200)
    {
        fonte("assets/Milky Honey.ttf", 40.00);

        if (botao_mouse_acabou_de_ser_apertado(BOTAO_DIREITO) == true)
        {
            fecha_janela();
        }
    }

    desenha_texto(30, 200, "Nao");
    fonte("assets/Milky Honey.ttf", 20.00);
    if (mouse_x > 30 && mouse_x < 120 && mouse_y > 400 && mouse_y < 420)
    {
        fonte("assets/Milky Honey.ttf", 30.00);

        if (botao_mouse_acabou_de_ser_apertado(BOTAO_DIREITO) == true)
        {
            jogador->num = 0;
            reinicia(luana, jogador);
        }
    }
    desenha_texto(30, 420, "Menu");
}
void reinicia(Cobra *luana, Jogador *jogador)
{
    luana->c[0].x = 320;
    luana->c[0].y = 240;
    luana->tamanho_cobra = 1;
    jogador->pontos = 0;
    if (jogador->num == 1)jogador->tela = 2;
    if (jogador->num == 0)jogador->tela = 0;
}
void desenha(Cobra *luana, Jogador *jogador)
{
    char c[50];
    if(luana->direcao== 3){
        desenha_imagem(luana->c[0].x+6, luana->c[0].y+6, "assets/cabeca_subida.png");
    }
    if(luana->direcao== 4){
        desenha_imagem(luana->c[0].x+6, luana->c[0].y+6, "assets/cabeca_baixo.png");
    }
    if(luana->direcao== 1){
        desenha_imagem(luana->c[0].x+6, luana->c[0].y+6, "assets/cabeca_lado.png");
    }
    if(luana->direcao== 2){
        desenha_imagem(luana->c[0].x+6, luana->c[0].y+6, "assets/cabeca_esquerda.png");
    }
    
    for (int i = 1; i < luana->tamanho_cobra; i++)
    {
        desenha_imagem(luana->c[i].x+6, luana->c[i].y+6, "assets/corpo1.png");
    }

    desenha_imagem(80,240,"assets/ghost.gif");
    cor(BRANCO);
    sprintf(c,"%d", jogador->pontos);
    desenha_texto(65,350, c);
}
void desenha_maca(Coordenada *m)
{
    desenha_imagem(m->x+6,m->y+6,"assets/maca.gif");
    
}
void anda(Cobra *luana)
{
    for (int i = luana->tamanho_cobra - 1; i > 0; i--)
    {
        luana->c[i] = luana->c[i - 1];
    }
   
        if (luana->direcao == 1)
        {
            luana->c[0].x += 10;
        }
        if (luana->direcao == 2)
        {
            luana->c[0].x -= 10;
        }
        if (luana->direcao == 3)
        {
            luana->c[0].y -= 10;
        }
        if (luana->direcao == 4)
        {
            luana->c[0].y += 10;
        }
        
}
void comeu_maca(Cobra *luana, Coordenada *m, Jogador *jogador)
{
    if (luana->c[0].x == m->x && luana->c[0].y == m->y)
    {
        toca_som("assets/come.mp3");
        altera_coordenada(m);
        luana->tamanho_cobra += 1;
        jogador->pontos += 1;
    }
}
void altera_coordenada(Coordenada *m)
{
    m->x = (rand() % 469) +160;
    m->y = (rand() % 469);
    m->x -= (m->x) % 10;
    m->y -= (m->y) % 10;
  
 
}
void confere(Cobra *luana, Jogador *jogador)
{
    for (int i = 1; i < luana->tamanho_cobra; i++)
    {
        if (luana->c[0].x == luana->c[i].x && luana->c[0].y == luana->c[i].y)
        {
            arquivo(jogador);
            jogador->tela = 4;
        }
    }
    if (luana->c[0].x < 160 || luana->c[0].x > 630 || luana->c[0].y < 0 || luana->c[0].y > 470)
    {
        arquivo(jogador);
        jogador->tela = 4;
    }
}
void arquivo(Jogador *jogador)
{
    FILE *arq1 = fopen("src/placar.txt", "a");
    char nomes_aux[5];
    int i = 0;
    char buf[50];
    int aux;
    int pontos[6];
    char nomes[6][6];
    if (arq1 == NULL)
    {
        printf("ERRO\n");
        exit(1);
    }

    fprintf(arq1, "%s,%d\n", jogador->apelido, jogador->pontos);
    fclose(arq1);
    arq1 = fopen("src/placar.txt", "r");
    if (arq1 == NULL)
    {
        printf("ERRO\n");
        exit(1);
    }
    fgets(buf, 50, arq1);
    while (!feof(arq1))
    {
        strcpy(nomes[i], strtok(buf, ","));
        pontos[i] = atoi(strtok(NULL, ","));
        i++;
        fgets(buf, 50, arq1);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {
            if (pontos[j] > pontos[j + 1])
            {
                aux = pontos[j];
                strcpy(nomes_aux, nomes[j]);
                pontos[j] = pontos[j + 1];
                strcpy(nomes[j], nomes[j + 1]);
                pontos[j + 1] = aux;
                strcpy(nomes[j + 1], nomes_aux);
            }
        }
    }

    fclose(arq1);
    arq1 = fopen("src/placar.txt", "w");
    if (arq1 == NULL)
    {
        printf("ERRO\n");
        exit(1);
    }
    for (int i = 5; i > 0; i--)
    {
        fprintf(arq1, "%s,%d\n", nomes[i], pontos[i]);
    }
    fclose(arq1);
}
void desaloca(Cobra *c, Jogador *jogador)
{
    free(c->c);
    free(c);
    free(jogador);
}