#include "Object.h"

void Ball::draw() {
    DrawCircle(x, y, radius, color);
}

void Ball::start(int WINDOW_WIDTH, int WINDOW_HEIGHT) {
    x = WINDOW_WIDTH / 2;
    y = WINDOW_HEIGHT / 2;
    x_speed *= -1;
    if (rand() % 2)
        y_speed *= -1;
}



Rectangle Paddle::getRectangle() {
    return Rectangle{ x, y, width, height };
}

void Paddle::draw() {
    DrawRectangleRec(getRectangle(), color);
}

void Score::updateScore(int WINDOW_WIDTH) {
    string left_score = to_string(l_score);
    string right_score = to_string(r_score);

    int left_text_width = MeasureText(left_score.c_str(), font_size);
    int right_text_width = MeasureText(right_score.c_str(), font_size);

    x_left = WINDOW_WIDTH / 2 - left_text_width;
    x_right = WINDOW_WIDTH / 2;
}

void Text::draw() {
    DrawText(text.c_str(), x, y, font_size, color);
}

void Score::draw(int WINDOW_WIDTH) {
    string left_score = to_string(l_score);
    string right_score = to_string(r_score);

    DrawText(left_score.c_str(), x_left - font_size / 1.5, y, font_size, color);
    DrawText(right_score.c_str(), x_right + font_size / 1.5, y, font_size, color);
}
