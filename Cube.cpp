#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Terminal Size
#define WIDTH 80
#define HEIGHT 30

float A = 0, B = 0, C = 0; // Rotation angles around X, Y, Z
float cubeWidth = 10.0f;
float distanceFromCam = 60.0f; 
float K1 = 35.0f;
float incrementSpeed = 0.6f;

float zBuffer[WIDTH * HEIGHT];
char buffer[WIDTH * HEIGHT];
const char *shades = ".,-~:;=!*#$@"; // . -> darkest, @ -> brightest

// Light direction (Surface Normal light coming from top-front)
const float lx = 0.0f, ly = 0.70f, lz = -0.707f;

// Apply X, Y, Z rotations to any 3d vector
void rotate(float x, float y, float z, float *rx, float *ry, float *rz) {
    // Rotate around X
    float y1 = y * cosf(A) - z * sinf(A);
    float z1 = y * sinf(A) + z * cosf(A);
    float x1 = x;

    // Rotates around Y
    float x2 = x1 * cosf(B) + z1 * sinf(B);
    float z2 = -x1 * sinf(B) + z1 * cosf(B);
    float y2 = y1;

    // Rotate around Z
    *rx = x2 * cosf(C) - y2 * sinf(C);
    *ry = x2 * sinf(C) + y2 * cosf(C);
    *rz = z2;


}

void renderSurface(float cubeX, float cubeY, float cubeZ, float nx, float ny, float nz) {
    float x, y, z;
    rotate(cubeX, cubeY, cubeZ, &x, &y, &z);
    z += distanceFromCam; // Push cube in front of camera

    float ooz = 1.0f / z;

    // Now convert 3d to 2d terminal coordinate
    int screenX = (int)(WIDTH / 2 + K1 * ooz * x * 2);
}