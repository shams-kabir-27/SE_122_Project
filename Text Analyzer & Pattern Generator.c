// CONTRIBUTERS :
// Shams Kabir (242-35-154)
// Abu Ridwan Siddique (242-35-045)
// Nazifa Rahman (242-35-039)

/*******************************************************
*                                                      *
*      Text Analyzer & Pattern Generator Program       *
*                                                      *
*  This program analyzes your sentence and generates   *
*  a super cool pattern based on vowels or consonants! *
*  Enjoy the magic!                                    *
*                                                      *
*******************************************************/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

void make_heart_pattern(int row){
    printf("\n Wow! You got an even number! That means you are balanced and symmetrical, just like this beautiful heart pattern!\n\n");
    for(int i=row/2;i<=row;i+=2){
        for(int space=1;space<row-i;space+=2){
            printf("  ");
        }
        for(int j=1;j<=i;j++){
            printf("* ");
        }
        for(int space=1;space<=row-i;space++){
            printf("  ");
        }
        for(int j=1;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
    for(int i=row;i>=0;i--){
        for(int space=0;space<row-i;space++){
            printf("  ");
        }
        for(int j=1;j<=(i*2)-1;j++){
            printf(" *");
        }
        printf("\n");
    }
}

void make_pyramid_pattern(int row){
    printf("\n Oh no! You got an odd number... Well, odd numbers are unpredictable, just like this pyramid. But hey, uniqueness has its own charm!\n\n");
    for(int i=1;i<=row;i++){
        for(int space=1;space<=row-i;space++){
            printf("  ");
        }
        for(int j=1;j<=(2*i-1);j++){
            printf("* ");
        }
        printf("\n");
    }
}

int type_check_vowel(char s[]){
    int v=0;
    for(int i=0;i<strlen(s);i++){
        char ch=tolower(s[i]);
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            v++;
        }
    }
    return v;
}

int type_check_consonant(char s[]){
    int c=0;
    for(int i=0;i<strlen(s);i++){
        char ch=tolower(s[i]);
        if(isalpha(ch)&&!(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')){
            c++;
        }
    }
    return c;
}

void type_count(int consonants,int vowels){
    printf("\n Analyzing your text... \n");
    if(consonants>vowels){
        printf("\n Whoa! Your sentence is **power-packed with consonants**! \n");
        printf(" CONSONANTS: %d\n",consonants);
        printf(" VOWELS: %d\n",vowels);
    }
    else if(consonants<vowels){
        printf("\n Ooh! Your sentence is **melodic with vowels**! \n");
        printf(" VOWELS: %d\n",vowels);
        printf(" CONSONANTS: %d\n",consonants);
    }
    else{
        printf("\n Perfect harmony! **Your sentence has a perfect balance of vowels and consonants!** \n");
        printf(" Vowels & Consonants: %d each!\n",consonants);
    }
}

int pattern_length(int consonants,int vowels){
    char choice;
    int n;
    printf("\n Let's turn your text into a **cool pattern**! \n");
    do{
        printf("\n Choose your pattern base:\n");
        printf("   > Press 'C' to use **consonants**.\n");
        printf("   > Press 'V' to use **vowels**.\n");
        printf(" Your choice: ");
        scanf(" %c",&choice);
        
        switch(tolower(choice)){
            case 'c':
                n = consonants;
                printf("\n Awesome! We'll generate a pattern with %d ROWS based on consonants!\n", consonants);
                break;
            case 'v':
                n = vowels;
                printf("\n Great choice! Your pattern will have %d ROWS based on vowels!\n", vowels);
                break;
            default:
                printf("\n Oops! That's not a valid option. Try again! \n");
                n = -1;
        }
    }while(n == -1);
    return n;
}

int main(){
    char sentence[10000];
    int vowels,consonants,rows;
    printf("\n Welcome to the **Text Analyzer & Pattern Generator!** (^-^)/ \n");
    printf(" Type a sentence, and let the magic begin! \n");
    printf("\n Enter your sentence: ");
    scanf(" %[^\n]",sentence);
    vowels=type_check_vowel(sentence);
    consonants=type_check_consonant(sentence);
    type_count(consonants,vowels);
    printf("\n Now, let's create an artistic pattern based on your text! \n");
    rows=pattern_length(consonants,vowels);
    printf("\n Behold! Your custom-generated pattern is here! \n\n");
    if(rows%2==0){
        make_heart_pattern(rows);
    }
    else{
        make_pyramid_pattern(rows);
    }
    printf("\n Thanks for using the **Text Analyzer & Pattern Generator!** \n");
    printf(" Keep writing awesome sentences & spreading creativity! \n");
    return 0;
}
