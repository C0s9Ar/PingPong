#pragma once
#include "Common.h"

struct Object {
    float x = 0, y = 0;
    Color color = WHITE;
};

struct Ball : Object {
    float x_speed, y_speed;
    float radius;
    void draw();
    void start(int WINDOW_WIDTH, int WINDOW_HEIGHT);
};

struct Paddle : Object {
    float width, height;
    float speed;

    Rectangle getRectangle();
    void draw();
};

struct Text : Object{
    string text;
    int font_size;
    void draw();
};

struct Score : Text {
    int l_score = 0, r_score = 0;
    int x_left, x_right, y;

    void updateScore(int WINDOW_WIDTH);
    void draw(int WINDOW_WIDTH);
};
