//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
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
}
