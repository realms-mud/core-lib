//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Defensive Harmonics");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the technique of weaving "
        "defensive harmonics into the bladesong. By "
        "sustaining specific resonant frequencies "
        "during combat, the bladesinger creates "
        "standing waves of protective energy that "
        "deflect incoming attacks with an almost "
        "musical precision.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/"
        "bladesong-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 33
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 5);
    addSpecification("bonus resist magical", 4);
}
