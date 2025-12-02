//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Part Smite");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a master smite - the part smite. This is a vertical "
        "descending smite that ends in the fool's guard. This smite is dealt "
        "to the opponent's head where the hair parts - thus its name. This "
        "smite is used to break the fool guard.");
    
    addSpecification("limited by", (["equipment":({ "hammer" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 23 ]));

    addPrerequisite("/guilds/scion/paths/hammer/forms/the-fool.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/hammer/forms/over-smite.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hammer", 1);
    addSpecification("bonus attack", 1);
    addSpecification("bonus defense", 1);
}
