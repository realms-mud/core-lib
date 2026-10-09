//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Immortal Knowledge");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with immortal knowledge, the deepest "
        "secrets of sorcery known only to those who "
        "have lived for ages. This understanding "
        "reveals the true names of forces and "
        "elements, granting authority over magic "
        "that lesser minds cannot comprehend.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "sorcery-supremacy.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 63
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus intelligence", 2);
    addSpecification("bonus spellcraft", 6);
    addSpecification("bonus spell points", 40);
}
