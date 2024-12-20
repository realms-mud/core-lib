//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "hedonist");
    addSpecification("description", "You believe that the pursuit of "
        "sensual pleasures is paramount.");
    addSpecification("root", "hedonist");
    addSpecification("opposing root", "celibate");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -15);
}
