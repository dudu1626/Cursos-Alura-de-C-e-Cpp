# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "foge-foge.h"
# include "mapa.h"

void copiaMapa(MAPA* destino, MAPA* origem){
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;
    
	alocarMapa(destino);
    
	for(int i = 0; i < origem->linhas; i++){
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

int dentroDoMapa(MAPA* mapa, int x, int y){
	if(x >= mapa->linhas) 
    	return 0;
	if(y >= mapa->colunas) 
    	return 0;
    	
    return 1;
}

int ehVazia(MAPA* mapa, int x, int y){
	return mapa->matriz[x][y] == VAZIO;
}

int podeAndar(MAPA* m, char personagem,int x, int y) {
    return 
        dentroDoMapa(m, x, y) && 
        !ehParede(m, x, y) &&
        !ehPersonagem(m, personagem, x, y);
}

int ehParede(MAPA* m, int x, int y) {
    return 
        m->matriz[x][y] == PAREDE_VERTICAL ||
        m->matriz[x][y] == PAREDE_HORIZONTAL;
}

int ehPersonagem(MAPA* m, char personagem, int x, int y) {
    return
        m->matriz[x][y] == personagem;
}

int encontraMapa(MAPA* mapa, POSICAO* p, char c){
	// achar a posição do boneco @ ou do fantasma F que são char
	for(int i = 0; i < mapa->linhas; i++){
		for(int j = 0; j < mapa->colunas; j++){
			if(mapa->matriz[i][j] == c){
				p->x = i;
				p->y = j;
				return 1;
			}
		}
	}
	
	return 0;
}

void liberarEspacoMapa(MAPA* mapa){
	for(int i = 0 ; i < mapa->linhas ; i++){
		free(mapa->matriz[i]);
	}
	
	free(mapa->matriz);
} // fim libera espaço

void lerMapa(MAPA* mapa){
		
	FILE* f; // criação de ponteiro para abrir arquivo

	f = fopen("mapa_01.txt", "r");
	if(f == 0) {
    	printf("Erro na leitura do mapa");
    	exit(1);
	}
	
	fscanf(f, "%d %d", &mapa->linhas, &mapa->colunas);
	
	alocarMapa(mapa);	
	
	// ler o mapa do arquivo
	for(int i = 0; i < mapa->linhas; i++) {
    	fscanf(f, "%s", mapa->matriz[i]); // dessa maneira conseguimos ler as linhas de uma vez
	}	
	
	fclose(f); // fechar o arquivo
} //fim ler mapa

void alocarMapa(MAPA* mapa){
// alocação dinâmica do espaço de memória para carregar o mapa
	mapa->matriz = malloc(sizeof(char*) * mapa->linhas); 
	for(int i=0 ; i<mapa->linhas ; i++){
		mapa->matriz[i] = malloc(sizeof(char) * (mapa->colunas+1)); // colunas +1 é por causa do formato escolhido no arquivo que termina em um enter
	}	
} // fim alocaMapa


