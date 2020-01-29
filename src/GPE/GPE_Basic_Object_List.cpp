/*
GPE_Basic_Object_List.cpp
This file is part of:
GAME PENCIL ENGINE
https://create.pawbyte.com
Copyright (c) 2014-2020 Nathan Hurde, Chase Lee.

Copyright (c) 2014-2020 PawByte LLC.
Copyright (c) 2014-2020 Game Pencil Engine contributors ( Contributors Page )

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

-Game Pencil Engine <https://create.pawbyte.com>


*/

#include "GPE_Basic_Object_List.h"


GPE_GameObject_List::GPE_GameObject_List()
{

}

GPE_GameObject_List::~GPE_GameObject_List()
{
    internalArray.clear();
}

void GPE_GameObject_List::add_object(GPE_GameObject * objectIn)
{
    if( objectIn!=NULL)
    {
        internalArray.push_back(objectIn);
    }
}

void GPE_GameObject_List::remove_held_object(GPE_GameObject * objectIn)
{
    if( objectIn!=NULL )
    {
        GPE_GameObject * foundHeldObject = NULL;
        for( int ii = (int)internalArray.size()-1;  ii>=0; ii--)
        {
            foundHeldObject = internalArray[ii];
            if( foundHeldObject->get_id()==objectIn->get_id() )
            {
                internalArray.erase( internalArray.begin()+ii);
            }
        }
    }
}
