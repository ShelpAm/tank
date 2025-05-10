#version 460 core
in  vec3 fragPos;                     // now holds model-space coords
out vec4 FragColor;
uniform float time;

void main()
{
    float s = abs(sin(time));
    float t = abs(sin(time + 1));
    float r = abs(sin(time + 2));
    FragColor = vec4(s, t, r, 1.0);
}
