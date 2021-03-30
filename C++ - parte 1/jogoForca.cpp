#include <iostream>
#include <cstdlib>    // para usar as funções do c , principalmente a função randon
#include <ctime>	  // para usar a função time
#include <string>     // para usar funções de string
#include <map>        // para usar o map (dicionário) no c++
#include <vector>     // para usar vector/vetor especial do c++
#include <fstream>    // para usar arquivos no c++

using namespace std;

// variáveis globais
string palavra_secreta;

// escopo das funções
bool letra_existe(char chute);
bool nao_acertou();
bool nao_enforcou();
void apresentacao_jogo();
void pula_linhas(int num);
void imprime_erros();
void imprime_palavra_secreta();
void chutar();
void mensagem_final();
vector<string> le_arquivo();
void sorteia_palavra();
void adiciona_palavra();
void salva_arquivo(vector<string> nova_lista);

// variáveis globais
map<char,bool> chutou; // dicionário em c++
vector<char> chutes_errados; // vetor de alocação dinâmica

int main(int argc, char const *argv[]){
    
    setlocale(LC_ALL, "Portuguese");

	apresentacao_jogo();
	sorteia_palavra();
	
	while(nao_acertou() && nao_enforcou()){
		
		imprime_palavra_secreta();
		 
		chutar();
		
		imprime_erros();	
	}
	
	if(nao_acertou()){
		cout << " Você perdeu! Tente novamente..." << endl;
	}
	else{
		cout << " Parabéns! Você ganhou!" << endl;
		
		cout << "Você gostaria de adiciornar uma nova palavra ao banco?  (S / N)" << endl;
		char resposta;
		cin >> resposta;
		
		if(resposta == 'S' or resposta == 's'){
			adiciona_palavra();
		}
	}
	
	mensagem_final();
	
	system("PAUSE");
	return 0;
}

bool letra_existe(char chute){
    for(char letra : palavra_secreta){ // implementa um for onde a "variável" que vai andar é o tipo 
        if(chute == letra){            // da primeira que tem na segunda variável
            return true;               // na string palavra_secreta as letras dela vao "andando"
        }
    }
    return false;
}

bool nao_acertou(){
	for(char letra : palavra_secreta){
		if(!chutou[letra]){
			return true; // faz uma leitura se ainda tem letras na palavra secreta que ainda não foram
						// "acertadas"
		}
	}
	return false;
}

bool nao_enforcou(){
	return chutes_errados.size() < 5; // se errar 5 vezes "enforcou"
}

void apresentacao_jogo(){
	
    cout << "*******************************" << endl;
    cout << "* Bem-vindo ao jogo da forca! *" << endl;
    cout << "*******************************" << endl;
	pula_linhas(2);
}

void pula_linhas(int num){
	for(int i = 0; i < num; i++){
		cout << endl;
	}
}

void imprime_erros(){
	cout << "Chutes errados: ";
	for(char letra : chutes_errados){
		cout << letra << " ";
	}
	pula_linhas(2);
}

void imprime_palavra_secreta(){
	for(char letra : palavra_secreta){
		if(chutou[letra]){
			cout << letra << " ";
		}else{
			cout << "_ ";
				
		}
			
	}	
	pula_linhas(1);
}

void chutar(){
	cout << "Digite uma letra: ";
	char chute;
	cin >> chute;
		
	chutou[chute] = true;
		
	if(letra_existe(chute)){
        cout << "Você acertou! Seu chute está na palavra.\n" << endl;
    }else{
        cout << "Você errou! Seu chute não está na palavra.\n" << endl;
        chutes_errados.push_back(chute); // coloca a letra no vetor
    }
}

void mensagem_final(){
	cout << "A palavra secreta era: " << palavra_secreta << endl;
	cout << "\n\n\t\t GAME OVER\n\n" <<endl;
	pula_linhas(1);
}

vector<string> le_arquivo(){
	ifstream arquivo; // criação de uma "variável" de leitura de um arquivo
	arquivo.open("palavras.txt");
	
	if(arquivo.is_open()){
		int quantidade_palavras;
		arquivo >> quantidade_palavras;
		vector<string> palavras_arquivo;
	
		for(int i = 0 ; i < quantidade_palavras ; i++){
		
			string palavra_lida;
			arquivo >> palavra_lida; // pega a palavra do arquivo e coloca na variável
			palavras_arquivo.push_back(palavra_lida); // preenche o vetro com as palavras do arquivo
		}
		
		arquivo.close();
	
		return palavras_arquivo;
	}else{
		cout << "Não foi possível acessar o banco de palavras!!!" << endl;
		exit(0);
	}
	
}

void sorteia_palavra(){
	vector<string> palavras = le_arquivo();
	
	srand(time(NULL)); // coloca a semente no rand com o time
	
	int indice_sorteado = rand() % palavras.size(); // resto da divisão do tamanho do vetor 
	
	palavra_secreta = palavras[indice_sorteado];
	
}

void adiciona_palavra(){
	cout << "Digite a nova palavra, usando letras maiúsculas." << endl;
	string nova_palavra;
	cin >> nova_palavra;
	
	vector<string> lista_palavras = le_arquivo();
	
	lista_palavras.push_back(nova_palavra);
	
	salva_arquivo(lista_palavras);
}

void salva_arquivo(vector<string> nova_lista){
	ofstream arquivo; // criação de uma "variável" para para escrever no arquivo
	
	arquivo.open("palavras.txt");
	
	if(arquivo.is_open()){
		arquivo << nova_lista.size() << endl; // para manter o padrão e funcionamento pensado no jogo
		                                      // a primeira linha é o número de palavras da lista
											  
		for(string palavra : nova_lista){     // caminha por cada string contida no vetor nova_lista
			arquivo << palavra << endl;       // para cada palavra da lista será "impresso" no arquivo
		}
		
		arquivo.close();
	}else{
		exit(0);
	}
}
