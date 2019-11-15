#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {insect, fish, bird, mammal} AnimalType;
typedef enum {true, false} bool;
typedef struct {String name; double size; AnimalType type;} Animal;
typedef char String[128];

char* stringType(AnimalType type){
  switch (type) {
  case insect:
    return "insect";
    break;
  case fish:
    return "fish";
    break;
  case bird:
    return "bird";
    break;
  case mammal:
    return "mammal";
    break;
  default:
    return "error";
    break;
  }
}

void print(Animal ** found, int size){
  Animal * x; 
  printf("The following new species were found:");
  int i;
  for(i = 0; i < size; i++){
    x = *(found + i);
    printf("\n%-20s has size %6.2f and is a %s", x->name, x->size, stringType(x->type));
  }
}

void room(Animal *** found, int * size){
  *size *= 2;
  *found = realloc(*found, *size * sizeof(Animal *));

  if(*found == NULL){
    perror("Could not reallocate");
  }
}

bool input(Animal * a){
  String type;

  printf("Enter animal information (\"exit\ to exit)\n");
  printf("What is the name: ");
  scanf("%s", a->name);

  if(!strcmp(a->name, "exit")){
    return false;
  }

  printf("What is the size: ");
  scanf("%1f", &a->size);

  printf("What is the type: ");
  scanf("%s", type);

  a->type = inputType(type);

  return true;
}

AnimalType type(String type{
  if(!strcmp(type, "mammal")){
    return mammal;
  }
  else if(!strcmp(type, "insect")){
    return insect;
  }
  else if(!strcmp(type, "bird")){
    return bird;
  }
  else if(!strcmp(type, "fish")){
    return fish;
  }
  else{
    perror("invalid animal type");
  }
}

int main(void){
  int size = 1;
  int index = -1;

  Animal ** found = malloc(sizeof(Animal *));

  while(true){
    Animal * a = malloc(sizeof(Animal));
    
    if(++index >= size){
      room(&found, &size);
    }

    if(!input(a)){
      break;
    }
    else{
      *(found + index) = a;
    }
  }
  
  print(found, index);
  printf("\n");
  return(EXIT_SUCCESS);
}
		 
