//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Dread");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with an "
        "aura of eternal dread that never fades from the minds of those "
        "who witness them.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 53 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/nightmare-apotheosis.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 12);
    addSpecification("bonus soak", 6);
    addSpecification("bonus resist psionic", 20);
}
