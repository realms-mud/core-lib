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
        addSpecification("type", "personality");
        addSpecification("name", "oppressive");
        addSpecification("description", "You have an overbearing, soul-sucking "
            "personality. When you enter the room, it is almost as though the "
            "life gets sucked out of it.");
        addSpecification("root", "annoying");
        addSpecification("opinion", -10);
        addSpecification("penalty to diplomacy", 1);
        addSpecification("bonus intimidation", 1);
        "baseTrait"::reset(arg);
    }
}
