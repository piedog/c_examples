/*
    Develop a function that returns an integer value. The first time called, a zero is returned.
    On each subsequent call, the result returned is incremented by 1 until after it becomes 255.
    At this point, each subsequent call decrements the result, until after it becomes zero. At
    which point, the result is incremented, and so on.
        0, 1, ..., 254, 255, 254, ..., 1, 0, 1, ...

    Algorithm:

    Initialize the result to 0 (this will be the current result)
    Initialize the direction to down (-1)
    Save the current result in a temporary variable
    If the current result is either 0 or 255, then reverse direction by multiplying the direction by -1
    Add the direction value to the result
        Obviously, decrementing will occur when direction is -1, and incrementing will occur if +1
    Return the saved result
 */
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
