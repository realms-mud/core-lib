//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Reverse Thrust");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to transition from the boar guard into a "
        "reverse thrust.");
    addSpecification("limited by", (["equipment":({
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 10 ]));

    addPrerequisite("guilds/scion/paths/sword/forms/the-boar.c",
        (["type":"research"]));
    addPrerequisite("guilds/scion/paths/sword/forms/thrusting.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus long sword", 1);
    addSpecification("bonus hand and a half sword", 1);
    addSpecification("bonus two-handed sword", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 1);
    addSpecification("equivalence", "reverse thrust");
}
