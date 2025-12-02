//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Advanced Changing Through");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of various advanced techniques of escaping a bind by "
        "sliding the mace's head out from underneath the foe's weapon and "
        "then mauling to another opening.");

    addSpecification("limited by", (["equipment":({ "mace", "flail" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 29 ]));

    addPrerequisite("/guilds/scion/paths/mace/forms/changing-through.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mace", 1);
    addSpecification("bonus flail", 1);
    addSpecification("bonus dodge", 2);
    addSpecification("bonus parry", 2);
    addSpecification("bonus attack", 2);
}
