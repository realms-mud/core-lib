//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "selfish");
    addSpecification("description", "You tend to be very me-centric. "
        "are both reluctant to show charity and very keen on finding "
        "ways to improve your situation - damn the cost to others.");
    addSpecification("root", "miserly");
    addSpecification("opposing root", "generous");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -10);
    addSpecification("penalty to persuasion", 1);
    addSpecification("penalty to diplomacy", 1);
}
