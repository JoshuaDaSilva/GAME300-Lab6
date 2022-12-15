#version 430 core

out vec4 color;                                                   

in vec2 UV;
in vec3 normalVec;
in vec3 lightVec;

vec3 N = normalize(normalVec);
vec3 L = normalize(lightVec);

uniform sampler2D texture0;

uniform vec3 ambientLight = vec3(0.2,0.2,0.2);

uniform vec3 diffuse_albedo = vec3(1.0, 1.0, 1.0);

void main(void)                                                   
{                                      
    vec3 diffuse = max(dot(N, L), 0.0) * diffuse_albedo;
    color = texture( texture0, UV ) * vec4(diffuse + ambientLight, 1.0f);  

}                                                                 