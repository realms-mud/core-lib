//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pliant Armor Mastery");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to more effectively move in leathers and mail "
        "armors as well as distribute and soften landed blows.");

    addSpecification("limited by", (["equipment":({ "soft leather",
        "scalemail", "chainmail", })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "fighter",
          "value": 25 ]));

    addPrerequisite("/guilds/fighter/techniques/pliant-armor-techniques.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 5);
    addSpecification("bonus soak", 3);
    addSpecification("bonus soft leather", 4);
    addSpecification("bonus scalemail", 4);
    addSpecification("bonus chainmail", 4);
}
