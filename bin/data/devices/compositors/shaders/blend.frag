#version 120

#ifdef GL_ES
precision mediump float;
#endif

uniform sampler2DRect tex0;
uniform sampler2DRect tex1;
uniform float opacity = 0.0;
uniform int blendmode = 0; 

void main()
{
    vec4 base = texture2DRect(tex0, gl_FragCoord.xy);
    vec4 blend = texture2DRect(tex1, gl_FragCoord.xy);

    vec4 result;
    if (blendmode == 0) {
        // normal
        result = blend;
    } else if (blendmode == 1) {
        // addition
        result = base + blend;
    } else if (blendmode == 2) {
        // multiply
        result = base * blend;
    } else if (blendmode == 3) {
        // screen
        result = vec4(1.0) - ((vec4(1.0) - blend) * (vec4(1.0) - base));
    } else if (blendmode == 4) {
        // darken
        result = min(blend, base);
    } else if (blendmode == 5) {
        // lighten
        result = max(blend, base);
    } else if (blendmode == 6) {
        // difference
        result = abs(base - blend);
    } else if (blendmode == 7) {
        // negation
        result = vec4(1.0) - abs( vec4(1.0) - base - blend );
    } else if (blendmode == 8) {
        // exclusion
        result = base + blend - (2.0*base*blend);
    } else if (blendmode == 9) {
        // dodge
        result = base / (vec4(1.0) - blend);
    } else if (blendmode == 10) {
        result = vec4(1.0) - (vec4(1.0) - base) / blend;
    } else {
          result = blend;
    }
    gl_FragColor = mix(base, result, result.a * opacity);
}

