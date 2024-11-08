//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mutating Attack");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to change a displaced stab maneuver into a thrust or "
        "a displaced thrust into a stab maneuver.");
    addSpecification("limited by", (["equipment":({
        "dagger", "short sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 14 ]));

    addPrerequisite("/guilds/scion/paths/dagger/forms/doubling.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/dagger/forms/plunge.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/dagger/forms/thrusting.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dagger", 1);
    addSpecification("bonus short sword", 1);

    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 1);
}
