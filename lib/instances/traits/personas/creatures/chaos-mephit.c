//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "chaos mephit");
    addSpecification("description", "You are a chaos mephit.");
    addSpecification("root", "creature persona");
    addSpecification("bonus resist chaos", 25);
    addSpecification("bonus resist physical", 20);
}
