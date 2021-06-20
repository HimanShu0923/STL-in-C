#include<stdio.h>
#include<stdlib.h>

/* 
	# Initialize List
	void list_init()

	# Returns list size
	int list_size()

	# Adds element to list
	void list_add(int n)
**/

int *list;
int idx; 
int len;

void list_init(){
	list = (int*)calloc(1, sizeof(int)); 
	len= 1;
	idx = 0;
}

int list_size(){
	return idx;	
}

void list_add(int n){
	if(idx+1==len){
		list = (int*)realloc(list, len*2);
		len = len*2;
	}
	list[idx++] = n;
}

int main(){
	list_init();
	printf("size: %d\n", list_size());
	list_add(1);
	list_add(2);
	list_add(3);
	list_add(4);

	printf("size: %d\n", list_size());
	for(int i=0;i<list_size();i++){
		printf("%d ", list[i]);
	}

}

int *list_1_;
int idx_1_; 
int len_1_;

void list_1_init (){
	list_1_ = (int*)calloc(1, sizeof(int)); 
	len_1_= 1;
	idx_1_ = 0;
}

int list_1_size (){
	return idx_1_;	
}

void list_1_add(int n){
	if(idx_1_+1==len_1_){
		list_1_ = (int*)realloc(list_1_, len_1_*2);
		len_1_ = len_1_*2;
	}
	list_1_[idx_1_++] = n;
}
