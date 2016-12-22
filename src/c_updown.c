#include <stdio.h>
#include <stdlib.h>


typedef struct _UpDown {
    int direction;
    int value;
    int lower;
    int upper;
} UpDown_t;


UpDown_t *create(int lower, int upper);
void destroy(UpDown_t *r);
int get_current(UpDown_t *r);
/** ----------------------------------------------------- **/

int main(int argc, char** argv)
{
    int i;
    int N = 511;
    UpDown_t *ud = create(0,255);
    fprintf(stdout,"Up-Down test\n");

    for (i=0;i<N;i++) {
        fprintf(stdout,"val=%d\n", get_current(ud));
    }
    destroy(ud);

    return 0;
}


UpDown_t *create(int lower, int upper)
{
    UpDown_t *ud = malloc(sizeof(UpDown_t));
    if (!ud) {
        fprintf(stderr, "**error** (could not allocation UpDown_t:create)\n");
        exit(1);
    }
    ud->direction = -1;
    ud->value = lower;
    ud->lower = lower;
    ud->upper = upper;
    return ud;
}


void destroy(UpDown_t *ud)
{
    if (ud) free(ud);
}


    
int get_current(UpDown_t *ud)
{
    int temp = ud->value;
    if (ud->value == ud->lower || ud->value == ud->upper) {
        ud->direction *= -1;
    }
    ud->value += ud->direction;
    return temp;
}
