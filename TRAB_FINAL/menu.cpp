#include "menu.hpp"


Menu::Menu()
{
    window = new RenderWindow();
    winclose = new RectangleShape();
    font = new Font();
    image = new Texture();
    sprite = new Sprite();
    set_values();
}

Menu::~Menu()
{
    delete window;
    delete winclose;
    delete font;
    delete image;
    delete sprite;
}

void Menu::set_values()
{
    window->create(VideoMode(1200, 750), "Menu", Style::Titlebar | Style::Close);
    window->setPosition(Vector2i(0, 0));

    team = 0;
    choice = 0;
    pressed = false;
    select = false;
    theselect = false;

    font->loadFromFile("font.ttf");
    image->loadFromFile("menu.png");
    sprite->setTexture(*image);


    options.push_back("Start");
    options.push_back("Exit");
    options.push_back("IA Test");
    coords.push_back(Vector2f( 475,223));
    coords.push_back(Vector2f( 475,374));
    coords.push_back(Vector2f( 475,525));
    sizes.push_back(100);
    sizes.push_back(100);
    sizes.push_back(100);

    teams.push_back("Portugal");
    teams.push_back("Argentina");
    teams.push_back("Holanda");
    teams.push_back("Canada");
    teams.push_back("Croacia");
    teams.push_back("Qatar");
    teams.push_back("Italia");
    teams.push_back("Espanha");
    teams.push_back("Belgica");
    teams.push_back("Marrocos");
    teams.push_back("Inglaterra");
    teams.push_back("Camaroes");
    teams.push_back("Brasil");
    teams.push_back("Colombia");
    teams.push_back("Franca");
    teams.push_back("Alemanha");
    teams.push_back("Equador");
    teams.push_back("Koreia do Sul");
    coords_teams.push_back(Vector2f( 138,186));
    coords_teams.push_back(Vector2f( 138,257));
    coords_teams.push_back(Vector2f( 138,328));
    coords_teams.push_back(Vector2f( 138,397));
    coords_teams.push_back(Vector2f( 138,472));
    coords_teams.push_back(Vector2f( 138,536));
    coords_teams.push_back(Vector2f( 553,186));
    coords_teams.push_back(Vector2f( 553,257));
    coords_teams.push_back(Vector2f( 553,328));
    coords_teams.push_back(Vector2f( 553,397));
    coords_teams.push_back(Vector2f( 553,472));
    coords_teams.push_back(Vector2f( 553,536));
    coords_teams.push_back(Vector2f( 954,186));
    coords_teams.push_back(Vector2f( 954,257));
    coords_teams.push_back(Vector2f( 954,328));
    coords_teams.push_back(Vector2f( 954,397));
    coords_teams.push_back(Vector2f( 954,472));
    coords_teams.push_back(Vector2f( 954,536));
    sizes_teams.push_back(30);
    sizes_teams.push_back(30);
    sizes_teams.push_back(30);
    sizes_teams.push_back(30);  
    sizes_teams.push_back(30);
    sizes_teams.push_back(30);
    sizes_teams.push_back(30);
    sizes_teams.push_back(30);
    sizes_teams.push_back(30);
    sizes_teams.push_back(30);
    sizes_teams.push_back(30);
    sizes_teams.push_back(30);
    sizes_teams.push_back(30);
    sizes_teams.push_back(30);
    sizes_teams.push_back(30);
    sizes_teams.push_back(30);
    sizes_teams.push_back(30);
    sizes_teams.push_back(30);
    sizes_teams.push_back(30);

    for(size_t i = 0; i < teams.size(); i++)
    {
        text_teams.push_back(Text());
        text_teams[i].setFont(*font);
        text_teams[i].setString(teams[i]);
        text_teams[i].setCharacterSize(sizes_teams[i]);
        text_teams[i].setFillColor(Color::Black);
        text_teams[i].setPosition(coords_teams[i]);
    }

    for(size_t i = 0; i < options.size(); i++)
    {
        text_options.push_back(Text());
        text_options[i].setFont(*font);
        text_options[i].setString(options[i]);
        text_options[i].setCharacterSize(sizes[i]);
        text_options[i].setFillColor(Color::White);
        text_options[i].setPosition(coords[i]);
    }
} 

void Menu::loop_events()
{
    Event event;
    while (window->pollEvent(event))
    {
        if (event.type == Event::Closed)
            window->close();
        if (event.type == Event::KeyPressed)
        {
            if (event.key.code == Keyboard::Up && select == false )
            {
                if (choice > 0)
                    choice--;
                 theselect = false;   
            }
            if (event.key.code == Keyboard::Down && select == false)
            {
                if (choice < options.size() - 1)
                    choice++;
                theselect = false;
                   
            }
            if (event.key.code == Keyboard::Enter && select == false && !theselect)
            {
                theselect = true;
                select = true;
                cout << "Enter pressed" << endl;
                cout << "Choice: " << options[choice] << endl;
                
                //start the game
                if (choice == 0)
                {   
                    image->loadFromFile("teams.png");
                    sprite->setTexture(*image);
                }
                //stop the game
                if (choice == 1)
                    window->close();
                //IA game
                if (choice == 2)
                {
                    select = false;
                    PongBall *pong = new PongBall();
                    pong->run_ia();
                }
                    
                }
             if (event.key.code == Keyboard::Up && select == true)
                    {
                        theselect = false;
                         if (team > 0)
                            team--;
                   
                    }
                    if (event.key.code == Keyboard::Down && select == true)
                    {
                        theselect = false;
                        if (team < teams.size() - 1)
                        team++;
                   
                    }
                    if (event.key.code == Keyboard::Right && select == true)
                    {
                        theselect = false;
                        if(team < teams.size() - 6)
                            team += 6;
                    }
                    if(event.key.code == Keyboard::Left && select == true)
                    {
                        theselect = false;
                        if(team > 5)
                            team -= 6;
                    }   
                if( event.key.code == Keyboard::Enter && select == true && !theselect )
                {
                    
                    cout << "Space pressed" << endl;
                    cout << "Team: " << teams[team] << endl;
                    
                    PongBall *pong = new PongBall(team);
                    pong->run();
                     
                }

                if( event.key.code == Keyboard::Escape && select == true)
                {
                    select = false;
                    image->loadFromFile("menu.png");
                    sprite->setTexture(*image);
                }

                
            }
        }
      
    }


void Menu::draw_all()
{
    window->clear(Color::Black);
    window->draw(*sprite);
    for(size_t i = 0; i < options.size(); i++)
    {
        if (choice == i)
            text_options[i].setFillColor(Color::Yellow);
        else
            text_options[i].setFillColor(Color::Black);
        window->draw(text_options[i]);
    }
    window->display();
}



void Menu::draw_teams()
{
    
    window->clear(Color::Black);
    window->draw(*sprite);
    for(size_t i = 0; i < teams.size(); i++)
    {
        if (team == i)
            text_teams[i].setFillColor(Color::Yellow);
        else
            text_teams[i].setFillColor(Color::Black);
        window->draw(text_teams[i]);
    }
    window->display();
}

void Menu::run_menu()
{
    while (window->isOpen())
    {
        loop_events();
        if(select==false)
        draw_all();
        if(select==true)
        {
            draw_teams();
        }
        
    }
}