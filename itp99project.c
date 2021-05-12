#include <stdio.h>
#include <string.h>
#include "clui.h"
//Last edit date: 1/23/2021
//By Hora Haghighatkhah

/*this is a simple task manager
can creat new task see saved tasks with two kind of sort
see each task alone edit or delet it and ...*/ 

struct date
{
    int year;
    int month;
    int day;
};
struct task
{
    char name[100];
    char description[400];
    int importance;
    struct date deadline;
    int number;
};
void insertionsort(struct task arr[], int n)
{
    int i, j;
    struct task key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].importance > key.importance)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void seeourtasks1(struct task tasks[], int number)
{
    int num = 1;
    for (int i = number - 1; i >= 0; i--) //10 9 8 7 6...
    {
        printf("%d. \n", num);
        printf("NAME:             %s\n", tasks[i].name);
        printf("IMPORTANCE:       %d \n", tasks[i].importance);
        printf("DEADLINE:         %d/%d/%d\n", tasks[i].deadline.month, tasks[i].deadline.day, tasks[i].deadline.year);
        tasks[i].number = num;
        int cols = get_window_cols();
        for (int i = 0; i < cols; i++)
        {
            change_color_rgb(204, 255, 255);
            printf("*");
        }
        reset_color();
        printf("\n");
        num++;
    }
}
void seeourtasks2(struct task tasks[], int number)
{
    int num = 1;
    for (int i = 0; i < number; i++) //1 2 3 ...
    {
        printf("%d. \n", num);
        printf("NAME:             %s\n", tasks[i].name);
        printf("IMPORTANCE:       %d \n", tasks[i].importance);
        printf("DEADLINE:         %d/%d/%d\n", tasks[i].deadline.month, tasks[i].deadline.day, tasks[i].deadline.year);
        tasks[i].number = num;
        int cols = get_window_cols();
        for (int i = 0; i < cols; i++)
        {
            change_color_rgb(204, 255, 255);
            printf("*");
        }
        reset_color();
        printf("\n");
        num++;
    }
}
void seeatask(struct task tasks[], int number, int wanted)
{
    int i;
    for (i = 0; i < number; i++)
    {
        if (wanted == tasks[i].number)
        {
            printf("NAME:             %s\n", tasks[i].name);
            printf("DESCRIPTION:      %s\n", tasks[i].description);
            printf("IMPORTANCE:       %d \n", tasks[i].importance);
            printf("DEADLINE:         %d/%d/%d\n", tasks[i].deadline.month, tasks[i].deadline.day, tasks[i].deadline.year);
            break;
        }
    }
    if (i == number)
    {
        change_color_rgb(255, 128, 128);
        printf("TASK %d DOES NOT EXIST :(\n", wanted);
        reset_color();
    }
}
struct task deleter(struct task tasks[], int number, int wanted)
{
    int j;
    for (j = 0; j < number; j++)
    {
        if (tasks[j].number == wanted)
        {
            break;
        }
    }

    for (int i = j; i < number - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }
    return tasks[number - 1];
}
void printheart()
{
    int i, j, size, len;
    char text[50] = "THANKS FOR YOUR CHOICE:)";
    len = strlen(text);
    change_color_rgb(255, 128, 128);
    printf("\n");
    for (i = 20 / 2; i <= 20; i += 2)
    {
        for (j = 1; j < 20 - i; j += 2)
            printf(" ");
        for (j = 1; j <= i; j++)
            printf("*");
        for (j = 1; j <= 20 - i; j++)
            printf(" ");
        for (j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
    for (i = 20; i >= 1; i--)
    {
        for (j = i; j < 20; j++)
            printf(" ");
        if (i == 20)
        {
            for (j = 1; j <= (20 * 2 - len) / 2; j++)
                printf("*");
            change_color_rgb(153, 204, 255);
            printf("%s", text);
            change_color_rgb(255, 128, 128);

            for (j = 1; j < (20 * 2 - len) / 2; j++)
                printf("*");
        }
        else
        {
            for (j = 1; j <= (i * 2) - 1; j++)
                printf("*");
        }
        printf("\n");
    }
    reset_color();
}
int main()
{
    init_clui();
    printf("IN THE NAME OF GOD\n");
    delay(1000);
    printf("ENTER 1 TO CREAT YOUR TASK:)\n");
    int start;
    scanf("%d", &start);
    int row = get_window_rows();
    int cols = get_window_cols();
    if (start != 1)
    {
        save_cursor();
        cursor_to_pos(row / 2 - 1, cols / 4);
        change_color_rgb(204, 204, 255); //banafsh
        printf("TRY AGAIN LATER:)\n");
        reset_color();
        save_cursor();
        cursor_to_pos(row / 2, cols / 2 - 2);
        change_color_rgb(153, 204, 255); //abi
        printf("BYE");
        delay(3000);
        quit();
    }
    else
    {
        change_color_rgb(204, 255, 255); //abikam
        printf("LETS GO:)\n");
        printf("YOU CAN CREAT MORE THAN 500 TASKS HERE =)");
        reset_color();
        delay(2000);
        clear_screen();
    }
    int j;
    struct task arroftask[501];
    for (j = 0; j < 100;)
    {
        clear_screen();
        save_cursor();
        cursor_to_pos(2, cols / 2 - 10);
        change_color_rgb(255, 255, 153);
        printf("* M A I N  M E N U *\n\n");
        reset_color();
        printf(" select a number: \n\n");
        printf(" 1- Add a new task\n");
        printf(" 2- See your tasks\n");
        printf(" 3- Time to say Goodbye:)\n");

        cursor_to_pos(row - 5, 1);
        for (int i = 0; i < cols / 3; i++)
        {
            change_color_rgb(204, 153, 255);
            printf("*");
            change_color_rgb(153, 204, 255);
            printf("*");
            change_color_rgb(255, 153, 204);
            printf("*");
        }
        reset_color();
        change_color_rgb(204, 255, 204);
        printf("\n Your action is: ");
        reset_color();
        int action;
        scanf("%d", &action);
        if (action == 1) //besaz
        {
            clear_screen();
            printf(" Enter The Name: \n");
            scanf("%s", arroftask[j].name);
            //fgets(arroftask[j].name, 100, stdin);
            //fgets(arroftask[j].name, 100, stdin);
            clear_screen();
            printf(" Enter The Description: \n");
            //scanf("%s", arroftask[j].description);
            fgets(arroftask[j].description, 400, stdin);
            fgets(arroftask[j].description, 400, stdin);
            clear_screen();
            do
            {
                printf(" Enter The Importance(from 1 to 10): \n");
                scanf("%d", &(arroftask[j].importance));
                if (arroftask[j].importance > 10)
                {
                    change_color_rgb(255, 128, 128);
                    printf("please choose a number between 1 and 10\n");
                    reset_color();
                }
            } while (arroftask[j].importance > 10);
            clear_screen();
            printf(" Enter The Deadline Year(like 2022 or 22): \n");
            scanf("%d", &(arroftask[j].deadline.year));
            if ((arroftask[j].deadline.year < 2021 && arroftask[j].deadline.year > 2000) || (arroftask[j].deadline.year < 21 && arroftask[j].deadline.year > 0))
            {
                change_color_rgb(255, 128, 128);
                printf("DEADLIEN HAS EXPIRED:(\n");
                reset_color();
            }
            do
            {
                printf(" Enter The Deadline Month: \n");
                scanf("%d", &(arroftask[j].deadline.month));
                if (arroftask[j].deadline.month > 12)
                {
                    change_color_rgb(255, 128, 128);
                    printf("Choose between 1(Jan) to 12(Dec)\n");
                    reset_color();
                }

            } while (arroftask[j].deadline.month > 12);

            do
            {
                printf(" Enter The Deadline Day: \n");
                scanf("%d", &(arroftask[j].deadline.day));
                if (arroftask[j].deadline.day > 31)
                {
                    change_color_rgb(255, 128, 128);
                    printf("Choose from 1 to 31\n");
                    reset_color();
                }
            } while (arroftask[j].deadline.day > 31);

            j++;
            clear_screen();
            change_color_rgb(204, 204, 255);
            save_cursor();
            cursor_to_pos(row / 2, cols / 2 - 9);
            printf("*YOUR TASK SAVED*\n");
            restore_cursor();
            reset_color();
            delay(2000);
            clear_screen();
        }
        else if (action == 2) //bebine
        {
            clear_screen();
            printf("\nSort Tasks By:\n\n");
            printf(" 1- IMPORTANCE :)\n\n 2- TIME OF ENTERED :)");
            save_cursor();
            cursor_to_pos(row - 2, 1);
            for (int i = 0; i < cols / 2; i++)
            {
                change_color_rgb(204, 255, 255);
                printf("*");
                change_color_rgb(0, 128, 128);
                printf("*");
            }
            reset_color();
            change_color_rgb(153, 204, 255);
            printf("\n Your action is: ");
            reset_color();
            int actionsort;
            scanf("%d", &actionsort);
            restore_cursor();
            clear_screen();
            if (actionsort == 1)
            {
                insertionsort(arroftask, j);
                if (j == 0)
                {
                    change_color_rgb(255, 128, 128);
                    save_cursor();
                    cursor_to_pos(row / 2, cols / 2 - 9);
                    printf("It Is Empty :|\n");
                    restore_cursor();
                    reset_color();
                    delay(3000);
                    clear_screen();
                    continue; //main menu
                }
                seeourtasks1(arroftask, j);
            }

            else //actionsort==2 zamane vorood
            {
                if (j == 0)
                {
                    change_color_rgb(255, 128, 128);
                    save_cursor();
                    cursor_to_pos(row / 2, cols / 2 - 9);
                    printf("It Is Empty :|\n");
                    restore_cursor();
                    reset_color();
                    delay(3000);
                    clear_screen();
                    continue; //main menu
                }
                seeourtasks2(arroftask, j);
            }
            printf(" select a number:\n"); //namayesh taske khas
            printf(" 1- See an specific task\n 2- Main Menu\n");
            for (int i = 0; i < cols / 2; i++)
            {
                change_color_rgb(0, 204, 255);
                printf("*");
                change_color_rgb(0, 128, 128);
                printf("*");
            }
            reset_color();
            change_color_rgb(153, 204, 255);
            printf("\n Your action is: ");
            reset_color();
            int action2;
            scanf("%d", &action2);
            restore_cursor();
            clear_screen();
            if (action2 == 1) //taske khas
            {
                printf("Enter the task number:\n");
                int tasknumber;
                scanf("%d", &tasknumber);
                seeatask(arroftask, j, tasknumber);
                int action3;
                change_color_rgb(153, 204, 255);
                save_cursor();
                cursor_to_pos(row / 2, cols / 2 - 9);
                printf("This is Task ( %d )!\n", tasknumber);
                restore_cursor();
                cursor_to_pos(row - 8, 1);
                printf("Enter 1 to see ");
                flush();
                change_color_rgb(255, 255, 153);
                printf("MAIN MENU :)\n");
                change_color_rgb(153, 204, 255);
                printf("Enter 2 to ");
                flush();
                change_color_rgb(255, 128, 128);
                printf("DELETE");
                flush();
                change_color_rgb(153, 204, 255);
                printf(" this task! \n");
                printf("Enter 3 to ");
                flush();
                change_color_rgb(204, 255, 204);
                printf("EDIT");
                flush();
                change_color_rgb(153, 204, 255);
                printf(" this task! \n");
                reset_color();
                cursor_to_pos(row - 5, 1);
                for (int i = 0; i < cols / 2; i++)
                {
                    change_color_rgb(204, 255, 255);
                    printf("*");
                    change_color_rgb(0, 128, 128);
                    printf("*");
                }
                reset_color();
                change_color_rgb(153, 204, 255);
                printf("\n Your action is: ");
                flush();
                reset_color();
                scanf("%d", &action3);
                restore_cursor();
                if (action3 == 1) //maim menu
                {
                    continue;
                }
                else if (action3 == 2) //delete
                {
                    clear_screen();
                    change_color_rgb(255, 128, 128);
                    save_cursor();
                    cursor_to_pos(row / 2, 1);
                    printf("WARNING! ARE YOU SURE YOU WANT TO DELETE THIS TASK?\n");
                    printf("(If task does not exist, last task will be deleted instead)\n\n");
                    printf("1- YES!\n");
                    printf("2- NO !\n");
                    restore_cursor();
                    reset_color();
                    cursor_to_pos(row - 5, 1);
                    for (int i = 0; i < cols / 2; i++)
                    {
                        change_color_rgb(204, 255, 255);
                        printf("*");
                        change_color_rgb(0, 128, 128);
                        printf("*");
                    }
                    reset_color();
                    change_color_rgb(153, 204, 255);
                    printf("\n Your action is: ");
                    flush();
                    reset_color();
                    int action4;
                    scanf("%d", &action4);
                    if (action4 == 1) //delete
                    {
                        deleter(arroftask, j, tasknumber);
                        j--;
                        clear_screen();
                        change_color_rgb(255, 128, 128);
                        save_cursor();
                        cursor_to_pos(row / 2, cols / 2 - 9);
                        printf("DELETED!\n");
                        delay(3000);
                        restore_cursor();
                        reset_color();
                    }
                    else
                    {
                        continue;
                    }
                }
                else if (action3 == 3) //edit
                {
                    clear_screen();
                    printf("Change:\n 1- NAME\n 2- DESCRIPTION\n 3- IMPORTANCE\n 4- DEADLINE\n 5- ALL\n");
                    int actionedit;
                    cursor_to_pos(row - 5, 1);
                    for (int i = 0; i < cols / 2; i++)
                    {
                        change_color_rgb(204, 255, 255);
                        printf("*");
                        change_color_rgb(0, 128, 128);
                        printf("*");
                    }
                    reset_color();
                    change_color_rgb(153, 204, 255);
                    printf("\n Your action is: ");
                    flush();
                    reset_color();
                    scanf("%d", &actionedit);
                    clear_screen();
                    int editnumberinarr;
                    for (editnumberinarr = 0; editnumberinarr < j; editnumberinarr++)
                    {
                        if (arroftask[editnumberinarr].number == tasknumber)
                        {
                            break;
                        }
                    }

                    if (actionedit == 1 || actionedit == 5)
                    {
                        printf(" Enter The NEW Name: \n");
                        scanf("%s", arroftask[editnumberinarr].name);
                    }
                    if (actionedit == 2 || actionedit == 5)
                    {
                        printf(" Enter The NEW Description: \n");
                        fgets(arroftask[editnumberinarr].description, 400, stdin);
                        fgets(arroftask[editnumberinarr].description, 400, stdin);
                    }
                    if (actionedit == 3 || actionedit == 5)
                    {
                        do
                        {
                            printf(" Enter The NEW Importance(from 1 to 10): \n");
                            scanf("%d", &(arroftask[editnumberinarr].importance));
                            if (arroftask[editnumberinarr].importance > 10)
                            {
                                change_color_rgb(255, 128, 128);
                                printf("please choose a number between 1 and 10\n");
                                reset_color();
                            }
                        } while (arroftask[editnumberinarr].importance > 10);
                    }
                    if (actionedit == 4 || actionedit == 5)
                    {
                        printf(" Enter The NEW Deadline Year(like 2022 or 22): \n");
                        scanf("%d", &(arroftask[editnumberinarr].deadline.year));
                        if ((arroftask[editnumberinarr].deadline.year < 2021 && arroftask[editnumberinarr].deadline.year > 2000) || (arroftask[editnumberinarr].deadline.year < 21 && arroftask[editnumberinarr].deadline.year > 0))
                        {
                            change_color_rgb(255, 128, 128);
                            printf("DEADLIEN HAS EXPIRED:(\n");
                            reset_color();
                        }
                        do
                        {
                            printf(" Enter The NEW Deadline Month: \n");
                            scanf("%d", &(arroftask[editnumberinarr].deadline.month));
                            if (arroftask[editnumberinarr].deadline.month > 12)
                            {
                                change_color_rgb(255, 128, 128);
                                printf("Choose between 1(Jan) to 12(Dec)\n");
                                reset_color();
                            }

                        } while (arroftask[editnumberinarr].deadline.month > 12);

                        do
                        {
                            printf(" Enter The NEW Deadline Day: \n");
                            scanf("%d", &(arroftask[editnumberinarr].deadline.day));
                            if (arroftask[editnumberinarr].deadline.day > 31)
                            {
                                change_color_rgb(255, 128, 128);
                                printf("Choose from 1 to 31\n");
                                reset_color();
                            }
                        } while (arroftask[editnumberinarr].deadline.day > 31);
                    }
                    clear_screen();
                    change_color_rgb(204, 204, 255);
                    save_cursor();
                    cursor_to_pos(row / 2, cols / 2 - 9);
                    printf("*YOUR TASK EDITED*\n");
                    restore_cursor();
                    reset_color();
                    delay(2000);
                    clear_screen();
                }

                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }
        }
        else
        {
            clear_screen();
            save_cursor();
            printf("\n\n");
            printheart();
            delay(7000);
            cursor_to_pos(row / 2, cols / 2 - 2);
            change_color_rgb(153, 204, 255); //abi
            printf("BYE !\n\n");
            delay(2000);
            break; //reset with quit function
        }
    }
    quit();
    return 0;
}