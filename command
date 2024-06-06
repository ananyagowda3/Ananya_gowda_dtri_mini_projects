#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    float cube_volume=0, sphere_volume=0, side,radius;



    while ((opt = getopt(argc, argv, "c:s:")) != -1) {
        switch (opt) {
            case 'c':
                side = atof(optarg);
                cube_volume = (side*side*side);
                printf("volume of cube is %f",cube_volume);
                break;
            case 's':
                radius = atof(optarg);
                sphere_volume = 1.33*3.14*radius*radius*radius ;
                printf("volune of sphere is %f",sphere_volume);
                break;
            default:
                printf("Invalid parameter");
        }
    }
    return 0;
}
