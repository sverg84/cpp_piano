#include "../include/Piano.hpp"

Piano::Piano(void) {}

Piano::~Piano(void) {}

void Piano::render(sf::RenderTarget& renderTarget) {
    pianoKey.render(renderTarget)
;}