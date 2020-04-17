#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

class Menus
{
    private:
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

        std::vector<std::string> MenuEntries;

        // Reset the cursor position to the top left, and clear the screen.
        // With the use of this function instead of "system(cls)" we wont
        // Experience the screen flickering.
        void ClearScreen()
        {
            // Initialize a COORD variable and set both values to 0.
            // Then set the console cursor position with the defined coordinates.
            // meaning the cursor will default to the top left corner (0, 0).
            COORD cursorPosition; cursorPosition.X = 0; cursorPosition.Y = 0;
            SetConsoleCursorPosition(out, cursorPosition);
        }


        // Get the cursor information and change the visibility.
        // By doing this, the cursor wont flicker every now and then,
        // when you scroll through the menuentries.
        void ToogleCursorVisibility(bool showFlag)
        {
            // Initializr a Cursor Info variable.
            CONSOLE_CURSOR_INFO cursorInfo;

            // Get Cursor information.
            GetConsoleCursorInfo(out, &cursorInfo);

            // Change the cursor visibility
            cursorInfo.bVisible = showFlag;

            // Update the cursor information.
            SetConsoleCursorInfo(out, &cursorInfo);
        }


        int InitializeMenu(std::string MenuTitle ,std::vector<std::string> Entries, size_t pointer = 0, bool ShowCursor = false, int MenuTitleTextAttribute = 15, int SelectedMenuEntry = 11, int MenuEntry = 15)
        {
            ClearScreen();

            // Set cursor visibility.
            ToogleCursorVisibility(ShowCursor);

            // Populate the Menuentries.
            for(size_t i = 0; i < Entries.size(); i++)
            {
                MenuEntries.push_back(Entries[i]);
            }

            while(true)
            {
                ClearScreen();

                // Change the text fore -& background.
                SetConsoleTextAttribute(out, MenuTitleTextAttribute);
                std::cout << MenuTitle << std::endl << std::endl;

                // Iterate through the entries and mark the selected entry to prevent confusion.
                for (size_t i = 0; i < MenuEntries.size(); ++i)
                {
                    if (i == pointer)
                    {
                        SetConsoleTextAttribute(out, SelectedMenuEntry);
                        std::cout << MenuEntries[i] << std::endl;
                    }
                    else
                    {
                        SetConsoleTextAttribute(out, MenuEntry);
                        std::cout << MenuEntries[i] << std::endl;
                    }
                }

                // Initialize a while loop where you get the input of the arrow keys and the return button asynchronous.
                // With this the Menu if fully functional.
                while(true)
                {
                    if (GetAsyncKeyState(VK_UP) != 0)
                    {
                        pointer -= 1;

                        if (pointer == -1)
                        {
                            pointer = Entries.size() - 1;
                        }

                        break;
                    }
                    else if (GetAsyncKeyState(VK_DOWN) != 0)
                    {
                        pointer += 1;

                        if (pointer == Entries.size())
                        {
                            pointer = 0;
                        }

                        break;
                    }
                    else if (GetAsyncKeyState(VK_RETURN) != 0)
                    {
                        return pointer;

                        break;
                    }
                }

                // Create an interval between detecting key presses,
                // preventing the scrolling funciton to run out of control.
                Sleep(125);
            }

            // Remove the menu entries.
            MenuEntries.clear();
        }

    public:
        int MainMenu()
        {
            int menu = InitializeMenu("Main Menu", {"Optimization", "Options", "Exit"}, 0, false, 15, 135, 15);

            switch (menu)
            {
                case 0:
                    // Start Optimization.
                break;

                case 1:
                    // BUG: After picking options, it just closes.
                    Options();
                break;

                case 3:
                return 0;
                break;
            }
        }

        int Options()
        {
            int menu = InitializeMenu("Options", {"Option 1", "Option 2", "Option 3", "Option 4", "Exit"}, 0, false, 15, 145, 15);

            switch (menu)
            {
                case 0:

                break;

                case 1:

                break;

                case 2:

                break;

                case 3:

                break;

                case 4:
                return 0;
                break;
            }
        }
};
