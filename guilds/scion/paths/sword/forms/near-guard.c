//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Near Guard");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a defensive maneuver where the blade is "
        "held to the side of the head, tip pointed perpendicular to "
        "one's foe.");
    addSpecification("limited by", (["equipment":({
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 4 ]));

    addPrerequisite("/guilds/scion/paths/sword/forms/the-ox.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 1);
    addSpecification("bonus parry", 2);
    addSpecification("equivalence", "near guard");
}
