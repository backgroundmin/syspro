#include <stdio.h>

char savedText[10][100];

int main(int argc, char *argv[]){
	FILE *fp;
	int i,totalLine;
	if (argc != 2) {
		fprintf(stderr, "How to use: %s file\n", argv[0]);
		return 1;
	}
	if ((fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Error open File\n");
		return 2;
	}
	i = 0;
	while (fgets(savedText[i], 100, fp) != NULL) {
		i++;
	}
	totalLine = i;
	for(i = 0 ; i < 2 ; i++){
		printf("%s",savedText[i]);
	}

	return 0;
}
