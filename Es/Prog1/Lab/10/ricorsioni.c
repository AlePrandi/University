#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

// Restituisce il valore minimo nell'array a[] attraverso una ricerca
// lineare. Se l'array è vuoto, restituisce INT_MAX
// Usa la ricorsione crescente:
int ritorna_minimo_cre(const size_t aLen, const int a[]); // involucro
// Usa la ricorsione decrescente:
int ritorna_minimo_dec(const size_t aLen, const int a[]); // involucro
// EXTRA: Usa la ricorsione dicotomica (dimezzamento intervalli):
int ritorna_minimo_dic(const size_t aLen, const int a[]); // involucro

//------------------------------------------------------------------

// Sostituisce tutti i numeri dispari nell'array a[] con il loro doppio
// Usa la ricorsione crescente:
void raddoppia_dispari_cre(const size_t aLen, int a[]); // involucro
// Usa la ricorsione decrescente:
void raddoppia_dispari_dec(const size_t aLen, int a[]); // involucro
// EXTRA: Usa la ricorsione dicotomica (dimezzamento intervalli):
void raddoppia_dispari_dic(const size_t aLen, int a[]); // involucro

//------------------------------------------------------------------

// Restituisce true se nell'array a[] esistono valori maggiori o uguali a val.
// Usa la ricorsione crescente:
bool esiste_maggiore_cre(const size_t aLen, const int a[], const int val); // involucro
// Usa la ricorsione decrescente:
bool esiste_maggiore_dec(const size_t aLen, const int a[], const int val); // involucro
// EXTRA: Usa la ricorsione dicotomica (dimezzamento intervalli):
bool esiste_maggiore_dic(const size_t aLen, const int a[], const int val); // involucro

//------------------------------------------------------------------

// Restituisce il numero di occorrenze degli elementi nell'array a[]
// che sono multipli di val.
// Usa la ricorsione crescente:
size_t conta_multipli_cre(const size_t aLen, const int a[], const int val); // involucro
// Usa la ricorsione decrescente:
size_t conta_multipli_dec(const size_t aLen, const int a[], const int val); // involucro
// EXTRA: Usa la ricorsione dicotomica (dimezzamento intervalli):
size_t conta_multipli_dic(const size_t aLen, const int a[], const int val); // involucro

//------------------------------------------------------------------

//------------------------------------------------------------------
// Prototipi delle funzioni ricorsive (non involucro)
//------------------------------------------------------------------

int ritorna_minimo_creR(const int a[],
                        const size_t left, const size_t right);
int ritorna_minimo_decR(const int a[],
                        const size_t left, const size_t right);
int ritorna_minimo_dicR(const int a[],
                        const size_t left, const size_t right);

void raddoppia_dispari_creR(int a[],
                            const size_t left, const size_t right);
void raddoppia_dispari_decR(int a[],
                            const size_t left, const size_t right);
void raddoppia_dispari_dicR(int a[],
                            const size_t left, const size_t right);

bool esiste_maggiore_creR(const int a[], const int val,
                          const size_t left, const size_t right);
bool esiste_maggiore_decR(const int a[], const int val,
                          const size_t left, const size_t right);
bool esiste_maggiore_dicR(const int a[], const int val,
                          const size_t left, const size_t right);

size_t conta_multipli_creR(const int a[], const int val,
                           const size_t left, const size_t right);
size_t conta_multipli_decR(const int a[], const int val,
                           const size_t left, const size_t right);
size_t conta_multipli_dicR(const int a[], const int val,
                           const size_t left, const size_t right);

// Funzioni Ausiliari ----------------------------------------------
int min(int a, int b);

//------------------------------------------------------------------

int main(void)
{
// matrice irregolare per il test
#define ROWS 8
#define COLS 15
  int mat[ROWS][COLS] = {
      {16, 20, 30, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
      {18, 3, 30, 22, 18, 71, 82, 6, 98, 57, 35, 35, 84, 19, 5},
      {79, 41, 99, 12, 66, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91},
      {63, 56, 79, 48, 28, 62, 15, 78, 100, 99, 98, 97, 96, 95, 94},
      {},
      {30, 66, 14, 88, 30, 23, 29, 50, 100, 99, 98, 97, 96, 95, 4},
      {50, 45, 72, 55, 10, 9, 71, 59, 95, 85, 16, 42, 37, 32, 70},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 11, 10, 9}};

  // Unit test per la ricerca del minimo
  puts("Ricerca del minimo:   controvariante  covariante  dicotomico");
  const int min_res[ROWS] = {1, 3, 12, 15, 0, 4, 9, 1};
  for (size_t r = 0; r < ROWS; r++)
  {
    int m1 = ritorna_minimo_cre(COLS, mat[r]);
    int m2 = ritorna_minimo_dec(COLS, mat[r]);
    int m3 = ritorna_minimo_dic(COLS, mat[r]);
    printf("[%s] Array %zu: minimo  %-16d%-12d%-8d\n",
           (m1 == min_res[r] && m2 == m1 && m3 == m1 ? "ok" : "NO"), r, m1, m2, m3);
  }
  puts("");

  // Unit test per il raddoppio dei dispari
  int mat_doppi[ROWS][COLS] = {
      {16, 20, 30, 2, 2, 6, 4, 10, 6, 14, 8, 18, 10, 22, 12},
      {18, 6, 30, 22, 18, 142, 82, 6, 98, 114, 70, 70, 84, 38, 10},
      {158, 82, 198, 12, 66, 100, 198, 98, 194, 96, 190, 94, 186, 92, 182},
      {126, 56, 158, 48, 28, 62, 30, 78, 100, 198, 98, 194, 96, 190, 94},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {30, 66, 14, 88, 30, 46, 58, 50, 100, 198, 98, 194, 96, 190, 4},
      {50, 90, 72, 110, 10, 18, 142, 118, 190, 170, 16, 42, 74, 32, 70},
      {2, 2, 6, 4, 10, 6, 14, 8, 18, 10, 22, 12, 22, 10, 18}};

  puts("Raddoppio dispari:   controvariante  covariante  dicotomico");
  for (size_t r = 0; r < ROWS; r++)
  {
    int a1[COLS], a2[COLS], a3[COLS];
    for (size_t i = 0; i < COLS; i++)
      a1[i] = a2[i] = a3[i] = mat[r][i];
    raddoppia_dispari_cre(COLS, a1);
    raddoppia_dispari_dec(COLS, a2);
    raddoppia_dispari_dic(COLS, a3);

    bool tutti_cre = true, tutti_dec = true, tutti_dic = true;
    for (size_t i = 0; i < COLS; i++)
    {
      tutti_cre = tutti_cre && (a1[i] == mat_doppi[r][i]);
      tutti_dec = tutti_dec && (a2[i] == mat_doppi[r][i]);
      tutti_dic = tutti_dic && (a3[i] == mat_doppi[r][i]);
    }
    printf("[%s] Array %zu: doppi  %-16d%-12d%-8d\n",
           (tutti_cre && tutti_dec && tutti_dic ? "ok" : "NO"), r,
           tutti_cre, tutti_dec, tutti_dic);
  }
  puts("");

  // Unit test per esistenza maggiore
  puts("Esiste maggiore:   controvariante  covariante  dicotomico");
  const bool esiste_res[ROWS] = {false, true, true, true, false, true, true, false};
  for (size_t r = 0; r < ROWS; r++)
  {
    bool e1 = esiste_maggiore_cre(COLS, mat[r], 80);
    bool e2 = esiste_maggiore_dec(COLS, mat[r], 80);
    bool e3 = esiste_maggiore_dic(COLS, mat[r], 80);
    printf("[%s] Array %zu: esiste?  %-16d%-12d%-8d\n",
           (e1 == esiste_res[r] && e2 == e1 && e3 == e1 ? "ok" : "NO"), r, e1, e2, e3);
  }
  puts("");

  // Unit test per conteggio multipli
  puts("Conta multipli:   controvariante  covariante  dicotomico");
  const size_t cm_res[ROWS] = {4, 4, 2, 3, 15, 5, 7, 3};
  for (size_t r = 0; r < ROWS; r++)
  {
    size_t c1 = conta_multipli_cre(COLS, mat[r], 5);
    size_t c2 = conta_multipli_dec(COLS, mat[r], 5);
    size_t c3 = conta_multipli_dic(COLS, mat[r], 5);
    printf("[%s] Array %zu: conteggio?  %-16zu%-12zu%-8zu\n",
           (c1 == cm_res[r] && c2 == c1 && c3 == c1 ? "ok" : "NO"), r, c1, c2, c3);
  }
  puts("");
}

int min(int a, int b)
{
  return (a < b) ? a : b;
}

// DA COMPLETARE
// Restituisce il valore minimo nell'array a[] attraverso una ricerca
// lineare. Se l'array è vuoto, restituisce INT_MAX
// Usa la ricorsione crescente:
int ritorna_minimo_cre(const size_t aLen, const int a[]) // involucro
{
  return ritorna_minimo_creR(a, 0, aLen);
}

int ritorna_minimo_dec(const size_t aLen, const int a[]) // involucro
// EXTRA: Usa la ricorsione dicotomica (dimezzamento intervalli):
{
  return ritorna_minimo_decR(a, 0, aLen);
}

int ritorna_minimo_dic(const size_t aLen, const int a[]) // involucro
{
  return ritorna_minimo_dicR(a, 0, aLen);
}

//------------------------------------------------------------------

// Sostituisce tutti i numeri dispari nell'array a[] con il loro doppio
// Usa la ricorsione crescente:
void raddoppia_dispari_cre(const size_t aLen, int a[]) // involucro
{
  return raddoppia_dispari_creR(a, 0, aLen);
}
// Usa la ricorsione decrescente:
void raddoppia_dispari_dec(const size_t aLen, int a[]) // involucro
{
  return raddoppia_dispari_decR(a, 0, aLen);
}
// EXTRA: Usa la ricorsione dicotomica (dimezzamento intervalli):
void raddoppia_dispari_dic(const size_t aLen, int a[]) // involucro
{
  return raddoppia_dispari_dicR(a, 0, aLen);
}
//------------------------------------------------------------------

// Restituisce true se nell'array a[] esistono valori maggiori o uguali a val.
// Usa la ricorsione crescente:
bool esiste_maggiore_cre(const size_t aLen, const int a[], const int val) // involucro
{
  return esiste_maggiore_creR(a, val, 0, aLen);
}
// Usa la ricorsione decrescente:
bool esiste_maggiore_dec(const size_t aLen, const int a[], const int val) // involucro
{
  return esiste_maggiore_decR(a, val, 0, aLen);
}
// EXTRA: Usa la ricorsione dicotomica (dimezzamento intervalli):
bool esiste_maggiore_dic(const size_t aLen, const int a[], const int val) // involucro
{
  return esiste_maggiore_dicR(a, val, 0, aLen);
}
//------------------------------------------------------------------

// Restituisce il numero di occorrenze degli elementi nell'array a[]
// che sono multipli di val.
// Usa la ricorsione crescente:
size_t conta_multipli_cre(const size_t aLen, const int a[], const int val) // involucro
{
  return conta_multipli_creR(a, val, 0, aLen);
}
// Usa la ricorsione decrescente:
size_t conta_multipli_dec(const size_t aLen, const int a[], const int val) // involucro
{
  return conta_multipli_decR(a, val, 0, aLen);
}
// EXTRA: Usa la ricorsione dicotomica (dimezzamento intervalli):
size_t conta_multipli_dic(const size_t aLen, const int a[], const int val) // involucro
{
  return conta_multipli_dicR(a, val, 0, aLen);
}
//------------------------------------------------------------------

//------------------------------------------------------------------
// Prototipi delle funzioni ricorsive (non involucro)
//------------------------------------------------------------------

int ritorna_minimo_creR(const int a[],
                        const size_t left, const size_t right)
{
  if (left >= right)
  {
    return INT_MAX;
  }
  else
  {
    int min = ritorna_minimo_creR(a, left + 1, right);
    return (a[left] < min) ? a[left] : min;
  }
}

int ritorna_minimo_decR(const int a[],
                        const size_t left, const size_t right)
{
  if (left >= right)
  {
    return INT_MAX;
  }
  else
  {
    int min = ritorna_minimo_decR(a, left, right - 1);
    return (a[right - 1] < min) ? a[right - 1] : min;
  }
}

int ritorna_minimo_dicR(const int a[],
                        const size_t left, const size_t right)
{
  if (left == right - 1)
  {
    return INT_MAX;
  }
  else
  {
    size_t mid = (left + (right - left) / 2);
    if (a[mid] > a[left])
    {
      int min = ritorna_minimo_dicR(a, mid, right);
      return (a[mid] < min) ? a[mid] : min;
    }
    else
    {
      int min = ritorna_minimo_dicR(a, left, mid);
      return (a[mid] < min) ? a[mid] : min;
    }
  }
}

void raddoppia_dispari_creR(int a[],
                            const size_t left, const size_t right)
{
  if (left == right - 1)
  {
    if (a[left] % 2 != 0)
    {
      a[left] = a[left] * 2;
    }
  }
  else
  {
    if (a[left] % 2 != 0)
    {
      a[left] = a[left] * 2;
    }
    raddoppia_dispari_creR(a, left + 1, right);
  }
}

void raddoppia_dispari_decR(int a[],
                            const size_t left, const size_t right)
{
  if (left == right - 1)
  {
    if (a[right - 1] % 2 != 0)
    {
      a[right - 1] = a[right - 1] * 2;
    }
  }
  else
  {
    if (a[right - 1] % 2 != 0)
    {
      a[right - 1] = a[right - 1] * 2;
    }
    raddoppia_dispari_creR(a, left, right - 1);
  }
}

void raddoppia_dispari_dicR(int a[],
                            const size_t left, const size_t right)
{
  if (left == right - 1)
  {
    if (a[left] % 2 != 0)
    {
      a[left] = a[left] * 2;
    }
  }
  else
  {
    size_t mid = (left + (right - left) / 2);
    raddoppia_dispari_dicR(a, left, mid), raddoppia_dispari_dicR(a, mid, right);
  }
}

bool esiste_maggiore_creR(const int a[], const int val,
                          const size_t left, const size_t right)
{
  if (left == right - 1)
  {
    if (a[left] == val)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return (a[left] > val) || esiste_maggiore_creR(a, val, left + 1, right);
  }
}

bool esiste_maggiore_decR(const int a[], const int val,
                          const size_t left, const size_t right)
{
  if (left == right - 1)
  {
    if (a[left] == val)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return (a[right - 1] > val) || esiste_maggiore_decR(a, val, left, right - 1);
  }
}

bool esiste_maggiore_dicR(const int a[], const int val,
                          const size_t left, const size_t right)
{
  return 0;
}

size_t conta_multipli_creR(const int a[], const int val,
                           const size_t left, const size_t right)
{
  if(left >= right){
    return 0;
  }else{
    return(a[left] % val == 0) ? 1 + conta_multipli_creR(a,val,left + 1,right) : conta_multipli_creR(a,val,left + 1,right);
  }
}


size_t conta_multipli_decR(const int a[], const int val,
                           const size_t left, const size_t right)
{
  if(left >= right){
    return 0;
  }else{
    return(a[right - 1] % val == 0) ? 1 + conta_multipli_decR(a,val,left,right - 1) : conta_multipli_decR(a,val,left,right - 1);
  }
}


size_t conta_multipli_dicR(const int a[], const int val,
                           const size_t left, const size_t right)
{
  return 0;
}