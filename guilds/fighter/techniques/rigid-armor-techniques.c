//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rigid Armor Techniques");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to more effectively move in plate and hard leather "
        "armors as well as distribute and soften landed blows.");

    addSpecification("limited by", (["equipment":({ "hard leather", 
        "splint armor", "plate armor" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "fighter",
          "value": 11 ]));

    addPrerequisite("/guilds/fighter/techniques/root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 2);
    addSpecification("bonus soak", 1);
    addSpecification("bonus hard leather", 2);
    addSpecification("bonus splint armor", 2);
    addSpecification("bonus plate armor", 2);
}
