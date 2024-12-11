/*
 * PROJECT:         CodePad Shader Utils
 * FILE:            shaderutils.cpp
 * PURPOSE:         Helper functions for working with OpenGL Shaders
 * PROGRAMMERS:     SusgUY446 
 * UPDATE HISTORY (DD/MM/YYYY):
 *      11-12-2024  Created
 */


#include "shaderutils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <glad/glad.h>



char* readShaderSource(const char* filePath) {
    FILE* fp = fopen(filePath, "r");
    if (!fp) {
        fprintf(stderr, "SHADERREADER::FILENOTFOUND - Shader File %s not found", filePath);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);

    char* shaderSource = (char*)malloc(fileSize+1);
    if(!shaderSource) {
        fprintf(stderr, "SHADERREADER::MEMALLOC - Failed to allocate memory for Shader Source");
        fclose(fp);
        return NULL;
    }

    fread(shaderSource, 1, fileSize, fp);

    shaderSource[fileSize] = '\0';

    fclose(fp);

    return shaderSource;
}

void freeShaderSource(char* shaderSource) {
    free(shaderSource);
}

