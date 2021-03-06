/*
 * Fog.h
 * Copyright (C) 2007 by Bryan Duff <duff0097@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
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
#pragma once

/**> HEADER FILES <**/
#include <GL/gl.h>
#include "Quaternions.hpp"
#include "Colors.hpp"

class Fog {
public:
  GLfloat fogColor[4];
  GLint fogMode;
  GLfloat fogDensity;
  GLfloat fogStart;
  GLfloat fogEnd;

  Color fogcolor;               //this should probably be in Environment

  void SetFog(float colorR, float colorG, float colorB, float fStart,
              float fEnd, float fogDensity);
  void SetFog(Color newColor, float fStart, float fEnd, float fogDensity);
  void TempFog(float colorR, float colorG, float colorB);
  void ResetFog();
};
