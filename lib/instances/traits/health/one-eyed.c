//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "health");
    addSpecification("name", "one-eyed");
    addSpecification("description", "You have lost one of your eyes.");
    addSpecification("root", "sickly");
    addSpecification("opposing root", "hale");
    addSpecification("opinion", -5);
    addSpecification("penalty to charisma", 1);
    addSpecification("penalty to dexterity", 1);
    addSpecification("penalty to perception", 10);
    addSpecification("penalty to search", 10);
    addSpecification("penalty to spot", 10);
    addSpecification("cost", -2);
}
