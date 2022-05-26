#include "design.h"

float lerp (float a , float b, float coeff){
    return a + (a-b)*coeff;
}

float distance(float x1, float y1, float x2, float y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
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
    glPushMatrix();
    glBegin(g);
        glVertex2f(0.5,0.5);
        glVertex2f(0.5,-0.5);
        glVertex2f(-0.5,-0.5);
        glVertex2f(-0.5,0.5);
    glEnd();
    glPopMatrix();
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


void affichenumNiveau(int NiveauActuel, float r, float g, float b) {
    glColor3f(r,g,b);

    char * adresse;
    
    if (NiveauActuel==1) {
        adresse = "doc/textures/n1.png"; 
    }

    drawTexturedRect(216,43,-1500,-1700, adresse);

    char * adresse2;
    adresse2 = "doc/textures/commandes.png"; 
    
    
    drawTexturedRect(1.2*216,1.2*134,-1500,-1700-150, adresse2);

    

}


void selectActivePlayer(float x, float y, float h, float r, float g, float b) {
    
    glColor3f(r,g,b);

    char * adresse;
    adresse = "doc/textures/select.png"; 
    

    drawTexturedRect(16,16,x,y+h/2+15,adresse);

}