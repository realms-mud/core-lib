//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "storm mephit");
    addSpecification("description", "You are a storm mephit.");
    addSpecification("root", "creature persona");
    addSpecification("bonus resist electricity", 25);
    addSpecification("bonus resist physical", 20);
}
