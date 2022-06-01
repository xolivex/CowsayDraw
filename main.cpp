#include <iostream>
#include <SFML/Graphics.hpp>
//primeiro commit 2
const int _x = 30, _y = 20; //change the tiles map

char desenho[_x][_y];

void ini()
{
    for(int x = 0;x < _x;x++)
    {
        for(int y = 0;y < _y;y++)
        {
            desenho[x][y]= '.';
            if(x == 0 or x == _x -1)
                desenho[x][y]= '*';
            if(y == 0 or y == _y -1)
                desenho[x][y]= '*';
            
        }
    }
}



int main()
{
    sf::RenderWindow window;
    
    window.create(sf::VideoMode(1024,800),"Cowsay Draw",sf::Style::Default);
    window.setFramerateLimit(60);
    sf::Event e;

    sf::Text text;
    sf::Font font;
    font.loadFromFile("assets/Hack-Regular.ttf");
    char c = 'A';
    char nav = 95; //Cod ASCII
    text.setFont(font);
    text.setStyle(sf::Text::Bold);
    text.setCharacterSize(32);

    ini();
    int x_nav = 1, y_nav = 1;
    //imagem
    sf::Texture texture;
    sf::Sprite sprite;
    texture.loadFromFile("assets/exemplo.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(500,600);
    
    bool runing = 1;
    while(runing)
    {
        if(window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
            {
                runing = 0;
            }
            if(e.type == sf::Event::TextEntered and false == sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)
                and false == sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)
            )
            {
                c = e.text.unicode;
                text.setString(c);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                y_nav--;
                if(y_nav < 1)
                    y_nav = 1;
                
    
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                y_nav++;
                if(y_nav > _y - 2)
                    y_nav = _y - 2;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                x_nav--;
                if(x_nav < 1)
                    x_nav = 1;
                
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                x_nav++;
                if(x_nav > _x - 2)
                    x_nav = _x - 2;
            }
            //table change
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                desenho[x_nav][y_nav] = c;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
            {
                ini();
            }
            
        }
        //beginUpdate
        
        //endUpdate
        window.clear(sf::Color::Blue);

        text.setPosition(0,660);
        text.setString("Move:< ^ v >");
        window.draw(text);
        //clear all
        text.setPosition(0,630);
        text.setString("Backspace=clearAll");
        window.draw(text);

        window.draw(text);
        text.setPosition(0,600);
        text.setString("Type the character: ");
        window.draw(text);
        //draw movement
        text.setPosition(x_nav*30,y_nav*30);
        text.setString(nav);
        window.draw(text);

        text.setPosition(0,690);
        text.setString("Enter=change");
        window.draw(text);

        for(int x = 0;x < _x;x++)
        {
            for(int y = 0;y < _y;y++)
            {

                text.setString(desenho[x][y]);
                text.setPosition(x*30,y*30);
                window.draw(text);
            }
        }

        text.setPosition(400,600);
        text.setString(c);
        window.draw(text);

        window.draw(sprite);

        window.display();
    }

    window.close();
    
}