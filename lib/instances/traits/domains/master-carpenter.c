//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "professional");
    addSpecification("name", "master carpenter");
    addSpecification("description", "You are a master carpenter");
    addSpecification("root", "carpenter");
    addSpecification("opinion", 5);
    addSpecification("bonus carpentry", 25);
    addSpecification("bonus wood crafting", 20);
    addSpecification("bonus engineering", 5);
}
