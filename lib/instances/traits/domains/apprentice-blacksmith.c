//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "professional");
    addSpecification("name", "apprentice blacksmith");
    addSpecification("description", "You have just begun learning about blacksmithing");
    addSpecification("root", "blacksmith");
    addSpecification("opinion", 1);
    addSpecification("bonus blacksmithing", 2);
    addSpecification("bonus metal crafting", 1);
}
