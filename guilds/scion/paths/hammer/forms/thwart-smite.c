//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Thwart Smite");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a master smite - the thwart smite. This is a high "
        "horizontal smite with the backhand edge from the right and then the "
        "main edge from the left. This breaks the from-the-roof guard.");

    addSpecification("limited by", (["equipment":({ "hammer" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 17 ]));

    addPrerequisite("guilds/scion/paths/hammer/forms/over-smite.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hammer", 1);
    addSpecification("bonus attack", 2);
}
