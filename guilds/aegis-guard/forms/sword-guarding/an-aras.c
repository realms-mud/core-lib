//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "An Aras");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a basic defensive maneuver where the blade is "
        "held to the side of the head, sword crossing in front of the "
        "brow.");
    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Aegis Guard",
          "value": 3 ]));  

    addPrerequisite("/guilds/aegis-guard/forms/sword-guarding/celon-ai-esgal.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 1);
    addSpecification("bonus parry", 1);
    addSpecification("equivalence", "the stag");
}
