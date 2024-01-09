//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Zerschlagen");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a form of attack wherein the mace's head "
        "is slammed against a body and then driven along the "
        "surface in a slicing motion during the follow-through.");
    addSpecification("limited by", (["equipment":({ "mace", "flail" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 12 ]));

    addPrerequisite("/guilds/scion/paths/mace/forms/smite.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 1);
    addSpecification("bonus damage", 1);
}
