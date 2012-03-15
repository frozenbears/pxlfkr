
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Text.h"
#include "cinder/Utilities.h"
#include "cinder/Font.h"

class Text {

public:
	
	void clear(float r, float g, float b, float a);
	void setColor(float r, float g, float b, float a);
	void setFont(const std::string& name, float pointSize);
	void addLine(const std::string& line);
	void addCenteredLine(const std::string& line);
	void addRightLine(const std::string& line);
	void append(const std::string& str);
	void setLeadingOffset(float offset);
	void setBorder(int horizontal, int vertical);
	void render();
	void draw(float x, float y);
	
private:
	ci::TextLayout layout;
	ci::gl::Texture texture;
	ci::Surface8u surface;
};
		