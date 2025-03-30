#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

void Task1_2_3() {
	char name[50];
	printf("Input file name: ");
	scanf("%s", name);
	FILE* in = fopen(name, "r");
	if (in == NULL) {
		printf("file %s not open", name);
		exit(1);
	}
	int count_all = 0;
	int count_empty = 0;
	char* IN_Str = new char[128];
	cout << "Enter string to find:" << endl;
	cin >> IN_Str;
	char* buff = new char[128];
	cout << "***File_text_start***\n";
	while (!feof(in)) {
		if (fgets(buff, 128, in)) {
			//Задание2
			for (int i = 0; i < strlen(buff); i++) {
				if (buff[i] <= 32) { count_empty++; }
				else { count_all++; }
			}
			//Задание3
			if (strstr(buff, IN_Str) != NULL) {
				cout << "SubString found: " << strstr(buff, IN_Str) << endl;
			}
			//Задание1
			printf("%s", buff);
		}
	}
	cout << "***File_text_end***\n";
	printf("Empty symbols found %i\n", count_empty);
	printf("Other symbols found %i\n", count_all);
	fclose(in);
}

void Task4() {
	char name[50];
	char fname[] = { "itogo_" };
	printf("Input file name(for number margin formatting): ");
	scanf("%s", name);
	strcat(fname, name);
	int page_count = 1;
	FILE* in = fopen(name, "r");
	FILE* out = fopen(fname, "w");
	char* buff = new char[128];
	if (in == NULL) {
		printf("file %s not open", name);
		exit(1);
	}
	while (!feof(in)) {
		if (fgets(buff, 128, in) != NULL) {
			if (strstr(buff, "\f") != NULL) {
				fprintf(out, "\t\t\t\t\t %i\f", page_count);
				page_count++;
			}
			if (strstr(buff, "- ") != NULL && strstr(buff, " -") != NULL) {
				continue;
			}
			else {
				fputs(buff, out);
			}
		}
	}
	fprintf(out, "\t\t\t\t\t %i\f", page_count);
	fclose(in);
	fclose(out);
	exit(0);
}

void Task5_6(char* name, int key) {
	char ch;
	char fname[] = { "code_" };
	FILE* in = fopen((char*)name, "r");
	if (in == NULL) {
		printf("file %s not open", name);
		return;
	}
	else
		strcat(fname, (char*)name);
	FILE* out = fopen(fname, "w");

	while (!feof(in))
	{
		ch = getc(in);
		ch = ch ^ key;
		fputc(ch, out);
	}
	fclose(in);
	fclose(out);
	exit(0);
}



int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Rus");
	Task1_2_3();
	Task4();
	return 0;
}