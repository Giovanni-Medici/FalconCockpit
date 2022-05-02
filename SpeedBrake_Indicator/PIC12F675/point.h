#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdio.h>

#ifndef POINT_H
#define POINT_H

struct point;

struct point *point_alloc(void);
void point_free(struct point *self);

void point_setCoordinates(struct point *self, float x, float y);
float point_getXCoordinate(struct point *self);
float point_getYCoordinate(struct point *self);

#endif /* POINT_H */