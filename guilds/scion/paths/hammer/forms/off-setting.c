//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Off-setting");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a maneuver wherein a smite or thrust from a sword is "
        "deflected at the same time as a countering maul is initiated.");
    
    addSpecification("limited by", (["equipment":({
        "hammer" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 17 ]));

    addPrerequisite("/guilds/scion/paths/hammer/forms/mauling.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/hammer/forms/over-smite.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/hammer/forms/dance-of-death.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 4);
    addSpecification("bonus attack", 1);
}
