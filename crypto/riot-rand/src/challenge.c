#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 100
#define MAX_USERNAME_LEN 11
#define MAX_ID_LEN 11

// Vulnerable function that terribly implements rand(). 
unsigned int create_id(int user_count, char *username) {
	srand(69420);
	
	int super_random_value = rand();
	return super_random_value + strlen(username) + (user_count * 69);
}

// Everything else below can be ignored.
void print_welcome() {
	printf("Welcome to the Riot Games account management system. What would you like to access today?\n");
	printf("Type any of the numbers below to access a feature:\n");
	printf("1: sign up\n");
	printf("2: log in\n");
	printf("3: view all users\n");
	printf("4: exit\n");
}

void clear_input_buffer() {
	int c;
	while (c = getchar() != '\n' && c != EOF) {}
}

int get_username(char *username_return, char *current_user_strings[], int user_count) {
	printf("Enter a username (max 10 chars) to create a Riot ID: ");
       	
	char username[MAX_USERNAME_LEN]; 
	if (fgets(username, MAX_USERNAME_LEN, stdin) == NULL) {
		printf("\nError: Invalid input given.\n");
		exit(EXIT_FAILURE);
	}	

	if (username[strlen(username) - 1] != '\n') {
		clear_input_buffer();
	}

	username[strcspn(username, "\n")] = '\0';
	if (username[0] == '\0') {
		printf("Error: Username cannot be empty.\n");
		return 0;
	}

	for (size_t i = 0; i < user_count; i++) {
		if (strcmp(username, current_user_strings[i]) == 0) {
			printf("Error: Riot username already taken.\n");
			return 0;
		}
	}
	
	for (size_t i = 0; i < strlen(username); i++) {
		if (!isalpha(username[i])) {
			printf("Error: Usernames must only include alphabet characters.\n");
			return 0;
		}
	}

	strcpy(username_return, username);
	return 1;
}

void login(unsigned int *current_user_ids) {
	char input_id[MAX_ID_LEN];
	printf("Enter Riot ID to log in to: ");
	if (fgets(input_id, MAX_ID_LEN, stdin) == NULL) {
		printf("\nError: Invalid input given.\n");
		exit(EXIT_FAILURE);	
	}
	
	if (input_id[strlen(input_id) - 1] != '\n') {
		clear_input_buffer();	
	}
	input_id[strcspn(input_id, "\n")] = '\0';

	unsigned int rand_id = current_user_ids[0];
	int n = 0;
	while (rand_id != 0) {
		n++;
		rand_id = rand_id / 10;
	}
	
	char *id = malloc(n * sizeof(char) + 1);
	snprintf(id, n * sizeof(char) + 1, "%u", current_user_ids[0]);
	if (strcmp(id, input_id) == 0) {
		printf("You have successfully logged in! Hopefully this feature will be accessible to everyone else on the Riot Games team soon.\n");
		printf("Here is your flag:\n");
		
		FILE *ptr = fopen("flag.txt", "r");

		int c;
		while (c != EOF) {
			c = fgetc(ptr);
			
			if (c != EOF) {
				fputc(c, stdout);
			}
		}
		
		fclose(ptr);
		exit(EXIT_SUCCESS);
	} else {
		printf("Only the administrator account (rand) can access the login feature.\n");
	}

	free(id);
}

void view_users(char *current_user_strings[], int user_count) {
	printf("Users currently registered: ");
	for (size_t i = 0; i < user_count; i++) {
		printf("%s", current_user_strings[i]);
		if (i != user_count - 1) {
			printf(", ");	
		} 
	}
	printf("\n");	
}

void handle_input(unsigned int *current_user_ids, char *current_user_strings[]) {
	int user_count = 1;

	int command;
	while (command != '4') {
		printf(">> ");
		
		command = getchar();
		if (command != '\n') {
			clear_input_buffer();
		}

		if (command == '1') {
			if (user_count == 100) {
				printf("Error: Maximum amount of Riot accounts has been reached. No more than 100 Riot accounts can exist.\n");
			} else {
				char *username = malloc(MAX_USERNAME_LEN * sizeof(char));
				
				int success = get_username(username, current_user_strings, user_count);
				if (success) {
					user_count++;

					current_user_strings[user_count - 1] = username;
					current_user_ids[user_count - 1] = create_id(user_count, username);
					printf("Account successfully created! Your SUPER SECURE ID is %d\n", current_user_ids[user_count - 1]);
				}	
			}
		} else if (command == '2') {
			login(current_user_ids);	
		} else if (command == '3') {
			view_users(current_user_strings, user_count);
		} else if (command != '4') {
			printf("Invalid command! Try again.\n");
		}
	}
	
	for (size_t i = 1; i < user_count; i++) {
		free(current_user_strings[i]);
	}

	return;
}

int main(void) {
	unsigned int current_user_ids[MAX_USERS] = {create_id(1, "rand")};
	char *current_user_strings[MAX_USERS] = {"rand"};	

	print_welcome();
	handle_input(current_user_ids, current_user_strings);

	return 0;
}
