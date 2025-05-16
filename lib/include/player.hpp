#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <string>

class Player 
{
public:
    Player();
    void handleInput();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

private:
    struct Animation 
    {
        std::vector<sf::Vector2i> frames;
    };

    sf::Texture texture_;
    sf::Sprite sprite_;
    float speed_;
    float animationTimer_;
    float animationDelay_;
    bool isMoving_;

    std::map<std::string, Animation> animations_;
    std::string currentAnimation_;
    int currentFrame_;
    std::string lastDirection_; 
    const int frameWidth_ = 16;
    const int frameHeight_ = 32;

    void loadAnimations();
    void updateAnimation(float deltaTime);
    void setAnimation(const std::string& name);
};

#endif
