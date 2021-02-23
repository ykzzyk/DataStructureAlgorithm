#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct { 
  char *element; 
  int length;
  int capacity;
} string_type;


/* function prototypes */
string_type Create(char *ary, int capacity);
void Print(string_type str);
void Length(string_type str);
void Capacity(string_type str);
void Retrieve(int i, string_type str);
string_type Concatenate(string_type str1, string_type str2);
void Copy (string_type str1, string_type str2);
void Destroy(string_type str);
bool Compare(string_type str1, string_type str2);


// Create the string type
string_type Create(char *ary, int capacity){

  string_type *p; // initial a string tyoe pointer
  int cnt = 0;

  // allocate memory
  p = (string_type *)malloc(sizeof(string_type));

  p->element = ary;
  p->capacity = capacity;

  // count the array length
  while (ary[cnt] != '\0'){
    cnt++;
  }
  p->length = cnt;
  
  return *p;
  free (p); // free the memory
}


void Print(string_type str){
  printf("The contents of string: %s\n", str.element);
}

void Length(string_type str){
  printf("The number of characters in the string: %d\n", str.length);
}

void Capacity(string_type str){
  printf("The maximum numbers of characters that can be stored in the string: %d\n", str.capacity);
}

void Retrieve(int i, string_type str){

  if ((i >= str.length) || (i < 0)){
    printf("cannot find the element %d in the string, please try again.\n", i);}
  else{
    printf("element %d of string is: %c\n", i, str.element[i]);}    
}

string_type Concatenate(string_type str1, string_type str2){

  int i = 0;
  int length = str1.length + str2.length;
  char arr[length];

  // Create a new string type
  string_type strcat = Create(arr, length); 
  strcat.length = length;
  strcat.capacity = str1.capacity + str2.capacity;

  // Concatenate two strings
    for (i = 0; i < str1.length; i++){
    strcat.element[i] = str1.element[i];
  }
    for(i = 0; i < str2.length; i++){
      strcat.element[str1.length + i] = str2.element[i];
    }

    strcat.element[strcat.length] = '\0';

    Length(strcat);
    Capacity(strcat);

  return strcat;

}

void Copy(string_type str1, string_type str2){
  
  int i = 0;

  for (i = 0; i < str1.length; i++){
    str2.element[i] = str1.element[i];
  }

  str2.element[str1.length] = '\0';

  printf("Copies the contents from s1 to s2, and now the content of s2 is: %s\n", str2.element);

}

void Destroy(string_type str){

  // string_type *p;
  // p = (string_type *)malloc(sizeof(string_type));

  // p = &str;

  // if(p){
  //   printf("not null\n");
  //   p->element = NULL;
  //   // p->length = 0;
  //   // p->capacity = 0;
  //   // free(p);
  //   // p = NULL;
  // }
  // else{
  //   printf("null");
  // }

  // free(p);


  // printf("hhh");

  // printf("true");
  // free(p);
  // p = NULL;

  // while (p->element != '\0')
  //   {
  //     free(p);
  //   }


  // /* free all pointers */

  // p->element[0] = '\0';
  // p->length = 0;
  // p->capacity = 0;

  // Print(str);
  // Length(str);
  // Capacity(str);

  // free(p->element);
  // free(p->length);
  // free(p->capacity);
  
  str.element[0] = '\0';
  str.length = 0;
  str.capacity = 0;

  // free(str1.element);

  printf("The element is successfully destroyed.\n");
}


bool Compare(string_type str1, string_type str2){

  int i = 0;
  
  for (i = 0; i < str1.length && i < str2.length; i++){
    if (str1.element[i] != str2.element[i]){
      if ((str1.element[i] - str2.element[i]) < 0){
        return true;
      }
      else{
        return false;
      }
    }
  }
  return false;
}