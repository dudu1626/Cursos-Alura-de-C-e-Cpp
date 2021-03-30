#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[]){
    
    setlocale(LC_ALL, "Portuguese");

    cout << "*************************************" << endl;
    cout << "* Bem-vindo ao jogo da adivinhação! *" << endl;
    cout << "*************************************" << endl;
    
    char dificuldade;
    int numero_de_tentativas = 0;
    int chute;
    double pontos = 1000.0;
    double pontos_perdidos = 0;
    int tentativa = 1;
    bool ganhou = false;
    
    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 101; // boa prática em c++ usa-se constantes em caixa alta
    
    do{
    	cout << "Escolha o nível de dificuldade:" << endl;
    	cout << "Fácil (F), Médio (M), Difícil (D)" << endl;
    	cin >> dificuldade;
    	
		switch(dificuldade) {
    		case 'F' : numero_de_tentativas = 15;
    		break;
    		
			case 'M' : numero_de_tentativas = 10;
    		break;
    		
			case 'D' : numero_de_tentativas = 5;
    		break;
    		
			default : cout << "opção inválida" << endl;
    		break;
		}
			
	}while(numero_de_tentativas == 0);
    
	for(tentativa ; tentativa <= numero_de_tentativas; tentativa++){
	
		pontos -= pontos_perdidos;
	    
	    cout << "Digite um número entre 0 e 100" << endl;
		cout << "Tentativa " << tentativa << endl;
		cout << "Digite o seu chute: ";
	    cin >> chute;
	    
	    if(chute == NUMERO_SECRETO){
	    	
			ganhou = true;
			break;	
		}
	    else if (chute > NUMERO_SECRETO){
	    	cout << "Você chutou um número maior que o número secreto!" << endl;
		}
	    else{
	    	cout << "Você chutou um número menor que o número secreto!" << endl;
		}
		
		pontos_perdidos = (tentativa * abs(chute - NUMERO_SECRETO))/1.5;
		
	}
	
	if(ganhou == true){
		cout << "Parabéns, você acertou o número secreto em "<< tentativa << " tentativas" << endl;
	    
		cout.precision(2); // colocar a precisão do cout em 2 casas decimais
		cout << fixed; // fixar o número de casas anteriores, senão será escrito em notação científica
		cout << "Pontuação final: " << pontos << endl;
				
	}else{
		
		cout << "Você perdeu! \nTente novamente! \n" << endl;
	}
				
	cout << "\t\t GAME OVER" << endl;
    
    system("PAUSE");
    return 0;
}


