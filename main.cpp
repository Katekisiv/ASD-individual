#include <stdio.h>
#include "Task.h"

int main()
{
    printf("\t\t\t\t\t\t\t\tMade by a student of the KM-93 group\n");
    printf("\t\t\t\t\t\t\t\tKisiv Kateryna\n");
    printf("\t\t\t\t\t\t\t\tDijkstra’s Algorithm\n\n");

    int choice, type1;
    while (true) {
        printf("Enter 1 if u want to start.\n");
        printf("If you want to end up - enter another integer number.\n");
        printf("Your choice is: ");
        type1 = scanf("%d", &choice);
        if (type1 == 1)
        {
            if (choice == 1)
            {
                Task();
            }
            else
            {
                printf("Good luck");
                break;
            }

        }
        else
        {
            printf("Wrong choice.\n");
        }
        fflush(stdin);
    }
    return 0;
}
