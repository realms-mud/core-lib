//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "pegasus");
    addSpecification("description", "You are a pegasus.");
    addSpecification("root", "creature persona");
    addSpecification("bonus resist physical", 100);
    addSpecification("bonus resist good", 100);
    addSpecification("bonus resist magical", 50);
}
