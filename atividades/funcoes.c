#include <stdio.h>
#include <math.h>

double delta(int a, int b, int c) {
	return pow(b, 2) - 4 * a * c;
}

int maior(int a, int b) {
	if (a > b) return a;
	if (b > a) return b;
}

void print(int n) {
	for (int i = 1; i < n; i++) {
		printf("%d, ", i);
	}

	printf("%d\n", n);
}

int par(int a, int b, int c) {
	int sum = 0;
	int num[3] = {a, b, c};

	for (int i = 0; i < 3; i++) {
		if (num[i] % 2 == 0) sum++;
	}

	return sum;
}

double pa(int a1, int a2, int n) {
	double s = ((a1 + a2) * n) / 2;

	return s;
}

int quadrado(int b, int h) {
	if (b == h) return 1;
	if (b != h) return 0;
}

int soma(int a, int b, int c) {
	int num[3] = {a, b, c};
	int maior = a;
	int menor = a;

	for (int i = 0; i < 3; i++) {
		if (num[i] > maior) {
			maior = num[i];
		}
		if (num[i] < menor) {
			menor = num[i];
		}
	}

	return maior + menor;
}

double juros(int c, int m, int t) {
	return c * m * (t / 100.0);
}

void raiz(int a, int b, int c) {
	double x1, x2;
	double d = delta(a, b, c);

	if (d < 0) {
		printf("Nao existem raizes.\n");
		return;
	}

	if (d == 0) {
		printf("Raiz: %lf\n", (-1.0 * b) / (2.0 * a));
		return;
	}

	x1 = ((-1.0 * b) + sqrt(d)) / (2.0 * a);
	x2 = ((-1.0 * b) - sqrt(d)) / (2.0 * a);

	printf("Raizes: %lf e %lf\n", x1, x2);
}

void pares(int a, int b) {
	int sum = 0;

	for(int i = a; i <= b; i++) {
		if (i % 2 == 0) sum += i;
	}

	if (sum == 0) {
		printf("Nao existem pares entre [%d, %d].\n", a, b);
	} else {
		printf("A soma dos pares entre [%d, %d] e: %d\n", a, b, sum);
	}
}

void divisores(int n) {
	if (n <= 0) {
		printf("Valor invalido.\n");
		return;
	}

	printf("Soma dos divisores de %d: ", n);

	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			printf("%d, ", i);
		}
	}

	printf("e %d.\n", n);
}


int main() {

	int opcao = -1, a, b, c;

	while (1) {
		printf("\n");
		printf("Menu:\n");
		printf("0 - Sair.\n");
		printf("1 - Calcular delta.\n");
		printf("2 - Maior numero.\n");
		printf("3 - Imprimir numeros de [1, n].\n");
		printf("4 - Quais sao pares?\n");
		printf("5 - Progressao aritmetica.\n");
		printf("6 - Quadrado ou retangulo?\n");
		printf("7 - Somar maior e menor.\n");
		printf("8 - Calcular juros.\n");
		printf("9 - Calcular raizes da equacao.\n");
		printf("10 - Somar pares entre dois numeros.\n");
		printf("11 - Imprimir divisores.\n");

		scanf("%d", &opcao);

		switch(opcao) {
			case 0:
				return 0;
				break;
			case 1:
				printf("Por favor, insira os numeros a, b, e c: ");
				scanf("%d %d %d", &a, &b, &c);
				printf("Delta: %lf\n", delta(a, b, c));
				break;
			case 2:
				printf("Insira os numeros x e y: ");
				scanf("%d %d", &a, &b);
				printf("O maior numero e: %d\n", maior(a, b));
				break;
			case 3:
				printf("Insira o numero n: ");
				scanf("%d", &a);
				print(a);
				break;
			case 4:
				printf("Digite tres numeros: ");
				scanf("%d %d %d", &a, &b, &c);
				printf("%d dos numeros inseridos sao pares.\n", par(a, b, c));
				break;
			case 5:
				printf("Digite, nessa ordem, a1, an, e n: ");
				scanf("%d %d %d", &a, &b, &c);
				printf("Soma da progressao aritimetica: %lf.\n", pa(a, b, c));
				break;
			case 6:
				printf("Digite a base e a altura. Se for um quadrado, o numero 1 sera impresso. Do contrario, o numero 0 sera impresso: ");
				scanf("%d %d", &a, &b);
				printf("%d\n", quadrado(a, b));
				break;
			case 7:
				printf("Digite 3 numeros: ");
				scanf("%d %d %d", &a, &b, &c);
				printf("Soma do maior com o menor: %d\n", soma(a, b, c));
				break;
			case 8:
				printf("Digite o valor, numero de meses, e porcentagem de juros: ");
				scanf("%d %d %d", &a, &b, &c);
				printf("Os juros cobrados correspondem a R$ %.2lf.\n", juros(a, b, c));
				break;
			case 9:
				printf("Por favor, insira os numeros a, b, e c: ");
				scanf("%d %d %d", &a, &b, &c);
				raiz(a, b, c);
				break;
			case 10:
				printf("Digite os dois numeros: ");
				scanf("%d %d", &a, &b);
				pares(a, b);
				break;
			case 11:
				printf("Digite o numero: ");
				scanf("%d", &a);
				divisores(a);
				break;
		}
	}

	return 0;
}
