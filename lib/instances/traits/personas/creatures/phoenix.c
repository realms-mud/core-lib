//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "phoenix");
    addSpecification("description", "You are a phoenix.");
    addSpecification("root", "creature persona");
    addSpecification("bonus resist fire", 100);
    addSpecification("bonus resist good", 100);
}
