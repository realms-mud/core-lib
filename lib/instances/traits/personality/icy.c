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
        addSpecification("type", "personality");
        addSpecification("name", "icy");
        addSpecification("description", "You lack affection and warmth "
            "toward other people with an almost simmering disdain.");
        addSpecification("root", "cold");
        addSpecification("opposing root", "warm");
        addSpecification("opinion", -10);
        addSpecification("opposing opinion", -15);
        addSpecification("penalty to diplomacy", 1);
        "baseTrait"::reset(arg);
    }
}
