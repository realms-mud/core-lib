//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "lustful");
    addSpecification("description", "You have a rather insatiable appetite "
        "for sexual pleasures.");
    addSpecification("root", "hedonist");
    addSpecification("opposing root", "celibate");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -10);
}
