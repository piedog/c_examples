#include <stdio.h>
#include <stdlib.h>


#define UpDown_MIN 0
#define UpDown_MAX 255
#define UpDown_CHANGE -1

typedef struct _UpDown {
    int direction;
    int value;
} UpDown_t;


UpDown_t *create();
void destroy(UpDown_t *r);
int get_current(UpDown_t *r);
/** ----------------------------------------------------- **/

int main(int argc, char** argv)
{
    int i;
    int N = 512;
    UpDown_t *ud = create();
    fprintf(stdout,"Up-Down test\n");

    for (i=0;i<N;i++) {
        fprintf(stdout,"val=%d\n", get_current(ud));
    }
    destroy(ud);

    return 0;
}


UpDown_t *create()
{
    UpDown_t *ud = malloc(sizeof(UpDown_t));
    if (!ud) {
        fprintf(stderr, "**error** (could not allocation UpDown_t:create)\n");
        exit(1);
    }
    ud->direction = -1;
    ud->value = UpDown_MIN;
    return ud;
}


void destroy(UpDown_t *ud)
{
    if (ud) free(ud);
}


    
int get_current(UpDown_t *ud)
{
    int temp;
    if (ud->value == UpDown_MIN) {
        ud->direction *= UpDown_CHANGE;
        temp = ud->value;
        ud->value += ud->direction;
        return temp;
    }
    else if (ud->value == UpDown_MAX) {
        ud->direction *= UpDown_CHANGE;
        temp = ud->value;
        ud->value += ud->direction;
        return temp;
    }
    temp = ud->value;
    ud->value+= ud->direction;
    return temp;
}
