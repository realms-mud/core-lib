//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "genetic");
        addSpecification("name", "Freak");
        addSpecification("description", "blah blah blah");
        addSpecification("root", "disfigured");
        addSpecification("opposing root", "normal");
        addPrerequisite("long sword", (["type":"skill", "value" : 10]));
        "baseTrait"::reset(arg);
    }
}
