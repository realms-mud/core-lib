//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "genetic");
    addSpecification("name", "homely");
    addSpecification("description", "You are a rather unattractive person.");
    addSpecification("root", "homely");
    addSpecification("opposing root", "beautiful");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -5);
    addSpecification("penalty to charisma", 2);
    addSpecification("penalty to persuasion", 5);
    addSpecification("cost", -1);
}
