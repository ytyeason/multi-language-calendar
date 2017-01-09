#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv ){

    
    FILE *Fpointer;
    Fpointer = fopen(argv[1],"r");

    int k = atoi(argv[2]);//convert string to int
    int w = atoi(argv[3]);//convert string to int

    if((Fpointer == NULL)||(k<2)||(w>8)||(w<1)){
        printf("%s\n","ERROR");
        return 0;
    }
        

    int d[7];//size of each week-day
    
    char e;
    int index = 0;
    int count = 0;
    while((e= fgetc(Fpointer))&&(e != EOF)&&(e != '\n')){//get the size of lable
        count++;
        if(e == ' '){
            d[index] = count-1;
            count = 0;
            index++;
        }
    }
    d[6]=count;

    rewind(Fpointer);//back to beginning
    
    
    int track=w-1;
    int position = w-1;
    
    char c;
    int countM;//count month
    
    for(int q =1;q<13;q++){
        
        //print a line of chars
        for(int t = 7*(k+3);t>0;t--)
            printf("*");
        printf("\n");
        
        //print month
        countM = q-1;
        printf("* ");
        while((fgetc(Fpointer) != '\n')){}//switch to months
        while((c = fgetc(Fpointer))&&(c != '\n')&&(c!= EOF)){
            if((countM)==0)
                putchar(c);
            if(c == ' ')
                countM--;
        }
        printf("\n");
        rewind(Fpointer);//back to file beginning
        
        //print a line of chars
        for(int t = 7*(k+3);t>0;t--)
            printf("*");
        printf("\n");
        
        //write weekdays
        int u=0;
        char c[k+1];
        for(int i = 0;i < 7;i++){
            if(d[i]>k)//if label is too long
                u=k+1;
            else//if lable is too short
                u=d[i]+1;
            fgets(c,u,Fpointer);//c is a pointer
            printf("* %s ",c);
            if(i!=6)
                while(fgetc(Fpointer) != ' '){}
            if(d[i]<=k){
                for(int p = k-d[i];p>0;p--){//pad up
                        printf(" ");
                }
            }

        }
        printf("\n");
        rewind(Fpointer);//back to file beginning
        
        //print a line of chars
        for(int t = 7*(k+3);t>0;t--)
            printf("*");
        printf("\n");
    
        
        //print days
        int date=0;//count days
        //pad up spaces in beginning
        for(track = position;track>0;track--){
            printf("* ");
            for(int o = k+1;o>0;o--)
                printf(" ");
        }
        track=position;//set up track
        for(int i =1;i<7;i++){//write days
            for(int j=date; j<30;j++){
                int n = 0;
                track++;
                printf("* %d",++date);
                if(date<10)
                    n = 1;
                else
                    n = 2;
            
                for(int o = k-n+1;o>0;o--)
                    printf(" ");
                if(track == 7)
                    break;
            }
            if(date == 30)
                break;
            track=0;
            printf("\n");
        }
        if(track !=7){//set track for next time
            position = track;
	    for(int p = 7-position;p>0;p--){//pad up
            	printf("* ");
            	for(int o = k+1;o>0;o--)
              	  printf(" ");
        	}
            }
        else
            position = 0;
	printf("\n");
    
    }
    
    return 0;
    
}
