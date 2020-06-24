#include "lab51.h" // 请不要删除本行头文件，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

void search(const struct part inv[], int np)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, inv, np);
    if (i >= 0) {
        printf("Part name: %s\n", inv[i].name);
        printf("Quantity on hand: %d\n", inv[i].on_hand);
    } else
        printf("Part not found.\n");
}
