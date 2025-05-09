#version 460 core
out vec4 FragColor;
uniform float time;

void main()
{
    float s = sin(time);
    FragColor = vec4(s, s, s, 1.0);
}
