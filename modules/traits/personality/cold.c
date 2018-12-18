//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "cold");
        addSpecification("description", "You lack affection and warmth "
            "toward other people.");
        addSpecification("root", "cold");
        addSpecification("opposing root", "warm");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -10);
        "baseTrait"::reset(arg);
    }
}
