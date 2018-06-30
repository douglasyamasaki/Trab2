#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#define LINHAS 30
#define COLUNAS 40

typedef struct {
	int x;
	int y;
}Personagem;

typedef struct {
	int x;
	int y;
	int tipo;
	int isVivo;
}Monstro;

typedef struct bomba {
    int x;
    int y;
    struct bomba *next;
    BITMAP* explosao;
    BITMAP* normal;
}Bomba;

Monstro * criaInimigos(){
    return (Monstro*)malloc(sizeof(Monstro) * 5);
}

Personagem * criaPlayer(){
    return (Personagem*) malloc(sizeof(Personagem));
}

char **leituraArquivo(Personagem* player, Monstro* monstros){ //Lê o arquivo, passando as coordenadas do player e inimigos por parametro. Também cria o labirinto.

	int i, j, k = 0,aux,xsaida, ysaida;

	char **maze = (char**)malloc(sizeof(char*) * LINHAS);
	for (i = 0; i<LINHAS; i++) {
		maze[i] = (char*)malloc(sizeof(char)*COLUNAS);
	}

    for(i=0;i<LINHAS;i++)
        for(j=0;j<COLUNAS;j++)
        maze[i][j]=' ';

	FILE *arquivo = fopen("maze_H_1.txt", "r");
	if (arquivo == NULL){
		printf("Arquivo nao encontrado\n");
		return 0;
	}

	while (k<7)
	{
		fscanf(arquivo, "%d %d", &i, &j);
		if (k == 0) {
			player->x = i;
			player->y = j;
			k++;
			continue;
		}
		if (k == 1) {
			monstros[0].x = i;
			monstros[0].y = j;
			monstros[0].tipo = 0;
			monstros[i].isVivo = 1;
			k++;
			continue;
		}
		if (k == 6) {
        xsaida = i;
        ysaida = j;
			k++;
			break;
		}
		monstros[k-1].x = i;
		monstros[k-1].y = j;
		monstros[k-1].tipo = 1;
		monstros[k-1].isVivo = 1;
		k++;
	}

	while (fscanf(arquivo,"%d %d %d",&i,&j,&aux)!=EOF){
        if(aux==0)
            maze[i][j] = ' ';
        else maze[i][j] = '*';
	}
    maze[xsaida][ysaida] = 's';
	fclose(arquivo);
	return maze;
}

int detectaBomba(Bomba* bombas,Monstro* monstros){
    if((bombas->x == monstros->x)&&(bombas->y == monstros->y))
        return 1;
    else return 0;
}

int main(){
	int i, j;
	Monstro *monstros = criaInimigos();
	Personagem *player = criaPlayer();
	char **maze = leituraArquivo(player, monstros);

	printf("player: %d %d\n", player->x, player->y);
	for (i = 0; i<5; i++)
	{
		printf("posicao do inimigo %d: %d %d\n",i,monstros[i].x,monstros[i].y);
	}
	for (i = 0; i<LINHAS; i++)
		for (j = 0; j<COLUNAS; j++)
			if (maze[i][j] == 's')
				printf("coords de saida %d %d\n", i, j);

    for(i=0;i<30;i++){
        for(j=0;j<40;j++)
            printf("%c",maze[i][j]);
        printf("\n");
    }
    free(monstros);
    free(maze);
	return 0;
}
