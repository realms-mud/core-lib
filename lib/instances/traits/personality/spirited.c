//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "spirited");
    addSpecification("description", "You are full of energy, entusiasm, "
        "and determination.");
    addSpecification("root", "passionate");
    addSpecification("opinion", 5);
    addSpecification("bonus persuasion", 1);
}
