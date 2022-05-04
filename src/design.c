#include "design.h"

float lerp (float a , float b, float coeff){
    return a + (a-b)*coeff;
}


void drawTexturedRect(float w, float h, float x, float y, char* adresse) {

    char a[70];
    sprintf(a, adresse);
    GLuint textID = loadingRessources(&a);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindTexture(GL_TEXTURE_2D, textID);


    // dessin du rect
    glPushMatrix();
        glTranslatef(x,y,0);
        
        glScalef(w,h,0);

        glBegin(GL_QUADS);

            glTexCoord2f(0,0);
            glVertex2f(-0.5,0.5);

            glTexCoord2f(1,0);
            glVertex2f(0.5,0.5);

            glTexCoord2f(1,1);
            glVertex2f(0.5,-0.5);

            glTexCoord2f(0,1);
            glVertex2f(-0.5,-0.5);

        glEnd();
    glPopMatrix();

        
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    glDeleteTextures(1, &textID);
}


void drawSquare(int full) {
    int g;
    if (full == 0) { 
        g = GL_LINE_LOOP ;
    }
    if (full == 1) {
        g = GL_POLYGON ;
    }
    glBegin(g);
        glVertex2f(0.5,0.5);
        glVertex2f(0.5,-0.5);
        glVertex2f(-0.5,-0.5);
        glVertex2f(-0.5,0.5);
    glEnd();
}


void drawRect(float w, float h, float x, float y, float r, float g, float b, int full) {
    glPushMatrix();
        glColor3f(r,g,b); 
        glTranslatef(x,y,0);
        glScalef(w,h,1);
        drawSquare(full);
        glColor3f(1,1,1); 
    glPopMatrix();
}

