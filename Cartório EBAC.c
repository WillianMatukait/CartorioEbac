#include <stdio.h> // biblioteca para textos
#include <stdlib.h> // biblioteca para alocação de espaço na memória (VAR)
#include <locale.h> // biblioteca para setar região de escrita
#include <string.h> // biblioteca resposável por armazenar string

int registro() //função responsável por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");//setar linguaguem de escrita
	
	//inicio das variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim das variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coleta informações do usuário
	scanf("%s", cpf); //%s para string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores entre strings
	
	FILE *file; //cria o banco de dados
	file = fopen(arquivo,"w"); //cria o arquivo("write" escrever arquivo novo)
	fprintf(file,cpf); //salva dados na váriavel
	fclose(file); //fecha o banco de dados
	 
	file = fopen(arquivo, "a"); //cria o arquivo ("a" atualizar o arquivo já criado)
	fprintf(file,",");//adiciona uma virgula
	fclose(file);//fecha o banco de dados
	
	printf("Digite o Nome a ser cadastrado: ");//coleta informações do usuário
	scanf("%s", nome);
	

	
	file = fopen(arquivo,"a");//cria o arquivo 
	fprintf(file,nome); //salva dados na váriavel
	fclose(file);//fecha o banco de dados
	
	
	file = fopen(arquivo,"a");//cria o arquivo 
	fprintf(file,",");//adiciona uma virgula
	fclose(file);//fecha o banco de dados
	
	printf("Digite o Sobrenome a ser cadastrado: ");//coleta informações do usuário
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");//cria o arquivo 
	fprintf(file,sobrenome); //salva dados na váriavel
	fclose(file);//fecha o banco de dados
	
	file = fopen(arquivo,"a");//cria o arquivo 
	fprintf(file,",");//adiciona uma virgula
	fclose(file);//fecha o banco de dados
	
	printf("Digite o Cargo a ser cadastrado:");//coleta informações do usuário
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");//cria o arquivo 
	fprintf(file,cargo); //salva dados na váriavel
	fclose(file);//fecha o banco de dados
	
		
}

int consulta()//função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");//setar linguaguem de escrita
	
	//inicio das variáveis/strings
	char conteudo[200];
	char cpf[40];
	//fim das variáveis/strings
	
	printf("Digite o CPF desejado: "); //coleta informações do usuário
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //cria o arquivo ("read" ler arquivo)
	
	if(file == NULL) //verificador para CPF válido
	{
		printf("CPF não localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL) // repetidor para tentar novamente o CPF
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}	
	
	system("pause");
}

int deletar() //função responsável por deletar os usuários do sistema
{
	setlocale(LC_ALL, "Portuguese");//setar linguaguem de escrita
	
	//inicio das variáveis/strings
	char cpf[40];
	//fim das variáveis/strings
	
	printf("Digite o CPF a ser deletado: "); //coleta informações do usuário
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //verificador para CPF inválido
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	
	else //verificador para CPF válido
	{
		fclose(file); //fecha o banco de dados
		remove(cpf); // remove o arquivo do banco de dados
		printf("Usuário deletado com sucesso!\n");
		system("pause");
	}
}

int main()
{
	//inicio das variáveis
	int opcao=0;
	int laco=1;
	//fim das variáveis
	
	for (laco=1;laco=1;)//laço de repetição para retornar ao menu
	{
	
		system("cls"); //limpa tela
		setlocale(LC_ALL, "Portuguese"); //setar linguaguem de escrita
	
		printf("=== Bem vindo ao cartório EBAC ===\n\n"); //inicio Menu
		printf("\t 1- Adicionar nomes\n");
		printf("\t 2- Consultar nomes \n");
		printf("\t 3- Deletar nomes \n");
		printf("\t 4- Sair do sistema \n");
		printf("escolha: ");
		scanf("%d", &opcao); //final menu
	
		system("cls");//limpa tela
	
		switch(opcao) // opções do menu
		{
			case 1: //inicio opção 1
			registro(); //chamada de funções
			break; //final opção 1
	
			case 2: //inicio opção 2
			consulta(); //chamada de funções
			break;//final opção 2
	
			case 3://inicio opção 3
			deletar(); //chamada de funções
			break;//final opção 3
	
			case 4://inicio opção 4
			printf("Obrigado por utilizar o sistema!");
			return 0;
			break;//final opção 4
				
			default://opção n/a
			printf("Opção invalida \n");
			system("pause"); //pausa no código
			break;//final opção n/a
			
 		}
 	}
}
