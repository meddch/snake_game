#pragma once


#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>

using namespace std;

static bool allowMove;
extern Color green;
extern Color darkGreen;

extern int cellSize;
extern int cellCount;
extern int offset;

extern double lastUpdateTime;


bool ElementInDeque(Vector2 element, deque<Vector2> deque);
bool EventTriggered(double interval);
