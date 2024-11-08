//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Barrier Guard");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a defensive maneuver where the dominant foot is "
        "forward, the haft held near the chest with the axe's edge "
        "pointed at the foe's face.");
    addSpecification("limited by", (["equipment":({ "axe" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 5 ]));

    addPrerequisite("/guilds/scion/paths/axe/forms/the-plough.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 2);
    addSpecification("bonus parry", 1);
}
