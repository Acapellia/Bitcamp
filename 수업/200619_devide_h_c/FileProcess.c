#include<stdio.h>

void main()
{
	FILE* fp = NULL;
	fopen_s(&fp, "data.bin", "rb");

	int num;
	double fnum;
	char ch;
	int nums[3] = { 0 };

	// write binary
	/*fwrite(&num, sizeof(num), 1, fp);
	fwrite(&fnum, sizeof(fnum), 1, fp);
	fwrite(&ch, sizeof(ch), 1, fp);
	fwrite(nums, sizeof(int), 3, fp);*/

	// read binary
	fread(&num, sizeof(num), 1, fp);
	fread(&fnum, sizeof(fnum), 1, fp);
	fread(&ch, sizeof(ch), 1, fp);
	fread(&nums, sizeof(int), 3, fp);

	printf("num : %d\n", num);
	printf("fnum : %.2lf\n", fnum);
	printf("ch : %c\n", ch);
	printf("nums : %d %d %d\n", nums[0],nums[1], nums[2]);
	fclose(fp);
}