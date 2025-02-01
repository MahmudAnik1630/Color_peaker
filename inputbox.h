#ifndef INPUTBOX_H
#define INPUTBOX_H

#include <graphics.h>

void inputbox(char buffer[], int maxLength, char prompt[]) {
    clearmouseclick(WM_LBUTTONDOWN);
    char ch;
    int i = 0;
    int windowWidth = 1024;
    int windowHeight = 600;
    int x = (windowWidth - maxLength * 8) / 2; // Centered horizontally
    int y = (windowHeight - 20) / 2;           // Centered vertically
    int boxWidth = maxLength * 8;

    setcolor(WHITE);  // Set text color to white
    settextstyle(3, HORIZ_DIR, 2);
    outtextxy(x, y - 30, prompt);

    rectangle(x - 5, y - 5, x + boxWidth + 5, y + 20);

    while (1) {
        if (kbhit()) {
            ch = getch();
            if (ch == 13) {
                buffer[i] = '\0';
                break;
            } else if (ch == 8 && i > 0) {
                // Handle backspace
                setcolor(getbkcolor());
                i--;

                // Move the cursor to the position of the last character
                moveto(x, y);

                // Clear the entire input box
                for (int j = 0; j < maxLength; j++) {
                    outtext(" ");
                }

                // Update the internal buffer to remove the deleted character
                buffer[i] = '\0';

                // Redraw the entire input box with updated characters
                setcolor(WHITE);
                rectangle(x - 5, y - 5, x + boxWidth + 5, y + 20);
                outtextxy(x, y, buffer);
            } else if (ch >= 32 && ch <= 126 && i < maxLength - 1) {
                // Handle printable characters
                buffer[i] = ch;
                buffer[i + 1] = '\0';
                setcolor(WHITE);
                rectangle(x - 5, y - 5, x + boxWidth + 5, y + 20);
                outtextxy(x, y, buffer);  // Redraw the entire input box with updated characters
                i++;
            }
        }

        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mouseX = mousex();
            int mouseY = mousey();

            if (mouseX >= x - 5 && mouseX <= x + boxWidth + 5 && mouseY >= y - 5 && mouseY <= y + 20) {
                // Click inside the input box
                setcolor(WHITE);
                rectangle(x + i * 8 - 5, y - 5, x + (i + 1) * 8 + 5, y + 20);
                i = 0;
            } else {
                // Click outside the input box
                buffer[i] = '\0';
                //break;
            }

            clearmouseclick(WM_LBUTTONDOWN);
        }
        delay(100);  // Increase delay to allow graphics to update
    }
}

#endif
