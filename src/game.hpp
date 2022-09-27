#pragma once

#include "config.hpp"
#include "entities/ghosts/ghost.hpp"
#include "entities/player.hpp"

class Game {

public:
    // Constructors
    Game();

    // Big Five
    Game(const Game& game) = delete;
    Game(Game&& game) noexcept = delete;
    Game& operator=(const Game& game) = delete;
    Game& operator=(Game&& game) noexcept = delete;
    ~Game() = default;

    // Public Methods
    void manageEvent(const sf::Event& event);
    void update();
    void display(sf::RenderWindow& window);

private:
    // Private Methods
    void _checkCollisions() const;

    // Attributes
    std::shared_ptr<Map> _map;
    std::unique_ptr<Player> _player;
    std::array<std::unique_ptr<Ghost>, 4> _ghosts;

    bool _hasWon { false };

};
