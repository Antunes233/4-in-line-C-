#include <iostream>
#include <iomanip>
#include "cjogo.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include<sstream>

using namespace std;



CJogo :: CJogo()
{
    cabeca = NULL;
    Njogadas = 0;
    Nvitorias = 0;
    Nvitorias2 = 0;
    Nderrotas = 0;
    vitorias_PC2 = 0;
    nivel = 0;
    Nempates = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            jogadas[i][j] = ' ';
        }
    }
    le_top10_file();
    ofstream file("jogadas.txt",ios::trunc);
    file.close();

}

//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
void CJogo::jogar()
{

    if(nivel == 0) escolher_dificuldade();
    switch(nivel){
    case 1:
        mostra_Nvitorias_player();
        mostra_Nderrotas();
        if(primeiro == 1){
            for(int i = Njogadas; i<42;i++){
                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: ";
                mostra_nome(player_name);
                cout << endl << endl;
                if(jogada_jogador()){
                    char b;
                    cout << endl << "Jogar novamente? s/n" << endl;
                    cin >> b;
                    switch (b) {
                    case 's':
                        reset_tabuleiro();
                        escolher_dificuldade();
                        jogar();
                        break;
                    case 'n':
                        reset_jogo();
                        menu();
                    default:
                        break;
                    }
                    break;
                }

                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC" << endl << endl;
                if(elementar()){
                    char b;
                    cout << endl << "Jogar novamente? s/n" << endl;
                    cin >> b;
                    switch (b) {
                    case 's':
                        reset_tabuleiro();
                        escolher_dificuldade();
                        jogar();
                        break;
                    case 'n':
                        reset_jogo();
                        menu();
                    default:
                        break;
                    }
                    break;
                }

            }
        }
        else if(primeiro == 2){
            for(int i = Njogadas; i<42;i++){
                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC" << endl << endl;
                if(elementar()){
                    char b;
                    cout << endl << "Jogar novamente? s/n" << endl;
                    cin >> b;
                    switch (b) {
                    case 's':
                        reset_tabuleiro();
                        escolher_dificuldade();
                        jogar();
                        break;
                    case 'n':
                        reset_jogo();
                        menu();
                    default:
                        break;
                    }
                    break;
                }

                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: ";
                mostra_nome(player_name);
                cout << endl << endl;
                if(jogada_jogador()){
                    char b;
                    cout << endl << "Jogar novamente? s/n" << endl;
                    cin >> b;
                    switch (b) {
                    case 's':
                        reset_tabuleiro();
                        escolher_dificuldade();
                        jogar();
                        break;
                    case 'n':
                        reset_jogo();
                        menu();
                    default:
                        break;
                    }
                    break;
                }

            }
        }
        if(empate()){
            cout << "Empate" << endl;
            break;
        }

    case 2:
        mostra_Nvitorias_player();
        mostra_Nderrotas();
        if(primeiro == 1){
            for(int i = Njogadas; i<42;i++){
                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: ";
                mostra_nome(player_name);
                cout << endl <<"Se quiser voltar atras prima 0";
                cout << endl << endl;
                if(jogada_jogador()){
                    char b;
                    cout << endl << "Jogar novamente? s/n" << endl;
                    cin >> b;
                    switch (b) {
                    case 's':
                        reset_tabuleiro();
                        escolher_dificuldade();
                        jogar();
                        break;
                    case 'n':
                        reset_jogo();
                        menu();
                    default:
                        break;
                    }
                    break;

                }


                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC" << endl << endl;
                if(basico()){
                    char b;
                    cout << endl << "Jogar novamente? s/n" << endl;
                    cin >> b;
                    switch (b) {
                    case 's':
                        reset_tabuleiro();
                        escolher_dificuldade();
                        jogar();
                        break;
                    case 'n':
                        reset_jogo();
                        menu();
                    default:
                        break;
                    }
                    break;
                }

            }
        }

        else if(primeiro == 2){
            for(int i = Njogadas; i<42;i++){
                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC" << endl << endl;
                if(basico()){
                    char b;
                    cout << endl << "Jogar novamente? s/n" << endl;
                    cin >> b;
                    switch (b) {
                    case 's':
                        reset_tabuleiro();
                        escolher_dificuldade();
                        jogar();
                        break;
                    case 'n':
                        reset_jogo();
                        menu();
                    default:
                        break;
                    }
                    break;
                }

                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: ";
                mostra_nome(player_name);
                cout << endl <<"Se quiser voltar atras prima 0";
                cout << endl << endl;
                if(jogada_jogador()){

                    break;
                }

            }
        }
        if(empate()){

            cout << "Empate" << endl;
            break;
        }

    case 3:
        mostra_Nvitorias_player();
        mostra_Nderrotas();
        if(primeiro == 1){
            for(int i = Njogadas; i<42;i++){
                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: ";
                mostra_nome(player_name);
                cout << endl << endl;
                if(jogada_jogador()){
                    char b;
                    cout << endl << "Jogar novamente? s/n" << endl;
                    cin >> b;
                    switch (b) {
                    case 's':
                        reset_tabuleiro();
                        escolher_dificuldade();
                        jogar();
                        break;
                    case 'n':
                        reset_jogo();
                        menu();
                    default:
                        break;
                    }

                    break;
                }

                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC" << endl << endl;
                if(medio()){
                    char b;
                    cout << endl << "Jogar novamente? s/n" << endl;
                    cin >> b;
                    switch (b) {
                    case 's':
                        reset_tabuleiro();
                        escolher_dificuldade();
                        jogar();
                        break;
                    case 'n':
                        reset_jogo();
                        menu();
                    default:
                        break;
                    }
                    break;
                }

            }
        }

        else if(primeiro == 2){
            for(int i = Njogadas; i<42;i++){
                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC" << endl << endl;
                if(medio()){
                    char b;
                    cout << endl << "Jogar novamente? s/n" << endl;
                    cin >> b;
                    switch (b) {
                    case 's':
                        reset_tabuleiro();
                        escolher_dificuldade();
                        jogar();
                        break;
                    case 'n':
                        reset_jogo();
                        menu();
                    default:
                        break;
                    }
                    break;
                }

                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: ";
                mostra_nome(player_name);
                cout << endl << endl;
                if(jogada_jogador()){

                    break;
                }

            }
        }
        if(empate()){
            char b;
            cout << endl << "Jogar novamente? s/n" << endl;
            cin >> b;
            switch (b) {
            case 's':
                reset_tabuleiro();
                escolher_dificuldade();
                jogar();
                break;
            case 'n':
                reset_jogo();
                menu();
            default:
                break;
            }
            cout << "Empate" << endl;
            break;
        }
    case 4 :
        mostra_Nvitorias_player();
        mostra_Nderrotas();
        if(primeiro == 1){
            for(int i = Njogadas; i<42;i++){
                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: ";
                mostra_nome(player_name);
                cout << endl << endl;
                if(jogada_jogador()){
                    char b;
                    cout << endl << "Jogar novamente? s/n" << endl;
                    cin >> b;
                    switch (b) {
                    case 's':
                        reset_tabuleiro();
                        escolher_dificuldade();
                        jogar();
                        break;
                    case 'n':
                        reset_jogo();
                        menu();
                    default:
                        break;
                    }

                    break;
                }

                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC" << endl << endl;
                if(avancado()){
                    char b;
                    cout << endl << "Jogar novamente? s/n" << endl;
                    cin >> b;
                    switch (b) {
                    case 's':
                        reset_tabuleiro();
                        escolher_dificuldade();
                        jogar();
                        break;
                    case 'n':
                        reset_jogo();
                        menu();
                    default:
                        break;
                    }
                    break;
                }

            }
        }

        else if(primeiro == 2){
            for(int i = Njogadas; i<42;i++){
                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC" << endl << endl;
                if(avancado()){
                    char b;
                    cout << endl << "Jogar novamente? s/n" << endl;
                    cin >> b;
                    switch (b) {
                    case 's':
                        reset_tabuleiro();
                        escolher_dificuldade();
                        jogar();
                        break;
                    case 'n':
                        reset_jogo();
                        menu();
                    default:
                        break;
                    }
                    break;
                }

                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: ";
                mostra_nome(player_name);
                cout << endl << endl;
                if(jogada_jogador()){

                    break;
                }

            }
        }
        if(empate()){
            char b;
            cout << endl << "Jogar novamente? s/n" << endl;
            cin >> b;
            switch (b) {
            case 's':
                reset_tabuleiro();
                escolher_dificuldade();
                jogar();
                break;
            case 'n':
                reset_jogo();
                menu();
            default:
                break;
            }
            cout << "Empate" << endl;
            break;
        }

    default:
        break;

    }


}
//----------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------
void CJogo::tabuleiro(){

    for(int i = 1; i <= 7; i++){
        cout << right << '|' << setw(2) << i << setw(2);
        if(i == 7) cout << '|';
    }
    cout << endl;
    for(int j = 0; j < 6; j++){
        for(int k = 0; k < 7; k++){
            cout << '|' << setw(2) << jogadas[j][k] << setw(2);
        }
        cout << '|' << endl;
    }
    cout << endl;

}
//----------------------------------------------------------------------------------------------------
void CJogo::menu(){
    nivel = 0;
    char a;
    do{
        cout << "Bem vindo ao 4 em linha" << endl;
        cout << setw(23) << "1 - Singleplayer" << endl;
        cout << setw(22) << "2 - Multiplayer" << endl;
        cout << setw(21) << "3 - COM vs COM" << endl;
        cout << setw(25) << "4 - Continuar jogo" << endl;
        cout << setw(17) << "5 - Top 10" << endl;
        cout << setw(15) << "6 - Sair" << endl;


        cin >> a;
        a = a-48;
    }while(a < 1 || a > 6);

    switch(a){
    case 1:

        inserirNome();
        reset_jogo();
        comeca();
        jogar();

        break;
    case 2:
        inserirNome();
        inserirNome2();
        jogar_multiplayer();
    case 3:
        reset_jogo();
        jogar_pc_vs_pc();
    case 4:
        recomeca_jogo();
        break;
    case 5:
        mostra_top10();
        menu();
        break;
    case 6:
        cout << "Bye have a great time" << endl;
        exit(0);
        break;
    default:
        break;
    }

}

//----------------------------------------------------------------------------------------------------
void CJogo::inserirNome(){
    do {
        cin.ignore();
        cout << "Jogador 1 insira o nome: ";
        getline(cin,player_name);
        if(player_name == "PC"){
            cout << "Nome invalido por favor inserir outro nome!" << endl << endl;
        }
    }while (player_name == "PC");
}
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
void CJogo::escolher_dificuldade(){
    char a;
    do{
        cout << "Welcome!" << endl
             << "Escolha o nivel de dificuldade: " << endl << endl
             << setw(14) << "1 - Elementar" << endl
             << setw(11) << "2 - Basico" << endl
             << setw(10) << "3 - Medio" << endl
             << setw(13) << "4 - Avancado" << endl;
        cin >> a;
        a = a-48;
    }while( a < 1 || a > 4);
    nivel = a;

}
//----------------------------------------------------------------------------------------------------
void CJogo::escolher_dificuldade_pc_vs_pc(){
    char a;
    do{
        cout << "Welcome!" << endl
             << "Escolha o nivel de dificuldade: " << endl << endl
             << setw(14) << "1 - Elementar" << endl
             << setw(11) << "2 - Basico" << endl
             << setw(10) << "3 - Medio" << endl;

        cin >> a;
        a = a-48;
    }while( a < 1 || a > 3);
    nivel = a;

}
//----------------------------------------------------------------------------------------------------
void CJogo::mostra_nome(string nome){
    cout << nome;
}
//----------------------------------------------------------------------------------------------------
void CJogo::comeca(void){
    char a;
    do{
        cout << "Quem comeca a jogar?" << endl
             << setw(3) << "1 - Utilizador" << endl
             << setw(3) << "2 - PC" << endl
             << setw(3) << "3 - Aleatorio" << endl;
        cin >> a;
        a = a-48;
    }while( a < 1 || a > 3);
    switch (a) {
    case 1:
        primeiro = 1; //começa o jogador
        break;
    case 2:
        primeiro = 2; //começa o computador
        break;
    case 3:
        primeiro = comeca_aleatorio();
        break;
    default:
        break;
    }
}
//---------------------------------------------------------------------------------------------------
int CJogo::comeca_aleatorio(){
    int a;
    srand(time(NULL));
    a = rand()%2;
    if(a == 0) return 1;
    else return 2;
}

//---------------------------------------------------------------------------------------------------
// computador joga nivel elementar
bool CJogo::elementar(){
    int linha; //colunas
    int coluna = 5; //linhas
    auxNjogadas = Njogadas;


    do{
        linha = 5;
        srand(time(NULL));
        coluna = rand() % 7;
        while(jogadas[linha][coluna] != ' '){
            linha--;
        }
    }while(jogadas[0][coluna] != ' ');

    jogadas[linha][coluna] = 'C';
    ultima_linha_jogada_C = linha;
    ultima_coluna_jogada_C = coluna;
    guarda_jogadas(linha, coluna, 'C');
    Njogadas++;

    tabuleiro();
    if(vitoria()==1){
        ofstream file("jogadas.txt",ios::trunc);
        file.close();
        ofstream file2("Saved_game.txt",ios::trunc);
        file2.close();
        ofstream file3("Game_info.txt",ios::trunc);
        file3.close();
        cout << "PC ganhou!" << endl;
        Nderrotas++;
        return true;
    }
    else return false;
}
//----------------------------------------------------------------------------------------------------
bool CJogo::troca(bool jogador){
    if(jogador == true){
        jogador = false;
    }
    else{
        jogador = true;
    }
    return jogador;
}
//----------------------------------------------------------------------------------------------------
bool CJogo::jogada_jogador(){
    int j = 5;
    char i;
    auxNjogadas = Njogadas;



    cout << endl << "Se quiser voltar atras prima 0.    Se quiser ver jogadas anteriores prima 9(so singleplayer)     Se quiser sair do jogo prima 8." << endl <<endl;
    cout << "Escolha a coluna em que quer jogar: ";
    cin >> i;

    i = i-48;
    while(jogadas[j][i-1] != ' '){
        j--;
    }
    if (i == 0) back();

    if((jogadas[0][i-1] != ' ' && i-1 >= 0)|| i < 0 || i > 9){
        cout << "Jogada impossivel, escolha outra coluna" << endl;
        jogada_jogador();
    }

    if(i == 8){
        suspende();
    }
    if(i == 9){
        mostra_jogadas();
    }
    if(i-1 >= 0 && 4 < 7 ) jogadas[j][i-1] = 'U';
    ultima_linha_jogada_U = j;
    ultima_coluna_jogada_U = i-1;
    guarda_jogadas(ultima_linha_jogada_U, ultima_coluna_jogada_U, 'U');
    Njogadas++;

    tabuleiro();
    guarda_jogo_em_ficheiro();
    guarda_info_file();

    if(vitoria() == 2){
        ofstream file("jogadas.txt",ios::trunc);
        file.close();
        ofstream file2("Saved_game.txt",ios::trunc);
        file2.close();
        ofstream file3("Game_info.txt",ios::trunc);
        file3.close();
        Nvitorias++;
        mostra_nome(player_name);
        cout << " ganhou" << endl;
        atualiza_top10(Njogadas,player_name);

        return true;
    }
    else return false;

}
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
int CJogo::mostra_Njogadas(){
    return Njogadas;
}
//----------------------------------------------------------------------------------------------------
int CJogo::vitoria(){
    for(int i=0;i<6; i++){
        for(int j=0;j<7;j++){
            if(j+3<7){
                if(jogadas[i][j]== 'C' && jogadas[i][j+1]=='C' && jogadas[i][j+2]=='C' && jogadas[i][j+3]=='C'){
                    return 1; //vitoria horizontal PC
                }

                if(jogadas[i][j]== 'U' && jogadas[i][j+1]=='U' && jogadas[i][j+2]=='U' && jogadas[i][j+3]=='U'){
                    return 2; //vitoria horizontal jogador
                }
            }

            if(i+3<6){
                if(jogadas[i][j]== 'C' && jogadas[i+1][j]=='C' && jogadas[i+2][j]=='C' && jogadas[i+3][j]=='C'){
                    return 1; //vitoria vertical PC
                }

                if(jogadas[i][j]== 'U' && jogadas[i+1][j]=='U' && jogadas[i+2][j]=='U' && jogadas[i+3][j]=='U'){
                    return 2; //vitoria vertical jogador
                }
            }
            if(i+3<6 && j+3<7){
                if(jogadas[i][j]== 'C' && jogadas[i+1][j+1]=='C' && jogadas[i+2][j+2]=='C' && jogadas[i+3][j+3]=='C'){
                    return 1; //vitoria diagonal esquerda-direita, cima-baixo PC
                }

                if(jogadas[i][j]== 'U' && jogadas[i+1][j+1]=='U' && jogadas[i+2][j+2]=='U' && jogadas[i+3][j+3]=='U'){
                    return 2; //vitoria diagonal esquerda-direita, cima-baixo jogador
                }
            }
            if(i+3<6 && j-3>=0){
                if(jogadas[i][j]== 'C' && jogadas[i+1][j-1]=='C' && jogadas[i+2][j-2]=='C' && jogadas[i+3][j-3]=='C'){
                    return 1; //vitoria diagonal direita-esquerda, cima-baixo PC
                }

                if(jogadas[i][j]== 'U' && jogadas[i+1][j-1]=='U' && jogadas[i+2][j-2]=='U' && jogadas[i+3][j-3]=='U'){
                    return 2; //vitoria diagonal direita-esquerda, cima-baixo jogador
                }
            }

            if(jogadas[0][0] != ' ' && jogadas[0][1] != ' ' && jogadas[0][2] != ' ' && jogadas[0][3] != ' ' && jogadas[0][4] != ' ' && jogadas[0][5] != ' ' && jogadas[0][6] != ' '){
                return 3;
            }
        }
    }
    return 0;

}

//----------------------------------------------------------------------------------------------------

bool CJogo::empate(){
    bool draw;
    if(vitoria() == 3) draw = true;
    else draw = false;
    return draw;
}
//----------------------------------------------------------------------------------------------------
// computador joga no nivel basico
bool CJogo::basico(void){
    int coluna; // colunas
    int linha; // linhas
    bool jogou = false;
    cout << endl;
    for(int i=0;i<6; i++){
        for(int j=0;j<7;j++){
            if(j+3<7){
                if(jogadas[i][j]== ' ' && jogadas[i][j+1]=='C' && jogadas[i][j+2]=='C' && jogadas[i][j+3]=='C' && jogadas[i+1][j]!= ' ' ){
                    jogadas[i][j] = 'C';
                    linha = i;
                    coluna = j;
                    jogou = true;
                    break;  //ganha horizontal 1º peça a contar de esquerda
                }
                if(jogadas[i][j]== 'C' && jogadas[i][j+1]==' ' && jogadas[i][j+2]=='C' && jogadas[i][j+3]=='C' && jogadas[i+1][j+1]!= ' '){
                    jogadas[i][j+1] = 'C';
                    linha = i;
                    coluna = j+1;
                    jogou = true;
                    break;  //ganha horizontal 2º peça
                }
                if(jogadas[i][j]== 'C' && jogadas[i][j+1]=='C' && jogadas[i][j+2]==' ' && jogadas[i][j+3]=='C' && jogadas[i+1][j+2]!= ' '){
                    jogadas[i][j+2] = 'C';
                    linha = i;
                    coluna = j+2;
                    jogou = true;
                    break;  //ganha horizontal 3º peça
                }

                if(jogadas[i][j]== 'C' && jogadas[i][j+1]=='C' && jogadas[i][j+2]=='C' && jogadas[i][j+3]==' ' && jogadas[i+1][j+3]!= ' '){
                    jogadas[i][j+3] = 'C';
                    linha = i;
                    coluna = j+3;
                    jogou = true;
                    break;  //ganha horizontal 4º peça
                }
            }
            if(i+3<6){
                if(jogadas[i][j]== ' ' && jogadas[i+1][j]=='C' && jogadas[i+2][j]=='C' && jogadas[i+3][j]=='C'){
                    jogadas[i][j] = 'C';
                    linha = i;
                    coluna = j;
                    jogou = true;
                    break;  //ganha vertical unica opçao, topo
                }
            }

            if(i+3<6 && j+3<7){
                if(jogadas[i][j]== ' ' && jogadas[i+1][j+1]=='C' && jogadas[i+2][j+2]=='C' && jogadas[i+3][j+3]=='C' && jogadas[i+1][j]!=' '){
                    jogadas[i][j]= 'C';
                    linha = i;
                    coluna = j;
                    jogou = true;
                    break; //vitoria diagonal esquerda-direita, cima-baixo, 1º peça
                }

                if(jogadas[i][j]== 'C' && jogadas[i+1][j+1]==' ' && jogadas[i+2][j+2]=='C' && jogadas[i+3][j+3]=='C' && jogadas[i+2][j+1]!=' '){
                    jogadas[i+1][j+1]= 'C';
                    linha = i+1;
                    coluna = j+1;
                    jogou = true;
                    break; //vitoria diagonal esquerda-direita, cima-baixo, 2º peça
                }

                if(jogadas[i][j]== 'C' && jogadas[i+1][j+1]=='C' && jogadas[i+2][j+2]==' ' && jogadas[i+3][j+3]=='C' && jogadas[i+3][j+2]!=' '){
                    jogadas[i+2][j+2]= 'C';
                    linha = i+2;
                    coluna = j+2;
                    jogou = true;
                    break; //vitoria diagonal esquerda-direita, cima-baixo, 3º peça
                }

                if(jogadas[i][j]== 'C' && jogadas[i+1][j+1]=='C' && jogadas[i+2][j+2]=='C' && jogadas[i+3][j+3]==' ' && (jogadas[i+4][j+3]!=' ' || jogadas[5][j+3]==' ')){
                    jogadas[i+3][j+3]= 'C';
                    linha = i+3;
                    coluna = j+3;
                    jogou = true;
                    break; //vitoria diagonal esquerda-direita, cima-baixo, 4º peça
                }
            }

            if(i+3<6 && j-3>=0){
                if(jogadas[i][j]== ' ' && jogadas[i+1][j-1]=='C' && jogadas[i+2][j-2]=='C' && jogadas[i+3][j-3]=='C' && jogadas[i+1][j]!= ' '){
                    jogadas[i][j]= 'C';
                    linha = i;
                    coluna = j;
                    jogou = true;
                    break; //vitoria diagonal direita-esquerda, cima-baixo, 1º peça
                }

                if(jogadas[i][j]== 'C' && jogadas[i+1][j-1]==' ' && jogadas[i+2][j-2]=='C' && jogadas[i+3][j-3]=='C' && jogadas[i+2][j-1]!= ' '){
                    jogadas[i+1][j-1]= 'C';
                    linha = i+1;
                    coluna = j-1;
                    jogou = true;
                    break; //vitoria diagonal direita-esquerda, cima-baixo, 2º peça
                }

                if(jogadas[i][j]== 'C' && jogadas[i+1][j-1]=='C' && jogadas[i+2][j-2]==' ' && jogadas[i+3][j-3]=='C' && jogadas[i+3][j-2]!= ' '){
                    jogadas[i+2][j-2]= 'C';
                    linha = i+2;
                    coluna = j-2;
                    jogou = true;
                    break; //vitoria diagonal direita-esquerda, cima-baixo, 3º peça
                }

                if(jogadas[i][j]== 'C' && jogadas[i+1][j-1]=='C' && jogadas[i+2][j-2]=='C' && jogadas[i+3][j-3]==' ' && (jogadas[i+4][j-3]!= ' '|| jogadas[5][j-3] == ' ')){
                    jogadas[i+3][j-3]= 'C';
                    linha = i+3;
                    coluna = j-3;
                    jogou = true;
                    break; //vitoria diagonal direita-esquerda, cima-baixo, 4º peça
                }
            }
        }
    }


    if(jogou == false){ // caso nenhuma das situaçoes anteriores aconteça joga de forma aleatoria
        do{
            linha = 5;
            srand(time(NULL));
            coluna = rand() % 7;
            while(jogadas[linha][coluna] != ' '){
                linha--;
            }
        }while(jogadas[0][coluna] != ' ');
    }

    jogadas[linha][coluna] = 'C';
    ultima_linha_jogada_C = linha;
    ultima_coluna_jogada_C = coluna;
    guarda_jogadas(ultima_linha_jogada_C,ultima_coluna_jogada_C,'C');


    Njogadas++;
    tabuleiro();
    if(vitoria() == 1){
        ofstream file("jogadas.txt",ios::trunc);
        file.close();
        ofstream file2("Saved_game.txt",ios::trunc);
        file2.close();
        ofstream file3("Game_info.txt",ios::trunc);
        file3.close();
        Nderrotas++;
        cout << "PC ganhou" << endl<< endl;
        return true;
    }
    else{

        return false;
    }
}
//--------------------------------------------------------------------------------------------------------------------
// o computador joga no nivel medio
bool CJogo::medio(){
    int coluna; // colunas
    int linha; // linhas
    int jogou = 0;
    cout << endl;

    for(int i=0;i<6; i++){
        for(int j=0;j<7;j++){
            //para o PC ganhar
            if(j+3<7){
                if(jogadas[i][j]== ' ' && jogadas[i][j+1]=='C' && jogadas[i][j+2]=='C' && jogadas[i][j+3]=='C' && jogadas[i+1][j]!= ' ' ){
                    jogadas[i][j] = 'C';
                    jogou = 1;
                    linha = i;
                    coluna = j;
                    break;  //ganha horizontal 1º peça a contar de esquerda
                }
                if(jogadas[i][j]== 'C' && jogadas[i][j+1]==' ' && jogadas[i][j+2]=='C' && jogadas[i][j+3]=='C' && jogadas[i+1][j+1]!= ' '){
                    jogadas[i][j+1] = 'C';
                    jogou = 1;
                    linha = i;
                    coluna = j+1;
                    break;  //ganha horizontal 2º peça
                }
                if(jogadas[i][j]== 'C' && jogadas[i][j+1]=='C' && jogadas[i][j+2]==' ' && jogadas[i][j+3]=='C' && jogadas[i+1][j+2]!= ' '){
                    jogadas[i][j+2] = 'C';
                    jogou = 1;
                    linha = i;
                    coluna = j+2;
                    break;  //ganha horizontal 3º peça
                }

                if(jogadas[i][j]== 'C' && jogadas[i][j+1]=='C' && jogadas[i][j+2]=='C' && jogadas[i][j+3]==' ' && jogadas[i+1][j+3]!= ' '){
                    jogadas[i][j+3] = 'C';
                    jogou = 1;
                    linha = i;
                    coluna = j+3;
                    break;  //ganha horizontal 4º peça
                }
            }
            if(i+3<6){
                if(jogadas[i][j]== ' ' && jogadas[i+1][j]=='C' && jogadas[i+2][j]=='C' && jogadas[i+3][j]=='C'){
                    jogadas[i][j] = 'C';
                    jogou = 1;
                    linha = i;
                    coluna = j;
                    break;  //ganha vertical unica opçao, topo
                }
            }

            if(i+3<6 && j+3<7){
                if(jogadas[i][j]== ' ' && jogadas[i+1][j+1]=='C' && jogadas[i+2][j+2]=='C' && jogadas[i+3][j+3]=='C' && jogadas[i+1][j]!=' '){
                    jogadas[i][j]= 'C';
                    jogou = 1;
                    linha = i;
                    coluna = j;
                    break; //vitoria diagonal esquerda-direita, cima-baixo, 1º peça
                }

                if(jogadas[i][j]== 'C' && jogadas[i+1][j+1]==' ' && jogadas[i+2][j+2]=='C' && jogadas[i+3][j+3]=='C' && jogadas[i+2][j+1]!=' '){
                    jogadas[i+1][j+1]= 'C';
                    jogou = 1;
                    linha = i+1;
                    coluna = j+1;
                    break; //vitoria diagonal esquerda-direita, cima-baixo, 2º peça
                }

                if(jogadas[i][j]== 'C' && jogadas[i+1][j+1]=='C' && jogadas[i+2][j+2]==' ' && jogadas[i+3][j+3]=='C' && jogadas[i+3][j+2]!=' '){
                    jogadas[i+2][j+2]= 'C';
                    jogou = 1;
                    linha = i+2;
                    coluna = j+2;
                    break; //vitoria diagonal esquerda-direita, cima-baixo, 3º peça
                }

                if(jogadas[i][j]== 'C' && jogadas[i+1][j+1]=='C' && jogadas[i+2][j+2]=='C' && jogadas[i+3][j+3]==' ' && (jogadas[i+4][j+3]!=' ' || jogadas[5][j+3]==' ')){
                    jogadas[i+3][j+3]= 'C';
                    jogou = 1;
                    linha = i+3;
                    coluna = j+3;
                    break; //vitoria diagonal esquerda-direita, cima-baixo, 4º peça
                }
            }

            if(i+3<6 && j-3>=0){
                if(jogadas[i][j]== ' ' && jogadas[i+1][j-1]=='C' && jogadas[i+2][j-2]=='C' && jogadas[i+3][j-3]=='C' && jogadas[i+1][j]!= ' '){
                    jogadas[i][j]= 'C';
                    jogou = 1;
                    linha = i;
                    coluna = j;
                    break; //vitoria diagonal direita-esquerda, cima-baixo, 1º peça
                }

                if(jogadas[i][j]== 'C' && jogadas[i+1][j-1]==' ' && jogadas[i+2][j-2]=='C' && jogadas[i+3][j-3]=='C' && jogadas[i+2][j-1]!= ' '){
                    jogadas[i+1][j-1]= 'C';
                    jogou = 1;
                    linha = i+1;
                    coluna = j-1;
                    break; //vitoria diagonal direita-esquerda, cima-baixo, 2º peça
                }

                if(jogadas[i][j]== 'C' && jogadas[i+1][j-1]=='C' && jogadas[i+2][j-2]==' ' && jogadas[i+3][j-3]=='C' && jogadas[i+3][j-2]!= ' '){
                    jogadas[i+2][j-2]= 'C';
                    jogou = 1;
                    linha = i+2;
                    coluna = j-2;
                    break; //vitoria diagonal direita-esquerda, cima-baixo, 3º peça
                }

                if(jogadas[i][j]== 'C' && jogadas[i+1][j-1]=='C' && jogadas[i+2][j-2]=='C' && jogadas[i+3][j-3]==' ' && (jogadas[i+4][j-3]!= ' '|| jogadas[5][j-3] == ' ')){
                    jogadas[i+3][j-3]= 'C';
                    jogou = 1;
                    linha = i-3;
                    coluna = j+3;
                    break; //vitoria diagonal direita-esquerda, cima-baixo, 4º peça
                }
            }
            //para o PC impedir o jogador ganhar
            if(jogou == 0){
                if(j+3<7){
                    if(jogadas[i][j]== ' ' && jogadas[i][j+1]=='U' && jogadas[i][j+2]=='U' && jogadas[i][j+3]=='U' && jogadas[i+1][j]!= ' ' ){
                        jogadas[i][j] = 'C';
                        jogou = 2;
                        linha = i;
                        coluna = j;
                        break;  //impede horizontal 1º peça a contar de esquerda
                    }
                    if(jogadas[i][j]== 'U' && jogadas[i][j+1]==' ' && jogadas[i][j+2]=='U' && jogadas[i][j+3]=='U' && jogadas[i+1][j+1]!= ' '){
                        jogadas[i][j+1] = 'C';
                        jogou = 2;
                        linha = i;
                        coluna = j+1;
                        break;  //impede horizontal 2º peça
                    }
                    if(jogadas[i][j]== 'U' && jogadas[i][j+1]=='U' && jogadas[i][j+2]==' ' && jogadas[i][j+3]=='U' && jogadas[i+1][j+2]!= ' '){
                        jogadas[i][j+2] = 'C';
                        jogou = 2;
                        linha = i;
                        coluna = j+2;
                        break;  //impede horizontal 3º peça
                    }

                    if(jogadas[i][j]== 'U' && jogadas[i][j+1]=='U' && jogadas[i][j+2]=='U' && jogadas[i][j+3]==' ' && jogadas[i+1][j+3]!= ' '){
                        jogadas[i][j+3] = 'C';
                        jogou = 2;
                        linha = i;
                        coluna = j+3;
                        break;  //impede horizontal 4º peça
                    }
                }
                if(i+3<6){
                    if(jogadas[i][j]== ' ' && jogadas[i+1][j]=='U' && jogadas[i+2][j]=='U' && jogadas[i+3][j]=='U'){
                        jogadas[i][j] = 'C';
                        jogou = 2;
                        linha = i;
                        coluna = j;
                        break;  //impede vertical unica opçao, topo
                    }
                }

                if(i+3<6 && j+3<7){
                    if(jogadas[i][j]== ' ' && jogadas[i+1][j+1]=='U' && jogadas[i+2][j+2]=='U' && jogadas[i+3][j+3]=='U' && jogadas[i+1][j]!=' '){
                        jogadas[i][j]= 'C';
                        jogou = 2;
                        linha = i;
                        coluna = j;
                        break; //impede diagonal esquerda-direita, cima-baixo, 1º peça
                    }

                    if(jogadas[i][j]== 'U' && jogadas[i+1][j+1]==' ' && jogadas[i+2][j+2]=='U' && jogadas[i+3][j+3]=='U' && jogadas[i+2][j+1]!=' '){
                        jogadas[i+1][j+1]= 'C';
                        jogou = 2;
                        linha = i+1;
                        coluna = j+1;
                        break; //impede diagonal esquerda-direita, cima-baixo, 2º peça
                    }

                    if(jogadas[i][j]== 'U' && jogadas[i+1][j+1]=='U' && jogadas[i+2][j+2]==' ' && jogadas[i+3][j+3]=='U' && jogadas[i+3][j+1]!=' '){
                        jogadas[i+2][j+2]= 'C';
                        jogou = 2;
                        linha = i+2;
                        coluna = j+2;
                        break; //impede diagonal esquerda-direita, cima-baixo, 3º peça
                    }

                    if(jogadas[i][j]== 'U' && jogadas[i+1][j+1]=='U' && jogadas[i+2][j+2]=='U' && jogadas[i+3][j+3]==' ' && (jogadas[i+4][j+1]!=' ' || jogadas[5][j+1]==' ')){
                        jogadas[i+3][j+3]= 'C';
                        jogou = 2;
                        linha = i+3;
                        coluna = j+3;
                        break; //impede diagonal esquerda-direita, cima-baixo, 4º peça
                    }
                }

                if(i+3<6 && j-3>=0){
                    if(jogadas[i][j]== ' ' && jogadas[i+1][j-1]=='U' && jogadas[i+2][j-2]=='U' && jogadas[i+3][j-3]=='U' && jogadas[i+1][j]!= ' '){
                        jogadas[i][j]= 'C';
                        jogou = 2;
                        linha = i;
                        coluna = j;
                        break; //impede diagonal direita-esquerda, cima-baixo, 1º peça
                    }

                    if(jogadas[i][j]== 'U' && jogadas[i+1][j-1]==' ' && jogadas[i+2][j-2]=='U' && jogadas[i+3][j-3]=='U' && jogadas[i+2][j-1]!= ' '){
                        jogadas[i+1][j-1]= 'C';
                        jogou = 2;
                        linha = i+1;
                        coluna = j-1;
                        break; //impede diagonal direita-esquerda, cima-baixo, 2º peça
                    }

                    if(jogadas[i][j]== 'U' && jogadas[i+1][j-1]=='U' && jogadas[i+2][j-2]==' ' && jogadas[i+3][j-3]=='U' && jogadas[i+3][j-2]!= ' '){
                        jogadas[i+2][j-2]= 'C';
                        jogou = 2;
                        linha = i+2;
                        coluna = j-2;
                        break; //impede diagonal direita-esquerda, cima-baixo, 3º peça
                    }

                    if(jogadas[i][j]== 'U' && jogadas[i+1][j-1]=='U' && jogadas[i+2][j-2]=='U' && jogadas[i+3][j-3]==' ' && (jogadas[i+4][j-3]!= ' '|| jogadas[5][j-3] == ' ')){
                        jogadas[i+3][j-3]= 'C';
                        jogou = 2;
                        linha = i+3;
                        coluna = j-3;
                        break; //impede diagonal direita-esquerda, cima-baixo, 4º peça
                    }
                }
            }
        }
    }


    if(jogou == 0){ // caso nenhuma das situaçoes anteriores aconteça joga de forma aleatoria
        do{
            linha = 5;
            srand(time(NULL));
            coluna = rand() % 7;
            while(jogadas[linha][coluna] != ' '){
                linha--;
            }
        }while(jogadas[0][coluna] != ' ');

    }

    jogadas[linha][coluna] = 'C';
    ultima_linha_jogada_C = linha;
    ultima_coluna_jogada_C = coluna;
    guarda_jogadas(ultima_linha_jogada_C,ultima_coluna_jogada_C,'C');


    Njogadas++;
    tabuleiro();
    if(vitoria() == 1){
        ofstream file("jogadas.txt",ios::trunc);
        file.close();
        ofstream file2("Saved_game.txt",ios::trunc);
        file2.close();
        ofstream file3("Game_info.txt",ios::trunc);
        file3.close();
        Nderrotas++;
        cout << "PC ganhou!" << endl;
        return true;
    }

    else return false;
}
//----------------------------------------------------------------------------------------------------
void CJogo::mostra_Nvitorias_player(){
    cout << endl;
    mostra_nome(player_name);
    cout << " tem " << Nvitorias << " vitorias!" << endl;
}
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
void CJogo::mostra_Nderrotas(){
    cout << endl;
    cout << "PC tem " << Nderrotas << " vitorias!" << endl;
}

//----------------------------------------------------------------------------------------------------
void CJogo::reset_tabuleiro(){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            jogadas[i][j] = ' ';
        }
    }
    Njogadas = 0;
}
//----------------------------------------------------------------------------------------------------
void CJogo::reset_jogo(){
    Njogadas = 0;
    Nvitorias = 0;
    Nvitorias2 = 0;
    Nderrotas = 0;
    Nempates = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            jogadas[i][j] = ' ';
        }
    }
}
//----------------------------------------------------------------------------------------------------
void CJogo::back(){ // volta duas jogadas atrás
    Njogadas = Njogadas-2;
    jogadas[ultima_linha_jogada_C][ultima_coluna_jogada_C] = ' ';
    jogadas[ultima_linha_jogada_U][ultima_coluna_jogada_U] = ' ';
}
//----------------------------------------------------------------------------------------------------
void CJogo::atualiza_top10(int numJogadas, string nome){
    CNoLista *novo = new CNoLista; // aloca espaço para o novo nó
    CNoLista *atual, *anterior;


    novo->data = numJogadas;
    novo->name = nome;// inicializa os dados do novo nó
    novo->next = NULL;
    if (cabeca == NULL) { // se lista vazia então este é o primeiro nó
        cabeca = novo;
        return;
    }
    atual = cabeca;
    anterior = NULL;
    while((atual!=NULL) && (atual->data<numJogadas)) { // procura a posição de
        anterior = atual; // inserção
        atual = atual->next;
    }
    if (anterior == NULL) // se o ponteiro para o elemento anterior
        cabeca = novo; // for NULL então insere no princípio
    else
        anterior->next=novo; // caso contrário insere entre dois nós
    novo->next = atual; // em qualquer dos casos atualiza o ponteiro



} // para o próximo elemento no novo nó.

//----------------------------------------------------------------------------------------------------
void CJogo::mostra_top10(){
    CNoLista *atual = cabeca;
    int i = 1;
    if (cabeca == NULL) cout << "Lista Vazia..." << endl;
    else {
        cout << "*****************************************TOP10*************************************************" << endl;
        while (atual != NULL && i <= 10) {
            cout << i << " -> " << atual->name << " -> " << atual->data << endl; // tarefa a fazer em cada nó
            atual = atual->next;
            i++;
        }
        cout << "***********************************************************************************************" << endl;
    }

    escreve_Top10_file(); // escreve no ficheiro
}
//---------------------------------------------------------------------------------------------------
void CJogo::escreve_Top10_file(){
    CNoLista *atual = cabeca;
    int i = 1;
    ofstream file("Top10.txt");
    if(!file.is_open()){
        cout << "Impossivel abrir ficheiro" << endl;
    }
    while(atual != NULL && i <= 10){
        file << atual->name << " " << atual->data << endl;
        atual = atual->next;
        i++;
    }
    file.close();
}

//---------------------------------------------------------------------------------------------------
int CJogo::guarda_jogo_em_ficheiro(){
    int linhas;
    int colunas;

    ofstream file("Saved_game.txt");

    if(!file.is_open()){
        cerr << "Nao foi possivel abrir o ficheiro!" << endl;
        return -1;
    }

    for(linhas = 0; linhas < 6; linhas++){
        for(colunas = 0; colunas < 7; colunas++){
            if(jogadas[linhas][colunas] == 'U'){
                file << linhas << ' ' << colunas << ' ' << 'U' << endl;
            }
            else if(jogadas[linhas][colunas] == 'C'){
                file << linhas << ' ' << colunas << ' ' <<'C' << endl;
            }
        }
    }
    file.close();
    return 0;
}
//----------------------------------------------------------------------------------------------------
void CJogo::suspende(){
    guarda_jogo_em_ficheiro();
    guarda_info_file();
    menu();
}
//----------------------------------------------------------------------------------------------------
void CJogo::recomeca_jogo(){
    int linhas;
    int colunas;
    char c;
    string jogada, info;

    ifstream file("Saved_game.txt");

    if(!file.is_open()){
        cout << "Ficheiro nao encontrado!" << endl;
        return;
    }



    while(getline(file,jogada)){

        if(jogada != " "){
            stringstream plays(jogada);
            plays >> linhas >> colunas >> c;
            jogadas[linhas][colunas] = c;
        }

    }
    file.close();


    ifstream file2("Game_info.txt");
    while(getline(file2,info)){
        stringstream game(info);
        game >> player_name >> nivel >> Njogadas >> Nvitorias >> Nderrotas >> Nempates >> primeiro;
    }
    file2.close();
    if(primeiro == 2) primeiro = 1;
    tabuleiro();
    jogar();
}
//----------------------------------------------------------------------------------------------------
void CJogo::le_top10_file(){
    string top;
    string nome;
    int numjogadas;
    ifstream file("Top10.txt");

    while(getline(file,top))
        if(top != " "){
            stringstream top_10(top);
            top_10 >> nome >> numjogadas;
            atualiza_top10(numjogadas,nome);
        }
    file.close();
}
//----------------------------------------------------------------------------------------------------
void CJogo::guarda_info_file(){
    ofstream file("Game_info.txt");
    file << player_name << ' ' << nivel << ' ' << Njogadas << ' ' << Nvitorias<< ' ' << Nderrotas << ' ' << Nempates << ' ' << primeiro;
    file.close();
}
//----------------------------------------------------------------------------------------------------
// miniprojeto 2
void CJogo::jogar_multiplayer(){
    srand(time(NULL));
    primeiro = rand() % 2;
    mostra_Nvitorias_player();
    cout << endl;
    mostra_Nvitorias_player2();
    cout << endl;

    if(primeiro == 0){
        for(int i = Njogadas; i<42;i++){
            cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: ";
            mostra_nome(player_name);
            if(jogada_jogador()){


                break;
            }
            cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: ";
            mostra_nome(player2_name);
            cout << endl << endl;
            if(jogada_jogador2()){


                break;
            }
        }
    }
    else if(primeiro == 1){
        for(int i = Njogadas; i<42;i++){
            cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: ";
            mostra_nome(player2_name);
            if(jogada_jogador2()){

                break;
            }
            cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: ";
            mostra_nome(player_name);
            cout << endl << endl;
            if(jogada_jogador()){


                break;
            }
        }
    }
    char b;
    cout << endl << "Jogar novamente? s/n" << endl;
    cin >> b;
    switch (b) {
    case 's':
        reset_tabuleiro();
        jogar_multiplayer();
        break;
    case 'n':
        reset_jogo();
        menu();
    default:
        break;
    }
}
//----------------------------------------------------------------------------------------------------
void CJogo::inserirNome2(){
    do {
        cin.ignore();
        cout << "Jogador 2 insira o nome: ";
        getline(cin,player2_name);
        if(player2_name == "PC"){
            cout << "Nome invalido por favor inserir outro nome!" << endl << endl;
        }
    }while (player2_name == "PC");
}
//----------------------------------------------------------------------------------------------------
bool CJogo::jogada_jogador2(){
    int j = 5;
    int i;

    cout << endl << "Se quiser voltar atras prima 0.             Se quiser sair do jogo prima 8." << endl << endl;
    cout << "Escolha a coluna em que quer jogar: ";
    cin >> i;
    while(jogadas[j][i-1] != ' '){
        j--;
    }
    if (i == 0) back();

    if((jogadas[0][i-1] != ' ' && i-1 >= 0)|| i < 0 || i > 8){
        cout << "Jogada impossivel, escolha outra coluna" << endl;
        jogada_jogador2();
    }
    else if(i-1 >= 0 && i-1 < 7 ) jogadas[j][i-1] = 'C';
    ultima_linha_jogada_U = j;
    ultima_coluna_jogada_U = i-1;
    Njogadas++;
    tabuleiro();
    if(i == 8){
        suspende();
    }
    if(vitoria()==1){

        Nvitorias2++;
        mostra_nome(player2_name);
        cout << " ganhou" << endl;
        atualiza_top10(Njogadas,player2_name);

        return true;
    }
    else return false;
}
//----------------------------------------------------------------------------------------------------
void CJogo::mostra_Nvitorias_player2(){
    cout << endl;
    mostra_nome(player2_name);
    cout << " tem " << Nvitorias2 << " vitorias!" << endl;
}
//----------------------------------------------------------------------------------------------------

void CJogo::guarda_jogadas(int linha, int coluna, char letra){
    ofstream file("jogadas.txt", ios::app);

    file << linha << ' ' << coluna << ' ' << letra << endl;

    file.close();

}
//---------------------------------------------------------------------------------------------------
void CJogo::mostra_jogadas(){
    reset_tabuleiro();
    string play;
    int linhas, colunas;
    char c;
    Njogadas = 0;
    ifstream file("jogadas.txt");
    while(getline(file,play) && Njogadas < auxNjogadas){
        stringstream plays(play);
        plays >> linhas >> colunas >> c;
        jogadas[linhas][colunas] = c;
        tabuleiro();
        Njogadas++;

        char ans;

        cout << "Continuar a jogar a partir desta jogada?(1-sim,outro-nao)" << endl;

        cin >> ans;
        ans = ans-48;
        if(ans == 1){
            if(jogadas[linhas][colunas] == 'U'){
                primeiro = 2;
            }
            else if(jogadas[linhas][colunas] == 'C'){
                primeiro = 1;
            }
            jogar();
            break;
        }

    }
    primeiro = 1;
    jogar();
}

//----------------------------------------------------------------------------------------------------
bool CJogo::elementar_PC2(){
    int linha; //colunas
    int coluna = 5; //linhas
    cout << endl;
    do{
        linha = 5;
        srand(time(NULL));
        coluna = rand() % 7;
        while(jogadas[linha][coluna] != ' '){
            linha--;
        }
    }while(jogadas[0][coluna] != ' ');

    jogadas[linha][coluna] = 'U';
    ultima_linha_jogada_C = linha;
    ultima_coluna_jogada_C = coluna;
    Njogadas++;

    tabuleiro();
    if(vitoria()==2){
        cout << "PC2 ganhou!" << endl;
        vitorias_PC2++;
        Nderrotas++;
        return true;
    }
    else return false;
}
//----------------------------------------------------------------------------------------------------
bool CJogo::basico_PC2(){
    int coluna; // colunas
    int linha; // linhas
    bool jogou = false;
    cout << endl;
    for(int i=0;i<6; i++){
        for(int j=0;j<7;j++){
            if(j+3<7){
                if(jogadas[i][j]== ' ' && jogadas[i][j+1]=='U' && jogadas[i][j+2]=='U' && jogadas[i][j+3]=='U' && jogadas[i+1][j]!= ' ' ){
                    jogadas[i][j] = 'U';
                    linha = i;
                    coluna = j;
                    jogou = true;
                    break;  //ganha horizontal 1º peça a contar de esquerda
                }
                if(jogadas[i][j]== 'U' && jogadas[i][j+1]==' ' && jogadas[i][j+2]=='U' && jogadas[i][j+3]=='U' && jogadas[i+1][j+1]!= ' '){
                    jogadas[i][j+1] = 'U';
                    linha = i;
                    coluna = j+1;
                    jogou = true;
                    break;  //ganha horizontal 2º peça
                }
                if(jogadas[i][j]== 'U' && jogadas[i][j+1]=='U' && jogadas[i][j+2]==' ' && jogadas[i][j+3]=='U' && jogadas[i+1][j+2]!= ' '){
                    jogadas[i][j+2] = 'U';
                    linha = i;
                    coluna = j+2;
                    jogou = true;
                    break;  //ganha horizontal 3º peça
                }

                if(jogadas[i][j]== 'U' && jogadas[i][j+1]=='U' && jogadas[i][j+2]=='U' && jogadas[i][j+3]==' ' && jogadas[i+1][j+3]!= ' '){
                    jogadas[i][j+3] = 'U';
                    linha = i;
                    coluna = j+3;
                    jogou = true;
                    break;  //ganha horizontal 4º peça
                }
            }
            if(i+3<6){
                if(jogadas[i][j]== ' ' && jogadas[i+1][j]=='U' && jogadas[i+2][j]=='U' && jogadas[i+3][j]=='U'){
                    jogadas[i][j] = 'U';
                    linha = i;
                    coluna = j;
                    jogou = true;
                    break;  //ganha vertical unica opçao, topo
                }
            }

            if(i+3<6 && j+3<7){
                if(jogadas[i][j]== ' ' && jogadas[i+1][j+1]=='U' && jogadas[i+2][j+2]=='U' && jogadas[i+3][j+3]=='U' && jogadas[i+1][j]!=' '){
                    jogadas[i][j]= 'U';
                    linha = i;
                    coluna = j;
                    jogou = true;
                    break; //vitoria diagonal esquerda-direita, cima-baixo, 1º peça
                }

                if(jogadas[i][j]== 'U' && jogadas[i+1][j+1]==' ' && jogadas[i+2][j+2]=='U' && jogadas[i+3][j+3]=='U' && jogadas[i+2][j+1]!=' '){
                    jogadas[i+1][j+1]= 'U';
                    linha = i+1;
                    coluna = j+1;
                    jogou = true;
                    break; //vitoria diagonal esquerda-direita, cima-baixo, 2º peça
                }

                if(jogadas[i][j]== 'U' && jogadas[i+1][j+1]=='U' && jogadas[i+2][j+2]==' ' && jogadas[i+3][j+3]=='U' && jogadas[i+3][j+2]!=' '){
                    jogadas[i+2][j+2]= 'U';
                    linha = i+2;
                    coluna = j+2;
                    jogou = true;
                    break; //vitoria diagonal esquerda-direita, cima-baixo, 3º peça
                }

                if(jogadas[i][j]== 'U' && jogadas[i+1][j+1]=='U' && jogadas[i+2][j+2]=='U' && jogadas[i+3][j+3]==' ' && (jogadas[i+4][j+3]!=' ' || jogadas[5][j+3]==' ')){
                    jogadas[i+3][j+3]= 'U';
                    linha = i+3;
                    coluna = j+3;
                    jogou = true;
                    break; //vitoria diagonal esquerda-direita, cima-baixo, 4º peça
                }
            }

            if(i+3<6 && j-3>=0){
                if(jogadas[i][j]== ' ' && jogadas[i+1][j-1]=='U' && jogadas[i+2][j-2]=='U' && jogadas[i+3][j-3]=='U' && jogadas[i+1][j]!= ' '){
                    jogadas[i][j]= 'U';
                    linha = i;
                    coluna = j;
                    jogou = true;
                    break; //vitoria diagonal direita-esquerda, cima-baixo, 1º peça
                }

                if(jogadas[i][j]== 'U' && jogadas[i+1][j-1]==' ' && jogadas[i+2][j-2]=='U' && jogadas[i+3][j-3]=='U' && jogadas[i+2][j-1]!= ' '){
                    jogadas[i+1][j-1]= 'U';
                    linha = i+1;
                    coluna = j-1;
                    jogou = true;
                    break; //vitoria diagonal direita-esquerda, cima-baixo, 2º peça
                }

                if(jogadas[i][j]== 'U' && jogadas[i+1][j-1]=='U' && jogadas[i+2][j-2]==' ' && jogadas[i+3][j-3]=='U' && jogadas[i+3][j-2]!= ' '){
                    jogadas[i+2][j-2]= 'U';
                    linha = i+2;
                    coluna = j-2;
                    jogou = true;
                    break; //vitoria diagonal direita-esquerda, cima-baixo, 3º peça
                }

                if(jogadas[i][j]== 'U' && jogadas[i+1][j-1]=='U' && jogadas[i+2][j-2]=='U' && jogadas[i+3][j-3]==' ' && (jogadas[i+4][j-3]!= ' '|| jogadas[5][j-3] == ' ')){
                    jogadas[i+3][j-3]= 'U';
                    linha = i+3;
                    coluna = j-3;
                    jogou = true;
                    break; //vitoria diagonal direita-esquerda, cima-baixo, 4º peça
                }
            }
        }
    }


    if(jogou == false){ // caso nenhuma das situaçoes anteriores aconteça joga de forma aleatoria
        do{
            linha = 5;
            srand(time(NULL));
            coluna = rand() % 7;
            while(jogadas[linha][coluna] != ' '){
                linha--;
            }
        }while(jogadas[0][coluna] != ' ');
    }

    jogadas[linha][coluna] = 'U';
    ultima_linha_jogada_C = linha;
    ultima_coluna_jogada_C = coluna;


    Njogadas++;
    tabuleiro();
    if(vitoria() == 2){
        vitorias_PC2++;
        cout << "PC2 ganhou" << endl<< endl;
        return true;
    }
    else{

        return false;
    }
}
//----------------------------------------------------------------------------------------------------
bool CJogo::medio_PC2(){

    int coluna; // colunas
    int linha; // linhas
    bool jogou = false;
    cout << endl;

    for(int i=0;i<6; i++){
        for(int j=0;j<7;j++){
            // joga para ganhar
            if(j+3<7){
                if(jogadas[i][j]== ' ' && jogadas[i][j+1]=='U' && jogadas[i][j+2]=='U' && jogadas[i][j+3]=='U' && jogadas[i+1][j]!= ' ' ){
                    jogadas[i][j] = 'U';
                    jogou = true;
                    linha = i;
                    coluna = j;
                    break;  //ganha horizontal 1º peça a contar de esquerda
                }
                if(jogadas[i][j]== 'U' && jogadas[i][j+1]==' ' && jogadas[i][j+2]=='U' && jogadas[i][j+3]=='U' && jogadas[i+1][j+1]!= ' '){
                    jogadas[i][j+1] = 'U';
                    jogou = true;
                    linha = i;
                    coluna = j+1;
                    break;  //ganha horizontal 2º peça
                }
                if(jogadas[i][j]== 'U' && jogadas[i][j+1]=='U' && jogadas[i][j+2]==' ' && jogadas[i][j+3]=='U' && jogadas[i+1][j+2]!= ' '){
                    jogadas[i][j+2] = 'U';
                    jogou = true;
                    linha = i;
                    coluna = j+2;
                    break;  //ganha horizontal 3º peça
                }

                if(jogadas[i][j]== 'U' && jogadas[i][j+1]=='U' && jogadas[i][j+2]=='U' && jogadas[i][j+3]==' ' && jogadas[i+1][j+3]!= ' '){
                    jogadas[i][j+3] = 'U';
                    jogou = true;
                    linha = i;
                    coluna = j+3;
                    break;  //ganha horizontal 4º peça
                }
            }
            if(i+3<6){
                if(jogadas[i][j]== ' ' && jogadas[i+1][j]=='U' && jogadas[i+2][j]=='U' && jogadas[i+3][j]=='U'){
                    jogadas[i][j] = 'U';
                    jogou = true;
                    linha = i;
                    coluna = j;
                    break;  //ganha vertical unica opçao, topo
                }
            }

            if(i+3<6 && j+3<7){
                if(jogadas[i][j]== ' ' && jogadas[i+1][j+1]=='U' && jogadas[i+2][j+2]=='U' && jogadas[i+3][j+3]=='U' && jogadas[i+1][j]!=' '){
                    jogadas[i][j]= 'U';
                    jogou = true;
                    linha = i;
                    coluna = j;
                    break; //impede diagonal esquerda-direita, cima-baixo, 1º peça
                }

                if(jogadas[i][j]== 'U' && jogadas[i+1][j+1]==' ' && jogadas[i+2][j+2]=='U' && jogadas[i+3][j+3]=='U' && jogadas[i+2][j+1]!=' '){
                    jogadas[i+1][j+1]= 'U';
                    jogou = true;
                    linha = i+1;
                    coluna = j+1;
                    break; //ganha diagonal esquerda-direita, cima-baixo, 2º peça
                }

                if(jogadas[i][j]== 'U' && jogadas[i+1][j+1]=='U' && jogadas[i+2][j+2]==' ' && jogadas[i+3][j+3]=='U' && jogadas[i+3][j+2]!=' '){
                    jogadas[i+2][j+2]= 'U';
                    jogou = true;
                    linha = i+2;
                    coluna = j+2;
                    break; //ganha diagonal esquerda-direita, cima-baixo, 3º peça
                }

                if(jogadas[i][j]== 'U' && jogadas[i+1][j+1]=='U' && jogadas[i+2][j+2]=='U' && jogadas[i+3][j+3]==' ' && (jogadas[i+4][j+3]!=' ' || jogadas[5][j+3]==' ')){
                    jogadas[i+3][j+3]= 'U';
                    jogou = true;
                    linha = i+3;
                    coluna = j+3;
                    break; //ganha diagonal esquerda-direita, cima-baixo, 4º peça
                }
            }

            if(i+3<6 && j-3>=0){
                if(jogadas[i][j]== ' ' && jogadas[i+1][j-1]=='U' && jogadas[i+2][j-2]=='U' && jogadas[i+3][j-3]=='U' && jogadas[i+1][j]!= ' '){
                    jogadas[i][j]= 'U';
                    jogou = true;
                    linha = i;
                    coluna = j;
                    break; //ganha diagonal direita-esquerda, cima-baixo, 1º peça
                }

                if(jogadas[i][j]== 'U' && jogadas[i+1][j-1]==' ' && jogadas[i+2][j-2]=='U' && jogadas[i+3][j-3]=='U' && jogadas[i+2][j-1]!= ' '){
                    jogadas[i+1][j-1]= 'U';
                    jogou = true;
                    linha = i+1;
                    coluna = j-1;
                    break; //ganha diagonal direita-esquerda, cima-baixo, 2º peça
                }

                if(jogadas[i][j]== 'U' && jogadas[i+1][j-1]=='U' && jogadas[i+2][j-2]==' ' && jogadas[i+3][j-3]=='U' && jogadas[i+3][j-2]!= ' '){
                    jogadas[i+2][j-2]= 'U';
                    jogou = true;
                    linha = i+2;
                    coluna = j-2;
                    break; //ganha diagonal direita-esquerda, cima-baixo, 3º peça
                }

                if(jogadas[i][j]== 'U' && jogadas[i+1][j-1]=='U' && jogadas[i+2][j-2]=='U' && jogadas[i+3][j-3]==' ' && (jogadas[i+4][j-3]!= ' '|| jogadas[5][j-3] == ' ')){
                    jogadas[i+3][j-3]= 'U';
                    jogou = true;
                    linha = i+3;
                    coluna = j-3;
                    break; //ganha diagonal direita-esquerda, cima-baixo, 4º peça
                }
            }
            // caso nao consiga jogar para ganhar tenta impedir que o outro jogador ganhe
            if(jogou == false){
                if(j+3<7){
                    if(jogadas[i][j]== ' ' && jogadas[i][j+1]=='C' && jogadas[i][j+2]=='C' && jogadas[i][j+3]=='C' && jogadas[i+1][j]!= ' ' ){
                        jogadas[i][j] = 'U';
                        jogou = true;
                        linha = i;
                        coluna = j;
                        break;  //impede horizontal 1º peça a contar de esquerda
                    }
                    if(jogadas[i][j]== 'C' && jogadas[i][j+1]==' ' && jogadas[i][j+2]=='C' && jogadas[i][j+3]=='C' && jogadas[i+1][j+1]!= ' '){
                        jogadas[i][j+1] = 'U';
                        jogou = true;
                        linha = i;
                        coluna = j+1;
                        break;  //impede horizontal 2º peça
                    }
                    if(jogadas[i][j]== 'C' && jogadas[i][j+1]=='C' && jogadas[i][j+2]==' ' && jogadas[i][j+3]=='C' && jogadas[i+1][j+2]!= ' '){
                        jogadas[i][j+2] = 'U';
                        jogou = true;
                        linha = i;
                        coluna = j+2;
                        break;  //impede horizontal 3º peça
                    }

                    if(jogadas[i][j]== 'C' && jogadas[i][j+1]=='C' && jogadas[i][j+2]=='C' && jogadas[i][j+3]==' ' && jogadas[i+1][j+3]!= ' '){
                        jogadas[i][j+3] = 'U';
                        jogou = true;
                        linha = i;
                        coluna = j+3;
                        break;  //impede horizontal 4º peça
                    }
                }
                if(i+3<6){
                    if(jogadas[i][j]== ' ' && jogadas[i+1][j]=='C' && jogadas[i+2][j]=='C' && jogadas[i+3][j]=='C'){
                        jogadas[i][j] = 'U';
                        jogou = true;
                        linha = i;
                        coluna = j;
                        break;  //impede vertical unica opçao, topo
                    }
                }

                if(i+3<6 && j+3<7){
                    if(jogadas[i][j]== ' ' && jogadas[i+1][j+1]=='C' && jogadas[i+2][j+2]=='C' && jogadas[i+3][j+3]=='C' && jogadas[i+1][j]!=' '){
                        jogadas[i][j]= 'U';
                        jogou = true;
                        linha = i;
                        coluna = j;
                        break; //impede diagonal esquerda-direita, cima-baixo, 1º peça
                    }

                    if(jogadas[i][j]== 'C' && jogadas[i+1][j+1]==' ' && jogadas[i+2][j+2]=='C' && jogadas[i+3][j+3]=='C' && jogadas[i+2][j+1]!=' '){
                        jogadas[i+1][j+1]= 'U';
                        jogou = true;
                        linha = i+1;
                        coluna = j+1;
                        break; //impede diagonal esquerda-direita, cima-baixo, 2º peça
                    }

                    if(jogadas[i][j]== 'C' && jogadas[i+1][j+1]=='C' && jogadas[i+2][j+2]==' ' && jogadas[i+3][j+3]=='C' && jogadas[i+3][j+1]!=' '){
                        jogadas[i+2][j+2]= 'U';
                        jogou = true;
                        linha = i+2;
                        coluna = j+2;
                        break; //impede diagonal esquerda-direita, cima-baixo, 3º peça
                    }

                    if(jogadas[i][j]== 'C' && jogadas[i+1][j+1]=='C' && jogadas[i+2][j+2]=='C' && jogadas[i+3][j+3]==' ' && (jogadas[i+4][j+1]!=' ' || jogadas[5][j+1]==' ')){
                        jogadas[i+3][j+3]= 'U';
                        jogou = true;
                        linha = i+3;
                        coluna = j+3;
                        break; //impede diagonal esquerda-direita, cima-baixo, 4º peça
                    }
                }

                if(i+3<6 && j-3>=0){
                    if(jogadas[i][j]== ' ' && jogadas[i+1][j-1]=='C' && jogadas[i+2][j-2]=='C' && jogadas[i+3][j-3]=='C' && jogadas[i+1][j]!= ' '){
                        jogadas[i][j]= 'U';
                        jogou = true;
                        linha = i;
                        coluna = j;
                        break; //impede diagonal direita-esquerda, cima-baixo, 1º peça
                    }

                    if(jogadas[i][j]== 'C' && jogadas[i+1][j-1]==' ' && jogadas[i+2][j-2]=='C' && jogadas[i+3][j-3]=='C' && jogadas[i+2][j-1]!= ' '){
                        jogadas[i+1][j-1]= 'U';
                        jogou = true;
                        linha = i+1;
                        coluna = j-1;
                        break; //impede diagonal direita-esquerda, cima-baixo, 2º peça
                    }

                    if(jogadas[i][j]== 'C' && jogadas[i+1][j-1]=='C' && jogadas[i+2][j-2]==' ' && jogadas[i+3][j-3]=='C' && jogadas[i+3][j-2]!= ' '){
                        jogadas[i+2][j-2]= 'U';
                        jogou = true;
                        linha = i+2;
                        coluna = j-2;
                        break; //impede diagonal direita-esquerda, cima-baixo, 3º peça
                    }

                    if(jogadas[i][j]== 'C' && jogadas[i+1][j-1]=='C' && jogadas[i+2][j-2]=='C' && jogadas[i+3][j-3]==' ' && (jogadas[i+4][j-3]!= ' '|| jogadas[5][j-3] == ' ')){
                        jogadas[i+3][j-3]= 'U';
                        jogou = true;
                        linha = i-3;
                        coluna = j+3;
                        break; //impede diagonal direita-esquerda, cima-baixo, 4º peça
                    }
                }
            }
        }
    }

    if(jogou == false){ // caso nenhuma das situaçoes anteriores aconteça joga de forma aleatoria
        do{
            linha = 5;
            srand(time(NULL));
            coluna = rand() % 7;
            while(jogadas[linha][coluna] != ' '){
                linha--;
            }
        }while(jogadas[0][coluna] != ' ');

    }

    jogadas[linha][coluna] = 'U';
    ultima_linha_jogada_C = linha;
    ultima_coluna_jogada_C = coluna;


    Njogadas++;
    tabuleiro();
    if(vitoria() == 2){
        vitorias_PC2++;
        cout << "PC2 ganhou!" << endl;

        return true;
    }

    else return false;

}
//----------------------------------------------------------------------------------------------------
void CJogo::mostra_vitorias_pc2(){
    cout << "O PC2 tem " << vitorias_PC2 << " vitorias" << endl;
}

//----------------------------------------------------------------------------------------------------
void CJogo::jogar_pc_vs_pc(){
    escolher_dificuldade_pc_vs_pc();
    comeca();



    switch (nivel) {
    case 1:


        if(primeiro == 1){
            for(int i = Njogadas; i<42;i++){
                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC2";
                cout << endl << endl;
                if(elementar_PC2()){
                    cout << endl << "End of demonstration" << endl;
                    menu();

                    break;
                }
                cout << "Prima ENTER para continuar" << endl;
                cin.ignore();

                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC";
                if(elementar()){
                    cout << endl << "End of demonstration" << endl;
                    menu();
                    break;
                }
                cout << "Prima ENTER para continuar" << endl;
                cin.ignore();
            }
        }
        else if(primeiro == 2){
            for(int i = Njogadas; i<42;i++){
                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC";
                if(elementar()){
                    cout << endl << "End of demonstration" << endl;
                    menu();
                    break;
                }
                cout << "Prima ENTER para continuar" << endl;
                cin.ignore();

                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC2";
                cout << endl << endl;
                if(elementar_PC2()){
                    cout << endl << "End of demonstration" << endl;
                    menu();
                    break;
                }
                cin.ignore();
                cout << "Prima ENTER para continuar" << endl;
            }
        }
        if(empate()){
            cout << endl << "End of demonstration" << endl;
            menu();
            break;
        }


    case 2:


        if(primeiro == 1){
            for(int i = Njogadas; i<42;i++){
                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC2";
                cout << endl << endl;
                if(basico_PC2()){
                    cout << endl << "End of demonstration" << endl;
                    menu();
                    break;
                }
                cout << "Prima ENTER para continuar" << endl;
                cin.ignore();

                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC";
                if(basico()){
                    cout << endl << "End of demonstration" << endl;
                    menu();
                    break;
                }
                cout << "Prima ENTER para continuar" << endl;
                cin.ignore();
            }
        }
        else if(primeiro == 2){
            for(int i = Njogadas; i<42;i++){
                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC";
                if(basico()){
                    cout << endl << "End of demonstration" << endl;
                    menu();
                    break;
                }
                cout << "Prima ENTER para continuar" << endl;
                cin.ignore();
                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC2";
                cout << endl << endl;
                if(basico_PC2()){
                    cout << endl << "End of demonstration" << endl;
                    menu();
                    break;
                }
                cout << "Prima ENTER para continuar" << endl;
                cin.ignore();
            }
        }
        if(empate()){

            cout << endl << "End of demonstration" << endl;
            menu();

            break;
        }
    case 3:


        if(primeiro == 1){
            for(int i = Njogadas; i<42;i++){
                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC2";
                cout << endl << endl;
                if(medio_PC2()){
                    cout << endl << "End of demonstration" << endl;
                    menu();
                    break;
                }
                cout << "Prima ENTER para continuar" << endl;
                cin.ignore();
                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC";
                if(medio()){
                    cout << endl << "End of demonstration" << endl;
                    menu();
                    break;
                }
                cout << "Prima ENTER para continuar" << endl;
                cin.ignore();
            }
        }
        else if(primeiro == 2){
            for(int i = Njogadas; i<42;i++){
                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC";
                if(medio()){
                    cout << endl << "End of demonstration" << endl;
                    menu();
                    break;
                }
                cout << "Prima ENTER para continuar" << endl;
                cin.ignore();
                cout << "Numero de jogadas:" << mostra_Njogadas() << setw(15) << "Jogador: PC2";
                cout << endl << endl;
                if(medio_PC2()){

                    cout << endl << "End of demonstration" << endl;
                    menu();
                    break;
                }
                cout << "Prima ENTER para continuar" << endl;
                cin.ignore();
            }
        }
        if(empate()){

            cout << "Empate" << endl;
            cout << endl << "End of demonstration" << endl;
            menu();
            break;
        }


    default:
        break;

    }

}
//----------------------------------------------------------------------------------------------------
bool CJogo::avancado(){


    int existe =1;
    for(int i=0;i<6; i++){
        for(int j=0;j<7;j++){
            if(Njogadas == 0){
                jogadas[5][3] = 'C';
                existe=3;
            }
            if(j+3<7){
                if(jogadas[i][j]== ' ' && jogadas[i][j+1]=='C' && jogadas[i][j+2]=='C' && jogadas[i][j+3]=='C' && jogadas[i+1][j]!= ' ' ){
                    jogadas[i][j] = 'C';
                    ultima_linha_jogada_C = i;
                    ultima_coluna_jogada_C = j;
                    existe=0;
                    break;  //ganha horizontal 1º peça a contar de esquerda
                }
                if(jogadas[i][j]== 'C' && jogadas[i][j+1]==' ' && jogadas[i][j+2]=='C' && jogadas[i][j+3]=='C' && jogadas[i+1][j+1]!= ' '){
                    jogadas[i][j+1] = 'C';
                    ultima_linha_jogada_C = i;
                    ultima_coluna_jogada_C = j+1;
                    existe=0;
                    break;  //ganha horizontal 2º peça
                }
                if(jogadas[i][j]== 'C' && jogadas[i][j+1]=='C' && jogadas[i][j+2]==' ' && jogadas[i][j+3]=='C' && jogadas[i+1][j+2]!= ' '){
                    jogadas[i][j+2] = 'C';
                    ultima_linha_jogada_C = i;
                    ultima_coluna_jogada_C = j+2;
                    existe=0;
                    break;  //ganha horizontal 3º peça
                }

                if(jogadas[i][j]== 'C' && jogadas[i][j+1]=='C' && jogadas[i][j+2]=='C' && jogadas[i][j+3]==' ' && jogadas[i+1][j+3]!= ' '){
                    jogadas[i][j+3] = 'C';
                    ultima_linha_jogada_C = i;
                    ultima_coluna_jogada_C = j+3;
                    existe=0;
                    break;  //ganha horizontal 4º peça
                }
            }
            if(existe==1){
                if(i+3<6){
                    if(jogadas[i][j]== ' ' && jogadas[i+1][j]=='C' && jogadas[i+2][j]=='C' && jogadas[i+3][j]=='C'){
                        jogadas[i][j] = 'C';
                        ultima_linha_jogada_C = i;
                        ultima_coluna_jogada_C = j;
                        existe=0;
                        break;  //ganha vertical unica opçao, topo
                    }
                }
            }

            if(existe==1){
                if(i+3<6 && j+3<7){
                    if(jogadas[i][j]== ' ' && jogadas[i+1][j+1]=='C' && jogadas[i+2][j+2]=='C' && jogadas[i+3][j+3]=='C' && jogadas[i+1][j]!=' '){
                        jogadas[i][j]= 'C';
                        ultima_linha_jogada_C = i;
                        ultima_coluna_jogada_C = j;
                        existe=0;
                        break; //vitoria diagonal esquerda-direita, cima-baixo, 1º peça
                    }

                    if(jogadas[i][j]== 'C' && jogadas[i+1][j+1]==' ' && jogadas[i+2][j+2]=='C' && jogadas[i+3][j+3]=='C' && jogadas[i+2][j+1]!=' '){
                        jogadas[i+1][j+1]= 'C';
                        ultima_linha_jogada_C = i+1;
                        ultima_coluna_jogada_C = j+1;
                        existe=0;
                        break; //vitoria diagonal esquerda-direita, cima-baixo, 2º peça
                    }

                    if(jogadas[i][j]== 'C' && jogadas[i+1][j+1]=='C' && jogadas[i+2][j+2]==' ' && jogadas[i+3][j+3]=='C' && jogadas[i+3][j+2]!=' '){
                        jogadas[i+2][j+2]= 'C';
                        ultima_linha_jogada_C = i+2;
                        ultima_coluna_jogada_C = j+2;
                        existe=0;
                        break; //vitoria diagonal esquerda-direita, cima-baixo, 3º peça
                    }

                    if(jogadas[i][j]== 'C' && jogadas[i+1][j+1]=='C' && jogadas[i+2][j+2]=='C' && jogadas[i+3][j+3]==' ' && (jogadas[i+4][j+3]!=' ' || jogadas[5][j+3]==' ')){
                        jogadas[i+3][j+3]= 'C';
                        ultima_linha_jogada_C = i+3;
                        ultima_coluna_jogada_C = j+3;
                        existe=0;
                        break; //vitoria diagonal esquerda-direita, cima-baixo, 4º peça
                    }
                }
            }

            if(existe==1){
                if(i+3<6 && j-3>=0){
                    if(jogadas[i][j]== ' ' && jogadas[i+1][j-1]=='C' && jogadas[i+2][j-2]=='C' && jogadas[i+3][j-3]=='C' && jogadas[i+1][j]!= ' '){
                        jogadas[i][j]= 'C';
                        ultima_linha_jogada_C = i;
                        ultima_coluna_jogada_C = j;
                        existe=0;
                        break; //vitoria diagonal direita-esquerda, cima-baixo, 1º peça
                    }

                    if(jogadas[i][j]== 'C' && jogadas[i+1][j-1]==' ' && jogadas[i+2][j-2]=='C' && jogadas[i+3][j-3]=='C' && jogadas[i+2][j-1]!= ' '){
                        jogadas[i+1][j-1]= 'C';
                        ultima_linha_jogada_C = i+1;
                        ultima_coluna_jogada_C = j-1;
                        existe=0;
                        break; //vitoria diagonal direita-esquerda, cima-baixo, 2º peça
                    }

                    if(jogadas[i][j]== 'C' && jogadas[i+1][j-1]=='C' && jogadas[i+2][j-2]==' ' && jogadas[i+3][j-3]=='C' && jogadas[i+3][j-2]!= ' '){
                        jogadas[i+2][j-2]= 'C';
                        ultima_linha_jogada_C = i+2;
                        ultima_coluna_jogada_C = j-2;
                        existe=0;
                        break; //vitoria diagonal direita-esquerda, cima-baixo, 3º peça
                    }

                    if(jogadas[i][j]== 'C' && jogadas[i+1][j-1]=='C' && jogadas[i+2][j-2]=='C' && jogadas[i+3][j-3]==' ' && (jogadas[i+4][j-3]!= ' '|| jogadas[5][j-3] == ' ')){
                        jogadas[i+3][j-3]= 'C';
                        ultima_linha_jogada_C = i+3;
                        ultima_coluna_jogada_C = j-3;
                        existe=0;
                        break; //vitoria diagonal direita-esquerda, cima-baixo, 4º peça
                    }
                }
            }
            //para o PC impedir o jogador ganhar
            if(existe==1){
                if(j+3<7){
                    if(jogadas[i][j]== ' ' && jogadas[i][j+1]=='U' && jogadas[i][j+2]=='U' && jogadas[i][j+3]=='U' && jogadas[i+1][j]!= ' ' ){
                        jogadas[i][j] = 'C';
                        ultima_linha_jogada_C = i;
                        ultima_coluna_jogada_C = j;
                        existe=2;
                        break;  //impede horizontal 1º peça a contar de esquerda
                    }
                    if(jogadas[i][j]== 'U' && jogadas[i][j+1]==' ' && jogadas[i][j+2]=='U' && jogadas[i][j+3]=='U' && jogadas[i+1][j+1]!= ' '){
                        jogadas[i][j+1] = 'C';
                        ultima_linha_jogada_C = i;
                        ultima_coluna_jogada_C = j+1;
                        existe=2;
                        break;  //impede horizontal 2º peça
                    }
                    if(jogadas[i][j]== 'U' && jogadas[i][j+1]=='U' && jogadas[i][j+2]==' ' && jogadas[i][j+3]=='U' && jogadas[i+1][j+2]!= ' '){
                        jogadas[i][j+2] = 'C';
                        ultima_linha_jogada_C = i;
                        ultima_coluna_jogada_C = j+2;
                        existe=2;
                        break;  //impede horizontal 3º peça
                    }

                    if(jogadas[i][j]== 'U' && jogadas[i][j+1]=='U' && jogadas[i][j+2]=='U' && jogadas[i][j+3]==' ' && jogadas[i+1][j+3]!= ' '){
                        jogadas[i][j+3] = 'C';
                        ultima_linha_jogada_C = i;
                        ultima_coluna_jogada_C = j+3;
                        existe=2;
                        break;  //impede horizontal 4º peça
                    }
                }
                if(existe==1){
                    if(i+3<6){
                        if(jogadas[i][j]== ' ' && jogadas[i+1][j]=='U' && jogadas[i+2][j]=='U' && jogadas[i+3][j]=='U'){
                            jogadas[i][j] = 'C';
                            ultima_linha_jogada_C = i;
                            ultima_coluna_jogada_C = j;
                            existe=2;
                            break;  //impede vertical unica opçao, topo
                        }
                    }
                }

                if(existe==1){
                    if(i+3<6 && j+3<7){
                        if(jogadas[i][j]== ' ' && jogadas[i+1][j+1]=='U' && jogadas[i+2][j+2]=='U' && jogadas[i+3][j+3]=='U' && jogadas[i+1][j]!=' '){
                            jogadas[i][j]= 'C';
                            ultima_linha_jogada_C = i;
                            ultima_coluna_jogada_C = j;
                            existe=2;
                            break; //impede diagonal esquerda-direita, cima-baixo, 1º peça
                        }

                        if(jogadas[i][j]== 'U' && jogadas[i+1][j+1]==' ' && jogadas[i+2][j+2]=='U' && jogadas[i+3][j+3]=='U' && jogadas[i+2][j+1]!=' '){
                            jogadas[i+1][j+1]= 'C';
                            ultima_linha_jogada_C = i+1;
                            ultima_coluna_jogada_C = j+1;
                            existe=2;
                            break; //impede diagonal esquerda-direita, cima-baixo, 2º peça
                        }

                        if(jogadas[i][j]== 'U' && jogadas[i+1][j+1]=='U' && jogadas[i+2][j+2]==' ' && jogadas[i+3][j+3]=='U' && jogadas[i+3][j+2]!=' '){
                            jogadas[i+2][j+2]= 'C';
                            ultima_linha_jogada_C = i+2;
                            ultima_coluna_jogada_C = j+2;
                            existe=2;
                            break; //impede diagonal esquerda-direita, cima-baixo, 3º peça
                        }

                        if(jogadas[i][j]== 'U' && jogadas[i+1][j+1]=='U' && jogadas[i+2][j+2]=='U' && jogadas[i+3][j+3]==' ' && (jogadas[i+4][j+3]!=' ' || jogadas[5][j+3]==' ')){
                            jogadas[i+3][j+3]= 'C';
                            ultima_linha_jogada_C = i+3;
                            ultima_coluna_jogada_C = j+3;
                            existe=2;
                            break; //impede diagonal esquerda-direita, cima-baixo, 4º peça
                        }
                    }
                }

                if(existe==1){
                    if(i+3<6 && j-3>=0){
                        if(jogadas[i][j]== ' ' && jogadas[i+1][j-1]=='U' && jogadas[i+2][j-2]=='U' && jogadas[i+3][j-3]=='U' && jogadas[i+1][j]!= ' '){
                            jogadas[i][j]= 'C';
                            ultima_linha_jogada_C=i;
                            ultima_coluna_jogada_C=j;
                            existe=2;
                            break; //impede diagonal direita-esquerda, cima-baixo, 1º peça
                        }

                        if(jogadas[i][j]== 'U' && jogadas[i+1][j-1]==' ' && jogadas[i+2][j-2]=='U' && jogadas[i+3][j-3]=='U' && jogadas[i+2][j-1]!= ' '){
                            jogadas[i+1][j-1]= 'C';
                            ultima_linha_jogada_C=i+1;
                            ultima_coluna_jogada_C=j-1;
                            existe=2;
                            break; //impede diagonal direita-esquerda, cima-baixo, 2º peça
                        }

                        if(jogadas[i][j]== 'U' && jogadas[i+1][j-1]=='U' && jogadas[i+2][j-2]==' ' && jogadas[i+3][j-3]=='U' && jogadas[i+3][j-2]!= ' '){
                            jogadas[i+2][j-2]= 'C';
                            ultima_linha_jogada_C=i+2;
                            ultima_coluna_jogada_C=j-2;
                            existe=2;
                            break; //impede diagonal direita-esquerda, cima-baixo, 3º peça
                        }

                        if(jogadas[i][j]== 'U' && jogadas[i+1][j-1]=='U' && jogadas[i+2][j-2]=='U' && jogadas[i+3][j-3]==' ' && (jogadas[i+4][j-3]!= ' '|| jogadas[5][j-3] == ' ')){
                            jogadas[i+3][j-3]= 'C';
                            ultima_linha_jogada_C=i+3;
                            ultima_coluna_jogada_C=j-3;
                            existe=2;
                            break; //impede diagonal direita-esquerda, cima-baixo, 4º peça
                        }
                    }
                }

            }
            // bloqueia sempre que encontra duas peças seguidas
            if(existe==1){
                if(i < 5 && j+3<7){
                    if(jogadas[i][j]== 'U' && jogadas[i][j+1]=='U' && jogadas[i][j+2]==' ' && jogadas[i][j+3]==' ' && jogadas[i+1][j+2]!=' '){

                        jogadas[i][j+2]='C';
                        ultima_linha_jogada_C = i;
                        ultima_coluna_jogada_C = j+2;
                        existe=3;
                        break;

                    }
                    if(jogadas[i][j]== ' ' && jogadas[i][j+1]=='U' && jogadas[i][j+2]=='U' && jogadas[i][j+3]==' ' && jogadas[i+1][j]!=' '){

                        jogadas[i][j]='C';
                        ultima_linha_jogada_C = i;
                        ultima_coluna_jogada_C = j;
                        existe=3;
                        break;

                    }
                }
            }
            if(existe==1){
                if(i == 5 && j+3<7){
                    if(jogadas[i][j]== 'U' && jogadas[i][j+1]=='U' && jogadas[i][j+2]==' ' && jogadas[i][j+3]==' '){

                        jogadas[i][j+2]='C';
                        ultima_linha_jogada_C = i;
                        ultima_coluna_jogada_C = j+2;
                        existe=3;
                        break;

                    }
                    if(jogadas[i][j]== ' ' && jogadas[i][j+1]=='U' && jogadas[i][j+2]=='U' && jogadas[i][j+3]==' '){

                        jogadas[i][j]='C';
                        ultima_linha_jogada_C = i;
                        ultima_coluna_jogada_C = j;
                        existe=3;
                        break;

                    }
                }
            }
            if(existe==1){
                if(i+2<6){
                    if(jogadas[i][j]== ' ' && jogadas[i+1][j]=='U' && jogadas[i+2][j]=='U'){
                        jogadas[i][j]='C';
                        ultima_linha_jogada_C = i;
                        ultima_coluna_jogada_C = j;
                        existe=3;
                        break;
                    }
                }
            }
            if(existe==1){
                if(i+3<6 && j-3>=0){
                    if(jogadas[i][j]== 'U' && jogadas[i+1][j-1]=='U' && jogadas[i+2][j-2]==' ' && jogadas[i+3][j-2]!= ' '){

                        jogadas[i+2][j-2]='C';
                        ultima_linha_jogada_C = i+2;
                        ultima_coluna_jogada_C = j-2;
                        existe=3;
                        break;

                    }
                }
            }

            if(existe==1){
                if(i+3<6 && j-3>=0){
                    if(jogadas[i][j]== ' ' && jogadas[i+1][j-1]=='U' && jogadas[i+2][j-2]=='U'&& jogadas[i+1][j]!= ' '){

                        jogadas[i][j]='C';
                        ultima_linha_jogada_C = i;
                        ultima_coluna_jogada_C = j;
                        existe=3;
                        break;

                    }
                }
            }

            if(existe==1){
                if(i+3<6 && j-3>=0){
                    if(jogadas[i][j]== 'U' && jogadas[i+1][j+1]=='U' && jogadas[i+2][j+2]==' ' && jogadas[i+3][j+2]!= ' '){

                        jogadas[i+2][j+2]='C';
                        ultima_linha_jogada_C = i+2;
                        ultima_coluna_jogada_C = j+2;
                        existe=3;
                        break;
                    }
                }
            }

            if(existe==1){
                if(i+3<6 && j-3>=0){
                    if(jogadas[i][j]== ' ' && jogadas[i+1][j+1]=='U' && jogadas[i+2][j+2]=='U' && jogadas[i+1][j]!= ' '){
                        jogadas[i][j]='C';
                        ultima_linha_jogada_C = i;
                        ultima_coluna_jogada_C = j;
                        existe=3;
                        break;
                    }
                }
            }
            if(existe==1){
                if(j-1>=0 && j+3<7){
                    if(jogadas[i][j]== 'U' && jogadas[i][j+1]==' ' && jogadas[i][j+2]=='U' && (jogadas[i][j+3]==' ' || jogadas[i][j-1]==' ' )&& jogadas[i+1][j+1]!=' '){
                        jogadas[i][j+1]='C';
                        ultima_linha_jogada_C = i;
                        ultima_coluna_jogada_C = j+1;
                        existe=3;
                        break;
                    }
                }
            }
            if(existe==1){
                if(i-1>=0 && i+3<6 && j-1>=0 && j+3<7){
                    if(jogadas[i][j]== 'U' && jogadas[i+1][j+1]==' ' && jogadas[i+2][j+2]=='U' && jogadas[i+1][j+1]!= ' ' && (jogadas[i-1][j-1]==' '|| jogadas[i+3][j+3]==' ')){
                        jogadas[i+1][j+1]= 'C';
                        ultima_linha_jogada_C = i+1;
                        ultima_coluna_jogada_C = j+1;
                        existe=3;
                        break;
                    }
                }
            }
            if(existe==1){
                if(i-1>=0 && i+3<6 && j-3>=0 && j+1<7){
                    if(jogadas[i][j]== 'U' && jogadas[i+1][j-1]==' ' && jogadas[i+2][j-2]=='U' && jogadas[i+1][j-1]!= ' ' && (jogadas[i-1][j+1]==' '|| jogadas[i+3][j-3]==' ')){
                        jogadas[i+1][j-1]= 'C';
                        ultima_linha_jogada_C = i+1;
                        ultima_coluna_jogada_C = j-1;
                        existe=3;
                        break;
                    }
                }
            }
        }
    }

    if(existe!=0 && existe!=2 && existe!=3){
        int coluna;
        int linha = 5;
        do{
            srand((unsigned) time(NULL));
            coluna= (rand() % 6) + 0;
        }while(jogadas[0][coluna] != ' ' );

        do{
            if(jogadas[linha][coluna] == ' ' ){
                jogadas[linha][coluna] = 'C';
                ultima_linha_jogada_C = linha;
                ultima_coluna_jogada_C = coluna;
                break;
            }
            else linha--;

        }while(linha >= 0);
    }

    guarda_jogadas(ultima_linha_jogada_C,ultima_coluna_jogada_C,'C');
    Njogadas++;
    tabuleiro();
    if(vitoria() == 1){
        ofstream file("jogadas.txt",ios::trunc);
        file.close();
        ofstream file2("Saved_game.txt",ios::trunc);
        file2.close();
        ofstream file3("Game_info.txt",ios::trunc);
        file3.close();
        Nderrotas++;
        cout << "PC ganhou!" << endl;
        return true;
    }

    else return false;

}
