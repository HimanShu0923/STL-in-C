#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 1000000
#define String char *

//_________________________Inputs___________________________________//
typedef long long ll;
char *nextLine()
{
    char *temp = (char *)malloc(sizeof(char *) * maxn);
    scanf("%s", temp);
    return temp;
}
long long nextInt()
{
    ll t;
    scanf("%lld", &t);
    return t;
}
double nextDouble()
{
    double t;
    scanf("%lf", &t);
    return t;
}


// __________________Main_____________________________________//

int main(){
	String name = nextLine();	
	ll age = nextInt();	

	printf("Name: %s\nAge: %d\n", name, age);
	return 0;
}