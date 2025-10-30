#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <iostream>

void DFS(int** G, int numG, int* visited, int s) {
	visited[s] = 1;
	printf("%3d", s);
	for (int i = 0; i < numG; i++) {
		if (G[s][i] == 1 && visited[i] == 0)
			DFS(G, numG, visited, i);

	}

}
int main(){
	setlocale(LC_ALL, "Russian");
	int** G;
	int* visited;
	int numG;
	int current;

	srand(time(NULL));

	printf("Сколько вершин???\n");;
	scanf_s("%d", &numG);

	G = (int**)malloc(numG * sizeof(int*));
	visited = (int*)malloc(numG * sizeof(int));
	for (int i = 0; i < numG; i++) {
		G[i] = (int*)malloc(numG * sizeof(int));
	}

	for (int i = 0; i < numG; i++) {
		visited[i] = 0;
		for (int j = i; j < numG; j++) {
			G[i][j] = G[j][i] = (i == j ? 0 : rand() % 2);
		}
	}
	for (int i = 0; i < numG; i++) {
		for (int j = 0; j < numG; j++) {
			printf("%3d", G[i][j]);
		}
		printf("\n");

	}
	printf("Введи номер вершины: ");
	scanf("%d", &current);

	printf("\n");
	printf("\nПуть :");
	DFS(G, numG, visited,current);
	printf("\n");

	return 0;
}