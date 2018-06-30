#include <stdio.h>
#include <stdlib.h>
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
}Inimigo;

Inimigo * criaInimigos(){
    return (Inimigo*)malloc(sizeof(Inimigo) * 5);
}

Personagem * criaPlayer(){
    return (Personagem*) malloc(sizeof(Personagem));
}

char **leituraArquivo(Personagem* player, Inimigo* inimigos){ //Lê o arquivo, passando as coordenadas do player e inimigos por parametro. Também cria o labirinto.

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
			inimigos[0].x = i;
			inimigos[0].y = j;
			inimigos[0].tipo = 0;
			k++;
			continue;
		}
		if (k == 6) {
        xsaida = i;
        ysaida = j;
			k++;
			break;
		}
		inimigos[k-1].x = i;
		inimigos[k-1].y = j;
		inimigos[k-1].tipo = 1;
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

int main() {
	int i, j;
	Inimigo *inimigos = criaInimigos();
	Personagem *player = criaPlayer();
	char **maze = leituraArquivo(player, inimigos);

	printf("player: %d %d\n", player->x, player->y);
	for (i = 0; i<5; i++)
	{
		printf("posicao do inimigo %d: %d %d\n",i,inimigos[i].x,inimigos[i].y);
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
    free(inimigos);
    free(maze);
	return 0;
}
