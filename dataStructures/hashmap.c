#include<stdio.h>
#include<stdlib.h>

const long MAP_SIZE = 10000001;
typedef struct Hentry Hentry;

struct Hentry{
	char* key;
	char* val;
	Hentry* next;
};

typedef struct{
	Hentry **arr;
}HashMap;

HashMap new_HashMap(HashMap *map){
	// map->arr = (typeof(map->arr))malloc(MAP_SIZE* sizeof(typeof(map->arr)));
	map->arr = (Hentry**)malloc(MAP_SIZE*sizeof(Hentry**));

	for(int i=0;i<MAP_SIZE;i++){
		map->arr[i] = NULL;
	}
	return *map;
}

// long num_hash(long n){
//     long hash = 5381;
//     int c;
// 	char s[1000]; 
// 	sprintf(s, "%d", n);
// 	char *str = &s[0];

//     while (c = *str++)
//         hash = ((hash << 5) + hash) + c; 

//     return hash%MAP_SIZE;
// }

long hash(char *str){
    long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; 

    return hash%MAP_SIZE;
}

void map_add(HashMap *map, char *key, char *val){
	Hentry e;
	e.key = key;
	e.val = val;
	e.next = NULL;

	long hash_key;
	hash_key = hash(key);

	if(!map->arr[hash_key]){
		map->arr[hash_key] = &e;
		// printf("%s --%d-- %s\n", map->arr[hash_key]->key,hash_key, map->arr[hash_key]->val);
	}
	else{
		Hentry* temp = map->arr[hash_key];
		while(temp->next){
			temp = temp->next;
		}
		temp->next = &e;
	}
}
bool map_contains(HashMap *map, char *key){
	long hash_key = hash(key);
	if(!map->arr[hash_key]){
		return false;
	}
	Hentry* temp = map->arr[hash_key];
	while(temp && temp->key!=key){
		// printf("%s -keys-- %s\n", temp->key, key);
		printf("works");
		temp = temp->next;
	}
	// printf("safe\n");
	if(!temp || temp->key!=key){
		return false;
	}
	return true;
}

char *map_get(HashMap *map, char *key){
	long hash_key = hash(key);
	if(!map->arr[hash_key]){
		return "";
	}
	Hentry* temp = map->arr[hash_key];
	// printf("%s --%d-- %s\n", map->arr[hash_key]->key,hash_key, map->arr[hash_key]->val);
	// while(temp && temp->key!=key){
	// 	printf("collision..........\n");
	// 	temp = temp->next;
	// }
	// if(!temp || temp->key!=key){
	// 	return "";
	// }
	return temp->val;
}

int main(){
	HashMap map = new_HashMap(&map);
	map_add(&map, "123", "please no err");
	printf("%s\n", map_contains(&map, "123")?"true":"false");
	printf("%s", map_get(&map, "123"));
	return 0;
}