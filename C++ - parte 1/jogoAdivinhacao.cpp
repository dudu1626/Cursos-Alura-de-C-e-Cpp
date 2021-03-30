#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[]){
    
    setlocale(LC_ALL, "Portuguese");

    cout << "*************************************" << endl;
    cout << "* Bem-vindo ao jogo da adivinha��o! *" << endl;
    cout << "*************************************" << endl;
    
    char dificuldade;
    int numero_de_tentativas = 0;
    int chute;
    double pontos = 1000.0;
    double pontos_perdidos = 0;
    int tentativa = 1;
    bool ganhou = false;
    
    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 101; // boa pr�tica em c++ usa-se constantes em caixa alta
    
    do{
    	cout << "Escolha o n�vel de dificuldade:" << endl;
    	cout << "F�cil (F), M�dio (M), Dif�cil (D)" << endl;
    	cin >> dificuldade;
    	
		switch(dificuldade) {
    		case 'F' : numero_de_tentativas = 15;
    		break;
    		
			case 'M' : numero_de_tentativas = 10;
    		break;
    		
			case 'D' : numero_de_tentativas = 5;
    		break;
    		
			default : cout << "op��o inv�lida" << endl;
    		break;
		}
			
	}while(numero_de_tentativas == 0);
    
	for(tentativa ; tentativa <= numero_de_tentativas; tentativa++){
	
		pontos -= pontos_perdidos;
	    
	    cout << "Digite um n�mero entre 0 e 100" << endl;
		cout << "Tentativa " << tentativa << endl;
		cout << "Digite o seu chute: ";
	    cin >> chute;
	    
	    if(chute == NUMERO_SECRETO){
	    	
			ganhou = true;
			break;	
		}
	    else if (chute > NUMERO_SECRETO){
	    	cout << "Voc� chutou um n�mero maior que o n�mero secreto!" << endl;
		}
	    else{
	    	cout << "Voc� chutou um n�mero menor que o n�mero secreto!" << endl;
		}
		
		pontos_perdidos = (tentativa * abs(chute - NUMERO_SECRETO))/1.5;
		
	}
	
	if(ganhou == true){
		cout << "Parab�ns, voc� acertou o n�mero secreto em "<< tentativa << " tentativas" << endl;
	    
		cout.precision(2); // colocar a precis�o do cout em 2 casas decimais
		cout << fixed; // fixar o n�mero de casas anteriores, sen�o ser� escrito em nota��o cient�fica
		cout << "Pontua��o final: " << pontos << endl;
				
	}else{
		
		cout << "Voc� perdeu! \nTente novamente! \n" << endl;
	}
				
	cout << "\t\t GAME OVER" << endl;
    
    system("PAUSE");
    return 0;
}


