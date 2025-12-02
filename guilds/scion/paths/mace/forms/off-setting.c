//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Off-setting");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a maneuver wherein a smite or thrust from a weapon is "
        "deflected at the same time as a countering maul is initiated.");
    
    addSpecification("limited by", (["equipment":({
        "mace", "flail" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 17 ]));

    addPrerequisite("/guilds/scion/paths/mace/forms/mauling.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/mace/forms/over-smite.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/mace/forms/dance-of-death.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 4);
    addSpecification("bonus attack", 1);
}
