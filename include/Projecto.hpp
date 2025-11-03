#pragma once
#include <vector>
#include <string>
#include <ftxui/screen/screen.hpp>

class Dibujo {
private:
    std::vector<std::string> frames;
    int x_pos;
    int y_pos;
    ftxui::Color color;

public:
    Dibujo(const std::vector<std::string>& ascii_frames, int start_x, int start_y, ftxui::Color draw_color);

    void Imprimir(ftxui::Screen& pantalla);
    void Mover(int dx, int dy);
    void SetY(int new_y);
    int GetHeight() const;
    int GetY() const;
};

Dibujo::Dibujo(const std::vector<std::string>& ascii_frames, int start_x, int start_y, ftxui::Color draw_color)
    : frames(ascii_frames), x_pos(start_x), y_pos(start_y), color(draw_color) {}

void Dibujo::Imprimir(ftxui::Screen& pantalla) {
    int current_y = y_pos;
    for (const auto& line : frames) {
        int current_x = x_pos;
        for (char c : line) {
            if (current_x >= 0 && current_y >= 0 && 
                current_x < pantalla.dimx() && current_y < pantalla.dimy()) {
                
                ftxui::Pixel& pixel = pantalla.PixelAt(current_x, current_y);
                if (c != ' ') {
                    pixel.character = c; 
                    pixel.foreground_color = color;
                }
            }
            current_x++;
        }
        current_y++;
    }
}

void Dibujo::Mover(int dx, int dy) {
    x_pos += dx;
    y_pos += dy;
}

void Dibujo::SetY(int new_y) {
    y_pos = new_y;
}

int Dibujo::GetHeight() const {
    return frames.size();
}

int Dibujo::GetY() const {
    return y_pos;
}