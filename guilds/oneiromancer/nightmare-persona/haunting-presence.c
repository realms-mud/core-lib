//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Haunting Presence");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with a "
        "haunting presence that lingers in the minds of those who witness "
        "them, making their psionic attacks more effective.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 25 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/psychic-predator.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 4);
    addSpecification("bonus intimidation", 5);
    addSpecification("bonus attack", 4);
    addSpecification("bonus damage", 3);
}
