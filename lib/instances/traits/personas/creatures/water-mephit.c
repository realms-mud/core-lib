//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "water mephit");
    addSpecification("description", "You are a water mephit.");
    addSpecification("root", "creature persona");
    addSpecification("bonus resist water", 25);
    addSpecification("bonus resist physical", 20);
}
