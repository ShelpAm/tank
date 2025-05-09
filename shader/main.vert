#version 460 core
layout(location = 0) in vec3 aPos;
out vec3 fragPos;

uniform mat4 uMVP;

void main() {
    vec4 clipPos = uMVP * vec4(aPos, 1.0);
    gl_Position = clipPos;
    fragPos = aPos;
}
