//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "health");
    addSpecification("name", "leper");
    addSpecification("description", "Your body has been absolutely devastated by leprosy.");
    addSpecification("root", "sickly");
    addSpecification("opposing root", "hale");
    addSpecification("opinion", -35);
    addSpecification("penalty to dexterity", 2);
    addSpecification("penalty to constitution", 4);
    addSpecification("penalty to charisma", 4);
    addSpecification("penalty to heal hit points", 2);
    addSpecification("penalty to heal hit points rate", 25);
    addSpecification("cost", -4);
}
