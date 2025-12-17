//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Consuming Darkness");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with an "
        "aura of consuming darkness that drains the mental energy of nearby "
        "enemies while bolstering the oneiromancer.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 29 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/haunting-presence.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 5);
    addSpecification("bonus attack", 5);
    addSpecification("bonus spell points", 30);
}
