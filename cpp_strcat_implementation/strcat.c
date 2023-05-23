#include <stdio.h>
#include <stdlib.h>
int my_strlen(char const* str);
char* my_strcat(const char* str1, const char* str2, char* ptr);

int main() {
	char *ptr = NULL;
	char str1[] = "Hello";
	char str2[] = "World";

	printf("%s", ptr = my_strcat(str1, str2, ptr));
	free(ptr);
	return 1;
}

int my_strlen(char const* str){
	int len;
	for(len = 0; str[len] != '\0'; len++);
	return len;
}

char* my_strcat(const char* str1, const char* str2, char* ptr) {
	int i = 0, j;
	int len_str1 = my_strlen(str1), len_str2 = my_strlen(str2);
	int len_all = len_str1 + len_str2 + 2;

	ptr = (char *) calloc((len_all), sizeof(char));
	if (ptr == NULL) {
		//raise error
		return 0;
	}
	else {
		//Memory successfully allocated. First Word injecting
		for(j = 0; j < len_str1; j++){
			*(ptr + j) = *(str1 + j);
		}
		//Space injecting
		*(ptr + j) = ' ';
		j++;
		//Second word injecting
		for( ; j < len_all; j++){
			*(ptr + j) = *(str2 + i);
			i++;
		}
		//printf("%s", ptr);
	}
	return ptr;
}
