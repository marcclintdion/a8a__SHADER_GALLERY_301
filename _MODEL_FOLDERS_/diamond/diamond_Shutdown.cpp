                    if(diamond_NORMALMAP != 0)
                    {                                                                                                              
                            glDeleteTextures(1, &diamond_NORMALMAP);
                            diamond_NORMALMAP = 0;
                    }                                                                                                              
                    if(diamond_TEXTUREMAP  != 0)
                    {                                                                                                              
                            glDeleteTextures(1, &diamond_TEXTUREMAP);
                            diamond_TEXTUREMAP  = 0;
                    }                                                                                                              
                    if(diamond_VBO  != 0)
                    {                                                                                                              
                            glDeleteBuffers(1, &diamond_VBO);
                            diamond_VBO  = 0;                                                                                         
                    }                                                                                                              
