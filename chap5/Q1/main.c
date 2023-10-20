#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char savedText[10][100];

int linePrintSolution(char input[10], int totalLine);
void onelinePrint(int line);
void multipleLinePrint(int line[], int lineCount);
void allLinePrint(int totalLine);
void betweenLinePrint(int line[]);

int main(int argc, char *argv[]) {
  FILE *fp;
  int i, totalLine;
  char input[10];
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
  printf("file read success\n total line : %d\n", totalLine);
  printf("you can choose 1 ~ %d line\n", totalLine);
  printf("Pls 'Enter' the line to select :");
  scanf("%s", input);
  linePrintSolution(input, totalLine);

}

void onelinePrint(int line) {
	printf("%s\n", savedText[line]);
}
void multipleLinePrint(int line[], int lineCount) {
  int i, lineI = 0;
  for (i = 0; i < lineCount; i++) {
    printf("%s\n", savedText[line[lineI]-1]);
    lineI++;
  }
}
void allLinePrint(int totalLine) {
  int i;
  for (i = 0; i < totalLine; i++) {
    printf("%s", savedText[i]);
  }
}
void betweenLinePrint(int line[]) {
  int i;
  printf("%d %d\n",line[0],line[1]);
  for (i = line[0]-1; i <= line[1]-1; i++) {
    printf("%s\n", savedText[i]);
  }
}
int linePrintSolution(char input[10], int totalLine){ // 1 = 성공 0 = 실패:wq
  int returnline[10], i;
  int findChar; // 0 = oneline , 1 = ',' , 2 = '-' , -1 = ERROR
  if (input[0] == '*') {
    allLinePrint(totalLine);
    return 1;
  }
  findChar = 0;
  for (int i = 0; i < 10; i++) {
	if(input[i] == '\0'){
		break;
	}
	else if (input[i] == ',') {
      findChar = 1;
      break;
    } 
	else if (input[i] == '-') {
      findChar = 2;
      break;
    }
	else if (input[i] < '0' || input[i] > '9') {
      findChar = -1;
      break;
    } 
  }
  if (findChar == -1) {
    return 0;
  } 
  else if (findChar == 0) {
	onelinePrint(atoi(input));
  } 
  else if (findChar == 1) {
    char *temp = strtok(input, ",");
    int num[10], numCount = 0;
    while (temp != NULL) {
      num[numCount] = atoi(temp);
      numCount++;
      temp = strtok(NULL, ",");
    }
    multipleLinePrint(num, numCount);
    return 1;
  } 
  else if (findChar == 2) {

    int num[2];
    char *temp = strtok(input, "-");
    num[0] = atoi(temp);
    temp = strtok(NULL, ",");
    num[1] = atoi(temp);
    betweenLinePrint(num);
  }
  
  return 1;
}
