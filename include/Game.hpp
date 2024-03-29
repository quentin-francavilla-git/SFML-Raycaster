#if !defined(GAME_HPP_)
#define GAME_HPP_

#include "lib.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "Rays.hpp"

#define WINDOW_WIDTH 1980
#define WINDOW_HEIGHT 1080
#define MAX_PLAYERS 1

class Game
{
private:
    // Variables
    // Window
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;

    // Time
    sf::Clock clock;
    float dt;

    // Mouse
    sf::Vector2i mousePosWindows;

    //Import classes
    vector<unique_ptr<Player>> player;
    unique_ptr<Map> map;
    unique_ptr<Rays> rays;

    // Private Functions
    void initVariables();
    void initWindow();
    void initPlayer();
    void initMap();
    void initRays();

public:
    // Constructors / Destructors
    Game();
    virtual ~Game();

    // Public Functions
    // Core Functions
    const bool running() const;
    void pollEvents();
    void update();
    void updateTime();
    float getTime();
    void render();
    void updateMousePositions();

    // Player
    void updatePlayer();
    void renderPlayer();
    Player getPlayer(int indexPlayer);

    // Map
    void renderMap2D();

    //Rays
    void renderRays();
};

#endif // GAME_HPP_
