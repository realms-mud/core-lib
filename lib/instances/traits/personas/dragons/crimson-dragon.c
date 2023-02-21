//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "crimson dragon");
    addSpecification("description", "You are a crimson dragon.");
    addSpecification("root", "large creature persona");
    addSpecification("bonus resist evil", 75);
    addSpecification("bonus resist undead", 75);
}
