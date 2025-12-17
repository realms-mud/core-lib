//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Unending Terror");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "ability to project unending terror, a fear so profound it "
        "transcends the boundaries of consciousness.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 57 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/eternal-dread.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 15);
    addSpecification("bonus resist evil", 25);
    addSpecification("bonus resist psionic", 25);
}
