
void main()
{
        vec2 position = gl_TexCoord[0].xy;
        
        
        
        vec4 pixel;
        
        pixel.r = position.y;
        pixel.a = 1.0;


        
        gl_FragColor = pixel;
}