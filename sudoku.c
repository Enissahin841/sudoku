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

 int tahtadolumu(int matris[][9]){
int i,j;
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            if(matris[i][j]==0){
                return 0;
            }
          
        }
    }
    return 1;
 }

 int satirgecerlimi(int matris[][9],int satir){
    int j,k;
    for(j=0; j<9; j++){
        for(k=j+1; k<9; k++){
            if(matris[satir][j]==matris[satir][k]){
                return 0;

            }
        }
    }
    return 1; 

 }
 int satirlargecerlimi(int matris[][9]){
int satir; 
for(satir=0; satir<9; satir++){
    if(satirgecerlimi(matris,satir)==0){
        return 0;

    }
    
}
return 1; 
 }


 int sutungecerlimi(int matris[][9],int sutun){
int i,k;
for(i=0; i<9; i++){
    for(k=i+1; k<9; k++){
        if(matris[i][sutun]==matris[k][sutun])
        return 0;
    }
}
return 1; 
 }

 int sutunlargecerlimi(int matris[][9]){
    int sutun;
    for(sutun=0; sutun<9; sutun++){
        if(sutungecerlimi(matris,sutun)==0){
            return 0;
        }
    }
    return 1; 
 }

 int kutugecerlimi(int matris[][9], int kutu){
    int kutubaslangicsatiri= (kutu/3)*3;
    int kutubaslangicsutunu= (kutu % 3)*3;
int i,j,k,l;  // iki farklı hücrenin konumunu karşılaştıracağız bu yüzden iki farklı konum gerek.
    for(i=0; i<3; i++ ){
        for(j=0; j<3; j++){

        for(k = i; k < 3; k++)
            {
                  for(l = 0; l < 3; l++)
                {
             if(k == i && l <= j)//aynı satırda seçilen hücrenin solundaki hücreleri ve aynı hücreleri terkardan karşılaştırmamak için
                    {
                        continue;
                    }

             if(matris[kutubaslangicsatiri + i][kutubaslangicsutunu + j] ==
                       matris[kutubaslangicsatiri + k][kutubaslangicsutunu + l])
                    {
                        return 0;
        }
    }
}
        }
    }
    return 1; 

 }
 int kutulargecerlimi(int matris[][9]){

    int kutu;
    for(kutu=0; kutu<9; kutu++){
        if(kutugecerlimi(matris,kutu)==0){
            return 0;
        }
    }
    return 1; 

 }

 int sudokugecerlimi(int matris[][9]){
    if(satirlargecerlimi(matris)==0){
        return 0;
    }
    if (sutunlargecerlimi(matris)==0){
        return 0;
    }
    if(kutulargecerlimi(matris)==0){
        return 0; 
    }
    return 1;
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
     
    for(i=0; i<9; i++)
{
    for(j=0; j<9; j++)
    {
        if(fscanf(dosya, "%d", &matris[i][j]) != 1) // %d ile 1 tane int degeri okumayı bekleriz. 
        {
            printf("Sudoku dosyasi okunurken hata olustu.\n");
            fclose(dosya);
            return 1; // main'den çıkarız.program hata nedeniyle sonlandırıldı. 
        }
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
    printf("ilk istenilen satır gireceğiniz kısıma 0 girdiğinzde oyununuzun sonucunu görebilirsiniz. \n");

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
    
        matris[satir-1][sutun-1]=deger;
    
   }

printf("oluşturduğunuz matris şu şekildedir :\n");
for(i=0; i<9; i++){
    for(j=0; j<9; j++){
        printf("%d ", matris[i][j]);
    }
    printf("\n");
}


if(tahtadolumu(matris)){
    if(sudokugecerlimi(matris)){
        printf("sudoku başarılı, tebrikler.");
    }
    else{
        printf("sudoku başarısız!");
    }
}
else{
    printf("tahta tam dolu değil!");
}
    return 0;

    }

