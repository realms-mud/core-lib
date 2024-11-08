//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "pragmatic");
    addSpecification("description", "You tend to deal with things in a "
        "sensible and realistic fashion based on practical "
        "considerations.");
    addSpecification("root", "pragmatic");
    addSpecification("opposing root", "optimistic");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -5);
}
