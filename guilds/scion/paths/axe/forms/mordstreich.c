//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mordstreich");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a maneuver wherein a counter-attack is placed "
        "with the haft of the axe in an attempt to first stun and then "
        "cleave into the opponent.");
    addSpecification("limited by", (["equipment":({ "axe" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 27 ]));

    addPrerequisite("/guilds/scion/paths/axe/forms/dance-of-death.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus axe", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 2);
}
