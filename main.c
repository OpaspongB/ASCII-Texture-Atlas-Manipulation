#include <stdio.h>
#include <string.h>

char quadrant_1[100];
char quadrant_2[100];
char quadrant_3[100];
char quadrant_4[100];

void divideText(){
    FILE *file = fopen("input.txt", "r");
    // Quadrant 1
    char c_1;
    int column_1 = 1, row_1 = 0, index_1 = 0;

    while (((c_1 = fgetc(file)) != EOF) && row_1 != 10) {
        if (column_1 == 11) {
            column_1 = 0;
            row_1++;
            fseek(file, 10, SEEK_CUR);
        }
        else {
            column_1++;
            quadrant_1[index_1++] = c_1;
        }
    }

    rewind(file);
    fseek(file, 10, SEEK_CUR);

    // Quadrant 2
    char c_2;
    int column_2 = 0, row_2 = 0, index_2 = 0;

    while (((c_2 = fgetc(file)) != EOF) && row_2 != 10) {
        if (column_2 == 10) {
            column_2 = 0;
            row_2++;
            fseek(file, 10, SEEK_CUR);
            quadrant_2[index_2++] = '\n';
        }
        else {
            column_2++;
            quadrant_2[index_2++] = c_2;
        }
    }

    rewind(file);
    fseek(file, 220, SEEK_CUR);

    // Quadrant 3
    char c_3;
    int column_3 = 11, row_3 = 10, index_3 = 0;

    while (((c_3 = fgetc(file)) != EOF) && row_3 != 20) {
        if (column_3 == 21) {
            column_3 = 10;
            row_3++;
            fseek(file, 10, SEEK_CUR);
        }
        else {
            column_3++;
            quadrant_3[index_3++] = c_3;
        }
    }

    rewind(file);
    fseek(file, 230, SEEK_CUR);

    // Quadrant 4
    char c_4;
    int column_4 = 0, row_4 = 0, index_4 = 0;

    while (((c_4 = fgetc(file)) != EOF) && row_4 != 10) {
        if (column_4 == 10) {
            column_4 = 0;
            row_4++;
            fseek(file, 10, SEEK_CUR);
            quadrant_4[index_4++] = '\n';
        }
        else {
            column_4++;
            quadrant_4[index_4++] = c_4;
        }
    }

    char c, index = 0, usin[255];
    while ((c = getchar()) != 'k') {
        usin[index++] = c;
    }

    int q1Index = 0, q2Index = 0, q3Index = 0, q4Index = 0, line = 0;
    rePrint:
    for (int i = 0; i < strlen(usin); i++) {
        switch(usin[i]) {
            case 'A':
                for (int j = 0; j < 10; j++) {
                    printf("%c", quadrant_1[q1Index++]);
                }
                break;
                case 'B':
                    for (int j = 0; j < 10; j++) {
                        printf("%c", quadrant_2[q2Index++]);
                    }
                    break;
                    case 'C':
                        for (int j = 0; j < 10; j++) {
                            printf("%c", quadrant_3[q3Index++]);
                        }
                        break;
                        case 'D':
                            for (int j = 0; j < 10; j++) {
                                printf("%c", quadrant_4[q4Index++]);
                            }
                            break;
                            default:
                                printf("\n");
                                if (line < 10) {
                                    line++;
                                    q1Index += 1;
                                    q2Index += 1;
                                    q3Index += 1;
                                    q4Index += 1;
                                    goto rePrint;
                                }
        }
    }
}

int main()
{
    divideText();
}