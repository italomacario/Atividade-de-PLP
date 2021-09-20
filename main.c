#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

typedef struct{
	char nome[50];
	int idade;
	float salario;
}Pessoa;
Pessoa pessoa[1];

typedef struct{
	float largura;
	float altura;
}Retangulo;
Retangulo retangulo;

typedef struct{
	char nome[50];
	float salarioBruto;
	float imposto;
	
	float salarioLiquido;
	float aumentarSalario;
}Funcionario;
Funcionario funcionario;

typedef struct{
	char nome[50];
	float nota1;
	float nota2;
	float nota3;
	float somadasnotas;
	
	float peso1;
	float peso2;
	float peso3;
	
}Aluno;
Aluno aluno;

float area(){
	return retangulo.largura * retangulo.altura;
}

float perimetro(){
	return 2 * (retangulo.largura + retangulo.altura);
}

float diagonal(){	
	return sqrt( pow(retangulo.largura,2) + pow(retangulo.altura,2) );
}

void salario_liquido(){
	funcionario.salarioLiquido = funcionario.salarioBruto - funcionario.imposto;
}

void aumentar_salario(){
	funcionario.salarioLiquido = funcionario.salarioLiquido + (funcionario.salarioBruto * (funcionario.aumentarSalario * 0.01));
}

void somasdasnotas(){
	aluno.somadasnotas = ((aluno.nota1 + aluno.nota2 + aluno.nota3) / (aluno.peso1 + aluno.peso2 + aluno.peso3)) * 100;
	
}

void menu(){
	
	printf("Escolha um numero correspondente\n");
	
	printf("1 - Pessoa mais velha\n");
	
	printf("2 - Salário médio\n");
	
	printf("3 - Retangulo \n");
	
	printf("4 - Aumentar o Salário\n");

	printf("5 - Calcular Nota\n");
	
	printf("6 - Para sair\n");
		
}

void Atividades(){
	
	int questao=0;
	
	do{
		menu();
		printf("Escolha sua questão\n");
		scanf("%d",&questao);
		
		switch(questao){
			case 1:
				system("cls");
				Atividade_1();
				system("pause");
				break;
				
			case 2:
				system("cls");
				Atividade_2();
				system("pause");
				break;
				
			case 3:
				system("cls");
				Atividade_3();
				system("pause");
				break;
				
			case 4:
				system("cls");
				Atividade_4();
				system("pause");
				break;
				
			case 5:
				system("cls");
				Atividade_5();
				system("pause");
				break;
				
			case 6:
				return 0;
				
			default:
				printf("opção invalida\n");
				system("pause");
		}
		system("cls");
	}while(questao != 6);
}

void Atividade_1(){
	
	printf("Um programa capaz de ler os dados de duas pessoas, depois mostrar o nome da pessoa mais velha\n");
	
	printf("\nDados da primeira pessoa\n");
	printf("Nome: ");
	fflush(stdin);
	fgets(pessoa[0].nome, 50, stdin);
	printf("Idade: ");
	scanf("%d",&pessoa[0].idade);
	
	printf("\nDados da segunda pessoa\n");
	printf("Nome: ");
	fflush(stdin);
	fgets(pessoa[1].nome, 50, stdin);
	printf("Idade: ");
	scanf("%d",&pessoa[1].idade);
	
		
	if(pessoa[0].idade > pessoa[1].idade){
		printf("\nPessoa mais é velha: %s\n",pessoa[0].nome);
		
	}if(pessoa[0].idade < pessoa[1].idade){
		printf("\nPessoa mais é velha: %s\n",pessoa[1].nome);
	
	}if(pessoa[0].idade == pessoa[1].idade){	
		printf("\nAs duas pessoas tem a mesma idade\n");
	}
	
	
}

void Atividade_2(){
		
	printf("Um programa capaz de ler nome e salário de dois funcionários. Depois, mostrar o salário médio dos funcionários.\n");
	
	printf("\nDados do primeiro funcionario\n");
	printf("Nome: ");
	fflush(stdin);
	fgets(pessoa[0].nome, 50, stdin);
	printf("Salário: ");
	scanf("%f",&pessoa[0].salario);
	
	printf("\nDados da segunda pessoa\n");
	printf("Nome: ");
	fflush(stdin);
	fgets(pessoa[1].nome, 50, stdin);
	printf("salario: ");
	scanf("%f",&pessoa[1].salario);
	
	pessoa[0].salario=pessoa[0].salario+pessoa[1].salario;
	pessoa[0].salario=pessoa[0].salario/2;
	
	printf("\nSalário médio %.2f\n",pessoa[0].salario);
	

}

void Atividade_3(){
	
	printf("Um programa capaz de ler os valores da largura e altura de um retângulo. Em seguida, mostrar na tela o valor de sua área, perímetro e diagonal. \n");
	printf("Entre a largura e altura do retângulo\n");
	
	printf("\nlargura: ");
	scanf("%f",&retangulo.largura);
	
	printf("\nAltura: ");
	scanf("%f",&retangulo.altura);
	
	printf("Area = %.2f \nPerímetro = %.2f \nDiagonal = %.2f\n", area(), perimetro(), diagonal());
	
}

void Atividade_4(){
	printf("Um programa capaz de ler os dados de um funcionário. Em seguida, mostrar os dados do funcionário, aumentar o salário do funcionário com base em uma porcentagem dada e mostrar novamente os dados do funcionário atualizado\n");
	printf("Nome: ");
	fflush(stdin);
	fgets(funcionario.nome, 50, stdin);
	funcionario.nome[strcspn(funcionario.nome, "\n")] = 0;
	printf("Salário Bruto: ");
	scanf("%f",&funcionario.salarioBruto);
	printf("Imposto: ");
	scanf("%f",&funcionario.imposto);
	
	salario_liquido();
	
	printf("Funcionário: %s R$ %.2f\n", funcionario.nome, funcionario.salarioLiquido);
	
	printf("Digite a porcentagem para aumentar o salário: ");
	scanf("%f",&funcionario.aumentarSalario);
	
	aumentar_salario();
	
	printf("Funcionário: %s R$ %.2f\n", funcionario.nome, funcionario.salarioLiquido);
	
}

void Atividade_5(){
	aluno.peso1=30;
	aluno.peso2=35;
	aluno.peso3=35;
	
	printf("Fazer um programa para ler o nome de um aluno e as três notas que ele obteve nos três trimestres do ano. \nAo final, mostrar qual a nota final do aluno no ano. Dizer também se o aluno está APROVADO ou REPROVADO e, \nem caso negativo, quantos pontos faltam para o aluno obter o mínimo para ser aprovado 5\n\n");
	printf("Nome: ");
	fflush(stdin);
	fgets(aluno.nome, 50, stdin);
	funcionario.nome[strcspn(funcionario.nome, "\n")] = 0;
	
	printf("Primeira nota: ");
	scanf("%f",&aluno.nota1);

	printf("Segunda nota: ");
	scanf("%f",&aluno.nota2);

	printf("Terceira nota: ");
	scanf("%f",&aluno.nota3);
	
	somasdasnotas();
	
	if(60 <= aluno.somadasnotas){
		printf("\nNota Final = %.2f \n\nAPROVADO\n", aluno.somadasnotas);
	}else{
		printf("\nNota Final = %.2f \nREPROVADO\n", aluno.somadasnotas);
		aluno.somadasnotas = 60 - aluno.somadasnotas;
		printf("FALTARAM %.2f PONTOS\n", aluno.somadasnotas);
	}
	
}

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	Atividades();
		
	return 0;
}

