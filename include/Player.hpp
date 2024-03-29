#if !defined(PLAYER_HPP_)
#define PLAYER_HPP_

#include "lib.hpp"
#include "Input.hpp"

enum PLAYER_ANIMATION_STATES
{
    IDLE = 0,
    MOVING_LEFT,
    MOVING_RIGHT,
    JUMPING,
    FALLING
};

class Player
{
private:
    //Globals
    sf::Sprite sprite;
    string characterName;
    string name;
    float speed;
    sf::Clock animationTimer;
    sf::Texture texture;
    sf::RectangleShape playerRectangle;

    //Position
    sf::Vector2f playerDelta;
    sf::Vector2f playerPos;
    sf::Vector2i playerPosInMap;
    sf::Vector2f playerMoveOffset;

    //Collisions
    sf::Vector2i CollisionOffset;
    sf::Vector2i playerPosInMap_add_Offset;
    sf::Vector2i playerPosInMap_sub_Offset;

    float playerAngle;

    // Animation
    short animState;
    sf::IntRect *currentFrame;

    // Physics
    sf::Vector2f velocity;
    float acceleration;
    float deceleration;

    //Map
    sf::Vector2i mapMaxSize;
    int tileSize;
    vector<int> mapArray;

    //Import classes
    shared_ptr<Input> inputs;

    // Private Functions
    void initVariables(string _name, string _characterName);
    void initCharacter();
    void initSprite();
    void initAnimation();

public:
    // Constructors Destructors
    Player(string _name, string _characterName);
    virtual ~Player();

    // Public Functions
    void update(float dt, int tileSize_, vector<int> mapArray_, sf::Vector2i mapMaxSize_);
    void updatePhysics();
    void updateMovement(float dt);
    void updateAnimation();
    void updateCollisions(float dt);
    void render(sf::RenderTarget &target);

    //Methods
    const float &getPlayerAngle() const;
    const sf::Vector2f &getPlayerPosition() const;
    const string &getName() const;
    void setName(string newName);
};

#endif // PLAYER_HPP_
