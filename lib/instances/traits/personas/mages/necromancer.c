//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "necromancer");
    addSpecification("description", "You are a necromancer.");
    addSpecification("root", "mage persona");
    addSpecification("bonus resist undead", 75);
    addSpecification("bonus resist evil", 75);
}
