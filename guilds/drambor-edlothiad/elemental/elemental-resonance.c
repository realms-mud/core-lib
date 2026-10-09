//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elemental Resonance");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides a profound "
        "understanding  of elemental resonance, significantly boosting all "
            "mid-tier enchantments.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/elemental-convergence.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 29
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Blazing Vortex": 20,
        "Avalanche Strike": 20,
        "Thunderstrike": 20,
        "Vitriol Blade": 20,
        "Resonance Blade": 20,
        "Void Blade": 20,
        "Eldritch Blade": 20,
    ]));
    addSpecification("affected research type", "percentage");
}
