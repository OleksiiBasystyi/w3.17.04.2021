/*
Условие задачи
Кузнечик начинает свой путь на клетке 0 и может прыгать на расстояние от 1 до <maxJump> клеток. Прыжки возможны только на целое число клеток вперед.
Посчитать кол-во способов <ways>, которыми кузнечик может попасть на клетку <cell>.

В файле task.in заданы целые числа:
<maxJump> <cell>

Вывести ways в task.out.

Ограничения:
1 <= maxJump <= 100
1 <= cell <= 100
1 <= ways <= 999 999 999 999 999 999

Пример ввода
2 3
Пример вывода
3
Пояснение
Кузнечик может прыгать на 1 или 2 клетки.
На 1-ю клетку он может попасть одним способом: 0->1.
На 2-ю клетку он может попасть двумя способами: 0->2, 0->1->2.
На 3-ю клетку можно попасть тремя способами: 0->1->2->3, 0->1->3, 0->2->3.
*/

#include <stdio.h>

#define MAX_CELL 101

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int maxJump, cell;
    unsigned long long ways[MAX_CELL];
    
    fscanf(in, "%d %d", &maxJump, &cell);
    
    for ( int i = 0; i <= maxJump; i++ ) {
        ways[i] = 1 << i;
    }
    
    for ( int i = maxJump; i < cell; i++ ) {
        unsigned long long way = 0;
        
        for ( int j = i - maxJump; j < i; j++ ) {
            way += ways[j];
        }
        
        ways[i] = way;
    }
    
    fprintf(out, "%llu\n", ways[cell-1]);
    
    return 0;
}
