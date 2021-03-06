    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      rubber_20bit_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_rubber_20bit =                                                                                                        

      "    #define highp                                                                                       \n"                           

      "    uniform highp vec4   light_POSITION_01;                                                             \n"                           
      "    uniform       mat4   mvpMatrix;                                                                     \n"                           
      "    uniform       mat4   lightMatrix;                                                                   \n"                           

      "    attribute     vec4   position;                                                                      \n"                           
      "    attribute     vec2   texture;                                                                       \n"                           

      "    varying highp vec4   lightPosition_PASS;                                                            \n"                           
      "    varying highp vec2   varTexcoord;                                                                   \n"                           

     "     varying highp vec4   diffuse;                                                                        \n"
      "    varying highp vec4   ambientGlobal;                                                                  \n"
      "    varying highp float  dist;                                                                           \n"
      "            highp vec4   ecPos;                                                                          \n"
      "            highp vec3   aux;                                                                            \n"

      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           

      "        ecPos                 = mvpMatrix * position;                                                   \n"
      "        aux                   = vec3(light_POSITION_01 - ecPos);                                        \n"
      "        dist                  = length(aux);                                                            \n"

      "        diffuse               = highp  vec4(  -1.925, 2.925 , 2.925, 1.0);                              \n"
      "        ambientGlobal         = highp  vec4(-1.75, -1.75, 0.0, 1.0);                                    \n"      
     
      "        lightPosition_PASS    = normalize(lightMatrix * light_POSITION_01);                             \n"                           
      "        varTexcoord           = texture;                                                                \n"                           
      "        gl_Position           = mvpMatrix * position;                                                   \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      rubber_20bit_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(rubber_20bit_SHADER_VERTEX, 1, &vertexSource_rubber_20bit, NULL);                                                                        
      glCompileShader(rubber_20bit_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_rubber_20bit =                                                                                                            

     
     
      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                            \n"                       
      " #define highp                                                                                                    \n"                       
      " #endif                                                                                                           \n"   
    
      "    uniform sampler2D     Texture1;                                                                               \n"                       
      "    uniform sampler2D     NormalMap;                                                                              \n"                       
      "    uniform highp float   shininess;                                                                              \n"                       
      "    uniform highp float   attenuation;                                                                            \n"                       

      "    varying highp vec4    lightPosition_PASS;                                                                     \n"                       
      "    varying highp vec2    varTexcoord;                                                                            \n"                       

      "            highp float   NdotL1;                                                                                 \n"                       
      "            highp vec3    normal;                                                                                 \n"                       
      "            highp vec3    NormalTex;                                                                              \n"                       

      "    varying highp vec4    diffuse;                                                                                \n"
      "    varying highp vec4    ambientGlobal;                                                                          \n"
      "    varying highp float   dist;                                                                                   \n"

      "            highp float   att;                                                                                    \n"
      "            highp vec4    color;                                                                                  \n"
     
    
      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
      "         NormalTex             =  texture2D(NormalMap,  varTexcoord).xyz;                                         \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      "         normal                =  normalize(NormalTex);                                                           \n"                       
      "         NdotL1                =  max(dot(normal, lightPosition_PASS.xyz), 0.0);                                  \n"                       

      "         color                 =  ambientGlobal + (0.72 * diffuse);                                               \n"
    
      "         color                +=  vec4(1.0, 1.0, 1.0, 1.0) * pow(NdotL1, shininess) * 0.6;                        \n"    
      "         gl_FragColor          = texture2D(Texture1, varTexcoord.st) * attenuation * color * NdotL1;              \n"                       

      "    }\n";                                                                                                                                   

        //---------------------------------------------------------------------                                                                         
        rubber_20bit_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
        glShaderSource(rubber_20bit_SHADER_FRAGMENT, 1, &fragmentSource_rubber_20bit, NULL);                                                                          
        glCompileShader(rubber_20bit_SHADER_FRAGMENT);                                                                                                         
        //------------------------------------------------                                                                                              
        glAttachShader(rubber_20bit_SHADER, rubber_20bit_SHADER_VERTEX);                                                                                              
        glAttachShader(rubber_20bit_SHADER, rubber_20bit_SHADER_FRAGMENT);                                                                                            
        //------------------------------------------------                                                                                              
        glBindAttribLocation(rubber_20bit_SHADER,    0, "position");                                                                                            
        glBindAttribLocation(rubber_20bit_SHADER,    1, "texture");                                                                                           
        //------------------------------------------------                                                                                              
        glLinkProgram(rubber_20bit_SHADER);                                                                                                                    
        //------------------------------------------------                                                                                              
        #ifdef __APPLE__                                                                                                                                
        glDetachShader(rubber_20bit_SHADER, rubber_20bit_SHADER_VERTEX);                                                                                              
        glDetachShader(rubber_20bit_SHADER, rubber_20bit_SHADER_FRAGMENT);                                                                                            
        #endif                                                                                                                                          
        //------------------------------------------------                                                                                              
        glDeleteShader(rubber_20bit_SHADER_VERTEX);                                                                                                            
        glDeleteShader(rubber_20bit_SHADER_FRAGMENT);                                                                                                          
        //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
        UNIFORM_MODELVIEWPROJ_rubber_20bit                   = glGetUniformLocation(rubber_20bit_SHADER,   "mvpMatrix");                                              
        UNIFORM_LIGHT_MATRIX_rubber_20bit                    = glGetUniformLocation(rubber_20bit_SHADER,   "lightMatrix");                                            
        UNIFORM_LIGHT_POSITION_01_rubber_20bit               = glGetUniformLocation(rubber_20bit_SHADER,   "light_POSITION_01");                                      
        UNIFORM_SHININESS_rubber_20bit                       = glGetUniformLocation(rubber_20bit_SHADER,   "shininess");                                              
        UNIFORM_ATTENUATION_rubber_20bit                     = glGetUniformLocation(rubber_20bit_SHADER,   "attenuation");                                              
        UNIFORM_TEXTURE_DOT3_rubber_20bit                    = glGetUniformLocation(rubber_20bit_SHADER,   "NormalMap");                                              
        UNIFORM_TEXTURE_rubber_20bit                         = glGetUniformLocation(rubber_20bit_SHADER,   "Texture1");                                   
