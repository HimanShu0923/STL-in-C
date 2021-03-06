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

void HashMap_add(HashMap *map, char *key, char *val){
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
bool HashMap_containsKey(HashMap *map, char *key){
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

char *HashMap_get(HashMap *map, char *key){
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

void HashMap_remove(HashMap *map, char* key)
{
	ll hash_key = hash(key);
	
	map->arr[hash_key] = NULL;
}
//======================================================================//


int main(){
	HashMap map = new_HashMap();
	HashMap_add(&map, "123", "please no err");
	HashMap_add(&map, "go", "ready");
	printf("%s\n", HashMap_containsKey(&map, "123")?"true":"false");
	printf("%s\n", HashMap_get(&map, "123"));
	printf("%s\n", HashMap_containsKey(&map, "13")?"true":"false");
	printf("%s\n", HashMap_containsKey(&map, "go")?"true":"false");
	printf("%s\n", HashMap_get(&map, "go"));

	printf("Remove 123\n");
	HashMap_remove(&map, "123");
	printf("%s\n", HashMap_containsKey(&map, "123")?"true":"false");
	printf("%s\n", HashMap_get(&map, "123"));
	return 0;
}