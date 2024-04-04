#ifndef  PONGBALL_HPP
#define  PONGBALL_HPP
#include  <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <ctime>

using namespace std;
using namespace sf;
class PongBall
{
    //SFML variables
    shared_ptr<RenderWindow> window;
    RectangleShape time_a;
    RectangleShape time_b;
    RectangleShape YourTeam;
    RectangleShape flag_Portugal, flag_Argentina, flag_Holanda, flag_Canada, flag_Croacia, flag_Qatar, flag_Italia, flag_Espanha, flag_Belgica, flag_Marrocos, flag_Inglaterra, flag_Camaroes, flag_Brasil, flag_Colombia, flag_Franca, flag_Alemanha, flag_Equador, flag_Korea_do_Sul, Quarts_1, Quarts_2, Quarts_3, Quarts_4, Quarts_5, Quarts_6, Quarts_7, Quarts_8, Semi_1, Semi_2, Semi_3, Semi_4, Final_1, Final_2, Winner;
    Texture t_time_a, t_time_b, t_campo, t_ball, t_table;
    Texture Portugal, Argentina, Holanda, Canada, Croacia, Qatar, Italia,Espanha, Belgica, Marrocos, Inglaterra, Camaroes, Brasil, Colombia, Franca, Alemanha, Equador, Korea_do_Sul;
    Texture t_flag_Portugal, t_flag_Argentina, t_flag_Holanda, t_flag_Canada, t_flag_Croacia, t_flag_Qatar, t_flag_Italia, t_flag_Espanha, t_flag_Belgica, t_flag_Marrocos, t_flag_Inglaterra, t_flag_Camaroes, t_flag_Brasil, t_flag_Colombia, t_flag_Franca, t_flag_Alemanha, t_flag_Equador, t_flag_Korea_do_Sul;
    vector<Texture> t_flags;
    vector<Vector2f> coords_flags;
    vector<RectangleShape> flags;
    vector<size_t> sizes;
    vector<Texture> t_teams;
    Sprite campo, ball, table;
    Vector2f velocity;
    Font font;
    Text text_time_a, text_time_b, text_end1, text_end2, text_win, text_lose;

    //variables
    int points_a, points_b, menu_end;
    float speed;
    bool start, menu, win, thesenter;
    size_t m_team;
    //functions
    protected :
        void events();
        void draw_game();
        void logic();
        void logic_ia();
        void menu_game();
        
        void end_game();

    public :
        PongBall();
        PongBall(size_t team);
        ~PongBall() {};
        void run();
        void run_ia();
        void set_games();

 friend class Menu;
};



#endif