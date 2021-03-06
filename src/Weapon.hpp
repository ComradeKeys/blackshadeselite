/*
 * Weapon.h
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
#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Config.hpp"
#include "Quaternions.hpp"

#define RAD2DEG 		56.54866776;

//this should be within the Person class (since everyone has one).
class Weapon {
public:
  int type; //ditto: int whichgun;
  int ammo;
  int reloads; //magazines
  float reloading;
  float gunrotate1, gunrotate2, gunrotate3;
  float recoil;
  float shotdelay;
  //Used in Person::DrawSkeleton()
  void FindRotationGun(XYZ start, XYZ target); 
  //void Reload();
};

#endif
