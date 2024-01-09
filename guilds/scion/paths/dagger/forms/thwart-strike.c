//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Thwart Strike");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a master stab maneuver - the thwart strike. This is a high "
        "horizontal stab maneuver with the backhand edge from the right and then the "
        "main edge from the left. This breaks the from-the-roof guard.");

    addSpecification("limited by", (["equipment":({
        "dagger", "short sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 17 ]));

    addPrerequisite("/guilds/scion/paths/dagger/forms/over-strike.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dagger", 1);
    addSpecification("bonus short sword", 1);

    addSpecification("bonus attack", 2);
}
