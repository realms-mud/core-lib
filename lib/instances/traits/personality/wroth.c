//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "wroth");
    addSpecification("description", "You tend to treat those who oppose "
        "you (and many who do not) in a savagely angry manner.");
    addSpecification("root", "cruel");
    addSpecification("opposing root", "kind");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -25);
    addSpecification("penalty to diplomacy", 1);
    addSpecification("bonus intimidation", 1);
}
