#version 330 core

// inputs
in vec2 texCoords;

// outputs
out vec4 FragColor;

// uniforms
uniform bool useTexture;
uniform vec4 color = vec4(1.0, 1.0, 1.0, 1.0);
uniform sampler2D image;

void main() {
    FragColor = useTexture ? texture(image, texCoords) * color : color;
}