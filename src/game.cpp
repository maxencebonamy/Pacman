#include "game.hpp"
#include "entities/ghosts/blinky.hpp"
#include "entities/ghosts/inky.hpp"
#include "entities/ghosts/clyde.hpp"
#include "entities/ghosts/pinky.hpp"


// Constructors

Game::Game() :
    _map(std::make_shared<Map>("map")),
    _player(std::make_unique<Player>(_map, Vector2::one())),
    _ghosts({
        std::make_unique<Blinky>(_map, Vector2(12, 11)),
        std::make_unique<Inky>(_map, Vector2(15, 11)),
        std::make_unique<Clyde>(_map, Vector2(12, 17)),
        std::make_unique<Pinky>(_map, Vector2(15, 17))
    })
{}


// Public Methods

void Game::manageEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Key::Left) {
            _player->setDirection(Direction::LEFT);
        }
        else if (event.key.code == sf::Keyboard::Key::Right) {
            _player->setDirection(Direction::RIGHT);
        }
        else if (event.key.code == sf::Keyboard::Key::Up) {
            _player->setDirection(Direction::UP);
        }
        else if (event.key.code == sf::Keyboard::Key::Down) {
            _player->setDirection(Direction::DOWN);
        }
        else if (event.key.code == sf::Keyboard::Key::K) {
            _player->kill();
        }
    }
}

void Game::update() {
    _checkCollisions();

    _map->update();
    if (!_map->containsPacgums() && !_hasWon) {
        _hasWon = true;
        std::cout << "Win" << std::endl;
    }

    _player->update();
    for (auto& ghost : _ghosts) {
        if (_player->hasAteSuperPacgum()) {
            ghost->scare();
        }
        ghost->update();
    }
}

void Game::display(sf::RenderWindow& window) {
    _map->display(window);
    for (auto& element : _ghosts) {
        element->display(window);
    }
    _player->display(window);
}

void Game::_checkCollisions() const {
    for (const auto& ghost : _ghosts) {
        if (_player->collide(*ghost)) {
            if (ghost->isScary()) {
                std::cout << ghost->getName() << " ate !" << std::endl;
            }
            else {
                std::cout << "Lose !" << std::endl;
            }
        }
    }
}