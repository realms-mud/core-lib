//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "fire wyrm");
    addSpecification("description", "You are a fire wyrm.");
    addSpecification("root", "large creature persona");
    addSpecification("bonus resist fire", 100);
}
