#include<stdio.h>
#define NCNT 15
#define MAX 99999
FILE* in = NULL;
typedef struct _Edge {
	int x, y, w;
}Edge;
Edge edge[NCNT] = { 0 };
void read_edge(int* ecnt, int* Ln) {
	fopen_s(&in, "input.txt", "r");
	while (1) {
		if (feof(in)) break;
		fscanf(in,"%d %d %d", &edge[*ecnt].x, &edge[*ecnt].y, &edge[*ecnt].w);
		if (*Ln < edge[*ecnt].y) *Ln = edge[*ecnt].y;
		(*ecnt)++;
	}
}
void MST(int w[NCNT+1], int ecnt, int Ln, int s) {
	int check[NCNT] = { 0 };
	int min = MAX, mi = 0;
	check[s] = 1;
	for (int i = 2; i <= Ln; i++) w[i] = MAX;
	
	for (int i = 0; i < ecnt; i++) {
		int x = edge[i].x;
		int y = edge[i].y;
		if (x == s && w[y] == MAX) {
			w[y] = edge[i].w;
		}
	}

	for (int n = 0; n <= Ln; n++) {
		min = MAX;
		for (int i = 0; i < ecnt; i++) {
			int x = edge[i].x; 
			int y = edge[i].y;
			if (w[x] != MAX && check[y] == 0) {
				if (min > edge[i].w) {
					min = edge[i].w; mi = y;
				}
			}
		}
		
		check[mi] = 1;

		for (int i = 0; i < ecnt; i++) {
			int x = edge[i].x;
			int y = edge[i].y;
			if (x == mi && check[y] == 0) {
				if (w[y] > w[x] + edge[i].w) {
					w[y] = w[x] + edge[i].w;
				}
			}
		}
	}
}
int main()
{
	int ecnt=0, Ln=0;
	int w[NCNT + 1] = { 0 };
	read_edge(&ecnt, &Ln);
	for (int i = 0; i < ecnt; i++)
		printf("%d %d %d\n", edge[i].x, edge[i].y, edge[i].w);
	printf("\n");
	MST(w,ecnt,Ln,1);
	for (int i = 1; i <= Ln; i++)
		printf("%-2d ", i);
	printf("\n");
	for (int i = 1; i <= Ln; i++)
		printf("%-2d ", w[i]);
	printf("\n");
}