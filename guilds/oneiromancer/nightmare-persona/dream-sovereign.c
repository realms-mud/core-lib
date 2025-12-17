//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dream Sovereign");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "status of a dream sovereign, one whose dominion over the nightmare "
        "realm is absolute and unquestionable.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 61 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/void-touched.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 8);
    addSpecification("bonus attack", 8);
    addSpecification("bonus damage", 6);
    addSpecification("bonus intimidation", 10);
}
