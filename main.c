#include <stdio.h>
#include <stdlib.h>

int i, location, count;
char box, bay;
float weight;
float sum;

//Question 1
//Struct changed to match a storage structure
typedef struct node{
    char bay;
    int location;
    char box;
    float weight;
    struct node *next;
} node;

//Question 2
//With a given pointer, it'll print all the values from the node.
void printNode(node *n){
    printf(" Item is located in bay: %c on location: %d in box: %c and the weight is %.2f kg \n", \
        n->bay, n->location, n->box, n->weight);
};

//Question 3
node* insert(node *ptr, char bay, int location, char box, float weight){

    node *entry = (node*)malloc(sizeof(node));
    if(entry == NULL){
        printf("No Free Memory!\n");
        exit(0);
    }
    else{

        entry->next = NULL;

        if(ptr == NULL){
            ptr = entry;
        }
        else{
            node *temp = ptr;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->bay = bay;
            temp->location = location;
            temp->box = box;
            temp->weight = weight;
            temp->next = entry;
        }
     }
     return ptr;
}

//Question 4
node* insertThousand(){
    node *ptr = NULL;
    srand(time(NULL));
    for(i = 0; i < 1000; i++){
        box = 'A' + rand() % 26;
        bay = 'A' + rand() % 26;
        location = rand()%100;
        weight = 1 + ((float) rand() / (float) RAND_MAX);
        ptr = insert(ptr, bay, location, box, weight);
    }
    return ptr;
}

//Question 5
//This function receives a pointer and
//returns the sum of ptr->weight
float totalWeight(node *ptr){
    node *temp = ptr;
    while (temp){
        sum = sum + ((float)temp->weight);
        temp = temp->next;
    }
    return sum;
}

//Question 5
//This function receives a pointer and
//returns the average of ptr->weight
float avgWeight(node *ptr){
    node *temp = ptr;
    count = 0;
    sum = 0;
    while(temp){
        sum = sum + ((float)temp->weight);
        temp = temp->next;
        count++;
    }
    return sum/count;
}

//Question 5
//This function receives a pointer and a char,
//prints the node which ptr->bay matches the given char.
void findBay(node *ptr, char c){
    node *temp = ptr;
    int countTemp = 0;
    while(temp){
        if (temp->bay == c){
            printNode(temp);
            countTemp++;
        }
        temp = temp->next;

    }
    printf("Total itens in bay %c is %d", c, countTemp);
}

int main(){

    node *first = insertThousand();

    node *temp = first;
    for (i = 0; i < 10; i++){
        printNode(temp);
        temp = temp->next;
    }

    printf("The total weight stored is %.2f \n", totalWeight(first));

    printf("The average weight stored is %.3f \n", avgWeight(first));

    findBay(first, 'X');

    return 0;
}
