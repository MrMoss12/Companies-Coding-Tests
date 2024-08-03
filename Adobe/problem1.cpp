#include <stdio.h>
#include <string.h>
#include <limits.h>

#define CHAR_COUNT 256

void count_chars(char *str, int *count){
	for (int i = 0; str[i]; i++){
		count[(unsigned char)str[i]]++;
	}
}


int contains_all(int *window_count, int *t_count){
	for (int i= 0; i < CHAR_COUNT; i++) {
		if(t_count[i] > window_count[i]){
			return 0;
		}
	}
	return 1;
}

void find_min_window(char *S, char *T){
	int s_len = strlen(S);
	int t_len = strlen(T);

	if (t_len > s_len){
		printf("\n");
		return;
	}	

	int t_count[CHAR_COUNT] = {0};
	int window_count[CHAR_COUNT] = {0};


	count_chars(T,  t_count);

	int min_len = INT_MAX;
	int min_start = 0;

	int start = 0;
	int end = 0;

	while (end < s_len){
		window_count[(unsigned char)S[end]]++;
		end++;

		while (contains_all(window_count, t_count)){
			if(end - start < min_len){
				min_len = end - start;
				min_start = start;

			}

			window_count[(unsigned char)S[start]]--;
			start++;
		}
	} 

	if ( min_len == INT_MAX){
		printf("\n");
	} else {
		for (int i = min_start; i < min_start + min_len; i++){
			printf("%c", S[i]);
		}
		printf("\n");
	}
}

int main(){
	char S[2001];
	char T[101];
	
	scanf("%s %s", S,T);
	find_min_window(S,T);

	return 0;
	              	                  // Reading input from STDIN
    // Writing output to STDOUT
}
