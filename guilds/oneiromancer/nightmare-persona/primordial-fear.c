//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Primordial Fear");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with access "
        "to primordial fear - the terror that existed before consciousness, "
        "the dread that lurks in the oldest dreams.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 65 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/dream-sovereign.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 10);
    addSpecification("bonus spirit", 6);
    addSpecification("bonus attack", 10);
    addSpecification("bonus damage", 8);
}
