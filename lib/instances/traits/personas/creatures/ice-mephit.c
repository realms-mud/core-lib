//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "ice mephit");
    addSpecification("description", "You are an ices mephit.");
    addSpecification("root", "creature persona");
    addSpecification("bonus resist cold", 25);
    addSpecification("bonus resist physical", 20);
}
