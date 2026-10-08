//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/quests/questItem.c";

protected void Setup()
{
    setName("Earn Chen's trust");
    addState("begun", "I promised to help Chen.");
    addState("complete", "I helped Chen.");
    addFinalState("complete", "success");
    setInitialState("begun");
    addRelationshipEffect("complete",
        getService("relationship")->identity(
            load_object("/lib/tests/support/relationships/npc.c")),
        ([ "trust":10, "respect":5, "gratitude":10 ]));
}
