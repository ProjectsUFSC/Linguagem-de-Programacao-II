#include "pongball.hpp"

PongBall::PongBall()
{
    window = make_shared<RenderWindow>(VideoMode(1200, 750), "Soccer game", Style::Titlebar | Style::Close);
    window->setPosition(Vector2i(0, 0));

    points_a = points_b = 0;
    speed = 1.4f;
    start = false;
    menu = true;
    thesenter = false;

    time_a.setSize(Vector2f(100.f, 120.f));
    time_b.setSize(Vector2f(100.f, 120.f));
    time_a.setPosition(-50, 20.f);
    time_b.setPosition((window->getSize().x - time_b.getSize().x)+50, 20.f);

    t_ball.loadFromFile("ball.png");
    t_campo.loadFromFile("campo.png");
    t_time_a.loadFromFile("time_a.png");
    t_time_b.loadFromFile("time_b.png");
    

    ball.setTexture(t_ball);
    campo.setTexture(t_campo);
    time_a.setTexture(&t_time_a);
    time_b.setTexture(&t_time_b);


    velocity = Vector2f(speed, speed);

    font.loadFromFile("font.ttf");

    //text_time_a
    text_time_a.setFont(font);
    text_time_a.setString(to_string(points_a));
    text_time_a.setPosition(( window->getSize().x / 2) - 50 , time_a.getPosition().y) ;
    text_time_a.setCharacterSize(50);
    text_time_a.setOutlineThickness(4);

  //text_time_b
    text_time_b.setFont(font);
    text_time_b.setString(to_string(points_b));
    text_time_b.setPosition( (window->getSize().x / 2) + 20 , time_b.getPosition().y);
    text_time_b.setCharacterSize(50);
    text_time_b.setOutlineThickness(4);

  


}

PongBall::PongBall(size_t team) 
{ 
     window = make_shared<RenderWindow>(VideoMode(1200, 750), "Soccer game", Style::Titlebar | Style::Close);
    window->setPosition(Vector2i(0, 0));

    points_a = points_b = menu_end = 0 ;
    speed = 1.4f;
    start = false;
    menu = true;
    thesenter = false;
    m_team = team;

    time_a.setSize(Vector2f(100.f, 120.f));
    time_b.setSize(Vector2f(100.f, 120.f));
    time_a.setPosition(-50, 20.f);
    time_b.setPosition((window->getSize().x - time_b.getSize().x)+50, 20.f);
    t_table.loadFromFile("table.png");
    t_ball.loadFromFile("ball.png");
    t_campo.loadFromFile("campo.png");

    Portugal.loadFromFile("team_Portugal.png");
    Argentina.loadFromFile("team_Argentina.png");
    Holanda.loadFromFile("team_Holanda.png");
    Canada.loadFromFile("team_Canada.png");
    Croacia.loadFromFile("team_Croacia.png");
    Qatar.loadFromFile("team_Qatar.png");
    Italia.loadFromFile("team_Italia.png");
    Espanha.loadFromFile("team_Espanha.png");
    Belgica.loadFromFile("team_Belgica.png");
    Marrocos.loadFromFile("team_Marrocos.png");
    Inglaterra.loadFromFile("team_Inglaterra.png");
    Camaroes.loadFromFile("team_Camaroes.png");
    Brasil.loadFromFile("team_Brasil.png");
    Franca.loadFromFile("team_Franca.png");
    Alemanha.loadFromFile("team_Alemanha.png");
    Korea_do_Sul.loadFromFile("team_Korea.png");
    t_teams.push_back(Portugal);
    t_teams.push_back(Argentina);
    t_teams.push_back(Holanda);
    t_teams.push_back(Canada);
    t_teams.push_back(Croacia);
    t_teams.push_back(Qatar);
    t_teams.push_back(Italia);
    t_teams.push_back(Espanha);
    t_teams.push_back(Belgica);
    t_teams.push_back(Marrocos);
    t_teams.push_back(Inglaterra);
    t_teams.push_back(Camaroes);
    t_teams.push_back(Brasil);
    t_teams.push_back(Franca);
    t_teams.push_back(Alemanha);
    t_teams.push_back(Korea_do_Sul);

    flag_Portugal.setSize(Vector2f(75.f, 60.f));
    flag_Argentina.setSize(Vector2f(75.f, 60.f));
    flag_Holanda.setSize(Vector2f(75.f, 60.f));
    flag_Canada.setSize(Vector2f(75.f, 60.f));
    flag_Croacia.setSize(Vector2f(75.f, 60.f));
    flag_Qatar.setSize(Vector2f(75.f, 60.f));
    flag_Italia.setSize(Vector2f(75.f, 60.f));
    flag_Espanha.setSize(Vector2f(75.f, 60.f));
    flag_Belgica.setSize(Vector2f(75.f, 60.f));
    flag_Marrocos.setSize(Vector2f(75.f, 60.f));
    flag_Inglaterra.setSize(Vector2f(75.f, 60.f));
    flag_Camaroes.setSize(Vector2f(75.f, 60.f));
    flag_Brasil.setSize(Vector2f(75.f, 60.f));
    flag_Franca.setSize(Vector2f(75.f, 60.f));
    flag_Alemanha.setSize(Vector2f(75.f, 60.f));
    flag_Korea_do_Sul.setSize(Vector2f(75.f, 60.f));
    Quarts_1.setSize(Vector2f(75.f, 60.f));
    Quarts_2.setSize(Vector2f(75.f, 60.f));
    Quarts_3.setSize(Vector2f(75.f, 60.f));
    Quarts_4.setSize(Vector2f(75.f, 60.f));
    Quarts_5.setSize(Vector2f(75.f, 60.f));
    Quarts_6.setSize(Vector2f(75.f, 60.f));
    Quarts_7.setSize(Vector2f(75.f, 60.f));
    Quarts_8.setSize(Vector2f(75.f, 60.f));
    Semi_1.setSize(Vector2f(75.f, 60.f));
    Semi_2.setSize(Vector2f(75.f, 60.f));
    Semi_3.setSize(Vector2f(75.f, 60.f));
    Semi_4.setSize(Vector2f(75.f, 60.f));
    Final_1.setSize(Vector2f(75.f, 60.f));
    Final_2.setSize(Vector2f(75.f, 60.f));
    Winner.setSize(Vector2f(75.f, 60.f));
    t_flag_Portugal.loadFromFile("flag_Portugal.png");
    t_flag_Argentina.loadFromFile("flag_Argentina.png");
    t_flag_Holanda.loadFromFile("flag_Holanda.png");
    t_flag_Canada.loadFromFile("flag_Canada.png");
    t_flag_Croacia.loadFromFile("flag_Croacia.png");
    t_flag_Qatar.loadFromFile("flag_Qatar.png");
    t_flag_Italia.loadFromFile("flag_Italia.png");
    t_flag_Espanha.loadFromFile("flag_Espanha.png");
    t_flag_Belgica.loadFromFile("flag_Belgica.png");
    t_flag_Marrocos.loadFromFile("flag_Marrocos.png");
    t_flag_Inglaterra.loadFromFile("flag_Inglaterra.png");
    t_flag_Camaroes.loadFromFile("flag_Camaroes.png");
    t_flag_Brasil.loadFromFile("flag_Brasil.png");
    t_flag_Franca.loadFromFile("flag_Franca.png");
    t_flag_Alemanha.loadFromFile("flag_Alemanha.png");
    t_flag_Korea_do_Sul.loadFromFile("flag_Korea.png");
    t_flags.push_back(t_flag_Portugal);
    t_flags.push_back(t_flag_Argentina);
    t_flags.push_back(t_flag_Holanda);
    t_flags.push_back(t_flag_Canada);
    t_flags.push_back(t_flag_Croacia);
    t_flags.push_back(t_flag_Qatar);
    t_flags.push_back(t_flag_Italia);
    t_flags.push_back(t_flag_Espanha);
    t_flags.push_back(t_flag_Belgica);
    t_flags.push_back(t_flag_Marrocos);
    t_flags.push_back(t_flag_Inglaterra);
    t_flags.push_back(t_flag_Camaroes);
    t_flags.push_back(t_flag_Brasil);
    t_flags.push_back(t_flag_Franca);
    t_flags.push_back(t_flag_Alemanha);
    t_flags.push_back(t_flag_Korea_do_Sul);
    flag_Portugal.setTexture(&t_flag_Portugal);
    flag_Argentina.setTexture(&t_flag_Argentina);
    flag_Holanda.setTexture(&t_flag_Holanda);
    flag_Canada.setTexture(&t_flag_Canada);
    flag_Croacia.setTexture(&t_flag_Croacia);
    flag_Qatar.setTexture(&t_flag_Qatar);
    flag_Italia.setTexture(&t_flag_Italia);
    flag_Espanha.setTexture(&t_flag_Espanha);
    flag_Belgica.setTexture(&t_flag_Belgica);
    flag_Marrocos.setTexture(&t_flag_Marrocos);
    flag_Inglaterra.setTexture(&t_flag_Inglaterra);
    flag_Camaroes.setTexture(&t_flag_Camaroes);
    flag_Brasil.setTexture(&t_flag_Brasil);
    flag_Franca.setTexture(&t_flag_Franca);
    flag_Alemanha.setTexture(&t_flag_Alemanha);
    flag_Korea_do_Sul.setTexture(&t_flag_Korea_do_Sul);
    
    
    
    flag_Portugal.setPosition(35, 14);
    flag_Argentina.setPosition(35, 96);
    flag_Holanda.setPosition(35, 195);
    flag_Canada.setPosition(35, 284);
    flag_Croacia.setPosition(35, 397);
    flag_Qatar.setPosition(35, 483);
    flag_Italia.setPosition(35, 596);
    flag_Espanha.setPosition(35, 670);
    flag_Belgica.setPosition(1092, 14);
    flag_Marrocos.setPosition(1092, 96);
    flag_Inglaterra.setPosition(1092, 195);
    flag_Camaroes.setPosition(1092, 284);
    flag_Brasil.setPosition(1092, 397);
    flag_Franca.setPosition(1092, 483);
    flag_Alemanha.setPosition(1092, 596);
    flag_Korea_do_Sul.setPosition(1092, 670);
    Quarts_1.setPosition(186, 57);
    Quarts_2.setPosition(186, 231);
    Quarts_3.setPosition(186, 442);
    Quarts_4.setPosition(186, 622);
    Quarts_5.setPosition(938, 57);
    Quarts_6.setPosition(938, 231);
    Quarts_7.setPosition(938, 442);
    Quarts_8.setPosition(938, 622);
    Semi_1.setPosition(336, 153);
    Semi_2.setPosition(336, 546);
    Semi_3.setPosition(782, 153);
    Semi_4.setPosition(782, 546);
    Final_1.setPosition(424, 344);
    Final_2.setPosition(702, 344);
    Winner.setPosition(570, 171);
    flags.push_back(flag_Portugal);
    flags.push_back(flag_Argentina);
    flags.push_back(flag_Holanda);
    flags.push_back(flag_Canada);
    flags.push_back(flag_Croacia);
    flags.push_back(flag_Qatar);
    flags.push_back(flag_Italia);
    flags.push_back(flag_Espanha);
    flags.push_back(flag_Belgica);
    flags.push_back(flag_Marrocos);
    flags.push_back(flag_Inglaterra);
    flags.push_back(flag_Camaroes);
    flags.push_back(flag_Brasil);
    flags.push_back(flag_Franca);
    flags.push_back(flag_Alemanha);
    flags.push_back(flag_Korea_do_Sul);
    flags.push_back(Quarts_1);
    flags.push_back(Quarts_2);
    flags.push_back(Quarts_3);
    flags.push_back(Quarts_4);
    flags.push_back(Quarts_5);
    flags.push_back(Quarts_6);
    flags.push_back(Quarts_7);
    flags.push_back(Quarts_8);
    flags.push_back(Semi_1);
    flags.push_back(Semi_2);
    flags.push_back(Semi_3);
    flags.push_back(Semi_4);
    flags.push_back(Final_1);
    flags.push_back(Final_2);
    
    


    

    table.setTexture(t_table);
    ball.setTexture(t_ball);
    campo.setTexture(t_campo);
    time_a.setTexture(&t_teams[team]);
    if(team %2 == 0)
    {
        time_b.setTexture(&t_teams[team+1]);
    }
    else
    {
        time_b.setTexture(&t_teams[team-1]);
    }


    velocity = Vector2f(speed, speed);

    font.loadFromFile("font.ttf");

      //text_time_a
    text_time_a.setFont(font);
    text_time_a.setString(to_string(points_a));
    text_time_a.setPosition(( window->getSize().x / 2) - 50 , time_a.getPosition().y) ;
    text_time_a.setCharacterSize(50);
    text_time_a.setOutlineThickness(4);

  //text_time_b
    text_time_b.setFont(font);
    text_time_b.setString(to_string(points_b));
    text_time_b.setPosition( (window->getSize().x / 2) + 20 , time_b.getPosition().y);
    text_time_b.setCharacterSize(50);
    text_time_b.setOutlineThickness(4);

  //text_end
    text_win.setFont(font);
    text_win.setString("YOU WIN");
    text_win.setPosition( (window->getSize().x / 2) -200 , (window->getSize().y / 2) );
    text_win.setCharacterSize(100);
    text_win.setOutlineThickness(4);
    text_lose.setFont(font);
    text_lose.setString("YOU LOSE");
    text_lose.setPosition( (window->getSize().x / 2)-200  , (window->getSize().y / 2) );
    text_lose.setCharacterSize(100);
    text_lose.setOutlineThickness(4);
    text_end1.setFont(font);
    text_end1.setString("Press Enter to restart");
    text_end1.setPosition( (window->getSize().x / 2) - 150 , (window->getSize().y / 2) + 200);
    text_end1.setCharacterSize(30);
    text_end1.setOutlineThickness(4);
    text_end2.setFont(font);
    text_end2.setString("Press Esc to exit");
    text_end2.setPosition( (window->getSize().x / 2) - 100 , (window->getSize().y / 2) + 250);
    text_end2.setCharacterSize(30);
    text_end2.setOutlineThickness(4);


  

}


void PongBall::draw_game()
{
    window->clear(Color::Black);
    window->draw(campo);
    window->draw(ball);
    window->draw(time_a);
    window->draw(time_b);
    window->draw(text_time_a);
    window->draw(text_time_b);
    window->display();
  
}



void PongBall::events()
{
    Event event;
    while (window->pollEvent(event))
    {
        if (event.type == Event::Closed)
         {
            window->close();
         }   
    }
}

void PongBall::run()
{
    while (window->isOpen())
    {
        events();
        menu = false;
        start = true;
        /*if(Keyboard::isKeyPressed(Keyboard::Enter) && win == false)
        {
            
            menu = false;
            start = true;
            
        }*/
        if(menu)
        {
            
            menu_game();
            
        }
        if(points_a == 5 || points_b == 5)
        {
            end_game();
            //start = false;
        }
    
        else
            {
                if(start)
                {
                    logic();
                    draw_game();
                    if(Keyboard::isKeyPressed(Keyboard::Escape))
                    {
                        window->close();
                    }
                }
                
            }

    }
        
}

void PongBall::run_ia()
{
    while (window->isOpen())
    {
        events();
        logic_ia();
        draw_game();
        if(Keyboard::isKeyPressed(Keyboard::Escape))
         {
             window->close();
         }
        
        
    }
}

void PongBall::menu_game()
{
    window->clear(Color::Black);
   window->draw(table);
    for(int i = 0; i < flags.size(); i++)
    {
        window->draw(flags[i]);
    } 
    window->display();
}
   
    

void PongBall::logic()
{

    //mov players
    if(Keyboard::isKeyPressed(Keyboard::S))
    {
        if(time_a.getPosition().y < window->getSize().y - time_a.getSize().y)
        {
            time_a.move(0, speed);
        }
    }
      if(Keyboard::isKeyPressed(Keyboard::W))
    {
        if(time_a.getPosition().y > 0)
        {
            time_a.move(0, -speed);
        }
    }
       if(Keyboard::isKeyPressed(Keyboard::Down))
    {
        if(time_b.getPosition().y < window->getSize().y - time_b.getSize().y)
        {
            time_b.move(0, speed);
        }
    }
      if(Keyboard::isKeyPressed(Keyboard::Up))
    {
        if(time_b.getPosition().y > 0)
        {
            time_b.move(0, -speed);
        }
    }
//fake IA test
    /*if(ball.getPosition().x > window->getSize().x / 2)
    {
        if(time_b.getPosition().y + time_b.getSize().y / 2 < ball.getPosition().y)
        {
            time_b.move(0, speed/1.6);
        }
        if(time_b.getPosition().y + time_b.getSize().y / 2 > ball.getPosition().y)
        {
            time_b.move(0, -speed/1.6);
        }
    }*/
   
    //mov ball
    if(ball.getPosition().y > window->getSize().y && velocity.y > 0 || ball.getPosition().y < 0 && velocity.y < 0)
    {
        velocity.y = -velocity.y;
    }
    if(time_a.getGlobalBounds().intersects(ball.getGlobalBounds()) && velocity.x < 0)
    {
        velocity.x = -velocity.x;
    }
    if(time_b.getGlobalBounds().intersects(ball.getGlobalBounds()) && velocity.x > 0)
    {
        velocity.x = -velocity.x;
    }
    ball.setPosition(ball.getPosition() + velocity);

    if(ball.getPosition().x > window->getSize().x)
    {
        points_a++;
        text_time_a.setString(to_string(points_a));
        ball.setPosition(window->getSize().x / 2, window->getSize().y / 2);
        velocity = Vector2f(speed, speed);
    }
    if(ball.getPosition().x < 0)
    {
        points_b++;
        text_time_b.setString(to_string(points_b));
        ball.setPosition(window->getSize().x / 2, window->getSize().y / 2);
        velocity = Vector2f(-speed, -speed);
    }


  
    
    
}  

void PongBall::logic_ia()
{
 //fake IA test
    if(ball.getPosition().x > window->getSize().x / 2)
    {
        if(time_b.getPosition().y + time_b.getSize().y / 2 < ball.getPosition().y)
        {
            time_b.move(0, speed);
        }
        if(time_b.getPosition().y + time_b.getSize().y / 2 > ball.getPosition().y)
        {
            time_b.move(0, -speed);
        }
    }
    if(ball.getPosition().x < window->getSize().x / 2)
    {
        if(time_a.getPosition().y + time_a.getSize().y / 2 < ball.getPosition().y)
        {
            time_a.move(0, speed);
        }
        if(time_a.getPosition().y + time_a.getSize().y / 2 > ball.getPosition().y)
        {
            time_a.move(0, -speed);
        }
    }
    //mov ball
    if(ball.getPosition().y > window->getSize().y && velocity.y > 0 || ball.getPosition().y < 0 && velocity.y < 0)
    {
        velocity.y = -velocity.y;
    }
    if(time_a.getGlobalBounds().intersects(ball.getGlobalBounds()) && velocity.x < 0)
    {
        velocity.x = -velocity.x;
    }
    if(time_b.getGlobalBounds().intersects(ball.getGlobalBounds()) && velocity.x > 0)
    {
        velocity.x = -velocity.x;
    }
    ball.setPosition(ball.getPosition() + velocity);

    if(ball.getPosition().x > window->getSize().x)
    {
        points_a++;
        text_time_a.setString(to_string(points_a));
        ball.setPosition(window->getSize().x / 2, window->getSize().y / 2);
        velocity = Vector2f(speed, speed);
    }
    if(ball.getPosition().x < 0)
    {
        points_b++;
        text_time_b.setString(to_string(points_b));
        ball.setPosition(window->getSize().x / 2, window->getSize().y / 2);
        velocity = Vector2f(-speed, -speed);
    }

}

void PongBall::set_games()
{
    
    if(m_team==0 || m_team==1)
    {
        if(win)
        Quarts_1.setTexture(&t_flag_Alemanha);
        
    }
    else Quarts_1.setTexture(&t_flags[1]);
    if(m_team ==2 || m_team ==3)
    {
        if(win)
        Quarts_2.setTexture(&t_flags[m_team]);
        
    }
    else Quarts_2.setTexture(&t_flags[3]);
    if(m_team ==4 || m_team ==5)
    {
        if(win)
        Quarts_3.setTexture(&t_flags[m_team]);
        
    }
    else Quarts_3.setTexture(&t_flags[5]);
    if(m_team ==6 || m_team ==7)
    {
        if(win)
        Quarts_4.setTexture(&t_flags[m_team]);
        
    }
    else Quarts_4.setTexture(&t_flags[7]);
    if(m_team ==8 || m_team ==9)
    {
        if(win)
        Quarts_5.setTexture(&t_flags[m_team]);
        
    }
    else Quarts_5.setTexture(&t_flags[9]);
    if(m_team ==10 || m_team ==11)
    {
        if(win)
        Quarts_6.setTexture(&t_flags[m_team]);
        
    }
    else Quarts_6.setTexture(&t_flags[11]);
    if(m_team ==12 || m_team ==13)
    {
        if(win)
        Quarts_7.setTexture(&t_flags[m_team]);
        
    }
    else Quarts_7.setTexture(&t_flags[13]);
    if(m_team ==14 || m_team ==15)
    {
        if(win)
        Quarts_8.setTexture(&t_flags[m_team]);
        
    }
    else Quarts_8.setTexture(&t_flags[15]);
    
    
}

void PongBall::end_game()
{
    window->clear();
    window->draw(campo);
    if(points_a == 5)
    {
        win = true;
        
        window->draw(text_win);
        if(Keyboard::isKeyPressed(Keyboard::Enter))
        {
            menu_end++;
            set_games();
            points_a = 0;
            points_b = 0;
            text_time_a.setString(to_string(points_a));
            text_time_b.setString(to_string(points_b));
            menu = true;
            menu_game();
            
        }
        if(Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window->close();
        }

    }
    if(points_b == 5)
    {
        win = false;
        
        window->draw(text_lose);
        if(Keyboard::isKeyPressed(Keyboard::Enter) && thesenter == false)
        
        {
            window->close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Escape))
    {
        window->close();
    }
    }
   window->draw(text_end1);
    window->draw(text_end2);
    
    window->display();
}