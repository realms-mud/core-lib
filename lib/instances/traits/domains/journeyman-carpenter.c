//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "professional");
    addSpecification("name", "journeyman carpenter");
    addSpecification("description", "You are an adept carpenter");
    addSpecification("root", "carpenter");
    addSpecification("opinion", 1);
    addSpecification("bonus carpentry", 10);
    addSpecification("bonus wood crafting", 5);
}
