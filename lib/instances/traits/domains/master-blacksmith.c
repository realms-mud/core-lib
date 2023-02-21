//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "professional");
    addSpecification("name", "master blacksmith");
    addSpecification("description", "You are a master blacksmith");
    addSpecification("root", "blacksmith");
    addSpecification("opinion", 5);
    addSpecification("bonus blacksmithing", 25);
    addSpecification("bonus metal crafting", 20);
    addSpecification("bonus engineering", 5);
}
