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
        addSpecification("type", "racial");
        addSpecification("name", "Moon Elf");
        addSpecification("description", "");
        addSpecification("root", "high elf");
        addSpecification("opposing root", "dwarf");
        addSpecification("opinion", 10);
        "baseTrait"::reset(arg);
    }
}

