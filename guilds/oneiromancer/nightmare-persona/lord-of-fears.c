//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lord of Fears");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with "
        "dominion over fear itself. They become a lord of fears, commanding "
        "the terror that dwells in all minds.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 33 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/consuming-darkness.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 5);
    addSpecification("bonus spirit", 3);
    addSpecification("bonus intimidation", 7);
    addSpecification("bonus damage", 4);
}
