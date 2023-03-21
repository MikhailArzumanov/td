#include "Window.hpp"

Window::Window(std::string _title, int _width, int _height){
    title = _title; width = _width; height = _height;
    init();
}
Window::Window(){}

void Window::clear(){
    if(window) delete window;
    window = nullptr;
}

void Window::init(){
    window = new sf::RenderWindow(sf::VideoMode(width, height), title);
}

void Window::initWindow(std::string _title, int _width, int _height){
    title = _title; width = _width; height = _height;
    clear();
    init();
}
void Window::setWindowTitle(std::string _title){
    title = _title;
    window->setTitle(title);
}

void Window::resizeWindow(int _width, int _height){
    width = _width; height = _height;
    clear();
    init();
}

int         Window::getHeight()const{return height;}
int         Window::getWidth() const{return  width;}
std::string Window::getTitle() const{return  title;}

sf::RenderWindow* Window::get()        const{return window;}
sf::RenderWindow* Window::operator->() const{return window;}

Window window;
