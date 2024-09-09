#include <stdio.h>
#include <stdlib.h> 

typedef struct {  
    int volume;  
    int value;  
} Item;

int compare(const void *a, const void *b) {  
    Item *itemA = (Item *)a;  
    Item *itemB = (Item *)b;  
    double densityA = (double)itemA->value / itemA->volume;  
    double densityB = (double)itemB->value / itemB->volume;  
    if (densityA > densityB) return -1;  
    if (densityA < densityB) return 1;  
    return 0;  
} 

int main() 
{
    int n, x;
    while (scanf("%d %d", &n, &x) != EOF) { 
        printf("%d\n", n + x);
    }
    Item items[n];
    int totalValue = 0; 
    for (int i = 0; i < n; i++) {  
        scanf("%d %d", &items[i].volume, &items[i].value);  
    }
    qsort(items, n, sizeof(Item), compare);  
    for (int i = 0; i < n; i++) {  
        if (items[i].volume <= x) {  
            totalValue += items[i].value;  
            x -= items[i].volume;  
        } else {  
            break;  
        }  
    }  
    printf("%d\n", totalValue);  
    return 0;
}

