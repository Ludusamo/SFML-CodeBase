#ifndef FADETRANSITION_H
#define FADETRANSITION_H

#include "Transition.h"

class FadeTransition : public Transition {
public:
    FadeTransition();
    ~FadeTransition();

    void loadContent(std::string text, sf::Texture texture, sf::Vector2f pos);
    void unloadContent();
    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);

    void setAlpha(float a);
protected:
private:
    bool increase;
    float fadeSpeed;

};

#endif // FADETRANSITION_H
