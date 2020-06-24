#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>

struct data {
	char name[20];
	int code;
	int type;
};
int main()
{
	FILE* fp = NULL;
	struct data d;
	d.code = 100;
	strncpy(d.name, "임의문자열", strlen("임의문자열"));
	d.type = 65;

	fopen_s(&fp, "demo-user.dat", "wb");
	fwrite(&d, sizeof(d), 1, fp);
	fclose(fp);

	struct data t;
	fopen_s(&fp, "demo-user.dat", "rb");
	fread(&t, sizeof(t), 1, fp);
	fclose(fp);

	return 0;
}

/*int main()
{
	FILE* fp = NULL;
	const char* fname = "demo-block.dat";
	fopen_s(&fp, fname, "wb");

	int char[5][20] = {0};

	fwrite(num,sizeof(num),1,fp);
	fclose(fp);
	
	fopen_s(&fp, fname, "rb");
	fread(num, sizeof(num), 1, fp);
	fclose(fp);

	return 0;
}*/
/*
int main()
{
	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");

	int n;
	int sum = 0;
	fscanf(in, "%d", &n);
	for (int i = 0; i < n; i++) {
		int a; fscanf(in, "%d", &a);
		sum += a;
	}
	printf("%d\n", sum);
	fprintf(out, "%d\n", sum);

	fclose(in);
	fclose(out);

	return 0;
}*/
/*
int main()
{
	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");

	int n;
	int sum = 0;
	fscanf(in, "%d", &n);
	for (int i = 0; i < n; i++) {
		int a; fscanf(in, "%d", &a);
		sum += a;
	}
	printf("%d\n", sum);
	fprintf(out, "%d\n", sum);

	fclose(in);
	fclose(out);

	return 0;
}*/