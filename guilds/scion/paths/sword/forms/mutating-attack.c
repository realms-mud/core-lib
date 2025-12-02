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
        "knowledge of how to change a displaced hew into a thrust or "
        "a displaced thrust into a hew.");
    addSpecification("limited by", (["equipment":({
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 14 ]));

    addPrerequisite("/guilds/scion/paths/sword/forms/doubling.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/sword/forms/hew.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/sword/forms/thrusting.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus long sword", 1);
    addSpecification("bonus hand and a half sword", 1);
    addSpecification("bonus two-handed sword", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 1);
    addSpecification("equivalence", "mutating attack");
}
