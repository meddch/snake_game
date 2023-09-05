#include "game.cpp"


Color white = {255, 255, 255, 255};

int main()
{
    InitWindow(2 * offset + cellSize * cellCount, 2 * offset + cellSize * cellCount, "Snake");
    SetTargetFPS(90);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        if (EventTriggered(0.2))
        {
            allowMove = true;
            game.Update();
        }

        if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1 && allowMove)
        {
            game.snake.direction = {0, -1};
            game.running = true;
            allowMove = false;
        }
        if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1 && allowMove)
        {
            game.snake.direction = {0, 1};
            game.running = true;
            allowMove = false;
        }
        if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1 && allowMove)
        {
            game.snake.direction = {-1, 0};
            game.running = true;
            allowMove = false;
        }
        if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1 && allowMove)
        {
            game.snake.direction = {1, 0};
            game.running = true;
            allowMove = false;
        }

        ClearBackground(green);
        DrawRectangleLinesEx(Rectangle{(float)offset - 5, (float)offset - 5, (float)cellSize * cellCount + 10, (float)cellSize * cellCount + 10}, 5, darkGreen);
        DrawText("Snake", offset - 5, 20, 40, white);
        DrawText(TextFormat("%i", game.score), offset - 5, offset + cellSize * cellCount + 10, 40, white);
        game.Draw();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}