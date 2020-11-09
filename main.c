#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int a[4][4]={0} ;

void pt(){
    int i , j ;
    for( i=0 ; i<=3 ; i++ ){
        for( j=0 ; j<=3 ; j++ ){
            printf("%7d" , a[i][j]);
        }
        puts("");
        puts("");
    }
}

int sum(){
    int i , j , s=0 ;
    for( i=0 ; i<=3 ; i++ ){
        for( j=0 ; j<=3 ; j++ ){
            s += a[i][j];
        }
    }
    return s ;
}

struct kon{
    int n ;
    int r[16] ;
    int l[16] ;
};

struct kon kong(){
    int i , j ;
    struct kon x={0} ;
    for( i=0 ; i<=3 ; i++ ){
        for( j=0 ; j<=3 ; j++ ){
            if( a[i][j]==0 ){
                x.r[x.n] = j ;
                x.l[x.n] = i ;
                x.n++;
            }
        }
    }
    return x ;
}

int mi(int x){
    if(x==0){
        return 1 ;
    }
    else{
        return mi(x-1)*2 ;
    }
}

void add(char c){
    int i , j , k ;
    switch(c){
        case 'w':
            for( i=0 ; i<=3 ; i++ ){
                for( k=0 ; k<=10 ; k++ ){
                    for( j=0 ; j<=2 ; j++ ){
                        if(a[j][i]==0){
                            a[j][i]=a[j+1][i];
                            a[j+1][i]=0;
                        }
                        else if(a[j][i]==a[j+1][i]){
                            a[j+1][i] *= 2 ;
                            a[j][i] = 0 ;
                        }
                    }
                }
            }
            break ;
        case 'a':
            for( i=0 ; i<=3 ; i++ ){
                for( k=0 ; k<=10 ; k++ ){
                    for( j=0 ; j<=2 ; j++ ){
                        if(a[i][j]==0){
                            a[i][j]=a[i][j+1];
                            a[i][j+1]=0;
                        }
                        else if(a[i][j]==a[i][j+1]){
                            a[i][j+1] *= 2 ;
                            a[i][j] = 0 ;
                        }
                    }
                }
            }
            break ;
        case 's':
            for( i=0 ; i<=3 ; i++ ){
                for( k=0 ; k<=10 ; k++ ){
                    for( j=3 ; j>=1 ; j-- ){
                        if(a[j][i]==0){
                            a[j][i]=a[j-1][i];
                            a[j-1][i]=0;
                        }
                        else if(a[j][i]==a[j-1][i]){
                            a[j][i] *= 2 ;
                            a[j-1][i] = 0 ;
                        }
                    }
                }
            }
            break ;
        case 'd':
            for( i=0 ; i<=3 ; i++ ){
                for( k=0 ; k<=10 ; k++ ){
                    for( j=3 ; j>=1 ; j-- ){
                        if(a[i][j]==0){
                            a[i][j]=a[i][j-1];
                            a[i][j-1]=0;
                        }
                        else if(a[i][j]==a[i][j-1]){
                            a[i][j] *= 2 ;
                            a[i][j-1] = 0 ;
                        }
                    }
                }
            }
            break ;
    }
}

int main(){

    srand(time(NULL));
    int b , r ;
    struct kon x={16} ;
    char c ;

    while( x.n!=0 ){
        b = mi(rand()%2+1) ;
        x = kong() ;
        if(x.n==0)break;
        r = rand()%x.n ;

        a[x.l[r]][x.r[r]] = b ;

        pt();

        do{
            c = _getch();
        }while(c!='w'&&c!='a'&&c!='s'&&c!='d');
        add( c ) ;

        system("cls");
    }

    puts("");
    puts("game over !!!");
    printf("your score is %d" , sum() );

    return 0;
}
