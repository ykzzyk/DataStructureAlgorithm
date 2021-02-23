#include <stdio.h>
#include <stdlib.h>
#include "String.h"

char a[] = "hello"; 
char b[] = "hi!";
char c[] = "hello everyone!";


int main(){
string_type str1, str2, str3;
str1 = Create(a, 15);
str2 = Create(b, 15);
str3 = Create(c, 40);

printf("TEST THE Print FUNCTION:\n");
Print(str1);

printf("\n\nTEST THE Length FUNCTION:\n");
Length(str1);

printf("\n\nTEST THE Capacity FUNCTION:\n");
Capacity(str1);

printf("\n\nTEST THE Retrieve FUNCTION:\n");
Retrieve(2, str1);
Retrieve(-1, str1);
Retrieve(10, str1);

printf("\n\nTEST THE Concatenate FUNCTION:\n");
Print(Concatenate(str1, str2));
Print(Concatenate(str3, str2));

printf("\n\nTEST THE Compare FUNCTION:\n");
printf("Is s1 is lexicographically greater than s2: %s\n",Compare(str1, str2) ? "true" : "false");

printf("\n\nTEST THE Copy FUNCTION:\n");
Copy(str1, str2);

printf("\n\nTEST THE Destroy FUNCTION:\n");
Destroy(str1);

// Sort given strings
printf("\n\nSorted the following strings lexicographically:\n");
string_type sortarr[17];
sortarr[0] = Create("defunct", 15);
sortarr[1] = Create("abeyance", 15);
sortarr[2] = Create("irrelevant", 15);
sortarr[3] = Create("acquiesce", 15);
sortarr[4] = Create("western", 15);
sortarr[5] = Create("zealous", 15);
sortarr[6] = Create("electric", 15);
sortarr[7] = Create("trihedral", 15);
sortarr[8] = Create("unimodal", 15);
sortarr[9] = Create("vanquish", 15);
sortarr[10] = Create("ambient", 15);
sortarr[11] = Create("abbreviate", 15);
sortarr[12] = Create("edifice", 15);
sortarr[13] = Create("genre", 15);
sortarr[14] = Create("ferrous", 15);
sortarr[15] = Create("breve", 15);
sortarr[16] = Create("brocade", 15);

int i = 0;
int j = 0;
string_type temp;

for (i = 0; i < 16; i++){
  for (j = 0; j < 16-i; j++){
    if (!Compare(sortarr[j], sortarr[j+1])){
      temp = sortarr[j+1];
      sortarr[j+1] = sortarr[j];
      sortarr[j] = temp;
    }
  }
}
for (i = 0; i < 17; i++){
  printf("%s\n", sortarr[i].element);
}

return 0;
}