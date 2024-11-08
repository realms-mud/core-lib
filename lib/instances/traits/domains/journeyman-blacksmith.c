//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "professional");
    addSpecification("name", "journeyman blacksmith");
    addSpecification("description", "You are an adept blacksmith");
    addSpecification("root", "blacksmith");
    addSpecification("opinion", 1);
    addSpecification("bonus blacksmithing", 10);
    addSpecification("bonus metal crafting", 5);
}
