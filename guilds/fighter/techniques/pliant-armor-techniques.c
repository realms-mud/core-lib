//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pliant Armor Techniques");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to more effectively move in leathers and mail "
        "armors as well as distribute and soften landed blows.");

    addSpecification("limited by", (["equipment":({ "soft leather",
        "scalemail", "chainmail", })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "fighter",
          "value": 10 ]));

    addPrerequisite("/guilds/fighter/techniques/root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 2);
    addSpecification("bonus soak", 1);
    addSpecification("bonus soft leather", 2);
    addSpecification("bonus scalemail", 2);
    addSpecification("bonus chainmail", 2);
}
