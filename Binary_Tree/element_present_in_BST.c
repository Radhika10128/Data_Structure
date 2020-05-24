#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    struct node *left,*right;
    int val;
};
typedef struct node node;
node * addElement(node * root, int x);
int isPresent(node* root, int val){
    if(root==NULL)
      return 0;
  if(root->val>val)
    return isPresent(root->left,val);
  else
  {
    if(root->val<val)
      return isPresent(root->right,val);
    else
      return 1;
  }

  //return isPresent(root->left,val) || isPresent(root->right,val);
}
int main(){
    node * root = NULL;
    int a[100005],K,i = 0,j = 0, _element, present;

    scanf("%d",&K);
    for( j = 0; j < K;j++ ) {
        scanf("%d",&a[i++]);
    }

    for( i = 0; i < K;i++ ){
        root = addElement(root,a[i]);
    }

    int q;
    scanf("%d", &q);

    while (q--) {
        scanf("%d",&_element);
        present = isPresent(root, _element);
        printf("%d\n", present);
    }

    return 0;
}
node * addElement(node * root, int x ){
    if( root == NULL ) {
        root = (node *) (malloc(sizeof(node)));
        root->val = x;
        root->left = NULL; root->right = NULL;
        return root;
    }
    if( x <= root->val ) {
         root->left = addElement(root->left,x);
    }
    else {
        root->right = addElement(root->right,x);
    }
    return root;
}
