//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "opulent");
    addSpecification("description", "You have extremely expensive "
        "and luxurious tastes. Some might even accuse them of being "
        "gaudy to the extreme.");
    addSpecification("root", "refined");
    addSpecification("opinion", 1);
}
