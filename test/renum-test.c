#include "reflag.h"

void print_font(char *str, Renum *renu);

int main() {

    // set length and configure the names (optional)
    uint32_t len = 3;
    char names[] = "script, italic, big";

    Renum* renu = new_r(names, len);

    printf("\nDefault: \n");
    renu->print(renu);
    print_font("This text is normal", renu);

    printf("\nLet's convert the font to script \n and making the text italic\n");
    renu->set_all(renu, 2, script, italic);
    renu->print(renu);
    print_font("This text is script and italic", renu);

    printf("\nNo, let's stretch all of that and just make the size bigger");
    renu->reset_all(renu, 2, script, italic);
    renu->set(renu, big);
    renu->print(renu);
    print_font("This text is just bigger", renu);

    // free memory
    del_r(renu);
}

void print_font(char* str, Renum *renu) {
    // int gd = DETECT, gm;
    // initgraph(&gd, &gm, "");
    // int x = 150;
    // int y = 150;

    // int font = 0;
    // int direction = 0;
    // int font_size = 10;

    // if (renu->is(renu, script)) font = 5;
    // if (renu->is(renu, italic)) direction = 45;
    // if (renu->is(renu, big)) font_size = 10;

    // settextstyle(font, direction, font_size);
    // outtextxy(x, y, str);
    // getch();
    // closegraph();

    printf("%s\n", str);
}