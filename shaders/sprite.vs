#version 330 core

// inputs
layout(location = 0) in vec2 aPos;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 aTexCoords;

// outputs
out vec2 texCoords;

// uniforms
uniform mat4 model;
uniform mat4 projection;
uniform vec4 uvRect;

void main() {
    gl_Position = projection * model * vec4(aPos, 0.0, 1.0);
    // texCoords = aTexCoords;
    texCoords = mix(uvRect.xy, uvRect.zw, aTexCoords);
}