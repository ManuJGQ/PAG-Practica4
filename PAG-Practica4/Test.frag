#version 400

layout (location = 0) out vec4 fragColor;

void main() {
	if(gl_FrontFacing){
		fragColor = vec4(0.0, 1.0, 0.0, 1.0);
	} else {
		fragColor = vec4(1.0, 0.0, 0.0, 1.0);
	}
}