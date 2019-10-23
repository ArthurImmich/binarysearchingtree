#include <stdio.h>
#include <stdlib.h>

typedef struct tree{

    int info;
    struct tree *left, *right;

}t_tree;

t_tree *init(){
    return NULL;
}

t_tree *newleaf (int info){

    t_tree *leaf= (t_tree *) malloc(sizeof(t_tree));

    leaf->info=info;
    leaf->left=leaf->right=NULL;

    return leaf;
}

void *insert(t_tree **tree, t_tree *leaf){

    if (!*tree) *tree = leaf;
    else insert( leaf->info <= (*tree)->info ? &(*tree)->left : &(*tree)->right , leaf);

}

void print(t_tree *tree){

    if(tree!=NULL){
	print(tree->left);
    printf("%d ", tree->info);
	print(tree->right);
    }
}

t_tree *retira (t_tree *r, int v){

if (!r) return NULL;
else if (r->info > v)
		r->left = retira(r->left, v);
	else if (r->info < v)
		r->right = retira(r->right, v);
	else {
		if (r->left == NULL && r->right == NULL) {
			free (r);
			r = init();
		}
		else if (r->left == NULL) {
			t_tree *t = r;
			r = r->right;
			free (t);
		}
		else if (r->right == NULL) {
			t_tree *t = r;
			r = r->left;
			free (t);
		}
		else {
			t_tree *parent = r;
			t_tree *son = r->left;
			while (son->right != NULL) {
				parent = son;
				son = son->right;
			}
			r->info = son->info;
			son->info = v;
			r->left = retira(r->left, v);
		}
	}
return r;
}

int main(){

    t_tree *tree;

    tree=init();
    insert(&tree, newleaf(50));
    insert(&tree, newleaf(60));
    insert(&tree, newleaf(40));
    insert(&tree, newleaf(70));
    print(tree);
    retira(tree, 40);
    puts("");
    print(tree);
}
