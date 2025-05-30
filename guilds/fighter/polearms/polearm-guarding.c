//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Polearm Guarding");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a defensive maneuver where the polearm head is "
        "held to the side with the haft near the hip, top pointed at the "
        "foe's chest.");

    addSpecification("limited by", (["equipment":({ "pole arm" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "fighter",
          "value": 5 ]));

    addPrerequisite("/guilds/fighter/polearms/root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 2);
    addSpecification("bonus parry", 3);
}
