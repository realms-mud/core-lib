//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Primal Agility");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with an understanding of primal agility "
        "drawn from the deepest wellsprings of elven "
        "heritage. The battlemage taps into ancient "
        "instincts shared by the first elves who "
        "hunted beneath primordial canopies, moving "
        "with a speed that borders on prescience.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/"
        "fluid-motion.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 37
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dexterity", 2);
    addSpecification("bonus dodge", 3);
}
