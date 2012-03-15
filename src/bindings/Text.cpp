
#include "Text.h"

void Text::clear(float r, float g, float b, float a) {
	
	ci::ColorA color(r,g,b,a);
	
	layout.clear(color);
}

void Text::setColor(float r, float g, float b, float a) {
	layout.setColor(ci::ColorA(r, g, b, a));
}

void Text::setFont(const std::string& name, float pointSize) {
	layout.setFont(ci::Font(name, pointSize)); 
}

void Text::addLine(const std::string& line) {
	layout.addLine(line);
}

void Text::addCenteredLine(const std::string& line) {
	layout.addCenteredLine(line);
}

void Text::addRightLine(const std::string& line) {
	layout.addRightLine(line);
}

void Text::append(const std::string& str) {
	layout.append(str);
}

void Text::setLeadingOffset(float offset) {
	layout.setLeadingOffset(offset);
}

void Text::setBorder(int horizontal, int vertical) {
	layout.setBorder(horizontal, vertical);
}

void Text::render() {
	surface = layout.render(true, true);
	texture = ci::gl::Texture(surface);
}

void Text::draw(float x, float y) {
	ci::gl::draw(texture, ci::Vec2f(x, y));
}