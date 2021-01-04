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
        addSpecification("name", "generous");
        addSpecification("description", "You tend to be very free with your "
            "time and wealth, happily giving to those in need.");
        addSpecification("root", "generous");
        addSpecification("opposing root", "miserly");
        addSpecification("opinion", 15);
        addSpecification("opposing opinion", -5);
        addSpecification("bonus persuasion", 1);
        addSpecification("bonus diplomacy", 1);
        "baseTrait"::reset(arg);
    }
}
