#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define get(i) get[i] 


typedef struct{
	long *get;
	int idx; 
	int len;
}vec;

void new_vec(vec *arr){
	arr->get = (typeof(arr->get))calloc(1, sizeof(typeof(arr->get))); 
	arr->len= 1;
	arr->idx = 0;
}

int vec_size(vec *arr){
	return arr->idx;	
}

void vec_add(vec *arr, auto n){
	if(arr->idx+1==arr->len){
		arr->get = (typeof(arr->get))realloc(arr->get, arr->len*2);
		arr->len = arr->len*2;
	}
	arr->get[arr->idx++] = n;
}

int main(){
	// vec arr2;
	// new_vec(&arr);
	// new_vec(&arr2);
	// printf("size: %d\n", vec_size(&arr));
	// vec_add(&arr,1);
	// vec_add(&arr,2);
	// vec_add(&arr2,3);
	// vec_add(&arr2,4);

	// printf("size: %d\n", vec_size(&arr));
	// for(int i=0;i<vec_size(&arr);i++){
	// 	printf("arr: %d ", arr.get(i));
	// 	printf("arr2: %d ", arr2.get(i));
	// }
	int t;
	scanf("%d", &t);
	while(t--){
		vec arr;
		new_vec(&arr);
		int n;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			int x;
			scanf("%d", &x);
			vec_add(&arr, x);
		}
		int flag = 0;
 	 	for(int i=0;i<n;i++){
 	       int cur = (int)sqrt((double)arr.get(i));
 	       if(cur*cur!=arr.get(i)){
				printf("YES");					
				flag = 1;	
				break;
 	       }
 	   }
		if(flag==1)continue;
		printf("NO");
		continue;
	}
		return 0;
}
