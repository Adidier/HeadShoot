#version 120

varying vec2 texCoord0;
varying vec3 normal0;

uniform sampler2D sampler;
uniform vec3 lightDirection;
void main()
{
	gl_FragColor = texture2D(sampler, texCoord0) * 
		clamp(dot(-lightDirection, normal0), 0.0, 1.0);
}

/*
varying vec3 N;
varying vec3 v;

void main(void)
{
   vec3 L = normalize(gl_LightSource[0].position.xyz - v);   
   vec4 Idiff = gl_FrontLightProduct[0].diffuse * max(dot(N,L), 0.0);  
   Idiff = clamp(Idiff, 0.0, 1.0); 

   gl_FragColor = Idiff;
} */  