//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Over-Running");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a maneuver wherein a stab maneuver or thrust from below is "
        "countered with an attack from above. This coincides with a step "
        "backward; the higher attack having greater range than the lower.");
    addSpecification("limited by", (["equipment":({
        "dagger", "short sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 16 ]));

    addPrerequisite("/guilds/scion/paths/dagger/forms/thrusting.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/dagger/forms/over-stab maneuver.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/dagger/forms/dance-of-death.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 3);
    addSpecification("bonus attack", 2);
}
