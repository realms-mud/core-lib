//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Phantom Form");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with a "
        "partially phantasmal form, making them harder to hit and more "
        "difficult to perceive.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 17 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/dream-walker.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 5);
    addSpecification("bonus dodge", 3);
    addSpecification("bonus hide", 3);
}
