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
        addSpecification("type", "professional");
        addSpecification("name", "apprentice arcane craftsman");
        addSpecification("description", "You have just begun learning about arcane craftsmanship");
        addSpecification("root", "arcane craftsman");
        addSpecification("opinion", 1);
        addSpecification("bonus engineering", 2);
        addSpecification("bonus mathematics", 1);
        addSpecification("bonus physics", 1);
        addSpecification("bonus spellcraft", 1);
        "baseTrait"::reset(arg);
    }
}
