//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
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
}
