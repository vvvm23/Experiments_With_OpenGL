#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    sf::CircleShape shape(100.f);

    shape.setFillColor(sf::Color::Red);

    //sf::CircleShape shape_2(50.f);
    //shape_2.setFillColor(sf::Color::Green);

    sf::CircleShape circles[20];
    int circle_start[20];

    for (int c = 0; c < 20; c++) {
        circles[c].setRadius(50.0f);
        circle_start[c] = 30 * (c+1);
        circles[c].setPosition(0.0f, circle_start[c]);
        circles[c].setFillColor(sf::Color::Red);
        circles[c].setOutlineColor(sf::Color::Black);
        circles[c].setOutlineThickness(2);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        for (int c = 0; c < 20; c++) {
            circles[c].move(1.0f, 0.0f);
            if (circles[c].getPosition().x > 1280) {
                circles[c].setPosition(0.0f, circle_start[c]);
            }
            window.draw(circles[c]);
        }

        window.display();
    }

    return 0;
}

