// uniform vec2 resolution;
uniform float time;

void main() {
    vec2 resolution = vec2(1920., 1080.);
    vec2 uv = (gl_FragCoord.xy * 2. - resolution) / resolution;

    float distance = length(uv) * .70 + sin(time * 2.) * .15;

    float darkness = smoothstep(0.5, 0.3, distance);

    gl_FragColor = vec4(vec3(0.), distance);
}
