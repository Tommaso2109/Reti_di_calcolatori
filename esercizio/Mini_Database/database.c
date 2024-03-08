
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// This represent a record in the only schema of this database
struct Persona {
    char name[20];
    char surname[50];
    char address[100];
    int age;
};

// This is a node of an index that hold a string
typedef struct IndexNodeString {
    char * value;
    struct IndexNodeString * left;
    struct IndexNodeString * right;
} IndexNodeString;

// This is a node of an index that hold an int
typedef struct IndexNodeInt {
    int value;
    struct IndexNodeInt * left;
    struct IndexNodeInt * right;
} IndexNodeInt;

// A database hold a set of records and a set of indexes
typedef struct {
    IndexNodeString * name;
    IndexNodeString * surname;
    IndexNodeString * address;
    IndexNodeInt * age;
} Database;

// TODO implement the following methods
// The method return a Persona or NULL 

IndexNodeString *create_inddexNodeString ( char* root_value){
    IndexNodeString *node = malloc(sizeof(IndexNodeString));
    if (node == NULL) {
        return NULL;
    } 
    node->value = root_value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

IndexNodeInt *create_inddexNodeInt ( int root_value){
    IndexNodeInt *node = malloc(sizeof(IndexNodeInt));
    if (node == NULL) {
        return NULL;
    } 
    node->value = root_value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertname ( IndexNodeString* node, struct Persona * persona){
    if (persona->name <= node->value) {
        if(node->right == NULL){
           IndexNodeString* node = create_inddexNodeString(persona->name);
           node->right = node;
           insertname(node->right, persona);
           return;
        }
        
    }

    if(node->left == NULL){
        IndexNodeString* node = create_inddexNodeString(persona->name);
        node->left = node;
        insertname(node->left, persona);
        return;
    }
}

void insertsurname ( IndexNodeString* node, struct Persona * persona){
    if (persona->surname <= node->value) {
        if(node->right == NULL){
           IndexNodeString* node = create_inddexNodeString(persona->surname);
           node->right = node;
           insertname(node->right, persona);
           return;
        }
    }
    
    if(node->left == NULL){
        IndexNodeString* node = create_inddexNodeString(persona->surname);
        node->left = node;
        insertsurname(node->left, persona);
        return;
    }
}

void insertaddress ( IndexNodeString* node, struct Persona * persona){
    if (persona->address <= node->value) {
        if(node->right == NULL){
           IndexNodeString* node = create_inddexNodeString(persona->address);
           node->right = node;
           insertname(node->right, persona);
           return;
        }
    }
    
    if(node->left == NULL){
        IndexNodeString* node = create_inddexNodeString(persona->address);
        node->left = node;
        insertaddress(node->left, persona);
        return;
    }
}

void insertage ( IndexNodeInt* node, struct Persona * persona){
    if (persona->age <= node->value) {
        if(node->right == NULL){
           IndexNodeInt* node = create_inddexNodeInt(persona->age);
           node->right = node;
           insertage(node->right, persona);
           return;
        }
    }
    
    if(node->left == NULL){
        IndexNodeInt* node = create_inddexNodeInt(persona->age);
        node->left = node;
        insertage(node->left, persona);
        return;
    }
}


void insert(Database * database, struct Persona * persona){
    if (database == NULL) return;

    //? insert name
    insertname(database->name, persona);

    //? insert surname
    insertsurname(database->surname, persona);

    //? insert adress
    insertaddress(database->address, persona);

    //? insert age
    insertage(database->age, persona);

}


struct Persona* findByName(Database * database, char * name){

    if (database == NULL || name == NULL) return NULL;

    IndexNodeString *nameIndex = database->name;
    while(nameIndex != NULL){
        int comparison = strcmp(name, nameIndex->value);
        if (comparison == 0){
            //?comparison   
            return (struct Persona*) nameIndex;
        }
        else if(comparison<0){
            nameIndex = nameIndex->left;
        }
        else{
            nameIndex = nameIndex->right;
        }
    }
    //? persona not found
    return NULL;

}
struct Persona* findBySurname(Database * database, char * surname){

    if (database == NULL || surname == NULL) return NULL;

    IndexNodeString *surnameIndex = database->surname;
    while(surnameIndex != NULL){
        int comparison = strcmp(surname, surnameIndex->value);
        if (comparison == 0){
            //?comparison   
            return (struct Persona*) surnameIndex;
        }
        else if(comparison<0){
            surnameIndex = surnameIndex->left;
        }
        else{
            surnameIndex = surnameIndex->right;
        }
    }
    //? persona not found
    return NULL;

}
struct Persona* findByAddress(Database * database, char * address){


    if (database == NULL || address == NULL) return NULL;

    IndexNodeString *addressIndex = database->address;
    while(addressIndex != NULL){
        int comparison = strcmp(address, addressIndex->value);
        if (comparison == 0){
            //?comparison   
            return (struct Persona*) addressIndex;
        }
        else if(comparison<0){
            addressIndex = addressIndex->left;
        }
        else{
            addressIndex = addressIndex->right;
        }
    }
    //? persona not found
    return NULL;

}
struct Persona* findByAge(Database * database, int age){
    
    if (database == NULL || age == 0) return NULL;

    IndexNodeInt *ageIndex = database->age;
    while(ageIndex != NULL){
        if (age == ageIndex->value){
            //?comparison   
            return (struct Persona*) ageIndex;
        }
        else if(age<ageIndex->value){
            ageIndex = ageIndex->left;
        }
        else{
            ageIndex = ageIndex->right;
        }
    }
    //? persona not found
    return NULL;
}
