//===== INSTITUTO FEDERAL DO RIO GRANDE DO NORTE =====
// > PROJETO CRUD EM SISTEMA DE VOTA��O, COM BACKEND E FRONTEND(B�SICO)
// > FINALIZA��O - 22/08/2022
// > DOCENTE - KARLOS THADEU
// > DISCIPLINA - PEOO
// > PARTICIPA��O MAGNIFICA - DJAIR IPANGUA�U :D

#include <iostream>
#include <windows.h> // cor
#include <conio.h> // para ler o teclado
#include "crud.h" // biblioteca criada
using namespace std;

bool abertura(Candidato candidatos[]) // ABERTURA DO PROGRAMA
{
	
	system ("color 0B");
	setlocale(LC_ALL,"portuguese");
	
	int i2 = 1;
	
	// ~ � preciso ser um la�o infinito controlado, para que o usu�rio possa esta movimentando pra cima e para baixo com as teclas S ou W ~
	 
	while(true) { // La�o infinito controlado.
	
		//MARCA DO PROGRAMA - FRONTEND (PARTE VISUAL)
		cout <<"       _____  _____   _    _  _____"      << endl;
		cout <<"      / ____||  __ \\ | |  | ||  __ \\"   << endl;
		cout <<"     | |     | |__) || |  | || |  | |"    << endl;
		cout <<"     | |     |  _  / | |  | || |  | |"    << endl;
		cout <<"     | |____ | | \\ \\ | |__| || |__| |"  << endl;
		cout <<"      \\_____||_|  \\_\\ \\____/ |_____/" << endl << endl;
		for(int topo=0; topo<11; topo++) cout << "<<<<";
		
		
		// ~ Op�oes do �nicio que o usu�rio pode movimentar com as teclas S ou W e 
		// confirmar com o enter para escolher qual a��o quer fazer dentro do programa ~
		
	// USAMOS O SWITCH QUE ABAIXO DO CODE VAI ESTAR ENCREMENTANDO OU DECREMENTANDO O I2 FAZENDO A A��O DE SUBIR E DESCER! 
		switch(i2) { 
        		case 1:
            		printf("\n\n\t%c  Cadastro de candidato\n\n\t  Iniciar vota��o\n\n\t  Criadores\n\n\t  Resultado da Vota��o\n\n\t  Sair agora do progama\n\n", 16);
            		break;  
        		case 2:
            		printf("\n\n\t  Cadastro de candidato\n\n\t%c  Iniciar vota��o\n\n\t  Criadores\n\n\t  Resultado da Vota��o\n\n\t  Sair agora do progama\n\n", 16);
            		break;
        		case 3:
            		printf("\n\n\t  Cadastro de candidato\n\n\t  Iniciar vota��o\n\n\t%c  Criadores\n\n\t  Resultado da Vota��o\n\n\t  Sair agora do progama\n\n", 16);
            		break;
            	case 4:
            		printf("\n\n\t  Cadastro de candidato\n\n\t  Iniciar vota��o\n\n\t  Criadores \n\n\t%c  Resultado da Vota��o\n\n\t  Sair agora do progama\n\n", 16);
            		break;
            	case 5:
            		printf("\n\n\t  Cadastro de candidato\n\n\t  Iniciar vota��o\n\n\t  Criadores\n\n\t  Resultado da Vota��o\n\n\t%c  Sair agora do progama\n\n", 16);
            		break;	
        		default:;
    	}
    	for(int final=0; final<11; final++) cout << ">>>>"; // DEIXAR MAIS ORGANIZADO - FRONTEND (PARTE VISUAL)
    		
    	int direc = getch(); //~ l� a tecla que foi pressionada.~
    	
    	//NUMEROS CORRESPONDENTE AS TECLAS ->> 115-s | 83-S | 119-w | 87-W
    	if(direc== 115 && i2<=4 || direc== 83 && i2<=4 ){ // Para baixo, vai incrementando para o "case" ir descendo.
			i2 ++; 
    	}else if (direc==119 && i2>=2 || direc== 87 && i2>=2){ // Para cima, vai decrementando para o "case" ir subindo.
			i2--; 
		}else if (direc==13 && i2==1){ //Se confirmar na primeira op��o = sae da fun��o e vai para a fun��o crud (MAIN).
    		return false;
		}else if (direc==13 && i2==2) { //Se confirmar na segunda op��o, vai para a fun��o de vota��o.
			
			// Aqui confere se foi feito o cadastro antes, se �, aparece como erro
			if (contCadastro == 0) erro_404();
			else {
				system ("cls"); 
				inicioDaVotacao(candidatos);
				exibirResultados(candidatos);
				//system ("pause");
			}
			
		}else if (direc==13 && i2==3) { //Se confirmar na terceira op��o, vai para a fun��o dos alunos.
			system ("cls"); 
			creditos(); 
			system ("pause");
			
		}else if (direc==13 && i2==4) {//Se confirmar na quarta op��o, vai para a fun��o do resultado da vota��o anterior.
		
			// Aqui confere se foi feito uma vota��o antes, se �, aparece como erro
			if (contCadastro == 0) erro_404();
			else {
				system("cls");
				resultadoVotacao(candidatos);  
				system ("pause");
			}
			
		}else if (direc==13 && i2==5) { //Se confirmar na ultima op��o, o programa � fechado.
			system ("cls"); 
			cout << "At� mais! :) \n\n"; 
			system ("pause"); 
			exit(0); //~ FUN��O QUE CANCELA A OPERA��O DO PROGRAMA, DESLIGANDO.
		}
	
		system("cls");
		system ("color 0B");
	}
	
	return true;
}

int main(){
	
	int tam = 10; //Declaramos um numero previsto de candidatos escritos, mas pode ser mais.
	Candidato candidatos[tam]; //Scruct que est� na biblioteca

	loadingBar(); //Fun��o da barra de progresso do come�o - FRONTEND (PARTE VISUAL)
	
	//LA�O INFINITO - s� vai parar quando na fun��o abertura o usuario escolher sair do programa.
	while (true){ 
		abertura(candidatos); //Fun��o que chama algumas fun��es do programa, relacionda a abertura.
		CRUDCandidato(candidatos); //Fun��o que chama outras fun��es relacionadas ao CRUD.
	}
}


