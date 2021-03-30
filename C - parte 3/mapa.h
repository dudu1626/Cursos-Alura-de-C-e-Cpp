#ifndef _MAPA_H_
#define _MAPA_H_


// definições do mapa

# define HEROI '@'
# define VAZIO '.'
# define PAREDE_VERTICAL '|'
# define PAREDE_HORIZONTAL '-'


struct mapa{
	char** matriz; //mapa será uma matriz e matriz é um ponteiro que aponta para um array de ponteiros
	int linhas;
	int colunas;
};

typedef struct mapa MAPA;

struct posicao {
    int x;
    int y;
};

typedef struct posicao POSICAO;


void lerMapa(MAPA* mapa);
void alocarMapa(MAPA* mapa);
void liberarEspacoMapa(MAPA* mapa);
int encontraMapa(MAPA* mapa, POSICAO* p, char c);
int dentroDoMapa(MAPA* mapa, int x, int y);
int ehVazia(MAPA* mapa, int x, int y);
void andaNoMapa(MAPA* mapa, int xOrigem, int yOrigem, int xDestino, int yDestino);
void copiaMapa(MAPA* destino, MAPA* origem);
int podeAndar(MAPA* m, char personagem,int x, int y);
int ehParede(MAPA* m, int x, int y);
int ehPersonagem(MAPA* m, char personagem, int x, int y);


#endif

