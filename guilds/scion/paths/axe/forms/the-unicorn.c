//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "The Unicorn");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a basic defensive maneuver where the axe blade is "
        "held to the side of the head, edge facing one's foe.");
    addSpecification("limited by", (["equipment":({ "axe" })]));

     addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 3 ]));

    addPrerequisite("guilds/scion/paths/axe/forms/from-the-roof.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 1);
    addSpecification("bonus parry", 2);
}
