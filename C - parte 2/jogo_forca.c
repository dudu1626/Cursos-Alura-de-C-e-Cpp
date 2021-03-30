# include <stdio.h>
# include <string.h>
# include <locale.h>

/* para rodar o programa:

 cd C:\Users\dudu_\Documents\Curso Alura\C - parte 2
 parte 2>gcc jogo_forca.c -o jogo_forca.exe

*/

void abertura();
void chuta(char chutes[], int* tentativas);
int jaChutou(char letra, char* chutes, int* tentativas);
void desenhaForca(char* palavrasecreta, char* chutes, int* tentativas);
void escolhePalavraSecreta(char palavraSecreta[]);
int enforcou(char* palavraSecreta,int* tentativas,char chutes[]);

int main() {
	setlocale(LC_ALL, ""); // habilitar acentuação

	char palavraSecreta[20];

	int acertou = 0;
	int enforcado = 0;
	char chutes[26];
	int tentativas = 0;

	escolhePalavraSecreta(palavraSecreta);

	abertura();

	do {

		desenhaForca(palavraSecreta, chutes, &tentativas);

		chuta(chutes, &tentativas); // &tentativas é o endereço de memória da vairável tentativas

        enforcado = enforcou(palavraSecreta, &tentativas, chutes);

	} while (!acertou && !enforcou);

} //fim main

void abertura() {
	printf("*********************\n");
	printf("**  Jogo de Forca  **\n");
	printf("*********************\n\n");
}

void chuta(char chutes[], int* tentativas) {
	char chute;
	printf("Qual letra? ");
	scanf(" %c", &chute);

	chutes[*tentativas] = chute;
	(*tentativas)++;
}

int jaChutou(char letra, char* chutes, int* tentativas) {
	int achou = 0;
	for (int j = 0; j < (*tentativas); j++) {
		if (chutes[j] == letra) {
			achou = 1;
			break;
		}
	}//fim for j

	return achou;
}

void desenhaForca(char* palavraSecreta, char* chutes, int* tentativas) {
	int achou;
	printf("Você já deu %d chutes\n", (*tentativas));

		for (int i = 0; i < strlen(palavraSecreta); i++) {

			achou = jaChutou(palavraSecreta[i], chutes, &tentativas); // coloca chutes porque é um vetor que naturalmente é um ponteiro

			if (achou) {
				printf("%c ", palavraSecreta[i]);
			} else {
				printf("_ ");
			}

		} // fim for i
		printf("\n");
}

void escolhePalavraSecreta(char palavraSecreta[]){
	sprintf(palavraSecreta, "MELANCIA");
}

int enforcou(char* palavraSecreta,int* tentativas, char chutes[]){

    int erros = 0;

    // vamos fazer o loop em todos os chutes dados
    for(int i = 0; i < (*tentativas); i++) {

        int existe = 0;
        // agora vamos olhar letra a letra da palavra secreta
        // e ver se encontramos o chute aqui
        for(int j = 0; j < strlen(palavraSecreta); j++) {
            if(chutes[i] == palavraSecreta[j]) {
                // encontramos, vamos quebrar o loop
                existe = 1;
                break;
            }
        }
        // se nao encontrou, soma um na quantidade de erros
        if(!existe) erros++;
    }
    // se tivermos mais do que 5 erros, retornamos 1
    // caso contrario, retornamos 0.
    return erros >= 5;
}
