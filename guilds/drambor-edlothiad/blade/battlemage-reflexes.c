//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Battlemage Reflexes");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research hones the battlemage's "
        "reflexes  to supernatural levels through arcane enhancement.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/precision-of-ancients.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 31
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 5);
    addSpecification("bonus defense", 4);
    addSpecification("bonus dodge", 3);
    addSpecification("bonus long sword", 5);
}
