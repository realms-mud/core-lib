//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dread Presence");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with a "
        "dread presence that unsettles those around them. Enemies find it "
        "harder to focus when near the oneiromancer.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 9 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/shadow-self.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 2);
    addSpecification("bonus intimidation", 3);
    addSpecification("bonus damage", 2);
}
