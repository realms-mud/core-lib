//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Wisdom");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with eternal wisdom, the accumulated "
        "insight of elven sorcerers who have lived "
        "for thousands of years. This knowledge "
        "transcends mere intellect, representing "
        "an intuitive grasp of magical truth that "
        "can only come from ages of contemplation.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "ward-of-ages.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 53
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus wisdom", 2);
    addSpecification("bonus spellcraft", 5);
}
