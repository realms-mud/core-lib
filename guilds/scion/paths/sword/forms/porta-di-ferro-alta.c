//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Porta di Ferro Alta");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a defensive maneuver where the dominant foot is "
        "forward and the other foot placed sideways, both knees bent. The "
        "pommel is held at the waist with the tip pointed at the foe's "
        "face. From this position, it is possible to easily launch "
        "several cuts and thrusts.");
    addSpecification("limited by", (["equipment":({
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 7 ]));

    addPrerequisite("/guilds/scion/paths/sword/forms/eisenport.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus parry", 1);
    addSpecification("equivalence", "porta di ferro alta");
}
