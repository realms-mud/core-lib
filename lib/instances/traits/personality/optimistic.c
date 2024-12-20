//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "optimistic");
    addSpecification("description", "You tend to be a 'glass is half "
        "full' kind of a person. You typically see the best in the "
        "people you interact with or the situations you find yourself "
        "in. In other words, you're an idiot.");
    addSpecification("root", "optimistic");
    addSpecification("opposing root", "pragmatic");
    addSpecification("opinion", 15);
    addSpecification("opposing opinion", -5);
}
