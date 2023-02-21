//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wrath Strike");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a master stab maneuver - the wrath stab maneuver. This is a powerful "
        "diagonal stab maneuvering stroke dealt from the wrath guard and ending "
        "in a wechsel guard on the opposite side. When used to displace "
        "another stab maneuver, the impact and blade binding will result in the strike "
        "ending in a hanging parry.");
    addSpecification("limited by", (["equipment":({
        "dagger", "short sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 15 ]));

    addPrerequisite("/guilds/scion/paths/dagger/forms/over-strike.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/dagger/forms/wrath-guard.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/dagger/forms/wechsel.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dagger", 1);
    addSpecification("bonus short sword", 1);

    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 2);
}
