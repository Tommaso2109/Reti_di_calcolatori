
//! parte da rimuovere

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node * left;
    struct Node * right;
} Node;

Node* create_tree(int root_value) {
    Node *root = malloc(sizeof(Node));
    if (root == NULL) {
        return NULL;
    } 
    root->value = root_value;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void free_tree(Node* root) {
    free(root);
}

void insert_inorder(Node *root, int value) {
    if (root == NULL) {
        return;
    }
    if (value <= root->value) {
        if (root->left == NULL) {
            Node *node = create_tree(value);
            root->left = node;
            return;
        }
        insert_inorder(root->left, value);
        return;
    }
    if (root->right == NULL) {
        Node *node = create_tree(value);
        root->right = node;
        return;
    }
    insert_inorder(root->right, value);
}

void print_tree(Node * root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d\n", root->value);
    print_tree(root->right);
}

int main(int argc, const char * argv[]) {
    Node *root = create_tree(12);

    insert_inorder(root, 34);
    insert_inorder(root, 1);
    insert_inorder(root, -5);
    
    print_tree(root);

    free_tree(root); 
}

//! ############################################################################### !//


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

void insert(Database * database, Persona * persona){
    
}
Persona* findByName(Database * database, char * name){

}
Persona* findBySurname(Database * database, char * surname){

}
Persona* findByAddress(Database * database, char * address){

}
Persona* findByAge(Database * database, int age){
    
}