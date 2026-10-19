#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **leggi_lista(FILE *file_in, int *nof_elements);

void stampa_lista(char **array, int nof_elements);

char* parse_name(char *nome_completo);

int main(int argc, char **argv)
{

  FILE *file = fopen("lista_nomi.txt", "r");

  char *nome_completo = "paolo rossi";
  printf("Nome completo: %s \n", nome_completo);
  char *nome = parse_name(nome_completo);
  printf("Solo nome: %s \n", nome);

  free(nome);
  puts("");

  int elements = 0;
  char **array = leggi_lista(file, &elements);

  stampa_lista(array, elements);

  fclose(file);
  return 0;
}

char* parse_name(char* s){
  int size = 0;
  for(int i = 0; s[i] != '\0'; i++){
    if(s[i] == ' ') break;
    size++;
  }
  if(!s) return NULL;
  char* name= (char*)malloc(sizeof(char) * size);
  for(int i = 0; s[i] != '\0'; i++){
    if(s[i] == ' ') break;
    name[i] = s[i];
  }

  return name;
}

char **leggi_lista(FILE *file_in, int *nof_elements)
{
  if (file_in == NULL) return NULL;
  *nof_elements = 0;
  char buff[50];
  while (fgets(buff, sizeof(buff), file_in))
  {
    (*nof_elements)++;
  }

  rewind(file_in);

  char **array = (char **)malloc(sizeof(char *) * (*nof_elements));
  if (!array) return NULL;
  for (int i = 0; i < *nof_elements; i++)
  {
    fgets(buff, 50, file_in);
    buff[strcspn(buff, "\n")] = '\0';

    array[i] = malloc(strlen(buff) + 1);
    strcpy(array[i], buff);
  }
  return array;
}

void stampa_lista(char **array, int nof_elements)
{
  if (!(**array) || nof_elements == 0)
    return;

  printf("Lista: \n");
  for (int i = 0; i < nof_elements; i++)
  {
    printf("%s", array[i]);
    puts("");
  }
}