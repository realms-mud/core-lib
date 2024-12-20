//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Part Strike");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a master stab maneuver - the part stab maneuver. This is a vertical "
        "descending stab maneuver that ends in the fool's guard. This stab maneuver is dealt "
        "to the opponent's head where the hair parts - thus its name. This "
        "maneuver is used to break the fool guard.");
    
    addSpecification("limited by", (["equipment":({
        "dagger", "short sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 23 ]));

    addPrerequisite("/guilds/scion/paths/dagger/forms/the-fool.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/dagger/forms/over-strike.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dagger", 1);
    addSpecification("bonus short sword", 1);

    addSpecification("bonus attack", 1);
    addSpecification("bonus defense", 1);
}
