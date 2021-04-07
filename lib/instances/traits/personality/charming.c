//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "charming");
    addSpecification("description", "You are a pleasant person and, darn it, people like you.");
    addSpecification("root", "kind");
    addSpecification("opposing root", "harsh");
    addSpecification("bonus charisma", 1);
    addSpecification("opinion", 20);
    addSpecification("opposing opinion", -10);
    addSpecification("cost", 2);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus diplomacy", 1);
    addSpecification("bonus etiquette", 1);
    addSpecification("bonus bluff", 1);
}
