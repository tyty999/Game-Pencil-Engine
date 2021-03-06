/*
gpe_parser.cpp
This file is part of:
GAME PENCIL ENGINE
https://www.pawbyte.com/gamepencilengine
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

-Game Pencil Engine <https://www.pawbyte.com/gamepencilengine>


*/

#include "gpe_parser.h"

namespace gpe
{
    key_pair::key_pair(int idNumb, std::string str, std::string ksubstr, float kValue)
    {
        keyId = idNumb;
        keyString = str;
        keySubString = ksubstr;
        keyValue = kValue;
        parentPair = NULL;
        uniqueIdNumb = 0;
    }

    key_pair::~key_pair()
    {

    }

    gpe::key_pair * key_pair::add_keypair(std::string optionName, std::string optionSubStr,float optionValue )
    {
        bool optionExists = false;
        gpe::key_pair * tOption = NULL;
        for( int i = 0; i < (int)subOptions.size(); i++)
        {
            tOption = subOptions[i];
            if( tOption!=NULL )
            {
                if( tOption->keyString==optionName)
                {
                    optionExists = false;
                    return tOption; //returns option already that exists
                }
            }
        }
        if( !optionExists)
        {
            gpe::key_pair * kp = new gpe::key_pair( get_unique_id(),optionName,optionSubStr, optionValue);
            kp->parentPair = this;
            subOptions.push_back(kp);
            return kp; //returns new option
        }
        return NULL; //if everything breaks return nothing
    }

    gpe::key_pair *  key_pair::find_option_id( int kId )
    {
        if( keyId == kId)
        {
            return this;
        }
        gpe::key_pair * curKey = NULL;
        gpe::key_pair * fKey = NULL;
        int optionsSize = (int)subOptions.size();

        for( int i = 0; i < optionsSize; i++)
        {
            curKey = subOptions[i];
            if( curKey!=NULL)
            {
                fKey = curKey->find_option_id( kId);
                if( fKey!=NULL)
                {
                    return fKey;
                }
            }
        }
        return NULL;
    }

    gpe::key_pair *  key_pair::find_option_named( std::string str )
    {
        if( keyString == str || keySubString == str)
        {
            return this;
        }
        gpe::key_pair * curKey = NULL;
        gpe::key_pair * fKey = NULL;
        int optionsSize = subOptions.size();

        for( int i = 0; i < optionsSize; i++)
        {
            curKey = subOptions[i];
            if( curKey!=NULL)
            {
                fKey = curKey->find_option_named( str );
                if( fKey!=NULL)
                {
                    return fKey;
                }
            }
        }
        return NULL;
    }

    gpe::key_pair *  key_pair::find_option_value( float kVal )
    {
        if( keyValue == kVal)
        {
            return this;
        }
        gpe::key_pair * curKey = NULL;
        gpe::key_pair * fKey = NULL;
        int optionsSize = subOptions.size();

        for( int i = 0; i < optionsSize; i++)
        {
            curKey = subOptions[i];
            if( curKey!=NULL)
            {
                fKey = curKey->find_option_value( kVal );
                if( fKey!=NULL)
                {
                    return fKey;
                }
            }
        }
        return NULL;

    }

    int key_pair::get_unique_id()
    {
        if( parentPair!=NULL)
        {
            return parentPair->get_unique_id();
        }
        else
        {
            uniqueIdNumb++;
            return uniqueIdNumb;
        }
    }

    bool key_pair::name_exists( std::string str)
    {
        gpe::key_pair * curKey = NULL;
        int optionsSize = subOptions.size();

        for( int i = 0; i < optionsSize; i++)
        {
            curKey = subOptions[i];
            if( curKey!=NULL)
            {
                if( curKey->name_exists( str) )
                {
                    return true;
                }
            }
        }

        if( keyString == str || keySubString == str)
        {
            return true;
        }
        return false;
    }

    bool key_pair::remove_option_id( int kId, bool nestDown  )
    {
        bool optionRemoved = false;
        int optionsSize = subOptions.size();
        gpe::key_pair * curKey = NULL;
        for( int i = optionsSize -1; i >=0; i--)
        {
            curKey = subOptions[i];
            if( curKey!=NULL)
            {
                if( nestDown )
                {
                    if( curKey->remove_option_id( kId, true) )
                    {
                        optionRemoved = true;
                    }
                }
                if( curKey->keyId == kId)
                {
                    optionRemoved =  true;
                }
                subOptions.erase( subOptions.begin() + i );
                delete curKey;
                curKey = NULL;
            }
        }

        return optionRemoved;
    }

    bool key_pair::remove_option_named( std::string kStr, bool nestDown  )
    {
        bool optionRemoved = false;
        int optionsSize = (int)subOptions.size();
        gpe::key_pair * curKey = NULL;

        for( int i = optionsSize -1; i >=0; i--)
        {
            curKey = subOptions[i];
            if( curKey!=NULL)
            {
                if( nestDown )
                {
                    if( curKey->remove_option_named( kStr, true) )
                    {
                        optionRemoved = true;
                    }
                }
                if( curKey->keyString == kStr)
                {
                    optionRemoved =  true;
                }
                subOptions.erase( subOptions.begin() + i );
                delete curKey;
                curKey = NULL;
            }
        }

        return optionRemoved;

    }

    bool key_pair::remove_option_value( float kVal, bool nestDown  )
    {

        bool optionRemoved = false;
        int optionsSize = (int)subOptions.size();
        gpe::key_pair * curKey = NULL;

        for( int i = optionsSize -1; i >=0; i--)
        {
            curKey = subOptions[i];
            if( curKey!=NULL)
            {
                if( nestDown )
                {
                    if( curKey->remove_option_value( kVal, true) )
                    {
                        optionRemoved = true;
                    }
                }
                if( curKey->keyValue == kVal)
                {
                    optionRemoved =  true;
                }
                subOptions.erase( subOptions.begin() + i );
                delete curKey;
                curKey = NULL;
            }
        }
        return optionRemoved;
    }

    void key_pair::remove_all()
    {
        gpe::key_pair * curKey = NULL;
        for( int i = (int)subOptions.size()-1; i >=0; i--)
        {
            curKey = subOptions[i];
            if( curKey!=NULL)
            {
                delete curKey;
                curKey = NULL;
            }
        }
        subOptions.clear();
    }
}
