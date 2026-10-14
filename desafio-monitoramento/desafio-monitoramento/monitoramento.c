#include <stdio.h>

/* Constantes do programa */
#define TEMP_MIN -50      /* menor temperatura considerada valida */
#define TEMP_MAX 150      /* maior temperatura considerada valida */
#define SAIDA 999         /* valor digitado para encerrar manualmente */
#define SEQUENCIA 3       /* quantidade de leituras consecutivas para o alarme */

int main() {
    float limite, temp;
    float soma = 0, media, percentual;
    float maior = 0, menor = 0;
    int total = 0;            /* leituras validas */
    int acima = 0;            /* leituras acima do limite */
    int consecutivas = 0;     /* acima do limite em sequencia */
    int invalidas = 0;        /* tentativas invalidas */
    int alarme = 0;           /* 1 se o monitoramento parou pelo alarme */
    int continuar = 1;        /* controla o laço principal */
    int leituraOk;            /* guarda o retorno do scanf / validade */
    int c;                    /* usado para limpar o buffer do teclado */

    printf("=== MONITORAMENTO DE TEMPERATURA ===\n\n");

    /* 1) Leitura do limite: do...while porque precisa pedir pelo menos uma vez */
    do {
        printf("Digite o limite de temperatura (%d a %d): ", TEMP_MIN, TEMP_MAX);
        leituraOk = scanf("%f", &limite);

        /* limpa o que sobrou no buffer (ex.: letras) */
        while ((c = getchar()) != '\n' && c != EOF);

        if (leituraOk != 1) {
            printf("Entrada invalida! Digite apenas numeros.\n");
            leituraOk = 0;
        } else if (limite < TEMP_MIN || limite > TEMP_MAX) {
            printf("Limite fora do intervalo permitido!\n");
            leituraOk = 0;
        }
    } while (!leituraOk);

    printf("\nLimite definido: %.1f\n", limite);
    printf("Digite as temperaturas (%d encerra o monitoramento)\n\n", SAIDA);

    /* 2) Laço principal do monitoramento */
    while (continuar) {

        /* Validação da temperatura: repete ate vir um valor valido */
        do {
            printf("Leitura %d: ", total + 1);
            leituraOk = scanf("%f", &temp);
            while ((c = getchar()) != '\n' && c != EOF);

            if (leituraOk == EOF) {
                temp = SAIDA;          /* fim da entrada, encerra */
                leituraOk = 1;
            } else if (leituraOk != 1) {
                printf("Entrada invalida! Digite apenas numeros.\n");
                invalidas++;
                leituraOk = 0;
            } else if (temp != SAIDA && (temp < TEMP_MIN || temp > TEMP_MAX)) {
                printf("Temperatura fora do intervalo (%d a %d)!\n", TEMP_MIN, TEMP_MAX);
                invalidas++;
                leituraOk = 0;
            }
        } while (!leituraOk);

        if (temp == SAIDA) {
            /* usuario quis encerrar */
            continuar = 0;
        } else {
            /* leitura valida: atualiza os dados */
            total++;
            soma += temp;

            if (total == 1) {
                maior = temp;
                menor = temp;
            } else {
                if (temp > maior) {
                    maior = temp;
                }
                if (temp < menor) {
                    menor = temp;
                }
            }

            /* verifica o limite e controla as consecutivas */
            if (temp > limite) {
                acima++;
                consecutivas++;
                printf("  ATENCAO: acima do limite! (%d seguida(s))\n", consecutivas);
            } else {
                consecutivas = 0;      /* quebrou a sequencia, zera o contador */
            }

            /* 3 seguidas acima do limite: encerra automaticamente */
            if (consecutivas == SEQUENCIA) {
                alarme = 1;
                continuar = 0;
            }
        }
    }

    /* 3) Relatorio final */
    printf("\n=== RELATORIO FINAL ===\n");
    if (alarme) {
        printf("Monitoramento encerrado: %d temperaturas consecutivas acima do limite!\n", SEQUENCIA);
    } else {
        printf("Monitoramento encerrado pelo usuario.\n");
    }

    if (total > 0) {
        media = soma / total;
        percentual = (acima * 100.0) / total;

        printf("Leituras validas: %d\n", total);
        printf("Leituras invalidas: %d\n", invalidas);
        printf("Media: %.2f\n", media);
        printf("Maior temperatura: %.1f\n", maior);
        printf("Menor temperatura: %.1f\n", menor);
        printf("Acima do limite: %d\n", acima);
        printf("Percentual acima do limite: %.2f%%\n", percentual);
    } else {
        printf("Nenhuma leitura valida foi registrada.\n");
    }

    return 0;
}
