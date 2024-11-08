//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "brutal");
    addSpecification("description", "You tend to treat those who oppose "
        "you (and many who do not) in a savagely violent manner.");
    addSpecification("root", "brutal");
    addSpecification("opposing root", "kind");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -25);
    addSpecification("bonus intimidation", 1);
    addSpecification("penalty to etiquette", 1);
}
