
#include "Shader.h"
#include "cinder/app/AppBasic.h"

using namespace std;
using namespace ci;
using namespace ci::app;

Shader::Shader(const string& vertexFile, const string& fragmentFile) {
	
	try {
		mShader = gl::GlslProg(loadFile(vertexFile), loadFile(fragmentFile));
	} catch( gl::GlslProgCompileExc &exc ) {
		cout << "Shader compile error: " << endl;
		cout << exc.what();
	} catch( StreamExc &exc ) {
		cout << "Shader load error: " << endl;
		cout << exc.what();
	}
}

Shader::~Shader() {
	if (mShader) {
	    mShader.unbind();	
	}
}

void Shader::bind() {
	if(mShader) {
		mShader.bind();
	}
}

void Shader::unbind() {
	if (mShader) {
		mShader.unbind();
	}
}

void Shader::uniform1f(string& name, float data) {
	if (mShader) {
		mShader.uniform(name, data);
	}
}

void Shader::uniform2f(string& name, float data, float data2) {
	if (mShader) {
		mShader.uniform(name, Vec2f(data, data2));
	}
}

void Shader::uniform3f(string& name, float data, float data2, float data3) {
	if (mShader) {
		mShader.uniform(name, Vec3f(data, data2, data3));
	}
}

void Shader::uniform4f(string& name, float data, float data2, float data3, float data4) {
	if (mShader) {
		mShader.uniform(name, Vec4f(data, data2, data3));
	}
}

void Shader::uniform1i(string& name, int data) {
	if (mShader) {
		mShader.uniform(name, data);
	}
}

void Shader::uniform2i(string& name, int data, int data2) {
	if (mShader) {
		mShader.uniform(name, Vec2i(data, data2));
	}
}

