#version 120

const vec3 LumCoeff = vec3(0.2125, 0.7154, 0.0721);

uniform float alpha = 1.0;
uniform sampler2DRect tex0;

void main (void)
{
    vec4 texColor  = texture2DRect(tex0, gl_FragCoord.xy);
    vec3 intensity = vec3 (dot(texColor.rgb, LumCoeff));
    vec3 color     = mix(intensity, texColor.rgb, alpha);
    gl_FragColor   = vec4(color, texColor.a);
}
