#include "Common.h"
#include "Object.h"

int main() {
	srand(time(NULL));
	string title = "Ping Pong";
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	Color bg_color = BLACK;
	SetWindowState(FLAG_VSYNC_HINT);
	//SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, title.c_str());

	Ball ball;
	ball.x_speed = 300; ball.y_speed = 300;
	ball.radius = 5;
	ball.color = WHITE;
	ball.start(WINDOW_WIDTH, WINDOW_HEIGHT);

	Paddle left_paddle;
	left_paddle.width = 12, left_paddle.height = 110;
	left_paddle.x = 20, left_paddle.y = WINDOW_HEIGHT / 2 - left_paddle.height / 2;
	left_paddle.speed = 400;
	left_paddle.color = WHITE;

	Paddle right_paddle;
	right_paddle.width = 12, right_paddle.height = 110;
	right_paddle.x = WINDOW_WIDTH - 20 - right_paddle.width, right_paddle.y = WINDOW_HEIGHT / 2 - right_paddle.height / 2;
	right_paddle.speed = 400;
	right_paddle.color = WHITE;

	Score score;
	score.font_size = 125;
	score.x = WINDOW_WIDTH / 2 - score.font_size / 2, score.y = 30;
	score.color = Color{ 255, 255, 255, 200 };
	score.updateScore(WINDOW_WIDTH);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(bg_color);

		ball.draw();
		left_paddle.draw();
		right_paddle.draw();
		score.draw( WINDOW_WIDTH);

		DrawRectangle(WINDOW_WIDTH / 2 - 1, 0, 2, WINDOW_HEIGHT, WHITE);
		EndDrawing();

		ball.x += ball.x_speed * GetFrameTime(), ball.y += ball.y_speed * GetFrameTime();
		if (ball.x - ball.radius >= WINDOW_WIDTH) {
			score.l_score++;
			score.updateScore(WINDOW_WIDTH);
			ball.start(WINDOW_WIDTH, WINDOW_HEIGHT);
		}
		else if (ball.x + ball.radius <= 0){
			score.r_score++;
			score.updateScore(WINDOW_WIDTH);
			ball.start(WINDOW_WIDTH, WINDOW_HEIGHT);
		}

		if (ball.y + ball.radius > WINDOW_HEIGHT){
			ball.y = WINDOW_HEIGHT - ball.radius;
			ball.y_speed *= -1;
		}
		else if (ball.y - ball.radius < 0) {
			ball.y = ball.radius;
			ball.y_speed *= -1;
		}

		if (IsKeyDown(KEY_W)) 
			if (left_paddle.y > 0)
				left_paddle.y -= left_paddle.speed * GetFrameTime();
		if (IsKeyDown(KEY_S)) 
			if (left_paddle.y + left_paddle.height < WINDOW_HEIGHT)
				left_paddle.y += left_paddle.speed * GetFrameTime();

		if (IsKeyDown(KEY_UP))
			if (right_paddle.y > 0) 
				right_paddle.y -= right_paddle.speed * GetFrameTime();
		if (IsKeyDown(KEY_DOWN))
			if (right_paddle.y + right_paddle.height < WINDOW_HEIGHT) 
				right_paddle.y += right_paddle.speed * GetFrameTime();
		
		if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, left_paddle.getRectangle()))
			if (ball.x_speed < 0) {
				ball.x_speed *= -1;
			}
		if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, right_paddle.getRectangle()))
			if (ball.x_speed > 0) {
				ball.x_speed *= -1;
			}
	}

	CloseWindow();
	return 0;
}