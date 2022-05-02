#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdio.h>

struct point {
    float x;
    float y;
};

struct point *point_alloc(void) {
    struct point *point;

    point = malloc(sizeof(*point));
    if (point == NULL) {
        return NULL;
    }

    memset(point, 0, sizeof(*point));

    return point;
}

void point_setCoordinates(struct point *self, float x, float y) {
    self->x = x;
    self->y = y;
}

float point_getXCoordinate(struct point *self) {
    return self->x;
}

float point_getYCoordinate(struct point *self) {
    return self->y;
}

void point_free(struct point *self) {
    free(self);
}
