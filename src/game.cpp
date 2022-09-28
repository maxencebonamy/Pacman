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
    }),
    _state(State::IDLING),
    _label("3"),
    _startingTimer(3)
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
    }
}

void Game::update() {
    if (_state == State::IDLING) {
        _startingTimer.update();
        if (_startingTimer.isAt(1)) {
            _label.setContent("2");
        }
        else if (_startingTimer.isAt(2)) {
            _label.setContent("1");
        }
        else if (_startingTimer.hasFinished()) {
            _label.setContent("");
            _state = State::PLAYING;
        }
    }

    if (_state == State::PLAYING) {
        _checkCollisions();

        _map->update();
        if (!_map->containsPacgums()) {
            _state = State::ENDING;
            _label.setContent("Win!");
        }

        _player->update();
        for (const auto& ghost : _ghosts) {
            if (_player->hasAteSuperPacgum()) {
                ghost->scare();
            }
            ghost->update();
        }
    }

    if (_state == State::DYING) {
        _player->update();
        if (_player->hasFinished()) {
            _state = State::ENDING;
            _label.setContent("Lose!");
        }
    }
}

void Game::display(sf::RenderWindow& window) {
    _map->display(window);
    for (auto& element : _ghosts) {
        element->display(window);
    }
    _player->display(window);
    _label.display(window);
}

void Game::_checkCollisions() {
    for (const auto& ghost : _ghosts) {
        if (_player->collide(*ghost) && !ghost->isDead()) {
            if (ghost->isScary()) {
                ghost->die();
            }
            else if (!ghost->isScary()) {
                _player->kill();
                _state = State::DYING;
            }
        }
    }
}