#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char *readFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    char *code;
    size_t n = 0;
    int c;

    if (file == NULL) {
        printf("%s", "Could not open file");
    }
    fseek(file, 0, SEEK_END);
    long f_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    code = malloc(f_size);

    while ((c = fgetc(file)) != EOF) {
        code[n++] = (char)c;
    }

    code[n] = '\0';

    return code;
}

void count(char *file, char *count, char *time)
{
	clock_t begin = clock();

	int ones = 0;
	int twos = 0;
	int threes = 0;
	int fours = 0;
	int fives = 0;
	
	char *f = readFile(file);
	int n = 2531330;
	
	int i;
	for(i = 0; i < n; i++)
	{
		char a = f[i];
		int ia = a - '0';
		if(ia == 1)
		{
			char b = f[i+1];
			int ib = b - '0';
			if(ib == 2)
			{
				char c = f[i+2];
				int ic = c - '0';
				if(ic == 3)
				{
					char d = f[i+3];
					int id = d - '0';
					if(id == 4)
					{
						char e = f[i+4];
						int ie = e - '0';
						if(ie == 5)
						{
							fives++;
						}
						fours++;
					}
					threes++;
				}
				twos++;
			}
			ones++;
		}
	}
	
	FILE * fc;
	fc = fopen(count, "w");

	fprintf(fc, "%d %d %d %d %d", ones, twos, threes, fours, fives);

	fclose(fc);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	FILE * ft;
	ft = fopen(time, "w");

	fprintf(ft, "%f", time_spent);

	fclose(ft);
}

int main(int argc, char* argv[])
{
	count(argv[1], argv[2], argv[3]);

	return 0;
}