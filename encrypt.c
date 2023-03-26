#include <stdio.h>
#include <string.h>
int main(){
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
}
