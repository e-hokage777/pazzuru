#version 330 core

// inputs
in vec2 texCoords;

// outputs
out vec4 FragColor;

// uniforms
uniform bool useTexture;
uniform vec3 color = vec3(1.0, 0.8, 0.2);
uniform sampler2D image;

void main() {
    FragColor = useTexture ? texture(image, texCoords) * vec4(color, 1.0) : vec4(color, 1.0);
}