//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/dictionaries/domains/buildings.h"

string template = implode(castleLayout, "\n");

/////////////////////////////////////////////////////////////////////////////
void Setup()
{

}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{

}

/////////////////////////////////////////////////////////////////////////////
void castleDrawing()
{
    /*
    mapping swapstuff = BuildingBlueprints["motte and bailey"] + ([]);

    swapstuff["components"] += BuildingBlueprints["castle"]["components"];
    foreach(string key in m_indices(swapstuff["components"]))
    {
        foreach(string section in m_indices(swapstuff["components"][key]))
        {
            string color = (key == "moat") ? "\x1b[0;48;2;0;0;180;38;2;0;190;255m" :
                "\x1b[0;38;2;140;140;0m";
            template = regreplace(template, section, 
                (color + swapstuff["components"][key][section]["unicode"] + "\x1b[0m"), 1);
        }
    }
    template = "\n" + template;
    ExpectEq("\x1b[0;48;2;0;0;160;38;2;0;180;200m\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\x1b[0m\n", template);
    */
}
