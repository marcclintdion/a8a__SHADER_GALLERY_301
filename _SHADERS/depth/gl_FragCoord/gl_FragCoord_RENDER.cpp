    glUseProgram(gl_FragCoord_SHADER);      
    //-----------------------------------------------
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //--------------------------------------------------------------------------         
    LoadIdentity(lightMatrix1);                                                                                                                                                
    InvertMatrix(lightMatrix1, modelView);    
    //--------------------------------------------------------------------------  
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                                                                  
    glEnableVertexAttribArray(1);    
    glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);                                                                                                                                                
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------         
    glUniform4f(UNIFORM_LIGHT_POSITION_01_gl_FragCoord, gl_FragCoord_LIGHT_POSITION_01[0],  gl_FragCoord_LIGHT_POSITION_01[1],  gl_FragCoord_LIGHT_POSITION_01[2],  gl_FragCoord_LIGHT_POSITION_01[3]);

    glUniform4f(UNIFORM_moveSet_gl_FragCoord,           moveSet[0],                         moveSet[1],                         moveSet[2]*-1.0,                    moveSet[3]);


    //glUniform1f(UNIFORM_SHININESS_gl_FragCoord, gl_FragCoord_SHININESS);

    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_gl_FragCoord,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_gl_FragCoord,    1,0,  lightMatrix1);                                                                                                    
    
    glUniform1i (UNIFORM_TEXTURE_DOT3_gl_FragCoord, 0);


