//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "earth elemental");
    addSpecification("description", "You are an earth elemental.");
    addSpecification("root", "creature persona");
    addSpecification("bonus resist earth", 100);
    addSpecification("bonus resist physical", 50);
}
