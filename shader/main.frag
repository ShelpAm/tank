#version 460 core

in  vec3 fragPos;                     // now holds model-space coords
out vec4 FragColor;

uniform float time;

// HSV → RGB
vec3 hsv2rgb(vec3 c) {
    vec4 K = vec4(1.0, 2.0/3.0, 1.0/3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

// Ease-In/Out Cubic
float easeInOutCubic(float t) {
    return t < 0.5
        ? 4.0 * t * t * t
        : 1.0 - pow(-2.0 * t + 2.0, 3.0) / 2.0;
}

void main() {
    // Normalize model-space pos into [0,1)
    float modelSeed = fract((fragPos.x + fragPos.y + fragPos.z) / 2.0);

    // Time offset ∈ [0,1)
    float cycle  = 5.0;
    float rawT   = mod(time, cycle) / cycle;
    float easedT = easeInOutCubic(rawT);

    // Final hue
    float hue = fract(modelSeed + easedT);

    // Convert to RGB
    vec3 rgb = hsv2rgb(vec3(hue, 1.0, 1.0));
    FragColor = vec4(rgb, 1.0);
}

