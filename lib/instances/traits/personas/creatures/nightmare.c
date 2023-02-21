//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "nightmare");
    addSpecification("description", "You are a nightmare.");
    addSpecification("root", "creature persona");
    addSpecification("bonus resist fire", 50);
    addSpecification("bonus resist evil", 50);
}
