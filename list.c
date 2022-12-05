#include <stdio.h>
#include <stdlib.h>

typedef struct nodes{
    int val;
    struct nodes* next;
}
node;
node* head;

void print(node* head){
    node* ptr = head;
    int total = 0;
    while(ptr != NULL){
        // printf("%d", ptr->val);
        ptr = ptr->next;
        total++;
    }
    printf("%d :", total); //need to print before the val
    ptr = head;
    while(ptr != NULL){
        printf(" %d", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
    //free(ptr);
}

void free_all(node* head){
    node* ptr = head, *temp = NULL;
    while(ptr != NULL){
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    free(ptr);
}

int dataCheck(node* head, int data){
    node* temp = head;
    if(head == NULL){
    	return 0;
    }
    while(temp != NULL){
    	if(temp->val == data){
    		return 1;
    	}
    	temp = temp->next;
    }
    //free(ptr);
    // free(temp);
    return 0;
}

node* insert(node* head, int data){
    node* ptr = (node*)malloc(sizeof(node));
    ptr->val = data;
    ptr->next = NULL;
    if(head == NULL){
        ptr->next = head;
        head = ptr;
        return head;
    }
    if(dataCheck(head, data) == 1){
    	return head;
    }
    if(data < head->val){
        ptr->next = head;
        head = ptr;
        return head;
    }
    node* temp = head;
    node* prev = head;
	while(temp != NULL){
		if(temp -> next == NULL){
			temp -> next = ptr;
			return head;
		}else if(data < temp -> val){
			ptr -> next = temp;
			prev -> next = ptr;
			return head;
		}else if(data < temp -> next -> val){
			ptr -> next = temp -> next;
			temp -> next = ptr;
			return head;
            // temp = head->next;
            // head->next = ptr;
            // ptr->next = temp;
            // return head;
		}
		temp = temp -> next;
    }
    // while(data > head->val){
    //     node* temp = (node*)malloc(sizeof(node));
    //     if(data <  head -> next -> val){
    //         temp = head->next;
    //         head->next = ptr;
    //         ptr->next = temp;
    //         return head;
    //     }
    //     else if(data > head -> next -> val){
    //         if(head -> next -> next != NULL){
    //             temp = head -> next -> next;
    //             head -> next = ptr;
    //             ptr -> next = temp;
    //             return head;
    //         }else{
    //             head -> next -> next = ptr;
    //             return head;
    //         }
    //     }
    //     return head;
    // }
    free(ptr);
    // free(temp);
    // free(prev);
    return head;
}

node* delete(node*head, int data){
    node* ptr = head;
    node* temp = NULL;
    // temp = NULL;
    if(head == NULL || dataCheck(head, data) == 0){
    	return head;
    }
    while(ptr != NULL){
        // temp = ptr;
        if(ptr -> val == data){
            if(head -> next == NULL){
                head = NULL;
                free(ptr);
                return head;
            }
            if(head -> val == data){
            	head = head -> next;
                free(ptr);
            	return head;
            }
            temp -> next = ptr -> next;
            free(ptr);
            return head;
        }
        temp = ptr;
        ptr = ptr -> next;
    }
    free(ptr);
    return head;
}

int main(int argc, char** argv){
    node* head = NULL;
    int data;
    char command;
    while(scanf("%c\t%d\n", &command, &data) != EOF){
    	if(command == 'i'){
    	    head = insert(head, data);
    	    print(head);
    	}
    	else if(command == 'd'){
    	    head = delete(head, data);
    	    print(head);
    	}
    }
    
    // head->val = 3;
    // node* temp = (node*)malloc(sizeof(node));
    // temp->val = 5;
    // head->next = temp;
    // temp = (node*)malloc(sizeof(node));
    // temp->val = 10;
    // temp->next = NULL;
    // head->next->next = temp;
    //insert(head, data);
    //delete(head, data);
    //print();
    //free(head);
    free_all(head);
    return EXIT_SUCCESS;
}
