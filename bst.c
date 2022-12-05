#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node*left;
    struct node*right;
}
node;
void free_all();

struct node* newNode(int item){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/*use to find the key in the bst. Have the same key do not insert; without the key absent*/
struct node* search(struct node* node, int key){
    if(node == NULL || node -> key == key){
        return node;
    }
    if(node -> key > key){
        return search(node -> left, key);
    }else{
        return search(node -> right, key);
    }
}

struct node* insert(struct node* node, int key){
    if(node == NULL){
        printf("inserted\n");
        return newNode(key);
    }
    if(key < node -> key){
        node -> left = insert(node -> left , key);
	}else if(key > node -> key){
		node -> right = insert(node -> right , key);
	}else{  //the key already in bst
		printf("not inserted\n");
	}
	return node;    
}

/* case 1: no child; case 2: 1 child; case 3: more than 1 child */
struct node* delete(struct node* node, int key){
    struct node *temp;
    if(node == NULL){
        return node;
    }
    if(key < node -> key){
        node -> left = delete(node -> left , key);
    }else if(key > node -> key){
        node -> right = delete(node -> right , key);
    }else{
        if(node -> right == NULL){
            temp = node -> left;
            //node = temp;
            free(node);
            return temp;
        }else if(node -> left == NULL){
            temp = node -> right;
            //node = temp;
            free(node);
            return temp;
        }else if(node -> left != NULL && node -> right != NULL){ 
            temp = node;
            while(temp != NULL && temp -> left != NULL){
                temp = temp -> left;
            }
            free(node);
            return temp;
        }else{//both are null
            free(node);
            return NULL;
        }
    }
    //free(temp);
    return node;
}

void print(struct node* node){
    if(node != NULL){
        printf("(");
        print(node -> left);
        printf("%d", node -> key);
        print(node -> right);
        printf(")");
    }
}

int main(){
	char commond;
	int key;
	struct node *node = NULL;
	while(scanf("%c" , &commond) != EOF){
        if(commond == 'i'){
            scanf("%d" , &key);
            node = insert(node , key);
        }
        else if(commond == 'd'){
            scanf("%d" , &key);
            if(search(node , key)){
                printf("deleted\n");
                }else{
                printf("absent\n");
                }
            node = delete(node , key);
        }else if(commond == 's'){
            scanf("%d" , &key);
            if(search(node , key)){
                printf("present\n");
            }else{
                printf("absent\n");
            }
        }else if(commond == 'p'){
            print(node);
            printf("\n");
        }
	}
    free_all(node);
	return EXIT_SUCCESS;
}

void free_all(struct node* node){
    struct node* head = node;
    if(head == NULL){
        return;
    }else{
        free_all(head -> right);
        free_all(head -> left);
    }
    free(head);
}
