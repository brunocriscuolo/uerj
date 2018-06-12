#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct Tree {
    char character;
    int freq;
    Tree *right, *left; 
} Node;

typedef struct List{
    Node * node;
    List * next;
} NodeList;

Node * createNode (char c, int f, Node *nLeft, Node *nRight){
    Node *n = (Node*) malloc(sizeof(Node));;
    n->left = nLeft;
    n->right = nRight;
    n->character = c;
    n->freq = f;
    return n;
}

void insertHeap(Node *heap, int *n, Node insertNode){
    Node tempNode;
    heap[*n] = insertNode;
    int i = *n;
    while ( (i >= 2) and (heap[i/2].freq >= heap[i].freq) ){
        tempNode = heap[i/2];
        heap[i/2] = heap[i];
        heap[i] = tempNode;
        i = i/2;
    }
    *n = *n + 1;
}

Node removeHeap(Node *heap, int *n){
    Node tempNode;
    Node removeNode = heap[1];
    *n = *n - 1;
    heap[1] = heap[*n];
    int i = 1, temp = 0;
    while (2*i <= *n){
        temp = 2*i;
        if ((temp < *n) and (heap[temp].freq > heap[temp+1].freq))
            temp++;
        if (heap[i].freq <= heap[temp].freq)
            i = *n;
        else {
            tempNode = heap[i];
            heap[i] = heap[temp];
            heap[temp] = tempNode;
            i = temp;
        }
        
    }
    return removeNode;
}

void printNode(Node * node){
    if (node != NULL){
        if ( (node->character == '\n') or (node->character == ' '))
            cout << "Char " << (int)node->character << " Frequency " << node->freq << endl;
        else 
            cout << "Char " << node->character << " Frequency " << node->freq << endl;
    }
}

void printHeap(Node *heap, int n){
    for (int i = 1; i < n; i++){
        printNode(&heap[i]);
    }
}

void printTree (Node * node, string code){
    if ( (node->left == NULL) and (node->right == NULL) ){
        if ( (node->character == '\n') or (node->character == ' '))
            cout << "Char " << (int)node->character << " Frequency " << node->freq << " Code " << code << endl;
        else 
            cout << "Char " << node->character << " Frequency " << node->freq << " Code " << code << endl;
    } else {
        printTree(node->left, code+"0");
        printTree(node->right, code+"1");
    }
}

string compressData(char c, Node * node, string code){
    string resultCode;
    if (c == node->character)
        return code;
    else if ((node->left == NULL) and (node->right == NULL)){
        return "";
    } else {
        resultCode = compressData(c, node->left, code+"0");
        if (resultCode != "")
            return resultCode;
        resultCode = compressData(c, node->right, code+"1");
        return resultCode;
    }
    
}

Node * createTree (Node * heap, int *n){
    Node *nodeLeft, *nodeRight, *node;
    while (*n > 2){
        nodeRight = (Node*) malloc(sizeof(Node));
        *nodeRight = removeHeap(heap, n);
        nodeLeft = (Node*) malloc(sizeof(Node));
        *nodeLeft = removeHeap(heap, n);
        node = createNode(0, nodeLeft->freq + nodeRight->freq, nodeLeft, nodeRight);
        insertHeap(heap, n, *node);
    }
    return &heap[1];
}

int main() {
    string msg, completeMsg;
    int allCharacters[256];
    Node heap[257];
    int n = 1;

    
    for ( int i = 0; i < 256; i++ ){
        allCharacters[i] = 0;
    }

    while( (getline(cin, msg)) and (msg[0] != EOF) ){
        for( int i = 0; i < msg.length(); i++ ){
            allCharacters[msg[i]]++;
        }
        completeMsg = completeMsg+msg+'\n';
        allCharacters['\n']++;
    }
    
    for ( int i = 0; i < 256; i++ ){
        if ( allCharacters[i] > 0){
            Node * node = createNode(i, allCharacters[i], NULL, NULL);
            insertHeap(heap, &n, *node);
        }
    }
    
    printHeap(heap, n);
    Node * node = createTree(heap, &n);
    printTree(node, "");
    msg = "";
    for( int i = 0; i < completeMsg.length(); i++ ){
        msg = msg + compressData(completeMsg[i], node, "");
    }
    cout << "Final Message" << endl;
    cout << msg << endl;
    return 0;
}