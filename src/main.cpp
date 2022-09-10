#include "SFML/Graphics.hpp"
#include "map/map.hpp"
#include "config.hpp"
#include "images/animated_image.hpp"


int main() {

    sf::VideoMode videoMode {
        static_cast<unsigned int>(config::WINDOW_SIZE.getX()),
        static_cast<unsigned int>(config::WINDOW_SIZE.getY())
    };
    int style { config::WINDOW_FULLSCREEN ? sf::Style::Fullscreen : sf::Style::Titlebar | sf::Style::Close };
    sf::RenderWindow window(videoMode, config::WINDOW_TITLE, style);
    window.setFramerateLimit(config::WINDOW_FPS);

    sf::Image icon;
    icon.loadFromFile("res/img/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    Map map { "map" };
    AnimatedImage player { "pacman/walk/walk_right", 32 };

    while (window.isOpen()) {
        sf::Event event {};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                window.close();
        }

        player.updateFrame();

        window.clear();
        map.display(window);
        player.setPosition(Vector2(100));
        player.display(window);
        window.display();
    }

    return 0;

}