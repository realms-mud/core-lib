//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "genetic");
    addSpecification("name", "maimed");
    addSpecification("description", "You suffered an accident that has permanently disfigured you.");
    addSpecification("root", "sickly");
    addSpecification("opposing root", "hale");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -5);
    addSpecification("penalty to charisma", 1);
    addSpecification("penalty to constitution", 1);
    addSpecification("penalty to strength", 1);
    addSpecification("penalty to dexterity", 2);
    addSpecification("penalty to persuasion", 3);
    addSpecification("cost", -2);
}
