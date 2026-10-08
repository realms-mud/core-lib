//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("chen");
    addRelationshipInteraction("social.bow", ([ "respect":1 ]));
    addRelationshipInteraction("gift.received", ([ "gratitude":5 ]));
    addRelationshipInteraction("training.completed", ([ "respect":2 ]));
    addRelationshipInteraction(
        "faction.helped:/lib/tests/support/factions/goodGuys.c",
        ([ "trust":3 ]));
}
