#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<stdbool.h>

struct node {

    int data;
    struct node *left;
    struct node *right;

};

struct node* insert( struct node* root, int data ) {

	if(root == NULL) {

        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;

	} else {

		struct node* cur;

		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}

		return root;
	}
}
typedef struct node node;
struct queue_node {
    node *data;
    struct queue_node *next;
};
typedef struct queue_node queue_node;

struct queue {
    int size;
    queue_node *front, *back;
};
typedef struct queue queue;

queue* create_queue(){
    queue *q = (queue*)malloc(sizeof(queue));
    if(q == NULL)return NULL;
    q->size = 0;
    q->front = q->back = NULL;
    return q;
}

bool is_queue_empty(struct queue *q){
    return q->size == 0;
}

bool push_queue(queue *q, node *data){
    if(q == NULL)return false;
    queue_node *qn = (queue_node*)malloc(sizeof(queue_node));
    if(qn == NULL)return false;
    qn->data = data;
    qn->next = NULL;
    if(is_queue_empty(q)){
        q->front = q->back = qn;
    }
    else {
        q->back->next = qn;
        q->back = qn;
    }
    q->size++;
    return true;
}

node* pop_queue(struct queue *q){
    if(q == NULL)return NULL;
    if(is_queue_empty(q))return NULL;
    node *data = q->front->data;
    if(q->size == 1){
        free(q->front);
        q->front = q->back = NULL;
    }
    else{
        queue_node *next = q->front->next;
        free(q->front);
        q->front = next;
    }
    q->size--;
    return data;
}
void levelOrder(node *root) {
    queue *q = create_queue();
    if(q == NULL)return;
    struct node *node = root;
    while(node != NULL){
        printf("%d ", node->data);
        if(node->left != NULL)push_queue(q, node->left);
        if(node->right != NULL)push_queue(q, node->right);
        node = pop_queue(q);
    }
}
int main() {

    struct node* root = NULL;

    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }

	levelOrder(root);
    return 0;
}
