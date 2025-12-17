//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Avatar of Nightmares");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "mantle of an avatar of nightmares. They become a living embodiment "
        "of terror, wielding the power of the dreamscape itself.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 41 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/mind-fortress.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 6);
    addSpecification("bonus spirit", 4);
    addSpecification("bonus psionic attack", 25);
    addSpecification("bonus intimidation", 8);
}
