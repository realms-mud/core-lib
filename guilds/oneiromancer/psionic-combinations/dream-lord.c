//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dream Lord");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "ultimate mastery over dream combinations, granting the title of "
        "Dream Lord and tremendously increasing combination effectiveness.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 45 ]));

    addPrerequisite("/guilds/oneiromancer/psionic-combinations/nightmare-mastery.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 5);
    addSpecification("bonus evocation", 3);
    addSpecification("bonus spellcraft", 3);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus wisdom", 1);
}
