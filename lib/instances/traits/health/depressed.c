//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "health");
    addSpecification("name", "depressed");
    addSpecification("description", "You are an unhappy, despondent person.");
    addSpecification("root", "sickly");
    addSpecification("opposing root", "hale");
    addSpecification("opinion", -10);
    addSpecification("penalty to constitution", 1);
    addSpecification("penalty to charisma", 1);
    addSpecification("penalty to heal hit points rate", 5);
    addSpecification("penalty to heal stamina rate", 5);
    addSpecification("cost", -1);
}
