#version 400

in vec3 position;
in vec3 normal;
in vec2 texCoord;

uniform vec3 lightPosition;
//uniform vec3 Ka;
//uniform vec3 Kd;
uniform vec3 Ks;
uniform vec3 Ia;
uniform vec3 Id;
uniform vec3 Is;
uniform float Shininess;

uniform sampler2D TexSamplerColor;

layout (location = 0) out vec4 FragColor;

vec3 ads(vec4 texColor){
	vec3 Kad = texColor.rgb;
	vec3 n = normalize( normal );
	vec3 l = normalize( lightPosition-position );
	vec3 v = normalize( -position );
	vec3 r = reflect( -l, n );
	vec3 ambient = (Ia * Kad);
	vec3 diffuse = (Id * Kad * max( dot(l,n), 0.0));
	vec3 specular;
	specular = (Is * Ks * pow( max( dot(r,v), 0.0), Shininess));
	return ambient + diffuse + specular;
}

void main() {
	vec4 texColor = texture(TexSamplerColor, texCoord);
	FragColor = vec4(ads(texColor), 1.0);
}