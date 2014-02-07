#include<stdlib.h>
#include<stdio.h>
#include<math.h>

typedef int bool;
#define true 1
#define false 0
#define max(a,b) ((a) > (b) ? a : b)

int countdigits_(int d, int low, int high) {
    return countdigits(d, low, high, false);
}

int countdigits(int d, int low, int high, bool inner) {
    if (high == 0)
        return (d == 0) ? 1 : 0;

    if (low > 0)
        return countdigits_(d, 0, high) - countdigits_(d, 0, low);

    int n = floor(log10(high));
    int m = floor((high + 1) / pow(10, n));
    int r = high - m * pow(10, n);
    //printf("\nn :%d\tm : %d\tr :%d\n",n,m,r);
    return
        (max(m, 1) * n * pow(10, n-1)) +                             // (1)
        ((d < m) ? pow(10, n) : 0) +                                 // (2)
        (((r >= 0) && (n > 0)) ? countdigits(d, 0, r, true) : 0) +   // (3)
        (((r >= 0) && (d == m)) ? (r + 1) : 0)+
        (((r >= 0) && (d == 0)) ? countpaddingzeros(n, r) : 0) -     // (5)
        (((d == 0) && !inner) ? countleadingzeros(n) : 0);           // (6)
}

int countleadingzeros(int n) {
	//printf("\nn :%d\n",n);
	int tmp= 0;
	do{
		tmp= pow(10, n)+tmp;
		--n;
		}while(n>0);
		//printf("\ncountleadingzeros :%d",tmp);
    return tmp;
}

int countpaddingzeros(int n, int r) {
    int re = (r + 1) * max(0, n - max(0, floor(log10(r))) - 1);
    //printf("\ncountpaddingzeros :%d",re);
    return re;
}


void main() {
int d =0 ;
int res[10];
printf("Please Enter the End Limit : ");
scanf("%d",&d);

int tmp=0;
int tmp_ = -1;
for(int i=0; i<10;++i){
		res[i]=0;
	}
for(int i =0; i<= d;++i){
		tmp=i;
			do{
				++res[tmp%10];
				tmp= tmp/10;

			}while(tmp>0);
	}
for(int i=0; i<10;++i){
		printf("\nBase Algo\t\t\tNew Algo\n");
		printf("For %d : %d :",i,res[i]);
		printf("\t\t\tFor %d : %d :\n",i,countdigits_(i,0,d));
	}
//	*/
/*
int n = floor(log10(d));
int tmp_ = countdigits_(0,0,d);
int tmp= 0;
	do{
		tmp= pow(10, n)+tmp;
		--n;
		}while(n>0);

	printf("\n|%d|\n",tmp_);
	printf("\t\t\tFor %d : %d :\n",0,tmp_-tmp);
	*/
}
