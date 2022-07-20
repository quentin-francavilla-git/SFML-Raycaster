#if !defined(MAP_HPP_)
#define MAP_HPP_

#include "lib.hpp"

class Map {
private:
    sf::Vector2i mapMaxSize;
    int tileSize;
    std::vector<int> mapArray;

public:
    // Constructors Destructors
    Map(int _size);
    virtual ~Map();

    void render(sf::RenderTarget &target);

    const int &getTileSizeMap() const;
    const sf::Vector2i &getMapMaxSize() const;
    const std::vector<int> &getMapArray() const;
};

#endif // MAP_HPP_