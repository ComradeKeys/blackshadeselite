/*
 * Text.cpp
 * Copyright (C) 2007 by Bryan Duff <duff0097@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */
/**> HEADER FILES <**/
#include "Text.hpp"

void Text::LoadFontTexture(const char *fileName) {

  TGAImageRec *tempTexture;
  GLuint type;

  //Load Image
  tempTexture = LoadTGA(fileName);
  //Is it valid?
  if(tempTexture) {
    //Alpha channel?
    if(tempTexture->bpp == 24)
      type = GL_RGB;
    else
      type = GL_RGBA;

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &FontTexture);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glBindTexture(GL_TEXTURE_2D, FontTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    gluBuild2DMipmaps(GL_TEXTURE_2D, type, tempTexture->sizeX,
                      tempTexture->sizeY, type, GL_UNSIGNED_BYTE,
                      tempTexture->data);
    free(tempTexture->data);
    free(tempTexture);
  }
}

void Text::BuildFont()          // Build Our Font Display List
{
  float cx;                     // Holds Our X Character Coord
  float cy;                     // Holds Our Y Character Coord
  int loop;

  base = glGenLists(256);       // Creating 256 Display Lists
  glBindTexture(GL_TEXTURE_2D, FontTexture);    // Select Our Font Texture
  for(loop = 0; loop < 256; loop++)     // Loop Through All 256 Lists
  {
    cx = float (loop % 16) / 16.0f;     // X Position Of Current Character
    cy = float (loop / 16) / 16.0f;     // Y Position Of Current Character

    glNewList(base + loop, GL_COMPILE); // Start Building A List
    glBegin(GL_QUADS);          // Use A Quad For Each Character
    glTexCoord2f(cx, 1 - cy - 0.0625f + .001);  // Texture Coord (Bottom Left)
    glVertex2i(0, 0);           // Vertex Coord (Bottom Left)
    glTexCoord2f(cx + 0.0625f, 1 - cy - 0.0625f + .001);        // Texture Coord (Bottom Right)
    glVertex2i(16, 0);          // Vertex Coord (Bottom Right)
    glTexCoord2f(cx + 0.0625f, 1 - cy - .001);  // Texture Coord (Top Right)
    glVertex2i(16, 16);         // Vertex Coord (Top Right)
    glTexCoord2f(cx, 1 - cy - +.001);   // Texture Coord (Top Left)
    glVertex2i(0, 16);          // Vertex Coord (Top Left)
    glEnd();                    // Done Building Our Quad (Character)
    glTranslated(10, 0, 0);     // Move To The Right Of The Character
    glEndList();                // Done Building The Display List
  }                             // Loop Until All 256 Are Built
}

void Text::glPrint(GLint x, GLint y, const char *string, int set, float size, float width, float height)      // Where The Printing Happens
{
  if(set > 1) {
    set = 1;
  }
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glBindTexture(GL_TEXTURE_2D, FontTexture);    // Select Our Font Texture
  glDisable(GL_DEPTH_TEST);     // Disables Depth Testing
  glDisable(GL_LIGHTING);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glMatrixMode(GL_PROJECTION);  // Select The Projection Matrix
  glPushMatrix();               // Store The Projection Matrix
  glLoadIdentity();             // Reset The Projection Matrix
  glOrtho(0, width, 0, height, -100, 100);      // Set Up An Ortho Screen
  glMatrixMode(GL_MODELVIEW);   // Select The Modelview Matrix
  glPushMatrix();               // Store The Modelview Matrix
  glLoadIdentity();
  glScalef(size, size, 1);      // Reset The Modelview Matrix
  glTranslated(x, y, 0);        // Position The Text (0,0 - Bottom Left)
  glListBase(base - 32 + (128 * set));  // Choose The Font Set (0 or 1)
  glCallLists(strlen(string), GL_BYTE, string); // Write The Text To The Screen
  glMatrixMode(GL_PROJECTION);  // Select The Projection Matrix
  glPopMatrix();                // Restore The Old Projection Matrix
  glMatrixMode(GL_MODELVIEW);   // Select The Modelview Matrix
  glPopMatrix();                // Restore The Old Projection Matrix
  glEnable(GL_DEPTH_TEST);      // Enables Depth Testing
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}
