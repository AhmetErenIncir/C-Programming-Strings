#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100];
    char newString[10][100];
    int i,j,ctr;
       printf("\n\n Split string by space into words :\n");
       printf("---------------------------------------\n");

    printf(" Input  a string : ");
    fgets(str1, sizeof str1, stdin); //Kullanicidan string alindi.

    j=0; ctr=0; // kopyalinacak string buffer initial edildi.
    for(i=0;i<=(strlen(str1));i++) //Girilen stringin sonuna kadar gidiliyor.
    {
        // if space or NULL found, assign NULL into newString[ctr]
        if(str1[i]==' '||str1[i]=='\0') //eger null karakter ya da bosluk bulunursa ,buffer a null koyulur.
        {
            newString[ctr][j]='\0'; //NULL koyuluyor buffer in ilgili indisine.
            ctr++;  //for next word .Bir sonraki kelime icin alt satira gecis.
            j=0;    //for next word, init index to 0 . yeni satirin harf sayisi sifirlanir.
        }
        else
        {
            newString[ctr][j]=str1[i]; //NULL ve bosluk olmadigi surece bufferin in ilgili satirina kelime kopyalanir.
            j++;
        }
    }
    printf("\n Strings or words after split by space are :\n");
    for(i=0;i < ctr;i++)
        printf(" %s\n",newString[i]); // satir satir bulunan kelimeler basilir.
    return 0;
}
