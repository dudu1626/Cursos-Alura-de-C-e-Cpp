#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "foge-foge.h" // maneira de colocar as definições de funções
#include "mapa.h"
#include "ui.h"

// para executar o programa no windows:
// gcc foge-foge.c mapa.c -o fogefoge.exe
// fogefoge

MAPA mapa;
POSICAO heroi;
int temBomba = 0;

// main
/////////////////////////////////////////////////
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	lerMapa(&mapa);
	encontraMapa(&mapa, &heroi, HEROI);
	
	do {		
		system("cls");
		printf("Bomba: %s\n", (temBomba ? "SIM" : "NÃO")); // if ternário
		imprimirMapa(&mapa);
		
		char comando;
		scanf(" %c", &comando);
		
		if(ehDirecao(comando))
			mover(comando);
		
		if(comando == BOMBA)
			explodeBomba(heroi.x, heroi.y, 3);
		
		fantasmas();
	
	} while(!acabou());
		
	liberarEspacoMapa(&mapa);
	
	system("PAUSE");
	return 0;
} // fim main
////////////////////////////////////////////////

int acabou(){
	POSICAO pos; // apenas para poder usar a função que já existe
    return !encontraMapa(&mapa, &pos, HEROI); //se não encontrar o heroi o jogo acaba
}

int ehDirecao(char direcao){
	return direcao == ESQUERDA || direcao == CIMA || direcao == BAIXO || direcao == DIREITA;
}

void andaNoMapa(MAPA* mapa, int xOrigem, int yOrigem, int xDestino, int yDestino) {
	
	char personagem = mapa->matriz[xOrigem][yOrigem];
    mapa->matriz[xDestino][yDestino] = personagem;
    mapa->matriz[xOrigem][yOrigem] = VAZIO;
}

void mover(char direcao){
	
	if(!ehDirecao(direcao))
    	return;
	
	int proximox = heroi.x;
    int proximoy = heroi.y;

    switch(direcao) {
        case ESQUERDA:
            proximoy--;
            break;
        case CIMA:
            proximox--;
            break;
        case BAIXO:
            proximox++;
            break;
        case DIREITA:
            proximoy++;
            break;
    }
    
	if(!podeAndar(&mapa, HEROI, proximox, proximoy))
		return;
	
	if(ehPersonagem(&mapa, PODER, proximox, proximoy))
        temBomba = 1;
		
    andaNoMapa(&mapa, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;
    
}// fim função mover

void fantasmas(){
    MAPA copia;

    copiaMapa(&copia, &mapa);

    for(int i = 0; i < copia.linhas; i++) {
        for(int j = 0; j < copia.colunas; j++) {
            
			if(copia.matriz[i][j] == FANTASMA) {
                
                int xdestino;
                int ydestino;

                int encontrou = praOndeFantasmaVai(i, j, &xdestino, &ydestino);

                if(encontrou) {
                    andaNoMapa(&mapa, i, j, xdestino, ydestino);
                
            	}
                
                
            }
        }
    }

    liberarEspacoMapa(&copia);
}

int praOndeFantasmaVai(int xatual, int yatual, int* xdestino, int* ydestino) {

    int opcoes[4][2] = { { xatual , yatual+1 }, { xatual+1 , yatual },  
        { xatual   , yatual-1 }, { xatual-1 , yatual   } };

    srand(time(0));
    for(int i = 0; i < 10; i++) {
        int posicao = rand() % 4;

        if(podeAndar(&mapa, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])){
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];
            return 1;
        } // essa aqui eu demorei para entender:
        // no xdestino a matriz opções vai dar como resposta uma linha aleatória na coluna 0
        // logo o x destino vai ser alterado no xatual
        // no ydestino a matriz vai dar retorno aleatoria da linha igualmente, mas 
		// o valor recebido vai ser ser da coluna 1, ou seja, o ydestino.
    }

    return 0;
}

void explodeBomba(){
	
	if(!temBomba)
		return;
		
	// chama a função e aplica para todas as direções
	explodeBomba2(heroi.x, heroi.y, 0, 1, 3);
    explodeBomba2(heroi.x, heroi.y, 0, -1, 3);
    explodeBomba2(heroi.x, heroi.y, 1, 0, 3);
    explodeBomba2(heroi.x, heroi.y, -1, 0, 3);
    
    temBomba = 0;

}

void explodeBomba2(int x, int y, int somax, int somay, int qtd){

    if(qtd == 0) return;

    int novox = x+somax;
    int novoy = y+somay;

    if(!dentroDoMapa(&mapa, novox, novoy))
		return;
    if(ehParede(&mapa, novox, novoy))
		return;

    mapa.matriz[novox][novoy] = VAZIO;
    explodeBomba2(novox, novoy, somax, somay, qtd-1);
}
