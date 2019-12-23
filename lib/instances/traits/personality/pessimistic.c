//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "pessimistic");
        addSpecification("description", "You tend to be a 'glass is half "
            "empty' kind of a person. You typically see the worst in the "
            "people you interact with or the situations you find yourself "
            "in. In other words, you're a realist.");
        addSpecification("root", "pessimistic");
        addSpecification("opposing root", "optimistic");
        addSpecification("opinion", 5);
        addSpecification("opposing opinion", -5);
        "baseTrait"::reset(arg);
    }
}
