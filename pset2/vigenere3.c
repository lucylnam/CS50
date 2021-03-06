/**
 * vigenere.c
 *
 * Thuy (Lucy) Nam
 * lucynam@college.harvard.edu
 *
 * This program takes a command line argument and prompts the user 
 * for a string and uses the Vigenere Cypher to encode it.
 */

#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#define LOWER_CASE 97;
#define UPPER_CASE 65;  
#define ALPHABET_LETTERS 26;

char conversion(int type, char char_in, int key);
int convert_key(int type, char char_in);

int main(int argc, char* argv[])

{
    // checks to see if there are two arguments
    if (argc != 2)
    {
        return 1;
    }
    
    // makes sure that the letters in the argument is in the alphabet
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            return 1;
        }
    }
    
    // turns argument letters into ASCII
    int key[strlen(argv[1])];
    int space = 0;
    
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        // conditions for lower case argument
        if (islower(argv[1][i]))
        {
            key[i] = convert_key(0, argv[1][i]);
        }
        
        // conditions for upper case argument
        if (isupper(argv[1][i]))
        {
            key[i] = convert_key(1, argv[1][i]);
        }
    }
    
    // prompt user for string
    string string = GetString();
    
    for (int i = 0, n = strlen(string); i < n; i++) 
    {   
        if (string[i] == 32)
        {
            space++;
        }            
        // conditions for lower case letters
        if (islower(string[i]))
        {
            if (string[i] != 32)
            {
                string[i] = conversion(0, string[i], key[(i-space)% strlen(argv[1])]);
            }
        }
        else if (isupper(string[i]))
        {
            // conditions for uppercase letters
            if (string[i] != 32)
            {
                string[i] = conversion(1, string[i], key[(i-space)% strlen(argv[1])]);
            }    
        } 
    }  
    // prints out the cyphertext
    for (int cyphertext = 0; cyphertext < strlen(string); cyphertext++)
    {
        printf("%c", string[cyphertext]);
    }  
    printf("\n");    

 
 }
 
 char conversion(int type, char char_in, int key)
{ 
    int ascii_char_in=0;
    int alpha_char_in = 0; 
    int cypher_alpha = 0;
    int cypher_ascii = 0; 
    int reducer = 0;
    char char_out = 0;
    
    if(type == 0)
    {
     reducer = LOWER_CASE;
    }
    if(type == 1)
    {
        reducer = UPPER_CASE;
    }
      ascii_char_in = char_in; 
    alpha_char_in = ascii_char_in - reducer;  
    cypher_alpha = (alpha_char_in + key) % ALPHABET_LETTERS;
    cypher_ascii = cypher_alpha + reducer;  
    char_out = cypher_ascii;
    return char_out;
}

int convert_key(int type, char char_in)
{
    int ascii_key = 0;
    int key = 0;
    int reducer = 0;
    if(type == 0)
    {
        reducer = LOWER_CASE;
    }
    if(type == 1)
    {
        reducer = UPPER_CASE;
    }       
    // turns argument into ASCII
    ascii_key = char_in;
    // turns ascii into alphabet
    key = ascii_key - LOWER_CASE;
    return key; 
 }              
