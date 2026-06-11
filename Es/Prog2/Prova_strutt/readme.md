per compilare si fa il **gcc** di tutti e i due file ma un solo file **.out**
l'importante è che ci sia un solo **main** tra tutti i nostri file.c

gli include locali hanno **"file.h"** mentre quelle esterne **<file.h>**

esempio compilazione: 

gcc src/file.c src/main.c -o bin/main.out

gcc -E  <- ferma il compilatore dopo il preprocessing

gcc -S  <- ferma il compilatore dopo aver creato l'assembly

gcc -c  <- ferma il compilatore dopo aver creato l'oggetto

es. 

#include <stdio.h>

#include "file.h"