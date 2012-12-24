
#include "Shader.h"
#include "cinder/app/AppBasic.h"

using namespace std;
using namespace ci;
using namespace ci::app;

Shader::Shader(const string& vertexFile, const string& fragmentFile) {
	
	try {
		mShader = gl::GlslProg(loadResource(vertexFile), loadResource(fragmentFile));
	} catch( gl::GlslProgCompileExc &exc ) {
		cout << "Shader compile error: " << endl;
		cout << exc.what();
	}
}

void Shader::bind() {
	mShader.bind();
}

void Shader::unbind() {
	mShader.unbind();
}

void Shader::uniform1f(string& name, float data) {
	mShader.uniform(name, data);
}

void Shader::uniform2f(string& name, float data, float data2) {
	mShader.uniform(name, Vec2f(data, data2));
}

void Shader::uniform3f(string& name, float data, float data2, float data3) {
	mShader.uniform(name, Vec3f(data, data2, data3));
}

void Shader::uniform4f(string& name, float data, float data2, float data3, float data4) {
	mShader.uniform(name, Vec4f(data, data2, data3));
}

void Shader::uniform1i(string& name, int data) {
	mShader.uniform(name, data);
}

void Shader::uniform2i(string& name, int data, int data2) {
	mShader.uniform(name, Vec2i(data, data2));
}

