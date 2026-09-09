/* Calculadora multifuncional - 20 operacoes
   Compilar: gcc calculadora.c -o calculadora -lm
   Executar: ./calculadora */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979

/* prototipos das funcoes */
double le(char *msg);
int leInteiro(char *msg);
void menu(void);

double soma(double a, double b);
double subtracao(double a, double b);
double multiplicacao(double a, double b);
double divisao(double a, double b);
double porcentagem(double valor, double taxa);
double grausParaRadianos(double graus);
double radianosParaGraus(double radianos);

unsigned long long fatorial(int n);
int primo(int n);
void tabuada(int n, int ate);
void bhaskara(double a, double b, double c);

void areas(void);
void perimetros(void);
void volumes(void);


/* ---------- leitura de dados ---------- */

/* Le um numero digitado pelo usuario. Se ele digitar algo que nao seja
   numero, o programa limpa o buffer do teclado e pergunta de novo. */
double le(char *msg)
{
    double valor;
    int caractere;

    while (1) {
        printf("%s", msg);

        if (scanf("%lf", &valor) == 1) {
            return valor;
        }

        /* descarta o que sobrou na linha que o usuario digitou */
        do {
            caractere = getchar();
        } while (caractere != '\n' && caractere != EOF);

        if (caractere == EOF) {
            exit(0);
        }

        printf("Valor invalido, digite um numero.\n");
    }
}

/* Le um numero e converte para inteiro. */
int leInteiro(char *msg)
{
    return (int) le(msg);
}


/* ---------- operacoes basicas ---------- */

double soma(double a, double b)
{
    return a + b;
}

double subtracao(double a, double b)
{
    return a - b;
}

double multiplicacao(double a, double b)
{
    return a * b;
}

double divisao(double a, double b)
{
    return a / b;
}

double porcentagem(double valor, double taxa)
{
    return valor * taxa / 100;
}


/* ---------- conversao de angulos ---------- */

double grausParaRadianos(double graus)
{
    return graus * PI / 180;
}

double radianosParaGraus(double radianos)
{
    return radianos * 180 / PI;
}


/* ---------- outras operacoes ---------- */

/* Calcula n! multiplicando todos os numeros de 2 ate n. */
unsigned long long fatorial(int n)
{
    unsigned long long resultado = 1;
    int i;

    for (i = 2; i <= n; i++) {
        resultado = resultado * i;
    }

    return resultado;
}

/* Retorna 1 se o numero for primo e 0 se nao for. */
int primo(int n)
{
    int i;

    if (n < 2) {
        return 0;
    }

    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

/* Mostra a tabuada de n, de 1 ate o limite escolhido. */
void tabuada(int n, int ate)
{
    int i;

    for (i = 1; i <= ate; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}

/* Resolve a equacao do 2o grau pela formula de Bhaskara. */
void bhaskara(double a, double b, double c)
{
    double delta;
    double x1;
    double x2;

    delta = b * b - 4 * a * c;
    printf("Delta = %g\n", delta);

    if (delta < 0) {
        printf("A equacao nao possui raizes reais.\n");
    } else if (delta == 0) {
        x1 = -b / (2 * a);
        printf("A equacao possui uma raiz real: x1 = x2 = %g\n", x1);
    } else {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("A equacao possui duas raizes reais:\n");
        printf("x1 = %g\n", x1);
        printf("x2 = %g\n", x2);
    }
}


/* ---------- geometria ---------- */

void areas(void)
{
    int opcao;
    double a;
    double b;
    double h;
    double resultado;

    printf("1 - Quadrado\n");
    printf("2 - Retangulo\n");
    printf("3 - Triangulo\n");
    printf("4 - Circulo\n");
    printf("5 - Trapezio\n");
    printf("6 - Losango\n");
    opcao = leInteiro("Escolha a figura: ");

    switch (opcao) {
        case 1:
            a = le("Digite o lado: ");
            resultado = a * a;
            break;

        case 2:
            a = le("Digite a base: ");
            b = le("Digite a altura: ");
            resultado = a * b;
            break;

        case 3:
            a = le("Digite a base: ");
            b = le("Digite a altura: ");
            resultado = a * b / 2;
            break;

        case 4:
            a = le("Digite o raio: ");
            resultado = PI * a * a;
            break;

        case 5:
            a = le("Digite a base maior: ");
            b = le("Digite a base menor: ");
            h = le("Digite a altura: ");
            resultado = (a + b) * h / 2;
            break;

        case 6:
            a = le("Digite a diagonal maior: ");
            b = le("Digite a diagonal menor: ");
            resultado = a * b / 2;
            break;

        default:
            printf("Opcao invalida.\n");
            return;
    }

    printf("Area = %g\n", resultado);
}

void perimetros(void)
{
    int opcao;
    double a;
    double b;
    double c;
    double resultado;

    printf("1 - Quadrado\n");
    printf("2 - Retangulo\n");
    printf("3 - Triangulo\n");
    printf("4 - Circunferencia\n");
    opcao = leInteiro("Escolha a figura: ");

    switch (opcao) {
        case 1:
            a = le("Digite o lado: ");
            resultado = 4 * a;
            break;

        case 2:
            a = le("Digite a base: ");
            b = le("Digite a altura: ");
            resultado = 2 * (a + b);
            break;

        case 3:
            a = le("Digite o lado 1: ");
            b = le("Digite o lado 2: ");
            c = le("Digite o lado 3: ");
            resultado = a + b + c;
            break;

        case 4:
            a = le("Digite o raio: ");
            resultado = 2 * PI * a;
            break;

        default:
            printf("Opcao invalida.\n");
            return;
    }

    printf("Perimetro = %g\n", resultado);
}

void volumes(void)
{
    int opcao;
    double a;
    double b;
    double c;
    double resultado;

    printf("1 - Cubo\n");
    printf("2 - Paralelepipedo\n");
    printf("3 - Esfera\n");
    printf("4 - Cilindro\n");
    printf("5 - Cone\n");
    printf("6 - Piramide de base quadrada\n");
    opcao = leInteiro("Escolha o solido: ");

    switch (opcao) {
        case 1:
            a = le("Digite a aresta: ");
            resultado = a * a * a;
            break;

        case 2:
            a = le("Digite o comprimento: ");
            b = le("Digite a largura: ");
            c = le("Digite a altura: ");
            resultado = a * b * c;
            break;

        case 3:
            a = le("Digite o raio: ");
            resultado = 4.0 / 3 * PI * a * a * a;
            break;

        case 4:
            a = le("Digite o raio da base: ");
            b = le("Digite a altura: ");
            resultado = PI * a * a * b;
            break;

        case 5:
            a = le("Digite o raio da base: ");
            b = le("Digite a altura: ");
            resultado = PI * a * a * b / 3;
            break;

        case 6:
            a = le("Digite o lado da base: ");
            b = le("Digite a altura: ");
            resultado = a * a * b / 3;
            break;

        default:
            printf("Opcao invalida.\n");
            return;
    }

    printf("Volume = %g\n", resultado);
}


/* ---------- menu ---------- */

void menu(void)
{
    char *nomes[20] = {
        "Soma",
        "Subtracao",
        "Multiplicacao",
        "Divisao",
        "Resto da divisao",
        "Porcentagem",
        "Potenciacao",
        "Raiz quadrada",
        "Fatorial",
        "Numero primo",
        "Tabuada",
        "Media aritmetica",
        "Maior e menor",
        "Area de figuras",
        "Perimetro",
        "Volume de solidos",
        "Teorema de Pitagoras",
        "Equacao do 2o grau",
        "Distancia entre pontos",
        "Graus e radianos"
    };
    int i;

    printf("\n===== CALCULADORA MULTIFUNCIONAL =====\n");

    for (i = 0; i < 20; i++) {
        printf("%2d - %-24s", i + 1, nomes[i]);

        /* quebra a linha a cada duas opcoes, para o menu ficar em duas colunas */
        if (i % 2 == 1) {
            printf("\n");
        }
    }

    printf(" 0 - Sair\n");
}


/* ---------- programa principal ---------- */

int main(void)
{
    int opcao;
    int n;
    int i;
    double a;
    double b;
    double c;
    double valor;
    double total;
    double maior;
    double menor;
    double x1;
    double y1;
    double x2;
    double y2;

    do {
        menu();
        opcao = leInteiro("Escolha uma opcao: ");
        printf("\n");

        switch (opcao) {
            case 1:
                a = le("Digite o primeiro numero: ");
                b = le("Digite o segundo numero: ");
                printf("%g + %g = %g\n", a, b, soma(a, b));
                break;

            case 2:
                a = le("Digite o primeiro numero: ");
                b = le("Digite o segundo numero: ");
                printf("%g - %g = %g\n", a, b, subtracao(a, b));
                break;

            case 3:
                a = le("Digite o primeiro numero: ");
                b = le("Digite o segundo numero: ");
                printf("%g x %g = %g\n", a, b, multiplicacao(a, b));
                break;

            case 4:
                a = le("Digite o dividendo: ");
                b = le("Digite o divisor: ");

                if (b == 0) {
                    printf("Nao existe divisao por zero.\n");
                } else {
                    printf("%g / %g = %g\n", a, b, divisao(a, b));
                }
                break;

            case 5:
                n = leInteiro("Digite o dividendo: ");
                i = leInteiro("Digite o divisor: ");

                if (i == 0) {
                    printf("Nao existe divisao por zero.\n");
                } else {
                    printf("Quociente = %d\n", n / i);
                    printf("Resto = %d\n", n % i);
                }
                break;

            case 6:
                a = le("Digite o valor: ");
                b = le("Digite a porcentagem: ");
                c = porcentagem(a, b);

                printf("%g%% de %g = %g\n", b, a, c);
                printf("Valor com acrescimo = %g\n", a + c);
                printf("Valor com desconto = %g\n", a - c);
                break;

            case 7:
                a = le("Digite a base: ");
                b = le("Digite o expoente: ");
                printf("%g ^ %g = %g\n", a, b, pow(a, b));
                break;

            case 8:
                a = le("Digite o numero: ");

                if (a < 0) {
                    printf("Nao existe raiz quadrada real de numero negativo.\n");
                } else {
                    printf("Raiz quadrada de %g = %g\n", a, sqrt(a));
                }
                break;

            case 9:
                n = leInteiro("Digite um numero de 0 a 20: ");

                if (n < 0 || n > 20) {
                    printf("Valor fora do intervalo permitido.\n");
                } else {
                    printf("%d! = %llu\n", n, fatorial(n));
                }
                break;

            case 10:
                n = leInteiro("Digite um numero inteiro: ");

                if (primo(n)) {
                    printf("%d e um numero primo.\n", n);
                } else {
                    printf("%d nao e um numero primo.\n", n);
                }
                break;

            case 11:
                n = leInteiro("Digite o numero da tabuada: ");
                i = leInteiro("Ate qual multiplicador? ");

                if (i < 1) {
                    printf("Limite invalido.\n");
                } else {
                    tabuada(n, i);
                }
                break;

            case 12:
                n = leInteiro("Quantos numeros deseja informar? ");

                if (n < 1) {
                    printf("Quantidade invalida.\n");
                    break;
                }

                total = 0;
                for (i = 0; i < n; i++) {
                    valor = le("Digite um valor: ");
                    total = total + valor;
                }

                printf("Soma = %g\n", total);
                printf("Media = %g\n", total / n);
                break;

            case 13:
                n = leInteiro("Quantos numeros deseja informar? ");

                if (n < 1) {
                    printf("Quantidade invalida.\n");
                    break;
                }

                maior = 0;
                menor = 0;

                for (i = 0; i < n; i++) {
                    valor = le("Digite um valor: ");

                    /* o primeiro valor digitado e o maior e o menor ao mesmo tempo */
                    if (i == 0) {
                        maior = valor;
                        menor = valor;
                    }

                    if (valor > maior) {
                        maior = valor;
                    }

                    if (valor < menor) {
                        menor = valor;
                    }
                }

                printf("Maior valor = %g\n", maior);
                printf("Menor valor = %g\n", menor);
                break;

            case 14:
                areas();
                break;

            case 15:
                perimetros();
                break;

            case 16:
                volumes();
                break;

            case 17:
                printf("1 - Calcular a hipotenusa\n");
                printf("2 - Calcular um cateto\n");
                n = leInteiro("Escolha uma opcao: ");

                if (n == 1) {
                    a = le("Digite o cateto 1: ");
                    b = le("Digite o cateto 2: ");
                    printf("Hipotenusa = %g\n", sqrt(a * a + b * b));
                } else if (n == 2) {
                    a = le("Digite a hipotenusa: ");
                    b = le("Digite o cateto conhecido: ");

                    if (a <= b) {
                        printf("A hipotenusa precisa ser maior que o cateto.\n");
                    } else {
                        printf("Outro cateto = %g\n", sqrt(a * a - b * b));
                    }
                } else {
                    printf("Opcao invalida.\n");
                }
                break;

            case 18:
                printf("Equacao no formato ax^2 + bx + c = 0\n");
                a = le("Digite o coeficiente a: ");
                b = le("Digite o coeficiente b: ");
                c = le("Digite o coeficiente c: ");

                if (a == 0) {
                    printf("Com a = 0 a equacao nao e do 2o grau.\n");
                } else {
                    bhaskara(a, b, c);
                }
                break;

            case 19:
                x1 = le("Digite x1: ");
                y1 = le("Digite y1: ");
                x2 = le("Digite x2: ");
                y2 = le("Digite y2: ");

                printf("Distancia = %g\n",
                       sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
                break;

            case 20:
                printf("1 - Graus para radianos\n");
                printf("2 - Radianos para graus\n");
                n = leInteiro("Escolha uma opcao: ");

                if (n == 1) {
                    a = le("Digite o angulo em graus: ");
                    printf("%g graus = %g radianos\n", a, grausParaRadianos(a));
                } else if (n == 2) {
                    a = le("Digite o angulo em radianos: ");
                    printf("%g radianos = %g graus\n", a, radianosParaGraus(a));
                } else {
                    printf("Opcao invalida.\n");
                }
                break;

            case 0:
                printf("Fim do programa.\n");
                break;

            default:
                printf("Opcao inexistente.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}