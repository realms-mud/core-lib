//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Glin an aemas");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a defensive maneuver where the blade is "
        "held to the side of the head, tip pointed down toward the foe's feet.");
    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Aegis Guard",
          "value": 5 ]));

    addPrerequisite("/guilds/aegis-guard/forms/sword-guarding/celon-ai-esgal.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus parry", 2);
    addSpecification("equivalence", "hanging point");
}
