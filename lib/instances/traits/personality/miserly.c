//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "miserly");
    addSpecification("description", "You tend to nickel and dime every "
        "siltuation you are in and only grudgingly expend your monetary "
        "wealth.");
    addSpecification("root", "miserly");
    addSpecification("opposing root", "generous");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -5);
}
