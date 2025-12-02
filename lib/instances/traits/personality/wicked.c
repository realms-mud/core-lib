//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "wicked");
    addSpecification("description", "You tend to treat those who oppose "
        "you (and many who do not) in a savagely cruel, almost evil "
        "manner.");
    addSpecification("root", "cruel");
    addSpecification("opposing root", "kind");
    addSpecification("opinion", -10);
    addSpecification("opposing opinion", -35);
    addSpecification("penalty to diplomacy", 2);
    addSpecification("bonus intimidation", 2);
}
