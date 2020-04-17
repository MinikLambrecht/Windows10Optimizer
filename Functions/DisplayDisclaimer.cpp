#include "TextJustification.cpp"
#include <string.h>
#include <iostream>
#include <windows.h>

class DisplayDisclaimer
{
    public:
        void PlaceCursor (const int x, const int y)
        {

            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

            COORD PlaceCursorHere;
            PlaceCursorHere.X = x;
            PlaceCursorHere.Y = y;

            SetConsoleCursorPosition(hConsole, PlaceCursorHere);
            return;
        }

        void Display()
        {
            std::cout << "***********************************DISCLAIMER***********************************" << std::endl;

            std::string Disclaimer = "Windows10Optimizer and the supporting code and scripts are free and open-source"
                                     "under the GPL Public License version 3. By running Windows10Optimizer you take complete responsibility"
                                     "for anything that may happen. There is NO WARRENTY, you run it at you OWN RISK,"
                                     "anything that happens (good or bad), is YOUR RESPONSIBILITY. USE AT OWN RISK";

            printText(Disclaimer, Alignment::Left);

            std::cout << std::endl <<  "Do you agree to these terms? (y/n): ";

            char ans;

            std::cin >> ans;

            switch (ans)
            {
                case 'y':

                break;

                case 'n':
                    exit(0);
                break;
            }
        }
};
