/**************************************************************************
    Lightspark, a free flash player implementation

    Copyright (C) 2009  Alessandro Pignotti (a.pignotti@sssup.it)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************************/

#ifndef _FLASH_GEOM_H
#define _FLASH_GEOM_H

#include "asobjects.h"

class Rectangle: public IInterface
{
public:
	number_t x,y,width,height;
	static void sinit(Class_base* c);
	ASFUNCTION(_constructor);
	ASFUNCTION(_getLeft);
	ASFUNCTION(_getRight);
	ASFUNCTION(_getTop);
	ASFUNCTION(_getBottom);
};

class ColorTransform: public IInterface
{
private:
	number_t redMultiplier,greenMultiplier,blueMultiplier,alphaMultiplier;
	number_t redOffset,greenOffset,blueOffset,alphaOffset;
public:
	static void sinit(Class_base* c);
	ASFUNCTION(_constructor);
	ASFUNCTION(setColor);
	ASFUNCTION(getColor);
};

#endif
