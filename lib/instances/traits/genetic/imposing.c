//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "genetic");
    addSpecification("name", "imposing");
    addSpecification("description", "You are a person who, through sheer force of nature, are a presence to be reckoned with. You are witty. Your physique is intimidating. You are attractive.");
    addSpecification("root", "beautiful");
    addSpecification("opposing root", "homely");
    addSpecification("opinion", 35);
    addSpecification("opposing opinion", 15);
    addSpecification("bonus strength", 1);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus constitution", 1);
    addSpecification("bonus charisma", 3);
    addSpecification("bonus persuasion", 5);
    addSpecification("cost", 2);
}
