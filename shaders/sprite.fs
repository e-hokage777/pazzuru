#version 330 core

// inputs
in vec2 texCoords;

// outputs
out vec4 FragColor;

// uniforms
uniform sampler2D sampler;

void main() {
    FragColor = texture2D(sampler, texCoords);
    
}