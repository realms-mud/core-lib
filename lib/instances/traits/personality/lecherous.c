//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "lecherous");
    addSpecification("description", "You tend to express your sexual "
        "desires in the most offensive manner possible.");
    addSpecification("root", "hedonist");
    addSpecification("opposing root", "celibate");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -25);
}
