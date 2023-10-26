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
   if (argc != 2) {
      fprintf(stderr, "How to use: %s FileName\n",argv[0]);
      exit(1); 
   }
   fp = fopen(argv[1], "wb");
   printf("%-3s %-10s %-15s %-5s %-3s\n", "ID", "Name", "category", "expiredDate","stock"); 
   while (scanf("%d %s %s %d %d", &pro.id, pro.name, pro.category, &pro.expiredDate, &pro.stock) == 5){
      fwrite(&pro, sizeof(pro), 1, fp);
	}
   fclose(fp);
   exit(0);
} 

