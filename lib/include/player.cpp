#include "player.hpp"

Player::Player()
    : speed_(1.0f), animationTimer_(0.0f), animationDelay_(0.2f),
      isMoving_(false), currentAnimation_("idle_down"), currentFrame_(0),
      lastDirection_("down") {

    texture_.loadFromFile("resources/detective.png");
    sprite_.setTexture(texture_);
    sprite_.setTextureRect(sf::IntRect(0, 0, frameWidth_, frameHeight_));
    sprite_.setPosition(380.0f, 280.0f);

    loadAnimations();
}

void Player::loadAnimations() {
    animations_["walk_down"]  = {{ {18, 2}, {19, 2}, {20, 2}, {21, 2}, {22, 2}, {23, 2} }};
    animations_["walk_left"]  = {{ {12, 2}, {13, 2}, {14, 2}, {15, 2}, {16, 2}, {17, 2} }};
    animations_["walk_right"] = {{ {0, 2},  {1, 2},  {2, 2},  {3, 2},  {4, 2},  {5, 2} }};
    animations_["walk_up"]    = {{ {6, 2},  {7, 2},  {8, 2},  {9, 2},  {10, 2}, {11, 2} }};

    animations_["idle_down"]  = {{ {18, 1}, {19, 1}, {20, 1}, {21, 1}, {22, 1}, {23, 1} }};
    animations_["idle_left"]  = {{ {12, 1}, {13, 1}, {14, 1}, {15, 1}, {16, 1}, {17, 1} }};
    animations_["idle_right"] = {{ {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1} }};
    animations_["idle_up"]    = {{ {6, 1}, {7, 1}, {8, 1}, {9, 1}, {10, 1}, {11, 1} }};
}

void Player::handleInput() 
{
    isMoving_ = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
    {
        sprite_.move(0, -speed_);
        setAnimation("walk_up");
        lastDirection_ = "up";
        isMoving_ = true;
    } 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
    {
        sprite_.move(0, speed_);
        setAnimation("walk_down");
        lastDirection_ = "down";
        isMoving_ = true;
    } 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        sprite_.move(-speed_, 0);
        setAnimation("walk_left");
        lastDirection_ = "left";
        isMoving_ = true;
    } 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
    {
        sprite_.move(speed_, 0);
        setAnimation("walk_right");
        lastDirection_ = "right";
        isMoving_ = true;
    }

    if (!isMoving_) 
    {
        setAnimation("idle_" + lastDirection_);
    }
}

void Player::setAnimation(const std::string& name) 
{
    if (currentAnimation_ != name) 
    {
        currentAnimation_ = name;
        currentFrame_ = 0;
        animationTimer_ = 0.0f;
    }
}

void Player::update(float deltaTime) 
{
    updateAnimation(deltaTime);
}

void Player::updateAnimation(float deltaTime) 
{
    const auto& animation = animations_[currentAnimation_];

    animationTimer_ += deltaTime;
    if (animationTimer_ >= animationDelay_) 
    {
        animationTimer_ = 0.0f;
        currentFrame_ = (currentFrame_ + 1) % animation.frames.size();
    }

    sf::Vector2i frame = animation.frames[currentFrame_];
    sprite_.setTextureRect(sf::IntRect(
        frame.x * frameWidth_,
        frame.y * frameHeight_,
        frameWidth_,
        frameHeight_
    ));
}

void Player::draw(sf::RenderWindow& window) 
{
    window.draw(sprite_);
}

