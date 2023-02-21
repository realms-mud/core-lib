//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "air elemental");
    addSpecification("description", "You are an air elemental.");
    addSpecification("root", "creature persona");
    addSpecification("bonus resist air", 100);
    addSpecification("bonus resist electricity", 100);
    addSpecification("bonus resist physical", 20);
}
