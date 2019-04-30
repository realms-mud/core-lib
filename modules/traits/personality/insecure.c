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
        addSpecification("name", "insecure");
        addSpecification("description", "You have a low sense of self-worth "
            "and as a result have some issues with anxiety. This is a "
            "polite way of saying that you're a whiny pain-in-the-ass.");
        addSpecification("root", "low self-esteem");
        addSpecification("opposing root", "high self-esteem");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -5);
        "baseTrait"::reset(arg);
    }
}
