//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mutating Attack");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to change a displaced smite into a strike or "
        "a displaced strike into a smite.");
    addSpecification("limited by", (["equipment":({ "staff" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 14 ]));

    addPrerequisite("/guilds/scion/paths/staff/forms/doubling.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/staff/forms/smite.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/staff/forms/striking.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus staff", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 1);
}
