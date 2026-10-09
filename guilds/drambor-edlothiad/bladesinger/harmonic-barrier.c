//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Harmonic Barrier");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the harmonic barrier technique. "
        "By layering multiple resonant tones into "
        "a persistent chord, the bladesinger "
        "manifests a shimmering wall of sonic "
        "energy that absorbs and disperses kinetic "
        "force, turning aside blows that would "
        "fell lesser warriors.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/"
        "eternal-ward.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 55
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 7);
    addSpecification("bonus resist physical", 6);
}
