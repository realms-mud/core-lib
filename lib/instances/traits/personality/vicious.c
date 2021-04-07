//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "vicious");
    addSpecification("description", "You tend to treat those who oppose "
        "you (and many who do not) in a deliberately cruel and violent "
        "manner.");
    addSpecification("root", "cruel");
    addSpecification("opposing root", "kind");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -25);
    addSpecification("penalty to diplomacy", 1);
    addSpecification("bonus intimidation", 1);
}
