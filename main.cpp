#include <SFML/Graphics.hpp>
#include <cstdlib>


int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Sierpinski triangle");
    sf::VertexArray lines(sf::Points, 100000);
    lines[0].position = sf::Vector2f(0.f, 0.f);
    lines[1].position = sf::Vector2f(500.f, 0.f);
    lines[2].position = sf::Vector2f(250.f, 433.0127f);
    lines[3].position = sf::Vector2f(50.f, 50.f);
    for (int i = 4;i < 100000;i++) {
        int random_number = std::rand() % 3;
        lines[i].position.x = (lines[i - 1].position.x+lines[random_number].position.x)/2;
        lines[i].position.y = (lines[i - 1].position.y + lines[random_number].position.y) / 2;
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
        window.draw(lines);
        window.display();
    }

    return 0;
}