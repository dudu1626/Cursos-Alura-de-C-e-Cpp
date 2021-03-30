// ui = unidede de interface:

#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include "ui.h"
#include "foge-foge.h"

	
char desenhoFantasma[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char desenhoParede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char desenhoHeroi[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char desenhoBomba[4][7] = {
    {" '''  "},
    {" .|.  "},
    {" '-'  "},
    {"      "}
};

char desenhoVazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void imprimeParte(char desenho[4][7], int parte) {
    printf("%s", desenho[parte]);
}

void imprimirMapa(MAPA* mapa){
		
		for(int i=0; i<mapa->linhas; i++){
			
			for(int parte = 0; parte < 4; parte++) {
				
            	for(int j = 0; j < mapa->colunas; j++) {

                	switch(mapa->matriz[i][j]) {
                    	case FANTASMA:
                        	imprimeParte(desenhoFantasma, parte);
                        	break;
	                    case HEROI:
	                        imprimeParte(desenhoHeroi, parte);
	                        break;
	                    case PODER:
	                        imprimeParte(desenhoBomba, parte);
	                        break;
	                    case PAREDE_VERTICAL:
	                    case PAREDE_HORIZONTAL:
	                        imprimeParte(desenhoParede, parte);
	                        break;
	                    case VAZIO:
	                        imprimeParte(desenhoVazio, parte);
	                        break;
	                }
	
			}
			printf("\n");
		}
	}
} // fim imprime mapa 
