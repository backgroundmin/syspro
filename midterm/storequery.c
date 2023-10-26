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
   struct product pro;
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

    printf("0:list of all goods, 1:list of available goods");
    scanf("%d",&input);
    printf("%3s %15s %6s %15s %5s\n","id","name","category","expiredDate","stock");
	while (fread(&pro, sizeof(pro), 1, fp) > 0){

	   if(input == 0){
		   printf("%3d %15s %6s %15d %15d\n", pro.id,pro.name,pro.category,pro.expiredDate,pro.stock);
	   }
	   else if(input == 1 && pro.stock>0 && pro.expiredDate >= 2023){
           printf("%3d %15s %6s %15d %15d\n", pro.id,pro.name,pro.category,pro.expiredDate,pro.stock);
	   }
	}
	
	fclose(fp);
	exit(0);
} 


