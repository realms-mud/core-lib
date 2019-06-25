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
        addSpecification("name", "pragmatic");
        addSpecification("description", "You tend to deal with things in a "
            "sensible and realistic fashion based on practical "
            "considerations.");
        addSpecification("root", "pragmatic");
        addSpecification("opposing root", "optimistic");
        addSpecification("opinion", 5);
        addSpecification("opposing opinion", -5);
        "baseTrait"::reset(arg);
    }
}
