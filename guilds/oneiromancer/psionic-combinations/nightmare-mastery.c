//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Nightmare Mastery");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with "
        "mastery over nightmare combinations, significantly increasing "
        "their devastating power.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 37 ]));

    addPrerequisite("/guilds/oneiromancer/psionic-combinations/devastating-focus.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 3);
    addSpecification("bonus spellcraft", 2);
    addSpecification("bonus evocation", 2);
}
