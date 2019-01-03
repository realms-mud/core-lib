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
        addSpecification("name", "exciting");
        addSpecification("description", "People gravitate toward you as you "
            "have a knack for piquing their enthusiasm.");
        addSpecification("root", "interesting");
        addSpecification("opinion", 5);
        "baseTrait"::reset(arg);
    }
}
