#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void optionNoting(){
	printf("옵션없음");
}
void optionI(){
	printf("-i");
}
void optionP(){
	printf("-p");
}
void optionQ(){
	printf("-Q");
}

int main(int argc, char *argv[]){
	if(argc[1] == 1){
		optionNoting();
	}
	else if(argv[1] == "-p"){
		optionP();
	}
	else if(argv[1] == "-i"){
		optionI();
	}
	else if(argv[1] == "-Q"){
		optionQ();
	}

}

