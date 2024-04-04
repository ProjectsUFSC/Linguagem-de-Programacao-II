#ifndef MENU_HPP
#define MENU_HPP

#include "pongball.hpp"
 


class Menu
{
    size_t choice, team;
    bool pressed, select, theselect;
    RenderWindow * window;
    RectangleShape * winclose;
    Font * font;
    Texture * image;
    Sprite * sprite;

    
    //Vector2f mouse_coord;

    vector<const char *> options;
    vector<Vector2f> coords;
    vector<Text> text_options;
    vector<size_t> sizes;

    vector<const char *> teams;
    
    vector<Vector2f> coords_teams;
    vector<Text> text_teams;
    vector<size_t> sizes_teams;

    //functions
    protected :
        void set_values();
        void loop_events();
        void draw_all();
        void draw_teams();
    

    public :
        Menu();
        ~Menu() ;
        void run_menu();

};

#endif