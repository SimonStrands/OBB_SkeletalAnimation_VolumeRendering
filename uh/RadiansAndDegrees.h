#pragma once
#define PI 3.14159265359
static float DToR(float degree){
    return 2 * PI * (degree/360);
}
static float RToD(float radians){
    return radians * (180.f/PI);
}