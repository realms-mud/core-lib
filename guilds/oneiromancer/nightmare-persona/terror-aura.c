//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Terror Aura");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with an "
        "aura of terror that radiates outward, weakening the resolve of "
        "nearby enemies.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 13 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/dread-presence.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 3);
    addSpecification("bonus intimidation", 3);
    addSpecification("bonus attack", 3);
}
