//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "racial");
        addSpecification("name", "Wood Elf");
        addSpecification("description", "");
        addSpecification("root", "elf");
        addSpecification("opposing root", "dwarf");
        addSpecification("opinion", 10);
        addSpecification("opposing opinion", -10);
        "baseTrait"::reset(arg);
    }
}
