//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "dreaded");
    addSpecification("description", "People regard you with a great "
        "deal of apprehension and fear.");
    addSpecification("root", "harsh");
    addSpecification("opposing root", "kind");
    addSpecification("penalty to charisma", 1);
    addSpecification("opinion", -15);
    addSpecification("opposing opinion", -15);
    addSpecification("penalty to persuasion", 1);
    addSpecification("penalty to diplomacy", 1);
    addSpecification("bonus intimidation", 1);
}
