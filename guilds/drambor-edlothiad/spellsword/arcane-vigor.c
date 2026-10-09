//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Vigor");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the technique of infusing the "
        "body with arcane vigor. By maintaining a "
        "constant undercurrent of restorative magic "
        "through muscle and bone, the spell sword "
        "achieves a state of tireless vitality that "
        "allows sustained aggression long after "
        "ordinary warriors would collapse.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/"
        "spell-blade-focus.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 21
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus stamina points", 25);
    addSpecification("bonus hit points", 25);
}
