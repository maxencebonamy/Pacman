#include "SFML/Graphics.hpp"
#include "map/map.hpp"
#include "config.hpp"
#include "images/animated_image.hpp"
#include "entities/player.hpp"


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

    std::shared_ptr<Map> map { std::make_shared<Map>("map") };
    Player player { map, Vector2(1) };

    while (window.isOpen()) {
        sf::Event event {};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Key::Left) {
                    player.setDirection(Direction::LEFT);
                }
                else if (event.key.code == sf::Keyboard::Key::Right) {
                    player.setDirection(Direction::RIGHT);
                }
                else if (event.key.code == sf::Keyboard::Key::Up) {
                    player.setDirection(Direction::UP);
                }
                else if (event.key.code == sf::Keyboard::Key::Down) {
                    player.setDirection(Direction::DOWN);
                }
                else if (event.key.code == sf::Keyboard::Key::K) {
                    player.kill();
                }
            }
        }

        player.update();

        window.clear();
        map->display(window);
//        player.setPosition(Vector2(100));
        player.display(window);
        window.display();
    }

    return 0;

}