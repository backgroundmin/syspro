#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product{
    int id;
    char name[10];
    char category[10];
    int expiredDate;
    int stock;
};

int main(int argc, char* argv[])
{
    struct product pro[10];
	struct product temp;
   FILE *fp;
   int proCount,i,j;
   char input[10];
   int a=0;

   if (argc != 2) {
      fprintf(stderr, "How to use: %s FileName\n", argv[0]);
      return 1;
   }
   if ((fp = fopen(argv[1], "rb")) == NULL ) {
      fprintf(stderr, "Error Open File\n");
      return 2;
   }
    i=0;
    while (fread(&pro[i], sizeof(pro[0]), 1, fp) > 0){
        i++;
    }
    proCount = i;
	
	for(i = 0 ; i < proCount-1 ; i++){
		for(j = i+1; j < proCount ; j++){
			if(pro[i].expiredDate < pro[j].expiredDate){
				temp = pro[i];
				pro[i] = pro[j];
				pro[j] = temp;
			}
		}
	}

	printf("input goods category ] ");
	scanf("%s",input);
	printf("%3s %15s %6s %15s %5s\n","id","name","category","expiredDate","stock");
	for(i = 0 ; i < proCount ; i++){
		if(strcmp(input,pro[i].category)==0){
			a++;
			printf("%3d %15s %6s %15d %15d\n", pro[i].id,pro[i].name,pro[i].category,pro[i].expiredDate,pro[i].stock);
		}

	}
	if(a == 0){
		printf("%s not found",input);
	}
	

    fclose(fp);
    exit(0);
}





