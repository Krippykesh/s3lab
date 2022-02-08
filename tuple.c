
#include<stdio.h>
#include<stdlib.h>
void inputarr(int arr[10][10],int *r,int *c);
void tupdisplay(int arr[][3]);
void spardisplay(int arr[10][10],int r,int c);
int  compare(int a,int b,int p,int q);
void sum(int tup1[][3],int tup2[][3]);
void spartotup(int arr[10][10],int r,int c,int tup[][3]);
void transpose(int tup[][3],int tupt[][3]);


int main()
{
int arr1[10][10],arr2[10][10],tup1[10][3],tup2[10][3],tupt1[10][3],tupt2[10][3],r1,r2,c1,c2,a;
printf(" First array\n");
inputarr(arr1,&r1,&c1);
printf("Second array\n");
inputarr(arr2,&r2,&c2);
for(int i=0;i<100;i++)
{ printf("1:Tuple form\n2:Transpose\n3:Sum\n4:exit\n");
  scanf("%d",&a);
  switch(a)
{
  case 1:
         {
        printf("\nThe Tuple Form Of First Array\n");
         spartotup(arr1,r1,c1,tup1);
         printf("\nThe Tuple Form Of Second Array\n");
         spartotup(arr2,r2,c2,tup2);
         break;
         }
  case 2:
         {
          printf("\nThe  Transpose Of The Tuple Form Of First Array\n");
          transpose(tup1,tupt1);
          printf("\nThe  Transpose Of The Tuple Form Of Second Array\n");
          transpose(tup2,tupt2);
          break;
          }
  case 3:{
          printf("\nThe Sum Of The Tuple Forms\n");
         sum(tup1,tup2);
          break;
         }
  case 4: exit(0);
 }
}
}


void inputarr(int arr[10][10],int *r,int *c){
    printf("\nEnter the dimensions:\n");
    scanf("%d %d",r,c);
    printf("\nEnter the elements\n");
    for(int i=0;i<*r;i++){
        for(int j=0;j<*c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    spardisplay(arr,*r,*c);
}

void tupdisplay(int arr[][3]){
    for(int i=0;i<=arr[0][2];i++)
        printf("%d  %d   %d\n",arr[i][0],arr[i][1],arr[i][2]);
    printf("\n");
}

void spardisplay(int arr[10][10],int r,int c){
    printf("\nThe Matrix\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",arr[i][j]);
        }printf("\n");
    }
    printf("\n");
}

void spartotup(int arr[10][10],int r,int c,int tup[][3]){
    int pos=1;
    tup[0][0]=r;tup[0][1]=c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]!=0){
                tup[pos][0]=i;
                tup[pos][1]=j;
                tup[pos][2]=arr[i][j];
                pos++;
            }
        }
    }
    tup[0][2]=pos-1;
    tupdisplay(tup);
}


int compare(int a,int b,int p,int q){
    if(a==b){
        if(p==q) return 0;
        else if(p<q) return 1;
        else if(p>q) return 2;
    }
    else if(a<b) return 1;
    else if(a>b) return 2;

}

void sum(int tup1[][3],int tup2[][3]){
    int p1=1,p2=1,p3=1;
    int sum[10][3];
    sum[0][0]=tup1[0][0];sum[0][1]=tup1[0][1];
    while(p1<=tup1[0][2] && p2<=tup2[0][2]){
        switch(compare(tup1[p1][0],tup2[p2][0],tup1[p1][1],tup2[p2][1])){
            case 0:
            if(tup1[p1][2]+tup2[p2][2]!=0){
                sum[p3][0]=tup1[p1][0];
                sum[p3][1]=tup1[p1][1];
                sum[p3][2]=tup1[p1][2]+tup2[p2][2];

                p3++;
                }
                p1++;p2++;
                break;
            case 1:
                sum[p3][0]=tup1[p1][0];
                sum[p3][1]=tup1[p1][1];
                sum[p3][2]=tup1[p1][2];

                p1++;p3++;
                break;
            case 2:
                sum[p3][0]=tup2[p2][0];
                sum[p3][1]=tup2[p2][1];
                sum[p3][2]=tup2[p2][2];

                p2++;p3++;
                break;

        }
    }
    while(p1<=tup1[0][2]){
        sum[p3][0]=tup1[p1][0];
        sum[p3][1]=tup1[p1][1];
        sum[p3][2]=tup1[p1][2];
        p1++;p3++;
    }
    while(p2<=tup2[0][2]){
        sum[p3][0]=tup2[p2][0];
        sum[p3][1]=tup2[p2][1];
        sum[p3][2]=tup2[p2][2];
        p2++;p3++;
    }
    sum[0][2]=p3-1;
    tupdisplay(sum);

}

void transpose(int tup[][3],int tupt[][3]){
    tupt[0][0]=tup[0][1];
    tupt[0][1]=tup[0][0];
    tupt[0][2]=tup[0][2];
    int pos=1;
    for(int i=0;i<tup[0][1];i++){
        for(int j=1;j<=tup[0][2];j++){
            if(tup[j][1]==i){
                tupt[pos][0]=tup[j][1];
                tupt[pos][1]=tup[j][0];
                tupt[pos][2]=tup[j][2];
                pos++;
            }
        }
    }
    tupdisplay(tupt);
}


