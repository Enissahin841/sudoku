#include <stdio.h>

int satirdavarmi(int matris[][9], int satir,int deger){
    int j;
    for(j=0; j<9; j++){
        if(matris[satir][j]==deger){
            return 1;
        }
    }
return 0;
}
int sutundavarmi(int matris[][9],int sutun ,int deger){
    int i;
    for(i=0; i<9; i++){
        if(matris[i][sutun]==deger){
            return 1;
        }
    }
    return 0;
}

 int kutudavarmi(int matris[][9],int satir,int sutun,int deger){
int i,j,kutusatiri,kutusutunu;

kutusatiri=(satir/3)*3;
kutusutunu=(sutun/3)*3;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(matris[i+kutusatiri][j+kutusutunu]==deger){
                return 1;
            }
        }
    }
    return 0;
 }

int main()
{
     int i,j,matris[9][9];
    FILE *dosya;   //Programın dosyayla olan bağlantısını tutacak değişken
    dosya=fopen("sudoku.txt", "r");  // sudoku.txt dosyasını okumak amacıyla aç bu dosyayla ilgili bilgiyi dosya değişkeninde tut.
     if(dosya==NULL){    // dosyayı açamadım mı? sorusunu sorar. evetse hata mesajını verip programı sonlandırabiliriz. 
        printf("dosya açılamadı \n");
        return 1;      
     }
     
     for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            fscanf(dosya, "%d", &matris[i][j]);
        }
     }
     fclose(dosya);

    printf("Sudoku projesi basliyor!\n"); 
    printf("Dosyadan okunan matris şu şekildedir : \n");
    int satir, sutun, deger;
    
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
    if(satirdavarmi(matris,satir-1,deger)){
        printf("satırda bu sayı zaten var. tekrar deneyiniz.\n");
        continue;
    }
    if(sutundavarmi(matris,sutun-1,deger)){
        printf("bu sayı sütunda zaten var. tekrar deneyiniz.\n");
        continue;
    }
    if(kutudavarmi(matris,satir-1,sutun-1,deger)){
        printf("3x3 kutuda zaten bu sayı var.\n");
        continue;
    }
    else{
        matris[satir-1][sutun-1]=deger;
    }
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
