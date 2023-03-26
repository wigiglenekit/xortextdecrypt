#include <stdio.h>
#include <string.h>

int keyinc();
int inplen =0;
int main(){
char inp[1024] = "aaaaaaaaaaa";
char allowed[] = " qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM1234567890,.'\n~!@#$%^&*()_+}{\",./:][;/";
unsigned char key[64];
char output[1024];
char buff[1024];
int brlen = 1;
//scanf("%s", key);
int k = strlen(key);

//for (int i = 0; i < strlen(inp); i++){

       // output[i] = key[i%k] ^ inp[i];
        //printf("%c XOR %c = ", key[i%k], inp[i]);
        //printf("%x ", output[i]);
//}
//for(int i =0;i<1024;i++){
//      inp[i]=0;
//}
for(int i =0;i<27;i++){
        scanf("%x",output+inplen);
}

//for(int i =0;i<11;i++){
//        printf("inp[%d]=%x = %c\n",i,inp[i],inp[i]);
//}

//return 0;
//init key and key length

//for(int i =0;i<64;i++)
//{
//key[i] = '\0';
//}
//key[0]=0;
//k=0;
//int is_normal = 1;
/*for(int i =0;i<(128*128*128);i++)
{
if(keyinc(key,k) == 1)
{
printf("zaconjiliz");
return 0;
}
for(int j=0;j<k+1;j++)
{
        //printf("%d\n",j);
        printf("key[%d]=%d ",j,key[j]);
}
printf("\n");
}

return 0;*/
for(int i =0;i<64;i++)
{
key[i] = '\0';
}

k=0;
int klen=k+1;
int is_normal = 1;
//long long int max = 128*128*128*128*128*128*128;
//for(long long int p = 0; p<max;p++){ //пройтись по всем ascii
while(1){
        is_normal = 1;       //строка изначально нормальная
        for (int i = 0; i < 27; i++){ //заполнить xor данными
                buff[i] = output[i] ^ key[i%klen];
                if(strchr(allowed,buff[i])==NULL){
                        //printf("strchr(allowed,buff[%d][%x])==NULL\n",i,buff[i]);
                        is_normal=0;
                        break;
                }
        }

        /*for(int j =0;j<strlen(inp);j++){      //проверить все данные подходят под норму выйти при первом не совпадении
                if(strchr(allowed,buff[j])==NULL){
                        //if(key[0]==51){
                        //      printf("strchr(allowed,buff[%d][%c]==NULL)\n",j,buff[j]);
                        //}
                        is_normal=0;
                        break;
                }
        }*/
        if(is_normal==1){                       //если строка оказалась нормальной вывести ее
                printf("found something! on key ");
                //printf("%s",key);
                printf("\n");

                for (int i = 0; i < 27; i++){
                        printf("%c",buff[i]);
                }
                printf("\n");
        }
        if(keyinc(key,k)==1){                           //перейти к следующему варианту
                k+=1;
                klen = k+1;
                for(int i =0;i<64;i++)
                {
                        key[i] = '\0';
                }
                printf("keusize=%d\n",klen);

        }
        /*for(int j=0;j<k+1;j++)
        {
                //printf("%d\n",j);
                printf("key[%d]=%d ",j,key[j]);
        }
        printf("\n");*/

}
//printf("trying decrypt keysize=%d, output char = %c\n",k,output[i] ^ key[i%k]);
}

int keyinc(char *key, int keylength){
        if(key[keylength]<127){
                key[keylength]+=1;
                return 0 ;
        }
        else{
                if(keylength!=0){
                        key[keylength] = 0;
                        keyinc(key,keylength-1);
                }
                else{
                return 1;
                }
        }
}
