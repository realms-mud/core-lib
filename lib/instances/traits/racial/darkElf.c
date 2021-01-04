//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "racial");
        addSpecification("name", "Dark Elf");
        addSpecification("description", "");
        addSpecification("penalty to constitution", 1);
        addSpecification("penalty to charisma", 1);
        addSpecification("bonus dexterity", 1);
        addSpecification("root", "elf");
        addSpecification("opposing root", "dwarf");
        addSpecification("opinion", 5);
        addSpecification("opposing opinion", -5);
        "baseTrait"::reset(arg);
    }
}
