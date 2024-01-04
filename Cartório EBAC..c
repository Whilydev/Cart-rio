#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocações de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string
		
int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio de criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim de criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações dos usuários
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa write "escrever"
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);   //armazenando a variavel "cpf" utilizado na função string %"s"

	
	FILE *file;
	file = fopen(cpf, "r");    //abre o arquivo CPF e R de read "ler"
	
	if(file == NULL)   // se não existir informar o usuário com a mensagem abaixo
	{
		printf("\nNão foi possível consultar o cpf por não estar cadastrado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)	//while (enquanto) tiver a informação, armazene a informação em conteudo se for diferente de NULL
	{
		printf("\nEssas são as informações do usuário:\n");	
			
	 	printf("%s", conteudo);		
			
		printf("\n\n");

	}
	
	system("pause");
}

int deletar()
{
		char cpf[40];
		
		printf("Digite o CPF a ser deletado: ");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("O usuário não se encontra no sistema!.\n");
			system("pause");
		}
		
		else
		{
			printf("\nCPF deletado com sucesso!\n");
			system("pause");
		}
		
}


	
int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls"); //responsável por limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cartório da EBAC ###\n\n"); //inicio da seleção do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls");
	
		switch(opcao) //inicio da seleção
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
		
			case 4:
			printf("Obrigado por utilizar o sistema! \n");
			return 0;	//Return 0 quebra a função do sistema
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		} //fim da seleção
			
	}	
}
