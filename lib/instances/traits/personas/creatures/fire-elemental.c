//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "fire elemental");
    addSpecification("description", "You are a fire elemental.");
    addSpecification("root", "creature persona");
    addSpecification("bonus resist fire", 100);
    addSpecification("bonus resist physical", 20);
}
