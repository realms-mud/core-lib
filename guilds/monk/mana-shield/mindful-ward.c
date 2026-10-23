//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

protected void Setup()
{
    addPrerequisite("level",
        ([ "type":"level", "guild":"monk", "value":10 ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "disciple", "adept", "senior disciple",
            "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c",
        ([ "type":"research" ]));
    addPrerequisite("/guilds/monk/discipline/students-awareness.c",
        ([ "type":"research" ]));
    addSpecification("name", "Mindful Ward");
    addSpecification("description", "Maintain a ward that reserves ten "
        "maximum stamina and diverts post-mitigation damage into spell "
        "points at one point per damage. Overflow damages hit points. "
        "An empty spell-point pool leaves the ward enabled but unable "
        "to absorb damage until spell points recover. Toggle it off "
        "to release the stamina reservation; no spell points are refunded.");
    addSpecification("source", "monk");
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);
    addSpecification("stamina point cost", 10);
    addSpecification("cooldown", 4);
    addSpecification("command template", "chi mindful ward");
    addSpecification("usage summary", "chi mindful ward");
    addSpecification("trait",
        "/guilds/monk/mana-shield/ward-trait.c");
    addSpecification("use ability activate message",
        "A quiet ward of energy settles around ##InitiatorName##.");
    addSpecification("use ability deactivate message",
        "The quiet ward around ##InitiatorName## fades.");
}
