#pragma once
#define PI 3.14159265359f
static float DToR(float degree){
    return 2.f * PI * (degree/360.f);
}
static float RToD(float radians){
    return radians * (180.f/PI);
}