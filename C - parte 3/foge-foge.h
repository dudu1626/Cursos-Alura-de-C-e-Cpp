#ifndef _FOGEFOGE_H_
#define _FOGEFOGE_H_

// definições das funções para uso no jogo

# define CIMA 'w'
# define BAIXO 's'
# define DIREITA 'd' 
# define ESQUERDA 'a'
# define FANTASMA 'F'
# define PODER 'w'
# define BOMBA 'b'

int acabou();
void mover(char direcao);
int ehDirecao(char direcao);
void fantasmas();
int praOndeFantasmaVai(int xatual, int yatual, int* xdestino, int* ydestino);
void explodeBomba();
void explodeBomba2(int x, int y, int somax, int somay, int qtd);

#endif
