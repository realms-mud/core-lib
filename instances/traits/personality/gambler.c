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
        addSpecification("name", "gambler");
        addSpecification("description", "You have a tendency to take "
            "chances - even when wisdom would dictate a different course.");
        addSpecification("root", "arbitrary");
        addSpecification("opposing root", "reasonable");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -5);
        "baseTrait"::reset(arg);
    }
}
