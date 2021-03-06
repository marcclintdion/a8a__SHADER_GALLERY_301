glUseProgram(HEMI_MIX_1_SHADER);      
//================================================================================== 
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix1);                                                                                                                                                
    InvertMatrix(lightMatrix1, modelView);                                                                                                                                     
    
    
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(textureMatrix);
    //Translate(textureMatrix, shadowsPositionOffset[0], shadowsPositionOffset[1], shadowsPositionOffset[2]);
    //Scale(textureMatrix, scaleShadows, scaleShadows, scaleShadows);   
    //======================================================================================================                                                                  
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);  
    glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);     
    //======================================================================================================                
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_HEMI_MIX_1,   1,0,  mvpMatrix); 
    glUniformMatrix4fv(UNIFORM_MODELVIEW_HEMI_MIX_1,       1,0,  modelView);                                                                                                          
    glUniformMatrix4fv(UNIFORM_MODELVIEW_HEMI_MIX_1,       1,0,  modelRotation);    
    //---------------     
    glUniformMatrix4fv(UNIFORM_viewMatrix_HEMI_MIX_1,      1,0,  viewMatrix);     
    //---------------  
    glUniformMatrix4fv(UNIFORM_SHADOW_PROJ_HEMI_MIX_1,     1,0,  ProjectionShadow);   
    glUniformMatrix4fv(UNIFORM_modelViewShadow_HEMI_MIX_1, 1,0,  modelViewShadow);     
    //----------------     
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_HEMI_MIX_1,    1,0,  lightMatrix1);
    glUniformMatrix4fv(UNIFORM_textureMatrix_HEMI_MIX_1,   1,0,  textureMatrix);  
    
    //---------------------------------------------------------------------------------    
    glUniform4f(UNIFORM_LIGHT_POSITION_01_HEMI_MIX_1, HEMI_MIX_1_LIGHT_POSITION_01[0], 
                                                  HEMI_MIX_1_LIGHT_POSITION_01[1], 
                                                  HEMI_MIX_1_LIGHT_POSITION_01[2], 
                                                  HEMI_MIX_1_LIGHT_POSITION_01[3]);      
    //---------------------------------------------------------------------------------     
    glUniform1f(UNIFORM_SHININESS_HEMI_MIX_1, HEMI_MIX_1_SHININESS);  
    
    //glUniform1f(UNIFORM_GENERIC_HEMI_MIX_1, adjust_w);     
    //---------------------------------------------------------------------------------       
    glUniform1i (UNIFORM_TEXTURE_COORDINATES_ADJUST_HEMI_MIX_1, 4);    
    glUniform1i (UNIFORM_TEXTURE_SHADOW_HEMI_MIX_1, 3);      
    glUniform1i (UNIFORM_TEXTURE_DOT3_HEMI_MIX_1, 1);                                                                                                                             
    glUniform1i (UNIFORM_TEXTURE_HEMI_MIX_1, 0 );                                                                                                                                 
    //======================================================================================================                                                                  

    
    glActiveTexture ( GL_TEXTURE3 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                                                                                                                          
    //---     





