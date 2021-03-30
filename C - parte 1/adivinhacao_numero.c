#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main(){
    setlocale(LC_ALL,"Portuguese");

    int segundos = time(0);
    srand(segundos); // "semente da função aleatória rand() forçada nos segundos"

    int chute = 0, numero_secreto;
    int i = 1;
    float pontos = 1000.0, pontos_perdidos = 0.0;
    int acertou = 0;

    numero_secreto = rand() % 101; // uso o resto da divisão por 101 para ter numeros entre 0 e 100


    printf("%d",numero_secreto); // para teste

    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");
    // ascii arts
    printf("\t");printf("                T~~                   ");printf("\n");
    printf("\t");printf("                |                     ");printf("\n");
    printf("\t");printf("               / \\                    ");printf("\n");
    printf("\t");printf("       T~~     | | T~~                ");printf("\n");
    printf("\t");printf("   T~~ |    T~ WWWW|                  ");printf("\n");
    printf("\t");printf("   |  / \\   |  |  |/\\T~~              ");printf("\n");
    printf("\t");printf("  / \\ WWW  / \\ |  |WW|                ");printf("\n");
    printf("\t");printf(" WWWWW/\\| /   \\| /\\|/ \\               ");printf("\n");
    printf("\t");printf(" |   /__\\/]WWW[\\/__\\WWWW              ");printf("\n");
    printf("\t");printf(" |   WWWW |I_I| WWWW   |              ");printf("\n");
    printf("\t");printf(" |   |  |/  -  \\|  |   |              ");printf("\n");
    printf("\t");printf(" |   |  |LI=H=LI|  |   |              ");printf("\n");
    printf("\t");printf(" |   |  | |[_]| |  |   |              ");printf("\n");
    printf("\t");printf(" |   |  |_|###|_|  |   |              ");printf("\n");
    printf("\t");printf("  --- -- -/___\\- -- ---               ");printf("\n");
    printf("\t");printf("MMMMMMMMMMMMMMMMMMMMMMMMM             ");printf("\n");

    int nivel, n_tentativas;

    printf("\nQual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch(nivel){
        case 1:
            n_tentativas = 20;
            break;

        case 2:
            n_tentativas = 10;
            break;

        case 3:
            n_tentativas = 5;
            break;
    }

    for(int i = 1; i <= n_tentativas; i++) {

        printf("Tentativa %d de %d\n", i, n_tentativas);
        printf("Digite seu chute:");
        scanf("%d", &chute);

        if(chute<0){

            printf("Não pode número negativo, tente novamente!\n");
            continue;
        }

        if(chute == numero_secreto) {

            printf("\nParabéns! Você acertou!\n");
            acertou = 1;
            break;

        }else if(chute > numero_secreto) {

            printf("Seu chute foi maior do que o número secreto!\n");

        }else{

            printf("Seu chute foi menor do que o número secreto!\n");
        }

        pontos_perdidos = abs(chute - numero_secreto) / (float)2; // casting transforma o numero int momentaneamente para float
        pontos = pontos - pontos_perdidos;
    }

    printf("Fim de Jogo!\n");

    if(acertou) {
        printf("Você ganhou!\n");
        printf("Você acertou em %d tentativas!\n", n_tentativas);
        printf("Total de pontos: %.2f\n", pontos);

printf("                                  .s* *s+.               \n");
printf("                          $;    `*b. .ss.                \n");
printf("                          `Ts.    `TP' `T..ss.           \n");
printf("                            `*b         $P  `T_,+.       \n");
printf("                             d'              :P'`$.      \n");
printf("                            d'                   :Ts.    \n");
printf("                           d'                   '  `*Ts. \n");
printf("                          d'                          `$;\n");
printf("                         d'                       .bs+sP \n");
printf("                        d'                        $      \n");
printf("                       d'                        :;      \n");
printf("                 s**s.d'                         $       \n");
printf("                d'.s $+_    .+s*s.              :;       \n");
printf("               d'dP d' `*+,d*'   `b             $        \n");
printf("              d'dP d'     d'     .P.s*s.       :;        \n");
printf("              T.  d'      $     .Pd'   `b      $         \n");
printf("               `*d'       T.   .Pd'     $     :;         \n");
printf("                d'         `*sP' $     .P     $          \n");
printf("               d'         .+     T.   .P *+. :;_         \n");
printf("              d'         d'      `*sP'     `^$P*s.       \n");
printf("             d'         :$        .         :; s`T       \n");
printf("            d'          :$        $         $ :P.P       \n");
printf("           d'            `Ts._  _.P        :;:P.P        \n");
printf("_        .d;               ` *TsP'         $;'.P         \n");
printf("^Ts._   d'`Tb.                            :;TsP          \n");
printf(" :P *Tsd;   `*Tb.                         $              \n");
printf(".P     Ts.     `*Tb.                     :;              \n");
printf("P       `Ts.      `*Tb.                  $               \n");
printf("          `Ts.       `$Tb._             :;               \n");
printf("b           `Ts.    .d$$$$$$$g+._       $                \n");
printf("$b            `Ts..dP'T$$$$$  ` *^Tbs+sd;                \n");
printf("$P*.            `TP'b  `T$$$ [bug]     :b                \n");
printf("P   $.             d$.  JTd$         _.sP+.              \n");
printf("     $$._         d$$$sP*' $bss++ssdP*'  `*Ts._          \n");
printf("     $$$$Ts._  _.d$$$$$b                     `*Tbs.      \n");
printf("     $$$$$$$$T^*' `T$$$P                         `*b     \n");
printf("     :$$$$$$$       T$P                            $     \n");
printf("     :$$$$$$$       :P                             $     \n");
printf("      $$$$$$$b     .P                              $     \n");
printf("____________________________________________________     \n");




    } else {
        printf("Você perdeu! Tente de novo!\n");
    }


    system("PAUSE");
    return 0;
}
