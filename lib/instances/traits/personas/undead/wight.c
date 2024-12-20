//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "wight");
    addSpecification("description", "You are a wight.");
    addSpecification("root", "undead persona");
    addSpecification("bonus resist physical", 50);
    addSpecification("bonus resist undead", 100);
    addSpecification("bonus resist evil", 100);
}
