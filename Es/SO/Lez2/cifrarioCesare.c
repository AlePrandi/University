#include <stdio.h>
#include <string.h>


int main(void){
    char *encoded = "Kn\"eqtuq\"hqtpkueg\"wp)kpvtqfw|kqpg\"cn\"nkpiwciikq\"fk\"rtqitcooc|kqpg\"E\"g\"cnnc\"rtqitcooc|kqpg\"korgtcvkxc0\"Wp\"pwogtq\"eqpukuvgpvg\"fk\"qtg\"gb\"wvknk||cvq\"rgt\"uxqnigtg\"gugtekvc|kqpk\"kp\"ncdqtcvqtkq\"hkpcnk||cvg\"c\"rtgpfgtg\"eqphkfgp|c\"eqp\"kn\"nkpiwciikq\"vtcokvg\"nc\"tgcnk||c|kqpg\"fk\"rtqitcook\"kp\"nkpiwciikq\"E0";

    printf("Decifrato: \n");
    while(*encoded != '\0'){
        printf("%c", (*encoded)-2);
        encoded++;
    }
    puts("");
    return 0;
}