
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[] ){
    FILE *Fpointer;
    Fpointer = fopen(argv[1], "r");

    if(Fpointer == NULL){
  	printf("%s\n","ERROR");
	return 0;
    }
    
    char c[4];
    char d[4];
    fgets(c,4,stdin);//get the weekday from stdin
    getchar();
    fgets(d,4,stdin);
    char *array[8]={"Sun","Mon","Tue","Wed","Thu","Fri","Sun","\0"};
    char *array2[13]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec","\0"};
    int index = 0;
    //detect if month is correct
     while(strcmp(array2[index],"\0")!=0){
	if(strcmp(d,array2[index])==0)
            break;
        index++;
    }
    if(index ==12){
      printf("ERROR\n");
      return 0;
    }
    index = 0;
    //detect if weekday is correct
    while(strcmp(array[index],"\0")!=0){
        if(strcmp(c,array[index])==0)
            break;
        index++;
    }
    if(index ==7){
      printf("ERROR\n");
      return 0;
    }

    //printf weekday
    char cha;
    
    while((cha = fgetc(Fpointer))&& (cha != EOF)&&(cha != '\n')){
        if(index == 0)
            printf("%c",cha);
        if(cha == ' ')
            index--;
    }
    
    int index2 = 0;
    
    while(strcmp(array2[index2],"\0")!=0){
        if(strcmp(d,array2[index2])==0)
            break;
        index2++;
    }
    
    while((cha = fgetc(Fpointer))&& (cha != EOF)&&(cha != '\n')){
        if(index2 == 0)
            printf("%c",cha);
        if(cha == ' ')
            index2--;
    }
    while(getchar() != ' '){}
    while((cha = getchar())&& cha != EOF)
        printf("%c",cha);

    
    return 0;
    
}
