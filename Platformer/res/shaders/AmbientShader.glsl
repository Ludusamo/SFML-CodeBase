#define LOWP

uniform sampler2D texture;

uniform LOWP vec4 ambientColor;

void main() {
        vec4 diffuseColor = texture2D(texture, gl_TexCoord[0].xy);
        vec3 ambient = ambientColor.rgb * ambientColor.a;

        vec3 final = gl_Color.rgb * diffuseColor.rgb * ambient;
        gl_FragColor = vec4(final, diffuseColor.a);
}
