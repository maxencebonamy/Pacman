#include "SFML/Graphics.hpp"
#include "map/map.hpp"
#include "config.hpp"
#include "entities/player.hpp"
#include "entities/ghosts/blinky.hpp"
#include "entities/ghosts/pinky.hpp"
#include "entities/ghosts/clyde.hpp"
#include "entities/ghosts/inky.hpp"


int main() {

    bool hasWon { false };
    bool close { false };

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
    Player player { map, Vector2(1, 1) };

//    std::unique_ptr<Ghost> blinky { std::make_unique<Ghost>(map, Vector2(12, 14), "blinky") };
//    std::unique_ptr<Ghost> pinky { std::make_unique<Ghost>(map, Vector2(12, 14), "pinky") };
    std::array<std::unique_ptr<Ghost>, 4> ghosts {
        std::make_unique<Blinky>(map, Vector2(12, 11)),
        std::make_unique<Inky>(map, Vector2(15, 11)),
        std::make_unique<Clyde>(map, Vector2(12, 17)),
        std::make_unique<Pinky>(map, Vector2(15, 17))
    };

    while (window.isOpen()) {
        sf::Event event {};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                    (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
                window.close();
                close = true;
                break;
            }
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

        if (close) {
            break;
        }

        map->update();
        if (!map->containsPacgums() && !hasWon) {
            hasWon = true;
            std::cout << "Win" << std::endl;
        }

        player.update();
        for (auto& ghost : ghosts) {
            if (player.hasAteSuperPacgum()) {
                ghost->scare();
            }
            ghost->update();
        }

        window.clear();

        map->display(window);
        for (auto& element : ghosts) {
            element->display(window);
        }
        player.display(window);

        window.display();
    }

    return 0;

}