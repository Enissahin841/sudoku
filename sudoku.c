#include <stdio.h>

int main()
{
    printf("Sudoku projesi basliyor!\n");
    printf("varsayılan sudoku matrisi şu şekildedir : \n");
    int i,j;
    int satir, sutun, deger;
    int matris[9][9]= {

        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
    };
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            printf("%d " , matris[i][j]);
        }
        printf("\n");
    }

    printf("sudokuda değiştirmek istediğiniz konumu ardından değerleri giriniz.\n");
    printf("ilk istenilen satır gireceğiniz kısıma 0 girerek döngüden çıkabilirsiniz. \n");

   while(1){
    printf("değiştirmek istediğiniz satırı giriniz :");
    scanf("%d", &satir);
    if(satir==0){
        break;
    }
    printf("değiştirmek istediğiniz sütunu giriniz :");
    scanf("%d",&sutun);
    printf("girdiğiniz konumdaki değeri değiştiniz :");
    scanf("%d",&deger);
    matris[satir-1][sutun-1]=deger;
   }

printf("oluşturduğunuz matris şu şekildedir :\n");
for(i=0; i<9; i++){
    for(j=0; j<9; j++){
        printf("%d ", matris[i][j]);
    }
    printf("\n");
}
    return 0;
    }
