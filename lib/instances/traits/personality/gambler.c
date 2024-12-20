//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "gambler");
    addSpecification("description", "You have a tendency to take "
        "chances - even when wisdom would dictate a different course.");
    addSpecification("root", "arbitrary");
    addSpecification("opposing root", "reasonable");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -5);
}
