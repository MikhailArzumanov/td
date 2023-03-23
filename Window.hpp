#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include <SFML/Graphics/RenderWindow.hpp>

class Window{
private:
    sf::RenderWindow* window = nullptr;
    std::string title = "";
    int width  = 0;
    int height = 0;

    void  init();
public:
    Window(std::string _title, int _width, int _height);
    Window();

    void clear();

    void initWindow    (std::string _title, int _width, int _height);
    void setWindowTitle(std::string _title);
    void resizeWindow(int _width, int _height);

    int getHeight()        const;
    int getWidth()         const;
    std::string getTitle() const;

    sf::RenderWindow* get()        const;
    sf::RenderWindow* operator->() const;
};

extern Window window;

#endif // WINDOW_HPP_INCLUDED
