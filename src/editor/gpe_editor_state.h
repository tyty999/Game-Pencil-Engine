/*
gpe_editor_state.h
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

#ifndef GPE_EDITOR_STATE_H
#define GPE_EDITOR_STATE_H

#include "GPE/GPE_Program_State.h"
#include "AOSGUI/paw_gui.h"
#include "gpe_editor.h"
#include "gpe_editor_settings.h"
#include "project_properties.h"
#include "AOSGUI/paw_gui.h"

#include "gpe_log_manager.h"
#include "gpe_resource_tree.h"
#include "gpe_project_resources.h"
#include "GPE/GPE_Texture_SDL.h"

class GPE_Editor_State : public GPE_ProgramState
{
private:
    //Intro message
    GPE_Texture_Base * message;
    GPE_Toolbar * mainToolBar;
    GPE_ToolIconButtonBar * mainButtonBar;
protected:
    //Intro background
    GPE_Texture_Base *background;
public:
    GPE_Texture_Base * country_language_image;
    SDL_version SDL_compiled_version;
    std::string SDL_VersionText;
    //Loads intro resources
    GPE_Editor_State( std::string sName = "");
    //Frees intro resources
    ~GPE_Editor_State();

    //Main loop functions
    void process_input();
    void apply_logic();
    void clean_up();
    void end_state();
    void render();
    void start_state();
};

bool GPE_Editor_Init( int argc, char* args[]);

#endif // GPE_EDITOR_STATE_H
