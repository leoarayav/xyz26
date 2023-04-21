#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

void encrypt(char* message, int key, char* secret);

int main() {
    char message[MAX_LENGTH];
    int key;
    
    printf("Write your message (max %d characters): ", MAX_LENGTH);
    fgets(message, MAX_LENGTH, stdin);
    
    printf("Write the key here: ");
    scanf("%d", &key);
    
    char encrypted_message[MAX_LENGTH];
    encrypt(message, key, encrypted_message);
    
    printf("Your encrypted text: ");
    for (int i = 0; i < strlen(encrypted_message); i++) 
    {
        printf("%02x", (unsigned char) encrypted_message[i]);
    }

    return 0;
}

/**
 * @brief This function encrypts a message using a substitution of the alphabet.
 * 
 * @param message The message to encrypt.
 * @param key The key to encrypt the message.
 * @param secret The encrypted message.
 * @return The encrypted message.
*/
void encrypt(char* message, int key, char* secret)
{
    int length = strlen(message);

    for(int i = 0; i < length; i++) 
    {
        if (message[i] >= 'a' && message[i] <= 'z') 
        {
            secret[i] = 'a' + (message[i] - 'a' + key) % 26;
        } else if (message[i] >= 'A' && message[i] <= 'Z') 
        {
            secret[i] = 'A' + (message[i] - 'A' + key) % 26;
        } 
        else 
        {
            secret[i] = message[i];
        }
    }
}