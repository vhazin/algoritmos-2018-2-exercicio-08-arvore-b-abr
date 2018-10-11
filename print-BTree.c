/*
Arthur Carlos da Rocha
Bernardo
Raphael
*/

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

#define MIN_NUMBER_OF_CHILDREN 3
#define MAX_NUMBER_OF_CHILDREN (2 * MIN_NUMBER_OF_CHILDREN) //this is the m

#define MIN_NUMBER_OF_KEYS (MIN_NUMBER_OF_CHILDREN - 1)
#define MAX_NUMBER_OF_KEYS (2 * MIN_NUMBER_OF_CHILDREN - 1)

typedef struct Node
{
    int isLeaf;
    int numKeys;
    int key[MAX_NUMBER_OF_KEYS + 1]; //one more to perform split child operation
    struct Node *fatherNode;
    struct Node *children[MAX_NUMBER_OF_CHILDREN + 1]; //Notice that this is an array of pointers. One for each children
} Node;

Node *createBTree()
{
    Node *root = (Node *)malloc(sizeof(Node));
    root->isLeaf = TRUE;
    root->numKeys = 0;
    root->fatherNode = root;
    return root;
}

void splitChild(Node *inputNode, int i, Node *fullChildren)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->isLeaf = fullChildren->isLeaf;
    newNode->numKeys = MIN_NUMBER_OF_KEYS;
    for (int j = 0; j < MIN_NUMBER_OF_KEYS; j++)
    {
        newNode->key[j] = fullChildren->key[j + MIN_NUMBER_OF_CHILDREN];
    }
    if (fullChildren->isLeaf == FALSE)
    {
        for (int j = 0; j < MIN_NUMBER_OF_CHILDREN; j++)
        {
            newNode->children[j] = fullChildren->children[j + MIN_NUMBER_OF_CHILDREN];
        }
    }
    fullChildren->numKeys = MIN_NUMBER_OF_KEYS;
    for (int j = inputNode->numKeys; j > i + 1; j--)
    {
        inputNode->children[j + 1] = inputNode->children[j];
    }
    inputNode->children[i + 1] = newNode;
    for (int j = inputNode->numKeys - 1; j > i; j--)
    {
        inputNode->key[j + 1] = inputNode->key[j];
    }
    inputNode->key[i] = fullChildren->key[MIN_NUMBER_OF_CHILDREN];
    inputNode->numKeys = inputNode->numKeys + 1;
}

void insertKeyNonFull(Node *inputNode, int newKey)
{
    int i = inputNode->numKeys;
    if (inputNode->isLeaf == TRUE)
    {
        while ((i >= 0) && (newKey < inputNode->key[i]))
        {
            inputNode->key[i + 1] = inputNode->key[i];
            i = i - 1;
        }
        inputNode->key[i + 1] = newKey;
        inputNode->numKeys = inputNode->numKeys + 1;
    }
    else
    {
        printf("i: %d",i);
        while ((i >= 0) && (newKey < inputNode->key[i]))
        {
            i = i - 1;
        }
        i = i + 1;

        if (inputNode->children[i]->numKeys == MAX_NUMBER_OF_KEYS)
        {

            splitChild(inputNode, i, inputNode->children[i]);
            if (newKey > inputNode->key[i] )
            {
                i = i + 1;
            }
        }
        insertKeyNonFull(inputNode->children[i], newKey);
    }
}
void insertKey(Node *inputNode, int key)
{
    Node *fatherNode = inputNode->fatherNode;
    if (inputNode->numKeys != MAX_NUMBER_OF_KEYS)
    {
        insertKeyNonFull(inputNode, key);
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node)); //remember this node is created above the input one
        inputNode->fatherNode = newNode;
        newNode->isLeaf = FALSE;
        newNode->numKeys = 0;
        newNode->children[0] = inputNode;
        splitChild(newNode, 0, fatherNode);
        insertKeyNonFull(fatherNode, key);
    }
}

void printBTree(Node *root)
{
    int nodeNumberOfChildren = root->numKeys + 1;
    printf("| ");
    for (int i = 0; i < root->numKeys; i++)
    {
        printf("%d ", root->key[i]);
    }
    printf("|\n");
    if (root->isLeaf == FALSE)
    {
        for (int i = 0; i < nodeNumberOfChildren; i++)
        {
            printBTree(root->children[i]);
        }
    }
}

int main()
{
    int numberOfKeys;
    int inputKey;
    Node *root = createBTree();
    for (int k = 0; k < numberOfKeys + 1; k++)
    {
        if (k == 0)
        {
            scanf("%d", &numberOfKeys);
            continue;
        }
        scanf("%d", &inputKey);
        insertKey(root, inputKey);
    }
    printBTree(root);
    return 0;
}