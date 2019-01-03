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
        addSpecification("name", "interesting");
        addSpecification("description", "You can easily catch and hold the "
            "attention of those around you.");
        addSpecification("root", "interesting");
        addSpecification("opinion", 5);
        "baseTrait"::reset(arg);
    }
}
