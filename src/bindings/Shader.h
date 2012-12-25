
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/GlslProg.h"

class Shader {

public:
	Shader(const std::string& vertexFile, const std::string& fragmentFile);
	~Shader();
	
	void bind();
	void unbind();
	
	/* note to self - the below feels a bit weird, seeing as though we're
	 converting these flat parameter lists into templated c++ typedefs only
	 for them to be converted back again underlyingly in the openGL calls.
	 
	 to me this suggests we might be better off binding Vec/Color/Mat types
	 directly, but maybe it's fine?
	 */
	
	void uniform1f(std::string& name, float data);
	void uniform2f(std::string& name, float data, float data2);
	void uniform3f(std::string& name, float data, float data2, float data3);
	void uniform4f(std::string& name, float data, float data2, float data3, float data4);
	
	void uniform1i(std::string& name, int data);
	void uniform2i(std::string& name, int data, int data2);
private:
	ci::gl::GlslProg mShader;
};