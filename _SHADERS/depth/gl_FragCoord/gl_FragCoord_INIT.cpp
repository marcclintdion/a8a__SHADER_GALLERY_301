 
    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      gl_FragCoord_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_gl_FragCoord =                                                                                                        

        "    #define highp                                                                                                                              \n"


        "    uniform highp vec4         light_POSITION_01;                                                                                              \n"

        "    uniform       mat4         mvpMatrix;                                                                                                      \n"
        "    uniform       mat4         lightMatrix;                                                                                                    \n"

        "    attribute     vec4         position;                                                                                                       \n"
        "    attribute     vec3         normal;                                                                                                         \n"
        "    attribute     vec2         texture;                                                                                                        \n"

        "    varying highp vec4         lightPosition_PASS;                                                                                             \n"
        "    varying highp vec2         varTexcoord;                                                                                                    \n"


        "    void main()                                                                                                                                \n"
        "    {                                                                                                                                          \n"

        "       lightPosition_PASS      =  normalize(lightMatrix * light_POSITION_01);                                                                  \n"
     
        "       varTexcoord             =  texture;                                                                                                     \n"


        "       gl_Position             =  mvpMatrix * position;                                                                                        \n"

        "    }\n";
      //---------------------------------------------------------------------                                                                   
      gl_FragCoord_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(gl_FragCoord_SHADER_VERTEX, 1, &vertexSource_gl_FragCoord, NULL);                                                                        
      glCompileShader(gl_FragCoord_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_gl_FragCoord =                                                                                                            

     
        " #ifdef GL_ES                                                                                                                                  \n"
        " #else                                                                                                                                         \n"
        " #define highp                                                                                                                                 \n"
        " #endif                                                                                                                                        \n"

        "    uniform highp sampler2D    NormalMap;                                                                                                      \n"

        "    uniform highp vec4         moveSet;                                                                                                        \n"

        "    varying highp vec4         lightPosition_PASS;                                                                                             \n"
        "    varying highp vec2         varTexcoord;                                                                                                    \n"

        "            highp vec3         normalFrag;                                                                                                     \n"
        "            highp vec3         NormalTex;                                                                                                      \n"
        "            highp float        NdotL1;                                                                                                         \n"


        "     void main()                                                                                                                               \n"
        "     {                                                                                                                                         \n"

        "         NormalTex             =  texture2D(NormalMap,  varTexcoord).xyz;                                                                      \n"
        "         NormalTex             =  (NormalTex - 0.5);                                                                                           \n"
        "         normalFrag            =  normalize(NormalTex);                                                                                        \n"
        "         NdotL1                =  dot(normalFrag, lightPosition_PASS.xyz);                                                                     \n"


        "         gl_FragColor          =  vec4(vec3(moveSet.z - (gl_FragCoord.z / gl_FragCoord.w)), 1.0);                                                    \n"




      "    }\n";

      //---------------------------------------------------------------------                                                                         
      gl_FragCoord_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(gl_FragCoord_SHADER_FRAGMENT, 1, &fragmentSource_gl_FragCoord, NULL);                                                                          
      glCompileShader(gl_FragCoord_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(gl_FragCoord_SHADER, gl_FragCoord_SHADER_VERTEX);                                                                                              
      glAttachShader(gl_FragCoord_SHADER, gl_FragCoord_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(gl_FragCoord_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(gl_FragCoord_SHADER,    1, "normal");       
      glBindAttribLocation(gl_FragCoord_SHADER,    2, "texture");                                                                                            
      //------------------------------------------------                                                                                              
      glLinkProgram(gl_FragCoord_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(gl_FragCoord_SHADER, gl_FragCoord_SHADER_VERTEX);                                                                                              
      glDetachShader(gl_FragCoord_SHADER, gl_FragCoord_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(gl_FragCoord_SHADER_VERTEX);                                                                                                            
      glDeleteShader(gl_FragCoord_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_gl_FragCoord                    = glGetUniformLocation(gl_FragCoord_SHADER,   "mvpMatrix");
      UNIFORM_LIGHT_MATRIX_gl_FragCoord                     = glGetUniformLocation(gl_FragCoord_SHADER,   "lightMatrix");
      UNIFORM_LIGHT_POSITION_01_gl_FragCoord                = glGetUniformLocation(gl_FragCoord_SHADER,   "light_POSITION_01");
      UNIFORM_moveSet_gl_FragCoord                          = glGetUniformLocation(gl_FragCoord_SHADER,   "moveSet");

      UNIFORM_TEXTURE_DOT3_gl_FragCoord                     = glGetUniformLocation(gl_FragCoord_SHADER,   "NormalMap");




