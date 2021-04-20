//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rigid Armor Mastery");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to more effectively move in plate and hard leather "
        "armors as well as distribute and soften landed blows.");

    addSpecification("limited by", (["equipment":({ "hard leather", 
        "splint armor", "plate armor" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "fighter",
          "value": 25 ]));

    addPrerequisite("/guilds/fighter/techniques/rigid-armor-techniques.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 5);
    addSpecification("bonus soak", 3);
    addSpecification("bonus hard leather", 4);
    addSpecification("bonus splint armor", 4);
    addSpecification("bonus plate armor", 4);
}
