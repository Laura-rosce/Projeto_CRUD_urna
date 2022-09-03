//BIBLIOTECA COM FUN��ES DO PROGRAMA CRUD
#include<iostream>
#include <stdio.h> // ~ barra de progresso
#include <windows.h> // ~ cor
#include <conio.h> // ~ ler o teclado
using namespace std;

//VARI�VEIS GLOBAIS - Usamos pelo fato do Scruct n�o aceitar receber valores.
int posicao = 0;
int contCadastro = 0;
int votos = 0;
int votos_nulos = 0;
int votos_branco = 0;
int final = 0;

struct Candidato
{
	string nome;
	string disciplina;
	int idade;
	int numero;
	int voto;	
	bool ativo;
	
};

//==== FUN��ES REFERENTES A FUN��O CRUD_CANDIDATO =====

void erro_404() //FUN��O VISUAL DO ERRO - FRONTEND
{	
	system ("cls");
	system("color 8F");
	cout << " ___   ___  ________  ___   ___"                 << endl;
	cout << "|\\  \\ |\\  \\|\\   __  \\|\\  \\ |\\  \\"      << endl;
	cout << "\\ \\  \\\\_\\  \\ \\  \\|\\  \\ \\  \\__\\  \\" << endl;
	cout << " \\ \\______  \\ \\  \\\\\\  \\ \\______  \\"    << endl;
	cout << "  \\|_____|\\  \\ \\  \\\\\\  \\|_____|\\  \\"   << endl;
	cout << "         \\ \\__\\ \\_______\\     \\ \\  \\"    << endl;
	cout << "          \\|__|\\|_______|      \\|__|"         << endl << endl;
	
	cout << "            !OPCAO INVALIDA!\n\n";
	
	system("pause");
	system("cls");
}
void loadingBar() //FUN��O VISUAL DA BARRA DE PROGRESSO - FRONTEND
{
    // 0 - black background,
    // A - Green Foreground
    system("color 0A");
  
    // Initialize char for printing
    // loading bar
    char a = 177, b = 219;
  
    printf("\n\n\n\n");
    printf("\n\n\t\t\t\t~ Use W para mover pra cima e S para baixo ~\n\n\t\t\t\t\tLoading...\n\n");
    printf("\t\t\t\t\t");
  
    // Print initial loading bar
    for (int i = 0; i < 26; i++)
        printf("%c", a);
  
    // Set the cursor again starting
    // point of loading bar
    printf("\r");
    printf("\t\t\t\t\t");
  
    // Print loading bar progress
    for (int i = 0; i < 26; i++) {
        printf("%c", b);
  
        // Sleep for 1 second
        Sleep(200);
    }
    system("cls");
}
void tabelaDeCadastra() //FUN��O VISUAL DA TABELA DE OP��ES QUANDO CADASTRA CANDIDATO - FRONTEND
{
	string nome[]={"Inscrever", "Listar", "Editar", "Excluir"}; //Vetor que deixa pronto o que quero mostrar
	
		cout << " \n\t\t >>>>> CADASTRO DE CANDIDATOS <<<<<";
		cout << "\n\n\t ______________________________________________\n";
		
		//Aqui diminuo o trabalho manual de esta imprimindo as informa��es da tabela
		for (int i=1; i<=4; i++){ cout << "\t| " << nome[i-1] << " candidato\t...................." << i << " |\n"; }
	
		cout << "\t| Sair do cadastro de candidato\t............0 |\n";
		cout << "\t ����������������������������������������������\n";
}
void inscreverCandidato(Candidato candidatos[]) //FUN��O QUE PEDE OS DADOS AO INSCREVER O CANDIDATO - BACKEND + FRONTEND
{
		system("color AF");
		Candidato candidato;	
		
		cout << " \n\t\t >>>>> INSCREVER CANDIDATO <<<<<\n\n";
		cout << " Digite o nome do candidato: ";
	 	cin>> candidato.nome;
			
		cout << " Digite o nome da disciplina do candidato: ";
		cin >> candidato.disciplina;
			
		cout << " Digite a idade do canditado: ";
		cin >> candidato.idade;
		
		if (!candidato.idade){ // Testa se o usu�rio informou um numero e n�o uma letra.
			erro_404();
			cout << "\n!Por Favor informe um digito valido. Um numero -> ";
			cin >> candidato.idade;
		}
			
		cout << "\n\t === INFORME UM NUMERO DIFERENTE DE 0 E 505 ===\n";
		
		for(int i=0; i<posicao; i++){ // Mostra os numeros que ja foram escolhidos para o cadastro	
			if(candidatos[i].ativo == true){
				cout<< " || " << candidatos[i].numero; 
			}		
		}
		
		cout << "\n Digite o n�mero do candidato: ";
		cin >> candidato.numero;
		candidato.ativo = true;
		
		if (candidato.numero == 505 or candidato.numero == 0){ // Caso a pessoa insita em cadastra um numero inv�lido aparece isso.
			cout << "\n\t >> NUMERO NAO DISPONIVEL. DIGITE UM NUMERO VALIDO! <<\n";
			cout<< "\n Digite o n�mero do candidato: ";
			cin >> candidato.numero;
				
		} 
		
		if(candidato.numero == 505 or candidato.numero == 0){ // Caso insistir novamente
			cout << "\n\t >>Volte ao come�o.<<\n";
			system("pause");
			return;	
		}
		
		for(int i = 0; i<posicao; i++){ // Fica testando se a pessoa informou um numero ja cadastrado.
			int j=0;
			while(candidato.numero == candidatos[i].numero){
			
				cout << "\n >> N�mero j� usado. Tente novamente. << \n";
				cout << " -> Digite o n�mero do candidato:";
				cin >> candidato.numero;
				j++;
				if(j==3) return ; // o la�o s� vai pedir apenas 4 vezes.	
			}
		}
								
		candidatos[posicao] = candidato; // Em uma determinada posi��o, vai esta assumido todos os dados pe�os desta fun��o.	
		posicao++; // Incremento da posi��o, para um novo cadastro
		contCadastro++; // Aqui ele vai ser utilizado na fun��o Abertura, para saber se houve o cadastro, ou seja, se entrou aqui, teve cadastro.
		
		cout << "\t~Candidato cadastrado com sucesso!~\n\n\n";
		
		system("pause"); // Para depois a tela ser limpa.
}
void listarCandidato(Candidato candidatos[]) //FUN��O QUE LISTA OS CANDIDATOS - BACKEND + FRONTEND
{
		system("color CF");
		cout << " \n\t\t >>>>> LISTAR CANDIDATOS <<<<<\n";
		
		for(int i = 0; i<posicao; i++){
			if(candidatos[i].ativo == true){ // Testa se � ativo e imprime somente os ativos
				cout<< "\n\nCandidato ATIVO:\n";
				cout << "\n - Professor(a) de " << candidatos[i].disciplina << ": " << candidatos[i].nome << endl;
				cout << " - Idade: " <<  candidatos[i].idade << " anos\n";
				cout << " - N�mero do candidato: " << candidatos[i].numero << "\n\n";
				for (int j=0; j<40; j++) cout << "*"; 
			}
		}
		for(int i = 0; i<posicao; i++){ // Testa se � inativo e imprime os candidatos excluidos
			if(candidatos[i].ativo == false){
				cout<< "\n\nCandidato INATIVO:\n";
				cout << "\n - Professor(a) de " << candidatos[i].disciplina << ": " << candidatos[i].nome << endl;
				cout << " - Idade: " <<  candidatos[i].idade << " anos\n";
				cout << " - N�mero do candidato: " << candidatos[i].numero << "\n\n";
				for (int j=0; j<40; j++){cout << "*";} 
			}
		}
		cout << endl;
		system ("pause");
}
void pessoa_nao_encontrada() //FUN��O VISUAL DE PESSOA N�O ENCONTRADA - FRONTEND
{
	system("color 06");
	system ("cls");
	
	cout << endl;
	cout << "\t                 MM"                 << endl; 
	cout << "\t                MMMM"                << endl; 
	cout << "\t               MMMMMM"               << endl; 
	cout << "\t              MMMMMMMM"              << endl;
 	cout << "\t             MMMMMMMMMM" 			  << endl;
   	cout << "\t            MMMMMMMMMMMM" 			  << endl; 
  	cout << "\t           MMMMMMMMMMMMMM" 		  << endl; 
	cout << "\t          MMMMMMM   MMMMMM" 		  << endl; 
	cout << "\t         MMMMMMMM   MMMMMMM" 		  << endl;
	cout << "\t        MMMMMMMMM   MMMMMMMM" 		  << endl;
	cout << "\t       MMMMMMMMMM   MMMMMMMMM"       << endl;
	cout << "\t      MMMMMMMMMMM   MMMMMMMMMM"      << endl;
	cout << "\t     MMMMMMMMMMMMMMMMMMMMMMMMMM"     << endl;
	cout << "\t    MMMMMMMMMMMMMMMMMMMMMMMMMMMM"    << endl;
	cout << "\t   MMMMMMMMMMMMMM   MMMMMMMMMMMMM"   << endl;
	cout << "\t  MMMMMMMMMMMMMMM   MMMMMMMMMMMMMM"  << endl; 
	cout << "\t MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl; 
	cout << "\t MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl; 
	cout << "\t  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"  << endl;
	cout << "\n\t === CANDIDATO NAO ENCONTRADO! ===\n\n";
	system ("pause");
}
bool editarCandidato(Candidato candidatos[]) //FUN��O QUE EDITA OS DADOS DO CANDIDATO - BACKEND + FRONTEND
{
		system("color F4");
		string nome;
		string disciplina;
		int numero;
		int idade;
		
		cout << " \n\t\t >>>>> EDITAR INFORMA��ES DO CANDIDATO <<<<<\n\n";
		
		cout << " - Informe o numero do candidato para editar as informa��es: ";
		cin >> numero;
		
		if (!numero){ //caso digite uma letra aparece o erro
			pessoa_nao_encontrada(); 
			return false; // E sai da fun��o, para a tela das op��es de CRUD
		}
		 
		for(int i=0; i<posicao; i++){
			if(candidatos[i].numero == numero){ // Busca pelo numero de candidatura
				cout << " - Novo nome: ";
				cin >> nome;
				
				cout << " - Nova disciplina: ";
				cin >> disciplina;
				
				cout << " - Nova idade: ";
				cin >> idade;
				
				cout << " - Novo n�mero de candidatura: ";
				cin >> numero;
				
				//Atribue novamente os dados.
				candidatos[i].nome = nome; 
				candidatos[i].disciplina = disciplina;
				candidatos[i].idade = idade;
				candidatos[i].numero = numero;
				return true; //E sai da fun��o
			}
		}
		pessoa_nao_encontrada(); //Caso o numero n�o entre no if do for, � sinal que o candidato n�o existe
		return false; // E sai da fun��o
	
}
bool excluirCandidato(Candidato candidatos[]) //FUN��O QUE EXCLOE/INATIVA O CANDIDATO - BACKEND + FRONTEND
{
		system("color 04");
		int num;
		
		cout << " \n\t\t >>>>> EXCLUIR CANDIDATO <<<<<\n\n";
		cout << "-> N�mero do candidato:";
		cin >> num;
	
		if (!num){ //Verifica se � um numero;
			cout << "\t >> UM NUMERO POR GENTILEZA! << ";
			cin >> num;
		}
		
		for(int i=0; i<posicao; i++){ 
			if(num == candidatos[i].numero){ //Testa se existe um numero no sistema igual ao informado;
				candidatos[i].ativo = false; //Caso verdadeiro -> esse candidato se torna inativo;
				cout << "\n\t === CANDIDATO DELETADO COM SUCESSO! ===\n\n";
				system("pause");
				return true; //E sai da fun��o	
			}
		}
		
		pessoa_nao_encontrada(); //Caso n�o tenha um numero no sistema igual ao digitado = � existe candidato;
		return false; //Sai da fun��o e volta para a tabela das op��es do CRUD;
}

//Conta com os limites da tabela (0 a 4)
int valida_numero(string msg, int limite_Minimo, int limite_Maximo){ //FUN��O QUE GARANTE QUE O CODE N�O QUEBRE
	
	int retorno, valor;
	char letra;
	
	 do{	
	        cout << msg;
	        retorno = scanf("%d", &valor);
	    
	        do{
	            letra = getchar();
	        }while(letra != '\n');
	        
	    }while(retorno == 0 || valor<limite_Minimo || valor>limite_Maximo); 
	    
	return valor;
}

void CRUDCandidato(Candidato candidatos[]) //FUN��O M�E CRUD - CHAMA TODAS AS FUN��ES A CIMA - BACKEND 
{	
		int opcao;
		string pergunta = "\nInforme uma op��o: ";
		
		do{
			system("cls");
			
			tabelaDeCadastra(); //Tabela das op��es do CRUD
			
			opcao = valida_numero(pergunta, 0, 4);
			
			switch(opcao){ //De acordo com o escolhido, seguindo a tabela, vai chamando as fun��es
				case 1:
					system("cls");
					inscreverCandidato(candidatos);
					break;
					
				case 2:
					system("cls");
					listarCandidato(candidatos);
					break;
					
				case 3:
					system("cls");
					editarCandidato(candidatos);
					break;
					
				case 4:
					system("cls");
					excluirCandidato(candidatos);
					break;	
	
				default:
					if(opcao > 4 or opcao < 0){
					system("cls");
					erro_404();
				}
			}
			system ("color 0B");
		
		}while(opcao != 0);
		system ("cls");
}

//===== A PARTIR DAQUI S�O FUN��ES REFERENTES � FUN��O ABERTURA =====

void tabelaCandidatos(Candidato candidatos[]) //FUN��O VISUAL DA TABELA DOS CANDIDATOS PARA VOTA��O - FRONTEND
{   
	for(int i = 0; i<posicao; i++){
		if(candidatos[i].ativo == true){
		cout << "\t| " <<  candidatos[i].nome << " ======" << candidatos[i].disciplina << " ====== \t" << candidatos[i].numero << " |\n";
		
		}
	}
	cout << "\n\t=> Para votar em branco digite 505\n";
	cout << "\t=> Para parar a vota��o digite 0\n\n";
}
bool inicioDaVotacao(Candidato candidatos[]) //FUN��O DA VOTA��O - BACKEND
{
		system("color 8F");
		int  votoUsuario, rep=1;
		
		for(int i=0; i<posicao; i++){ candidatos[i].voto = 0;} //Garante que o vetor esteja recebendo 0 para a contagem eficiente
		
			do{ 
				int voto_nulo = 0;
				
				cout << " \n\t\t >>>>> VOTA��O <<<<<\n\n";
				tabelaCandidatos(candidatos);
			
				cout << " -> Digite o n�mero do seu candidato:  ";
				cin >> votoUsuario;
				
				if(votoUsuario == 0){
				}else{
					votos++;			
					for(int i=0; i<posicao;i++){	
						if(votoUsuario == candidatos[i].numero){//Compara com os ativos, para contar os seus votos
							if(candidatos[i].ativo == true){ 
								candidatos[i].voto++;
								voto_nulo++;
							}
						}
					}
					
					if(votoUsuario == 505){//Contagem dos votos brancos
						votos_branco++;
						voto_nulo++;
					}
					
					if(voto_nulo == 0){
			    		votos_nulos++;
					}
				}
			   	cout << "\n\t === VOTO CONFIRMADO! ===\n\n";
			    system("pause");
			    system ("cls");
			    
			    while (votoUsuario == 0 ){//Usa o mesmo princ�pio da abertura
						cout << "\n\n\n\n\tConfimas que desejas finalizar a votacao? (Selecione com as setas)";
						
						switch (rep){
							case 1:
								printf("\n\t%c Sim \n\t N�o", 16);
					            break;  
					            
					        case 2:
					            printf("\n\t Sim \n\t%c N�o", 16);
					            break;
					        default:;
						}
					
						int direc = getch();
						
						if(direc== 80 && rep <=1) rep ++;
					    else if (direc == 72 && rep>=2) rep--; 
					    else if (direc == 13 && rep == 1) return false;
						else if (direc==13 && rep==2)votoUsuario = 1;
						
						system("cls");
				}
			}while(votoUsuario != 0); //Enquanto o usu�rio queira parar o programa
			
	system("cls");		
}
void resultadoVotacao(Candidato candidatos[]) //FUN��O QUE ARMAZENA O RESULTADO DA VOTA��O - BACKEND
{
	system("color 8F");
		
		int maiorVoto;
		int empate = 0;
		string vencedor;
		
		if (contCadastro == 0){
			erro_404();
		}else{
			cout << " \n\t\t >>>>> RESULTADO DA VOTACAO PASSADA <<<<<\n\n";
			cout << "\n\t>> VOTOS TOTAIS:" << votos;
			cout << "\n\t>> VOTOS NULOS:" << votos_nulos;
			cout << "\n\t>> VOTOS BRANCOS:" << votos_branco;
			cout << "\n\t>> VOTOS VALIDOS:" << votos - votos_nulos - votos_branco << "\n\n";

			for (int j=0; j<posicao; j++){
					if(candidatos[j].ativo == true){
						cout << "\t\t" << candidatos[j].nome << " == "
							 << candidatos[j].disciplina << " == votos: " << candidatos[j].voto << endl;
					}
			}
				
			for(int i = 0; i<posicao; i++){
				if(candidatos[i].voto > candidatos[maiorVoto].voto){ 
					vencedor = candidatos[i].nome;
					maiorVoto = i;
				}
			}
			
			for(int i = 0; i<posicao; i++){
				if(candidatos[maiorVoto].voto == candidatos[i].voto){
					empate = i;						
				}			
			}
			
			if(empate != maiorVoto){
				cout << "\t\t=== HOUVE UM EMPATE ENTRE ===\n    " << endl;
				cout << "\t\t\t" <<candidatos[maiorVoto].nome << "  e   " << candidatos[empate].nome << endl;
						
				if(candidatos[maiorVoto].idade > candidatos[empate].idade){
					cout << "\n\n   ~ Professor(a) " << candidatos[maiorVoto].nome << " da materia de " 
						 << candidatos[maiorVoto].disciplina << " ganhou por ter mais votos! ~\n\n";
				}else if(candidatos[maiorVoto].idade < candidatos[empate].idade){					
					cout << "\n\n   ~ Professor(a) " << candidatos[empate].nome << " da materia de " 
						 << candidatos[empate].disciplina << " ganhou por ter mais votos! ~\n\n";
				}
							
				if(candidatos[maiorVoto].idade == candidatos[empate].idade){
					if(maiorVoto < empate){
						cout << "\n\n   ~ Professor(a) " << candidatos[maiorVoto].nome << " da materia de " 
							 << candidatos[maiorVoto].disciplina << " ganhou por ter mais votos! ~\n\\";						
					}else if(maiorVoto > empate){
						cout << "\n\n   ~ Professor(a) " << candidatos[empate].nome << " da materia de " 
							 << candidatos[empate].disciplina << " ganhou por ter mais votos! ~\n\n";
					}		
				}		
			}else{
			cout << "\n\n   ~ Professor(a) " << candidatos[maiorVoto].nome << " da materia de " 
			     << candidatos[maiorVoto].disciplina << " ganhou por ter mais votos! ~\n\n";		
			}
			
			cout << "\t\t";
			system ("pause");
			system("cls");
		}
}	
bool exibirResultados(Candidato candidatos[]) //FUN��O QUE EXIBE O RESULTADO LOGO DEPOIS DA VOTA��O - BACKEND
{
	system("color 8F");
	
	int maiorVoto, empate = 0, rep = 1;
	string vencedor;
	
	system("cls");
	cout << " \n\t\t >>>>> RESULTADO DA VOTACAO <<<<<\n\n";
		cout << "\n\t>> VOTOS TOTAIS:" << votos;
		cout << "\n\t>> VOTOS NULOS:" << votos_nulos;
		cout << "\n\t>> VOTOS BRANCOS:" << votos_branco;
		cout << "\n\t>> VOTOS VALIDOS:" << votos - votos_nulos - votos_branco << "\n\n";

		for (int j=0; j<posicao; j++){
				if(candidatos[j].ativo == true){
					cout << "\t\t" << candidatos[j].nome << " == "
						 << candidatos[j].disciplina << " == votos: " << candidatos[j].voto << endl;
				}
		}
			
		for(int i = 0; i<posicao; i++){
			if(candidatos[i].voto > candidatos[maiorVoto].voto){ //Compara a posi��o com o que tem o maior voto
				vencedor = candidatos[i].nome;
				maiorVoto = i;
			}
		}
		
		for(int i = 0; i<posicao; i++){ //Verifica se tem um empate
			if(candidatos[maiorVoto].voto == candidatos[i].voto){
				empate = i;						
			}			
		}
		
		if(empate != maiorVoto){ //Se forem diferentes, significa que dois candidatos est�o com os maiores valores = empate
			cout << "\t\t=== HOUVE UM EMPATE ENTRE ===\n    " << endl;
			cout << "\t\t\t" << candidatos[maiorVoto].nome << "  e   " << candidatos[empate].nome << endl;
					
			if(candidatos[maiorVoto].idade > candidatos[empate].idade){
				cout << "\n\n   ~ Professor(a) " << candidatos[maiorVoto].nome << " da materia de " 
					 << candidatos[maiorVoto].disciplina << " pelo crit�rio de desempate de ser mais velho ~\n\n";
			}else if(candidatos[maiorVoto].idade < candidatos[empate].idade){					
				cout << "\n\n   ~ Professor(a) " << candidatos[empate].nome << " da materia de " 
					 << candidatos[empate].disciplina << " pelo crit�rio de desempate de ser mais velho ~\n\n";
			}
						
			if(candidatos[maiorVoto].idade == candidatos[empate].idade){
				if(maiorVoto < empate){
					cout << "\n\n   ~ Professor(a) " << candidatos[maiorVoto].nome << " da materia de " 
						 << candidatos[maiorVoto].disciplina << " ganhou por ter mais votos! ~\n\\";						
				}else if(maiorVoto > empate){
					cout << "\n\n   ~ Professor(a) " << candidatos[empate].nome << " da materia de " 
						 << candidatos[empate].disciplina << " ganhou por ter mais votos! ~\n\n";
				}		
			}		
		}else{ 
			cout << "\n\n   ~ Professor(a) " << candidatos[maiorVoto].nome << " da materia de " 
			     << candidatos[maiorVoto].disciplina << " ganhou por ter mais votos! ~\n\n";		
		}

	
	cout << "\t\t";
	system ("pause");
	system("cls");
	
	while (true){ //Confirma se quer ou n�o terminar
		cout << "\n\n\n\n\t ~ Voc� quer come�ar uma nova vota��o? (selecione com as setas) ~";
						
		switch (rep){
			case 1:
				printf("\n\t%c Sim \n\t N�o", 16); // Se sim, termina e vai para o resultado
				break;  
					          
			case 2:
				printf("\n\t Sim \n\t%c N�o", 16);// Se n�o ele volta para continuar de onde parou
				break;
			default:;
		}
					
		int direc = getch();
						
		if(direc== 80 && rep <=1) rep ++;
		else if (direc == 72 && rep>=2) rep--; 
		else if (direc == 13 && rep == 1){ // Se sim quer finalizar todos as vari�veis globais s�o limpas
			posicao = 0;
			contCadastro = 0;
			votos = 0;
			votos_nulos = 0;
			votos_branco = 0;
			
			cout << "\n\n    === TUDO CERTO, PODE INICIAR UMA NOVA VOTA�AO! ===\n\n";
			system("pause");
			return false;
			
		}else if (direc==13 && rep==2){ //Se n�o a fun��o sai e vai para a tela de vota��o novamente
			
			cout << "\n\n    === CASO MUDE DE IDEIA, PODE VOLTAR AQUI! ===\n\n";
			system("pause");
			return true;
		} 
						
		system("cls");
	}
}

void creditos() //FUN��O VISUAL COM NOMES DO GRUPO - FRONTEND
{
	string nomes[]={"Danyella Ketley","Jadson Rikelme","Laura Roscelle","Let�cia Rauane","Lucas Batista"};
	
	system("color 5F");
	cout << "\n\t   >>>>>> CRIADORES <<<<<<<\n\n";
	cout << "************************************************\n";
	for (int i=0; i<5; i++){ cout << "  > " << nomes[i] << endl;}
	cout << "************************************************\n\n";
}



