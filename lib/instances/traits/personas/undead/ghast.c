//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "ghast");
    addSpecification("description", "You are a ghast.");
    addSpecification("root", "undead persona");
    addSpecification("bonus resist undead", 100);
    addSpecification("bonus resist evil", 100);
}
