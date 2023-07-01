#include <iostream>
#include <string>
#include "SearchTree/binarySearchTree.h"
#include "DoubleList/doubleLinkedList.h"
#include "DoubleList/Sorters.h"
#include "Convert/convertTreeList.h"
#include <windows.h>
#include <chrono>
#include <sstream>
#include <limits>


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
    DoubleList listTree;
    BubbleSorter sorterBubble;
    SelectionSorter sorterSelection;
    InsertionSorter sorterInsertion;
    string sInput;

    system("cls");
    printHeader();
    while(keepRunning){
    cout << "Para comecar, e preciso criar uma arvore:" << endl;
    cout << "   1 - contruir Arvore a partir de arquivo" << endl;
    cout << "   2 - contruir Arvore a partir de entrada do usuario" << endl;
    cout << "   3 - Sair" << endl;

    std::getline(std::cin, sInput);

    //Deals with invalid input (non-integer)
    std::istringstream iss(sInput);
        if (!(iss >> iOption)) {
            //0.35 seconds delay
            Sleep(350);
            
            cout<<endl;
            std::cout << "Opcao invalida! Tente novamente." << std::endl;
            
            //0.35 seconds delay
            Sleep(350);
            
            cout<<endl;
            continue;
        }
    

    switch (iOption)
    {
        case 1:{
            cout << "Digite o caminho do arquivo: " << endl;
            cin >> sFilename;
            
            auto startTime = std::chrono::high_resolution_clock::now();
            bool created=tree.createFromTxt(sFilename);
            auto endTime = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
            if (!created)
            {
                cout<<"Tempo da operacao "<<duration<<" microsegundos."<<endl;
                cout<<"Retornando as opcoes"<<endl;
                cout<<endl;
                //0.85 seconds delay
                Sleep(850);
            }
            else{
                cout<<endl;
                std::cout << "Arvore criada com sucesso em " << duration << " microsegundos!" << std::endl;
                cout<<"Pressione ENTER para continuar."<<endl;
                fflush(stdin);
                getchar();
                keepRunning = false;
            }
            break;
        }
        case 2:{
            tree.buildTreeFromInput();
            cout<<endl;
            cout<<"Arvore criada com sucesso!"<<endl;
            cout<<"Pressione ENTER para continuar."<<endl;
            fflush(stdin);
            getchar();
            keepRunning = false;
            break;
        }
        case 3:
            return 0;
            break;
        default:
            cout<<endl;
            cout << "Opcao Invalida! Tente novamente." << endl;
            //0.85 seconds delay
            Sleep(850);
            cout<<endl;
            break;
    }
    }

    keepRunning = true;
    while (keepRunning)
    {
        printMainMenu();
        std::getline(std::cin, sInput);
        //Deals with invalid input (non-integer)
        std::istringstream iss(sInput);
        if (!(iss >> iOption)) {
            //0.3 seconds delay
            Sleep(450);
            
            cout<<endl;
            std::cout << "Opcao invalida! Tente novamente." << std::endl;
            
            //0.3 seconds delay
            Sleep(450);
            
            cout<<endl;
            continue;
        }



        switch (iOption)
        {
            case 1:
            //Manipular Arvore
                printManipulationMenu();
                
                cin >> iOption;

                switch (iOption)
                {
                    case 1:{
                    //Inserir Elemento
                        cout<<endl;
                        cout << "Digite um numero a ser inserido: " << endl;
                        cout << "Caso digite meltiplos numeros apenas o primeiro sera inserido." << endl;
                        cout<<endl;
                        cin >> iOption;

                        auto startTime = std::chrono::high_resolution_clock::now();
                        tree.insertNode(iOption);
                        auto endTime = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

                        cout<<endl;
                        cout << "Elemento inserido com sucesso!" << endl;
                        cout<<"Tempo da operacao "<<duration<<" microsegundos."<<endl;
                        cout<<"Pressione ENTER para continuar."<<endl;
                        fflush(stdin);
                        getchar();
                        break;
                    }
                    case 2:{
                    //Remover Elemento
                        cout<<endl;
                        cout << "Digite o numero a ser deletado: " << endl;
                        cout<<endl;
                        cin >> iOption;

                        cout<<endl;
                        cout << "Removendo elemento..." << endl;

                        auto startTime = std::chrono::high_resolution_clock::now();
                        tree.deleteNode(tree.searchNode(iOption));
                        auto endTime = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
                        
                        cout<<endl;
                        cout<<"Tempo da operacao "<<duration<<" microsegundos."<<endl;
                        cout<<"Pressione ENTER para continuar."<<endl;
                        fflush(stdin);
                        getchar();
                        break;
                    }
                    case 3:{
                    //Bubble Sort
                        cout << "Convertendo arvore para lista" << endl;
                        listTree = convertToListPostOrder(tree);

                        new (&sorterBubble) BubbleSorter();

                        cout<<"Lista desordenada: "<<endl;
                        listTree.printList();
                        sorterBubble.list = &listTree;
                        sorterBubble.sort();
                        cout << "Lista Ordenada:" << endl;
                        listTree.printList();
                        //Espera de 4 segundos
                        Sleep(4000);
                        break;
                    }
                    case 4:{
                    //Selection Sort
                        cout << "Convertendo arvore para lista" << endl;
                        listTree = convertToListPostOrder(tree);

                        new (&sorterSelection) SelectionSorter();
                        
                        cout<<"Lista desordenada: "<<endl;
                        listTree.printList();
                        
                        sorterSelection.list = &listTree;
                        sorterSelection.sort();
                        cout << "Lista Ordenada:" << endl;
                        listTree.printList();
                        //Espera de 4 segundos
                        Sleep(4000);
                        break;
                    }
                    case 5:{
                    //Insertion Sort
                        cout << "Convertendo arvore para lista" << endl;
                        listTree = convertToListPostOrder(tree);

                        new (&sorterInsertion) InsertionSorter();

                        cout<<"Lista desordenada: "<<endl;
                        listTree.printList();
                        sorterInsertion.list = &listTree;
                        sorterInsertion.sort();
                        cout << "Lista Ordenada:" << endl;
                        listTree.printList();
                        //Espera de 4 segundos
                        Sleep(4000);
                        break;
                    }
                    case 6: 
                        break;
                    case 7:
                    //Voltar
                        break;
                    case 8:
                        keepRunning = false;
                        break;
                    default:
                        cout << "Opcao invalida!" << endl;
                        //Espera de 4 segundos
                        Sleep(4000);
                        break;
                }

                break;
            case 2:
            //Informacoes da Arvore
                printInfoMenu();

                cin >> iOption;

                switch (iOption)
                {
                    case 1:{

                        auto startTime = std::chrono::high_resolution_clock::now();
                        int iHeight = tree.getHeight();
                        auto endTime = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

                        cout<<endl;
                        cout << "Altura da arvore: " << iHeight << endl;
                        cout<<"Tempo da operacao "<<duration<<" microsegundos."<<endl;
                        cout<<"Pressione ENTER para continuar."<<endl;
                        fflush(stdin);
                        getchar();

                        break;
                    }
                    case 2:{
                        auto startTime = std::chrono::high_resolution_clock::now();
                        int iSize = tree.getSize();
                        auto endTime = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

                        cout<<endl;
                        cout << "Tamanho da arvore: " << iSize << endl;
                        cout<<"Tempo da operacao "<<duration<<" microsegundos."<<endl;
                        cout<<"Pressione ENTER para continuar."<<endl;

                        fflush(stdin);
                        getchar();

                        break;
                    }
                    case 3:{
                        cout << "Digite o numero a ser buscado: " << endl;
                        cout<<endl;
                        cin >> iOption;

                        auto startTime = std::chrono::high_resolution_clock::now();
                        ptrNode = tree.searchNode(iOption);
                        auto endTime = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
                        
                        cout<<endl;
                        if (ptrNode == nullptr){
                            cout << "Elemento nao encontrado!" << endl;
                        }
                        else{
                            cout << "Endereco de memoria do elemento " << iOption << ": " << ptrNode << endl;
                        }
                        cout<<"Tempo da operacao "<<duration<<" microsegundos."<<endl;
                        cout<<"Pressione ENTER para continuar."<<endl;
                        fflush(stdin);
                        getchar();
                        break;
                    }
                    case 4:{
                        auto startTime = std::chrono::high_resolution_clock::now();
                        bool bComplete = tree.isComplete();
                        auto endTime = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

                        cout<<endl;
                        cout << "A arvore e completa? " << (bComplete ? "Sim" : "Nao") << endl;
                        cout<<"Tempo da operacao "<<duration<<" microsegundos."<<endl;
                        cout<<"Pressione ENTER para continuar."<<endl;
                        fflush(stdin);
                        getchar();
                        break;
                    }
                    case 5:{
                        auto startTime = std::chrono::high_resolution_clock::now();
                        bool bIsPerfect = tree.isPerfect();
                        auto endTime = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

                        cout<<endl;
                        cout << "A arvore e perfeita? " << (bIsPerfect ? "Sim" : "Nao") << endl;
                        cout<<"Tempo da operacao "<<duration<<" microsegundos."<<endl;
                        cout<<"Pressione ENTER para continuar."<<endl;

                        fflush(stdin);
                        getchar();
                        break;
                    }
                    case 6:{

                        cout<<endl;
                        auto startTime = std::chrono::high_resolution_clock::now();
                        tree.traverseBFS();
                        auto endTime = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

                        cout<<endl;
                        cout<<endl;
                        cout<<"Tempo da operacao "<<duration<<" microsegundos."<<endl;
                        cout<<"Pressione ENTER para continuar."<<endl;

                        fflush(stdin);
                        getchar();
                        break;
                    }
                    case 7:{
                        break;
                    }
                    case 8:{
                        keepRunning = false;
                        break;
                    }
                    default:{
                        cout << "Opcao invalida!" << endl;
                        //Espera de 4 segundos
                        Sleep(4000);
                        break;
                    }
                }

                break;
            case 3:
                printWorkInfo();
                //Espera de 4 segundos
                Sleep(4000);
                break;
            case 4:
            //Sair
                keepRunning = false;
                break;
            default:
                cout << "Opcao invalida!" << endl;
                //Espera de 4 segundos
                Sleep(4000);
                break;
        }
    }
    
    return 0;
}