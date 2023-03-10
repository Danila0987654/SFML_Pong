#include "pang.h"

sf::RenderWindow Pang::_window;
sf::Clock Pang::_clock;
Pang::State Pang::_state = Uninitialized;
std::map<Pang::State, GameState *> Pang::_stateInstances;

void Pang::start() {
    if (_state != Uninitialized) return;

    _window.create(sf::VideoMode(Pang::SCREEN_WIDTH, Pang::SCREEN_HEIGHT,
                                 32), "Pang");
    _window.setFramerateLimit(60);

    _stateInstances[Splashscreen] = new SplashscreenState();
    _stateInstances[Splashscreen]->init();
    _stateInstances[Menu] = new MenuState();
    _stateInstances[Menu]->init();
    _stateInstances[Playing] = new PlayingState();
    _stateInstances[Playing]->init();
    _state = Splashscreen;

    gameLoop();

    // Auto deleting game states which we aren't using
    auto itr = _stateInstances.begin();
    while (itr != _stateInstances.end()) {
        delete itr->second;
        itr++;
    }

    _window.close();
}

void Pang::gameLoop() {
    while (_state != Exiting) {
        float timeElapsed = _clock.restart().asSeconds();
        _window.clear(sf::Color(255, 255, 255));

        // For not changing our state during a frame
        GameState *currentState = _stateInstances[_state];

        // Handle input
        sf::Event event{};
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { _state = Exiting; }
            currentState->handleInput(&event);
        }

        // Update entries
        currentState->update(timeElapsed);

        // Draw our new entities
        currentState->draw(&_window);
        _window.display();
    }
}

void Pang::setState(State s) { _state = s;}