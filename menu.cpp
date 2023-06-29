#include <iostream>
#include <string>
#include "binarySearchTree.h"
#include <windows.h>

using namespace std;

void printHeader()
{
    cout << "  _____                             ___             _ __     _                                    " << endl;
    cout << " |_   _|    _ _    ___     ___     | __|   __ __   | '_ \\   | |     ___      _ _    ___      _ _  " << endl;
    cout << "   | |     | '_|  / -_)   / -_)    | _|    \\ \\ /   | .__/   | |    / _ \\    | '_|  / -_)    | '_| " << endl;
    cout << "  _|_|_   _|_|_   \\___|   \\___|    |___|   /_\\_\\   |_|__   _|_|_   \\___/   _|_|_   \\___|   _|_|_   V1.0" << endl;
    cout << "________________________________________________________________________________________________________ \n" << endl;
} 

void printMainMenu()
{
    system("cls");
    printHeader();
    cout << "Escolha uma opcao:" << endl;
    cout << "1 - Manipular a Arvore" << endl;
    cout << "2 - Informacoes sobre a Arvore" << endl;
    cout << "3 - Informacoes sobre o trabalho" << endl;
    cout << "4 - Sair" << endl;
}

void printInfoMenu()
{
    system("cls");
    printHeader();
    cout << "Escolha uma opcao:" << endl;
    cout << "1 - Altura da Arvore" << endl;
    cout << "2 - Tamanho da Arvore" << endl;
    cout << "3 - Endereco de Memoria do Elemento x" << endl;
    cout << "4 - Arvore e completa?" << endl;
    cout << "5 - Arvore e perfeita?" << endl;
    cout << "6 - Imprimir Arvore" << endl;
    cout << "7 - Voltar" << endl;
    cout << "8 - Sair" << endl;
}   

void printManipulationMenu()
{
    system("cls");
    printHeader();
    cout << "Escolha uma opcao:" << endl;
    cout << "1 - Inserir Elemento" << endl;
    cout << "2 - Remover Elemento" << endl;
    cout << "3 - Converter para lista e ordernar: BubbleSort" << endl;
    cout << "4 - Converter para lista e ordernar: SelectionSort" << endl;
    cout << "5 - Converter para lista e ordernar: InsertionSort" << endl;
    cout << "6 - Converter para lista e ordernar: ShellSort" << endl;
    cout << "7 - Voltar" << endl;
    cout << "8 - Sair" << endl;
}

void printWorkInfo()
{
    system("cls");
    printHeader();
    cout << "Trabalho final da disciplina de Estrutura de Dados 23.1 - FGV EMAp" << endl;
    cout << "Alunos: " << endl;
    cout << "   - Lunas" << endl;
    cout << "   - Osmar" << endl;
    cout << "   - Vini" << endl;
    cout << "   - Zuzu" << endl;
}

int main()
{
    int iOption;
    SearchTree tree;
    string sFilename;
    bool keepRunning = true;
    Node* ptrNode;

    system("cls");
    printHeader();
    cout << "Para comecar, e preciso criar uma arvore:" << endl;
    cout << "   1 - contruir Arvore a partir de arquivo" << endl;
    cout << "   2 - contruir Arvore a partir de entrada do usuario" << endl;

    cin >> iOption;

    switch (iOption)
    {
        case 1:
            cout << "Digite o caminho do arquivo do arquivo: " << endl;
            cin >> sFilename;
            tree.createFromTxt(sFilename);
            break;
        case 2:
            tree.buildTreeFromInput();
            break;    
    }

    cout << "Arvore criada com sucesso!" << endl;

    //Espera de 2 segundos
    Sleep(2000);

    while (keepRunning)
    {
        printMainMenu();

        cin >> iOption;

        switch (iOption)
        {
            case 1:
                printManipulationMenu();
                
                cin >> iOption;

                switch (iOption)
                {
                    case 1:
                        cout << "Digite o numero a ser inserido: " << endl;
                        cin >> iOption;
                        tree.insertNode(iOption);
                        break;
                    case 2:
                        cout << "Digite o numero a ser deletado: " << endl;
                        cin >> iOption;
                        tree.deleteNode(tree.searchNode(iOption));
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6: 
                        break;
                    case 7:
                        break;
                    case 8:
                        keepRunning = false;
                        break;
                }

                break;
            case 2:
                printInfoMenu();

                cin >> iOption;

                switch (iOption)
                {
                    case 1:
                        cout << "Altura da arvore: " << tree.getHeight() << endl;
                        //Espera de 4 segundos
                        Sleep(4000);
                        break;
                    case 2:
                        cout << "Tamanho da arvore: " << tree.getSize() << endl;
                        //Espera de 4 segundos
                        Sleep(4000);
                        break;
                    case 3:
                        cout << "Digite o numero a ser buscado: " << endl;
                        cin >> iOption;
                        ptrNode = tree.searchNode(iOption);
                        cout << "Endereco de memoria do elemento " << iOption << ": " << ptrNode << endl;
                        //Espera de 4 segundos
                        Sleep(4000);
                        break;
                    case 4:
                        cout << "A arvore e completa? " << (tree.isComplete() ? "Sim" : "Nao") << endl;
                        //Espera de 4 segundos
                        Sleep(4000);    
                        break;
                    case 5:
                        cout << "A arvore e perfeita? " << (tree.isPerfect() ? "Sim" : "Nao") << endl;
                        //Espera de 4 segundos
                        Sleep(4000);
                        break;
                    case 6:
                        tree.traverseInOrder();
                        //Espera de 4 segundos
                        Sleep(4000);
                        break;
                    case 7:
                        break;
                    case 8:
                        keepRunning = false;
                        break;
                }

                break;
            case 3:
                printWorkInfo();
                //Espera de 4 segundos
                Sleep(4000);
                break;
            case 4:
                keepRunning = false;
                break;
        }
    }
    
    return 0;
}