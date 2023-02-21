//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "educational");
    addSpecification("name", "schemer");
    addSpecification("description", "You are a viper amonst the rodents. You constantly plot, trying to manipulate the world to fit your desires.");
    addSpecification("root", "educated");
    addSpecification("opposing root", "uneducated");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", 25);
    addSpecification("bonus charisma", 2);
    addSpecification("bonus persuasion", 10);
    addSpecification("bonus barter", 5);
    addSpecification("cost", 1);
}
