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
        addSpecification("type", "professional");
        addSpecification("name", "apprentice blacksmith");
        addSpecification("description", "You have just begun learning about blacksmithing");
        addSpecification("root", "blacksmith");
        addSpecification("opinion", 1);
        addSpecification("bonus blacksmithing", 2);
        addSpecification("bonus metal crafting", 1);
        "baseTrait"::reset(arg);
    }
}
