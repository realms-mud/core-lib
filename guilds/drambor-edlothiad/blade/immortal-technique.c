//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Immortal Technique");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches techniques refined "
        " over immortal lifetimes, granting extraordinary combat prowess.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/steel-and-sorcery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 57
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 12);
    addSpecification("bonus damage", 8);
    addSpecification("bonus hit points", 50);
    addSpecification("bonus spell points", 50);
}
