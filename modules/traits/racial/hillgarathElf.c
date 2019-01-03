//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "racial");
        addSpecification("name", "Hillgarathi Elf");
        addSpecification("description", "");
        addSpecification("root", "high elf");
        addSpecification("opposing root", "dwarf");
        addSpecification("opinion", 10);
        addSpecification("opposing opinion", 5);
        "baseTrait"::reset(arg);
    }
}

