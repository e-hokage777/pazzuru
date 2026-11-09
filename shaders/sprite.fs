#version 330 core

// inputs
in vec2 texCoords;

// outputs
out vec4 FragColor;

// uniforms
uniform sampler2D sampler;
uniform vec3 spriteColor;

void main() {
    FragColor = vec4(spriteColor, 1.0) * texture(sampler, texCoords);
    // FragColor = texture2D(sampler, texCoords);
    
}