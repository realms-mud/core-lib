//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "loutish");
    addSpecification("description", "You are a rather unrefined and "
        "uncouth lout.");
    addSpecification("root", "crude");
    addSpecification("opposing root", "kind");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -10);
    addSpecification("penalty to etiquette", 1);
}
