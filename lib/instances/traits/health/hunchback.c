//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "health");
    addSpecification("name", "hunchback");
    addSpecification("description", "You're a hunchback.");
    addSpecification("root", "maimed");
    addSpecification("opposing root", "hale");
    addSpecification("opinion", -10);
    addSpecification("penalty to dexterity", 1);
    addSpecification("penalty to charisma", 2);
    addSpecification("cost", -1);
}
