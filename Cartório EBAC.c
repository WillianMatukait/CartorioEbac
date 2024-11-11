#include <stdio.h> // biblioteca para textos
#include <stdlib.h> // biblioteca para aloca��o de espa�o na mem�ria (VAR)
#include <locale.h> // biblioteca para setar regi�o de escrita
#include <string.h> // biblioteca respos�vel por armazenar string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");//setar linguaguem de escrita
	
	//inicio das vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim das vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coleta informa��es do usu�rio
	scanf("%s", cpf); //%s para string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores entre strings
	
	FILE *file; //cria o banco de dados
	file = fopen(arquivo,"w"); //cria o arquivo("write" escrever arquivo novo)
	fprintf(file,cpf); //salva dados na v�riavel
	fclose(file); //fecha o banco de dados
	 
	file = fopen(arquivo, "a"); //cria o arquivo ("a" atualizar o arquivo j� criado)
	fprintf(file,",");//adiciona uma virgula
	fclose(file);//fecha o banco de dados
	
	printf("Digite o Nome a ser cadastrado: ");//coleta informa��es do usu�rio
	scanf("%s", nome);
	

	
	file = fopen(arquivo,"a");//cria o arquivo 
	fprintf(file,nome); //salva dados na v�riavel
	fclose(file);//fecha o banco de dados
	
	
	file = fopen(arquivo,"a");//cria o arquivo 
	fprintf(file,",");//adiciona uma virgula
	fclose(file);//fecha o banco de dados
	
	printf("Digite o Sobrenome a ser cadastrado: ");//coleta informa��es do usu�rio
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");//cria o arquivo 
	fprintf(file,sobrenome); //salva dados na v�riavel
	fclose(file);//fecha o banco de dados
	
	file = fopen(arquivo,"a");//cria o arquivo 
	fprintf(file,",");//adiciona uma virgula
	fclose(file);//fecha o banco de dados
	
	printf("Digite o Cargo a ser cadastrado:");//coleta informa��es do usu�rio
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");//cria o arquivo 
	fprintf(file,cargo); //salva dados na v�riavel
	fclose(file);//fecha o banco de dados
	
		
}

int consulta()//fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");//setar linguaguem de escrita
	
	//inicio das vari�veis/strings
	char conteudo[200];
	char cpf[40];
	//fim das vari�veis/strings
	
	printf("Digite o CPF desejado: "); //coleta informa��es do usu�rio
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //cria o arquivo ("read" ler arquivo)
	
	if(file == NULL) //verificador para CPF v�lido
	{
		printf("CPF n�o localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL) // repetidor para tentar novamente o CPF
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}	
	
	system("pause");
}

int deletar() //fun��o respons�vel por deletar os usu�rios do sistema
{
	setlocale(LC_ALL, "Portuguese");//setar linguaguem de escrita
	
	//inicio das vari�veis/strings
	char cpf[40];
	//fim das vari�veis/strings
	
	printf("Digite o CPF a ser deletado: "); //coleta informa��es do usu�rio
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //verificador para CPF inv�lido
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	
	else //verificador para CPF v�lido
	{
		fclose(file); //fecha o banco de dados
		remove(cpf); // remove o arquivo do banco de dados
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");
	}
}

int main()
{
	//inicio das vari�veis
	int opcao=0;
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	//fim das vari�veis
	
	printf("=== Bem vindo ao cart�rio EBAC ===\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	
	if(comparacao == 0)
	{
	
		for (laco=1;laco=1;)//la�o de repeti��o para retornar ao menu
		{
	
			system("cls"); //limpa tela
			setlocale(LC_ALL, "Portuguese"); //setar linguaguem de escrita
	
			printf("=== Bem vindo ao cart�rio EBAC ===\n\n"); //inicio Menu
			printf("\t 1- Adicionar nomes\n");
			printf("\t 2- Consultar nomes \n");
			printf("\t 3- Deletar nomes \n");
			printf("\t 4- Sair do sistema \n\n");
			printf("escolha: ");
			scanf("%d", &opcao); //final menu
	
			system("cls");//limpa tela
	
			switch(opcao) // op��es do menu
			{
				case 1: //inicio op��o 1
				registro(); //chamada de fun��es
				break; //final op��o 1
	
				case 2: //inicio op��o 2
				consulta(); //chamada de fun��es
				break;//final op��o 2
	
				case 3://inicio op��o 3
				deletar(); //chamada de fun��es
				break;//final op��o 3
	
				case 4://inicio op��o 4
				printf("Obrigado por utilizar o sistema!");
				return 0; // quebra o c�digo (finaliza)
				break;//final op��o 4
				
				default://op��o n/a
				printf("Op��o invalida \n");
				system("pause"); //pausa no c�digo
				break;//final op��o n/a
			
 			}
 		}
 	}
 	
 	else
 		printf("Senha incorreta!");
}
