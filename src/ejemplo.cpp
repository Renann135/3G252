#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
using namespace std;

#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/component/component.hpp>

#include <ftxui/component/screen_interactive.hpp>
using namespace ftxui;

string tortuga =
    string("                __  \n") +
    string("     .,-;-;-,. /'_| \n") +
    string("   _/_/_/_|_|_|) /  \n") +
    string(" '-<_><_><_><_>=/|  \n") +
    string("   `/_/====/_/-'|_| \n") +
    string("    "
           "     "
           "    "
           " \n");

int main(int argc, char const *argv[])
{

    auto pantalla = Screen::Create(
        Dimension::Full(),
        Dimension::Fixed(10));

    int x = 0;
    int y = 0;

    while (true)
    {
        x++;
        stringstream ss(tortuga);
        string linea;
        int nolinea = 0;
        while (getline(ss, linea))
        {
            int columna = 0;
            for (auto &&letra : linea)
            {
                auto &pixel = pantalla.PixelAt(x + columna, y + nolinea);
                pixel.character = letra;
                columna++;
            }
            nolinea++;
        }

        // auto &pixel = pantalla.PixelAt(x, y);
        // pixel.blink = true;
        // pixel.background_color = Color::Blue;
        // pixel.foreground_color = Color::Red;
        // pixel.character = tortuga;
        // cout << pantalla.ToString() << endl;

        pantalla.Print();
        pantalla.Clear();
        cout << pantalla.ResetPosition();
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << pantalla.ResetPosition();
    }

    return 0;
}