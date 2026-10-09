//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven Swordcraft");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches traditional elven "
        "swordcraft techniques refined over millennia, improving basic "
        "blade handling and precision.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/spellblade-form.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 7
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus long sword", 3);
    addSpecification("bonus attack", 2);
    addSpecification("bonus defense", 1);
}
