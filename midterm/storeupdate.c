#include <stdio.h>
#include <stdlib.h>

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
   FILE *fp;
   int proCount,i;
   int input;

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
    printf("(n): sell one goods ] ");
    scanf("%d",&input);
    for(i = 0 ; i < proCount ; i++){
        if(pro[i].id == input){
            input = i; 
        }
    }
	if(pro[input].stock == 0){
		printf("%s has been sold out...\n",pro[input].name);
	}
	else{
		pro[input].stock--;
		printf("%s has been sold\n",pro[input].name);
		printf("%3s %15s %6s %15s %5s\n","id","name","category","expiredDate","stock");
		for(i = 0 ; i < proCount ; i++){
			printf("%3d %15s %6s %15d %15d\n", pro[i].id,pro[i].name,pro[i].category,pro[i].expiredDate,pro[i].stock);
		}
	}
	


    fclose(fp);
    exit(0);
}



