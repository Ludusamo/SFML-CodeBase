#define LOWP

uniform sampler2D texture;
uniform sampler2D lightmap;

uniform vec2 resolution;
uniform LOWP vec4 ambientColor;

void main() {
	vec4 diffuseColor = texture2D(texture, gl_TexCoord[0].xy);
	vec2 lighCoord = (gl_FragCoord.xy / resolution.xy);
	vec4 light = texture2D(lightmap, lighCoord);

	vec3 ambient = ambientColor.rgb * ambientColor.a;
	vec3 intensity = ambient + light.rgb;
 	vec3 finalColor = diffuseColor.rgb * intensity;

	gl_FragColor = gl_Color * vec4(finalColor, diffuseColor.a);
}
