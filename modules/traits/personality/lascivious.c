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
        addSpecification("name", "lascivious");
        addSpecification("description", "You have a rather insatiable appetite "
            "for sexual pleasures and are rather overt in expressing these "
            "toward your target.");
        addSpecification("root", "hedonist");
        addSpecification("opposing root", "celibate");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -25);
        "baseTrait"::reset(arg);
    }
}
