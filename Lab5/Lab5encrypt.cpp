#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>

using namespace std;


int main(int argc, char** argv) {
    char* inFileName = argv[1];
    char* outFileName = argv[2];
    char* password = argv[3];

    FILE* out = fopen(outFileName, "wb");
    if (argc < 4)
        printf("���������� ������������");
    else {
        FILE* in = fopen(inFileName, "rb");
        char ch;
        int i = 0;
        // ������� (��������������) ����������� � ����������� �������� xor
        while (!feof(in)) {
            ch = getc(in);
            ch = ch ^ password[i];
            putc(ch, out);
            i = (i + 1) % strlen(password);
        }
    }

    return 0;
}