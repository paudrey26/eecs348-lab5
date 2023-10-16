#include <stdio.h>

void print_score_combinations(int total_score) {
    for (int touchdown2 = 0; touchdown2 * 8 <= total_score; touchdown2++) {
        for (int touchdown1 = 0; touchdown1 * 7 <= (total_score - touchdown2 * 8); touchdown1++) {
            for (int touchdown = 0; touchdown * 6 <= (total_score - touchdown2 * 8 - touchdown1 * 7); touchdown++) {
                for (int field_goal = 0; field_goal * 3 <= (total_score - touchdown2 * 8 - touchdown1 * 7 - touchdown * 6); field_goal++) {
                    for (int safety = 0; safety * 2 <= (total_score - touchdown2 * 8 - touchdown1 * 7 - touchdown * 6 - field_goal * 3); safety++) {
                        if ((touchdown2 * 8 + touchdown1 * 7 + touchdown * 6 + field_goal * 3 + safety * 2) == total_score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", touchdown2, touchdown1, touchdown, field_goal, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int total_score = 2;
    while (total_score > 1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score:\n");
        scanf("%d", &total_score);
        print_score_combinations(total_score);
    }

    return 0;
}

