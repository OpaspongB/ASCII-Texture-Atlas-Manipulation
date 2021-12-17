#include <stdio.h>
#include <stdlib.h>

void check(){
    FILE * file;

    char ch;
    int characters, lines;

    /* Open source files in 'r' mode */
    file = fopen("input.txt", "r");


    /* Check if file opened successfully */
    if (file == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");

        exit(EXIT_FAILURE);
    }

    /*
     * Logic to count characters, words and lines.
     */
    characters = lines = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        characters++;

        /* Check new line */
        if (ch == '\n' || ch == '\0')
            lines++;

    }

    /* Increment words and lines for last word */
    if (characters > 0)
    {
        lines++;
    }

    /* Print file statistics */
    printf("\n");
    printf("Total characters = %d\n", characters);
    printf("Total lines      = %d\n", lines);


    /* Close files to release resources */
    fclose(file);
}

void replaceLine(){
    FILE *fp1, *fp2;
    //'filename'is a 40 character string to store filename
    char filename[40];
    char c;
    int del_line, temp = 1;
    //asks user for file name
    printf("Enter file name: ");
    //receives file name from user and stores in 'filename'
    scanf("%s", filename);
    fp1 = fopen(filename, "r");
    if (fp1 == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");

        exit(EXIT_FAILURE);
    }
    //open file in read mode
    c = getc(fp1);
    //print the contents of file .
    while (c != EOF) {
        printf("%c", c);
        c = getc(fp1);
    }
    //ask user for line number to be deleted.
    printf("\nEnter line number to be deleted and replaced");
    scanf("%d", &del_line);
    //take fp1 to start point.
    rewind(fp1);
    //open output.txt in write mode
    fp2 = fopen("output.txt", "w");
    c = getc(fp1);
    while (c != EOF) {
        if (c == ' ') {
            temp++;
        }
        //till the line to be deleted comes,copy the content from one file to other
        if (temp != del_line){
            putc(c, fp2);
        }
        else //when the line to be deleted comes
        {
            while ((getc(fp1)) != ' ') {
            }
            //read and skip the line ask for new text
            printf("Enter new text");
            //flush the input stream
            fflush(stdin);
            putc(' ', fp2);  //put '' in new file
            while ((c = getchar()) != ' '){
                putc(c, fp2);
                //take the data from user and place it in new file
                fputs("", fp2);
                temp++;
            }
            //continue this till EOF is encountered
            getc(fp1);
        }
        //close both files
        fclose(fp1);
        fclose(fp2);
        //remove original file
        remove(filename);
        //rename new file with old name opens the file in read mode
        rename("output.txt", filename);
        fp1 = fopen(filename, "r");
        //reads the character from file
        c = getc(fp1);
        //until last character of file is encountered
        while (c != EOF){
            printf("%c", c);
            //all characters are printed
            c = getc(fp1);
        }
        //close the file pointer
        fclose(fp1);
    }
}

int main()
{
    int h;
    printf("What would you like to do? (1 for check, 2 for replace): ");
    scanf("%d", &h);
    if (h == 1){
        check();
    }
    if (h == 2){
        replaceLine();
    }
    else{
        return 0;
    }
}