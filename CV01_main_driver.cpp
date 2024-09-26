#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_BIN "SOUBOR.BIN"
#define FILE_CSV "SOUBOR.CSV"

void read_bin_file(FILE* bin_file, int size) {
	char c;
	int i;
	double d;
	if (size == 1) {
		fread(&c, size, 1, bin_file);
		printf("char %c\n", c);
	}
	if (size == 4) {
		fread(&i, size, 1, bin_file);
		printf("char %d\n", i);
	}
	if (size == 8) {
		fread(&d, size, 1, bin_file);
		printf("char %e\n", d);
	}
}
void load_file() {
	char row[1024];
	char* token;
	FILE* csv_file = fopen(FILE_CSV, "r");
	FILE* bin_file = fopen(FILE_BIN, "rb");
	while (feof(csv_file) != true)	{
		fgets(row, 1024, csv_file);

		token = strtok(row, ";");

		while (token != NULL)		{
			printf("Token: %s\n", token);
			read_bin_file(bin_file, atoi(token));
			token = strtok(NULL, ";");
		}

	}
	fclose(csv_file);
	fclose(bin_file);
}


int generate_test_file( ) {
	FILE*  f_to_write = fopen(FILE_BIN, "wb");
	if (f_to_write == NULL) return 10;
	char c = 'a';
	int i = 45;
	double d = 3.14;
	fwrite(&c, sizeof(char), 1, f_to_write);
	fwrite(&i, sizeof(int), 1, f_to_write);
	fwrite(&d, sizeof(double), 1, f_to_write);
	fclose(f_to_write);

	f_to_write = fopen(FILE_CSV, "w");
	if (f_to_write == NULL) return 20;
	fprintf(f_to_write, "%d;%d;%d", (int)sizeof(char), (int)sizeof(int), (int)sizeof(double));
	fclose(f_to_write);
	return 0;
}

void tests() {
	generate_test_file();
	load_file();
}

int main() {
	tests();
	return 0;
}