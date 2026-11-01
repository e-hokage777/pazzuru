#version 330 core

in VS_OUT {
    vec2 texCoords;
} frag_in;

out vec4 FragColor;

uniform sampler2D sampler;

void main() {
    FragColor = vec4(texture2D(sampler, frag_in.texCoords));
}