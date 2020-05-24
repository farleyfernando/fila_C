#include <iostream> // biblioteca padrão de entrada e saida de dados
#include <cstdlib>  // biblioteca de conversão
#include <locale>   // biblioteca de acentuação
#include <string>   // biblioteca de strings
#include <math.h>   // matematica

/*

  DISCIPLINA - ALGORITIMO E PROGRAMAÇÃO ESTRUTURADA:
  TABALHO INTERDISCIPLINAR - SISTEMA ZER@DENGUE
  CONTROLE DE PROTOCOLOS - MODELO DE FILA

*/

using namespace std;

//-------------------------------------------------------

#define tam_fila 20

//--------------------------------------------------------

int vt_fila[tam_fila];
int topo = -1;
int opcao;

//--------------------------------------------------------

void listar( void );

void inserir( void );

void remover( int x[] );

void pular_linha( int x );

int menu();

void tamanho( void );

//----------------------------------------------------------

int main()
{
    setlocale(LC_ALL,"Portuguese");
    while ( opcao != 5)
      {
        system("cls");
        menu();
      }
  return 0;
}

//------------------------------------------------------------------------

int menu()
{
    pular_linha( 1 );
    cout << "                                                    Controle de Protocolos       " << endl;
    cout << "                                                      Sistema Zer@Dengue         " << endl << endl;

    cout << " \n                                                    *** MENU PRINCIPAL ***       " << endl << endl;

    cout << " 1 - Inserir Solicitacao - Informe o numero do protocolo" << endl;
    cout << " 2 - Remover Solicitacoes atendidas" << endl;
    cout << " 3 - Listar todas as solicitacoes cadastradas no sistema " << endl;
    cout << " 4 - Total de solicitacoes em aberto" << endl;
    cout << " 5 - Sair" << endl <<endl;
    cout << " Informe a opcao desejada: " ;
    cin >> opcao;

    switch (opcao)
    {
  case 1:
    inserir();
    break;
  case 2:
    pular_linha( 1 );
    remover( vt_fila );
    break;
  case 3:
    listar();
    break;
  case 4:
    tamanho();
    break;
    }
return 0;
}

// -----------------------------------------------------------------------

void listar( void )
{
 int temp;
 if (topo == -1)
 {
     cout << "A fila esta vazia, favor inserir solicitacao!" << endl;
     pular_linha( 1 );
 }
 else
 {
  for (temp = 0; temp <= topo; temp ++ )
      {
        cout << "Na posicao: [" << temp << "] foi alocado a solicitacao de N°: " << vt_fila[temp];
        pular_linha(1);
      }
 }
      pular_linha( 1 );
      system("pause");
}
//-----------------------------------------------------------------------------------------

void inserir( void )
{
    if (topo == tam_fila - 1)
    {
       cout << "A fila esta cheia, favor remover solicitacoes atendidas!" << endl;
    }
    else
    {
     topo ++ ;
     pular_linha(1);
     cout << "Posicao do topo atual .....................: " << topo << endl;
     cout << "Digite o Nº da solicitacao (protocolo) que deseja inserir no sistema: ";
     cin >> vt_fila[topo];
     listar();
    }
}

//------------------------------------------------------------------------------------------

void remover ( int x[] )
{
    int i;
    if (topo == -1 )
       {
         cout << "A fila esta vazia, todas as solicitacoes foram atendidas!" << endl;
         pular_linha ( 1 );
       }
    else
    {
     listar();
     pular_linha( 1 );
     cout << "Foi removida a solicitacao: " << vt_fila[0] << " Posicao do Topo " << endl;
     pular_linha( 1 );
     for (i = 0; i <= topo ; i ++)
         {
           vt_fila[i] = x[ i+1 ];
         }
     topo -- ;
     listar();
    }
}
// ------------------------------------------------------------------------------------

void pular_linha ( int x )
{
 int y;
 for ( y = 1; y <= x; y++ )
     cout << endl;
}

//-------------------------------------------------------------------------------------

void tamanho(void)
{
  int temp, tam = 0;
  if (topo == -1 )
     {
       cout << "A fila esta vazia " << endl;
       pular_linha( 1 );
     }
  else
     {
       cout << "Total de solicitacoes: " << topo + 1;
       pular_linha( 1 );
     }
    system("pause");
}

//-----------------------------------------------------------------------------------------
