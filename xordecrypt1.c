#include <stdio.h>
#include <string.h>

int main(){
unsigned int readed =0;
unsigned char str[500];
unsigned char tmp = 0;
FILE *fp;
unsigned char allowed[] = "qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM";
fp = fopen("1.txt", "r");
readed = fread(str, sizeof(char)*2, 100, fp);
fclose(fp);
//scanf("%x",str);

//*for(int i =0;i<readed;i++){
        for(int j =0;j<128;j++){
                printf("%c",str[i]^=j);
        }
        printf("\n");
}*//

char inp[1024] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it";
char key[64];
int i;
char output[1024];

scanf("%s", key);
int k = strlen(key);

for (i = 0; i < strlen(inp); i++){
        output[i] = key[i%k] ^ inp[i];
        printf("%c XOR %c = ", key[i%k], inp[i]);
        printf("%x \n", output[i]);
}

//for(int i =0; i< 500 ; i++){
//      printf("str[%d] = %c\n",i,str[i]);
//}
}
