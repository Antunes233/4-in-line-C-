#ifndef CJOGO
#define CJOGO
#include <string>

using namespace std;



class multiplayer;
class CNoLista{
public:
    int data;
    string name;
    struct CNoLista *next;
};

class CJogo{

private:


    CNoLista *cabeca;
    string player_name;
    string player2_name;
    int Njogadas;
    int Nvitorias;
    int Nvitorias2;
    int Nderrotas;
    int vitorias_PC2;
    int Nempates;
    char jogadas[6][7];
    int primeiro;
    int ultima_linha_jogada_U;
    int ultima_coluna_jogada_U;
    int ultima_linha_jogada_C;
    int ultima_coluna_jogada_C;
    int nivel;
    int auxNjogadas;


public:
    CJogo();

    void tabuleiro(void);
    void inserirNome(void);
    void escolher_dificuldade(void);
    void escolher_dificuldade_pc_vs_pc(void);
    void mostra_nome(string);
    void comeca(void);
    int comeca_aleatorio(void);
    bool elementar(void);
    bool elementar_PC2(void);
    bool basico(void);
    bool basico_PC2(void);
    bool medio(void);
    bool medio_PC2(void);
    bool avancado(void);
    bool jogada_jogador(void);
    bool troca(bool jogador);
    int mostra_Njogadas(void);
    int vitoria(void);
    bool empate(void);
    void menu();
    void reset_tabuleiro(void);
    void reset_jogo(void);
    void mostra_Nvitorias_player(void);
    void mostra_Nderrotas(void);
    void back(void);
    void atualiza_top10(int, string);
    void mostra_top10(void);
    void ordena(int);
    bool compara(int item, int);
    int guarda_jogo_em_ficheiro(void);
    void suspende(void);
    void jogar();
    void escreve_Top10_file(void);
    void recomeca_jogo(void);
    void le_top10_file(void);
    void guarda_info_file(void);
    void guarda_jogadas(int linha, int coluna, char letra);
    void apaga_file_jogadas(void);
    void inserirNome2(void);
    bool jogada_jogador2(void);
    void mostra_Nvitorias_player2(void);
    void jogar_multiplayer(void);
    void jogar_pc_vs_pc(void);
    void mostra_jogadas(void);
    void mostra_vitorias_pc2(void);



};

#endif // CJOGO

