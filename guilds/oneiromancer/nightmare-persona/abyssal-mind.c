//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Abyssal Mind");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with a "
        "mind that touches the abyss of the dream realm, granting deeper "
        "understanding of nightmare power.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 53 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/supreme-nightmare.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 6);
    addSpecification("bonus attack", 5);
    addSpecification("bonus damage", 4);
}
