#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const long MAP_SIZE = 10000000;
typedef long long ll;

typedef struct Hentry{
	char* key;
	char* value;
	Hentry* next;
} Hentry;

typedef struct{
	Hentry **arr;
}HashMap;

HashMap new_HashMap(){
	HashMap map;
	map.arr = (Hentry**)malloc(MAP_SIZE*sizeof(Hentry**));

	for(int i=0;i<MAP_SIZE;i++){
		map.arr[i] = NULL;
	}
	return map;
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

ll hash(char *str){
    ll hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; 

    return hash%MAP_SIZE;
}

void map_add(HashMap *map, char *key, char *val){
	Hentry* e = (Hentry*)malloc(sizeof(Hentry*));
	e->key = key;
	e->value = val;
	e->next = NULL;

	ll hash_key;
	hash_key = hash(key);

	if(!map->arr[hash_key]){
		map->arr[hash_key] = e;
	}
	else{
		Hentry* temp = map->arr[hash_key];
		while(temp->next){
			temp = temp->next;
		}
		temp->next = e;
	}
}
bool map_containsKey(HashMap *map, char *key){
	ll hash_key = hash(key);
	if(!map->arr[hash_key]){
		return false;
	}
	Hentry* temp = map->arr[hash_key];
	
	while(temp && temp->key!=key){
		temp = temp->next;
	}
	if(!temp || temp->key!=key){
		return false;
	}
	return true;
}

char *map_get(HashMap *map, char *key){
	ll hash_key = hash(key);
	if(!map->arr[hash_key]){
		return "";
	}
	Hentry* temp = map->arr[hash_key];
	while(temp && temp->key!=key){
		temp = temp->next;
	}
	if(!temp || temp->key!=key){
		return "";
	}
	return temp->value;
}

int main(){
	HashMap map = new_HashMap();
	map_add(&map, "123", "please no err");
	map_add(&map, "go", "ready");
	printf("%s\n", map_containsKey(&map, "123")?"true":"false");
	printf("%s\n", map_get(&map, "123"));
	printf("%s\n", map_containsKey(&map, "13")?"true":"false");
	printf("%s\n", map_containsKey(&map, "go")?"true":"false");
	printf("%s\n", map_get(&map, "go"));
	return 0;
}