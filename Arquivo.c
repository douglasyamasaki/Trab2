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

char **leituraArquivo(Personagem* player, Inimigo* inimigos) {

	int i, j, k = 0;
	char aux;
	inimigos = (Inimigo**)malloc(sizeof(Inimigo*) * 5);



	char **maze = (char**)malloc(sizeof(char*) * LINHAS);
	for (i = 0; i<LINHAS; i++) {
		maze[i] = (char*)malloc(sizeof(char)*COLUNAS);
	}

    for(i=0;i<LINHAS;i++)
        for(j=0;j<COLUNAS;j++)
        maze[i][j]=' ';

	FILE *arquivo = fopen("arquivo.txt", "r");
	if (arquivo == NULL) {
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
			maze[i][j] = 's';
			k++;
			break;
		}
		inimigos[k-1].x = i;
		inimigos[k-1].y = j;
		inimigos[k-1].tipo = 1;
		k++;
	}

    char line [10];
	while (fgets(line, 10, arquivo) != NULL){
            fscanf(arquivo,"%d %d",&i,&j);
            for (k=0;k<10;k++)
                if(line[k]=='*')
                maze[i][j]='*';
	}

	fclose(arquivo);


	return maze;
}

int main() {
	int i, j;
	Inimigo *inimigos;
	Personagem player;
	char **maze = leituraArquivo(&player, inimigos);

	printf("%d %d\n", player.x, player.y);
	for (i = 0; i<5; i++)
	{
		printf("%d %d\n", &(inimigos[i]).x,&(inimigos[i].y));
	}
	for (i = 0; i<LINHAS; i++)
		for (j = 0; j<COLUNAS; j++)
			if (maze[i][j] == 's')
				printf("%d %d", i, j);
	return 0;
}
