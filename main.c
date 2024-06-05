#include <stdio.h>
#include <string.h>

int main()
{
    char word[] = "water";
    char input[6];
    int attempt;

    for (attempt = 1; attempt <= 5; attempt++)
    {
        printf("Enter your guess (attempt %d/5): ", attempt);
        scanf("%5s", input);

        if (strlen(input) != 5)
        {
            printf("Invalid! \n");
            attempt--;
            continue;
        }

        if (strcmp(word, input) == 0)
        {
            printf("'%s' correct\n", word);
            break;
        }
        else
        {
            for(int i=0; i<5; i++)
            {
                for(int j=i; j<5; j++)
                {
                    if(word[i]==input[j])
                    {
                        if(i==j)
                        {
                            printf("%c is in correct position\n",input[j]);
                            break;
                        }
                        else
                        {
                            printf("%c is in word but not in same position\n",input[j]);
                            break;
                        }

                    }
                    else
                    {
                        printf("%c is not in word\n",input[j]);
                        break;
                    }
                }
            }
        }
    }

    if (attempt > 5)
    {
        printf("close.The correct word was: %s\n", word);
    }

    return 0;
}
