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
        addSpecification("name", "opulent");
        addSpecification("description", "You have extremely expensive "
            "and luxurious tastes. Some might even accuse them of being "
            "gaudy to the extreme.");
        addSpecification("root", "refined");
        addSpecification("opinion", 1);
        "baseTrait"::reset(arg);
    }
}
