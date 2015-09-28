   
     if(gl_FragCoord_SHADER != 0)
     {
         glDeleteProgram(gl_FragCoord_SHADER);
         gl_FragCoord_SHADER = 0;
     }
