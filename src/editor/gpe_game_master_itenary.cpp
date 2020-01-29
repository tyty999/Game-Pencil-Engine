/*
gpe_game_master_itenary.cpp
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

 ____                ____        _
|  _ \ __ ___      _| __ ) _   _| |_ ___
| |_) / _` \ \ /\ / /  _ \| | | | __/ _ \
|  __/ (_| |\ V  V /| |_) | |_| | ||  __/
|_|   \__,_| \_/\_/ |____/ \__, |\__\___|
                           |___/
Created By PawByte
Attribution required at start of program and in credits.
SDL 2.0.9 used for this version...
*/

#include "gpe_game_master_itenary.h"

bool GPE_Init_Master_Itenary( int argc, char* args[] )
{
/*
    if( GPE_Editor_Init(argc, args) == false)
    {
        return false;
    }
*/
    return true;
}

bool GPE_Quit_Master_Itenary()
{
    GPE_Report("Deleting Editor....");
    GPE_Editor_Quit();

    GPE_Report("Deleting Gui...");
    PAW_GUI_END();

    return true;
}
