//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("woman");
    short("A radiant woman");
    description("A woman of terrible beauty stands before you. Her "
        "features are exquisite beyond mortal measure - high cheekbones, "
        "full lips curved in a knowing smile, and eyes of deep violet "
        "that seem to hold the weight of millennia. Her hair flows like "
        "liquid shadow, dark and impossibly long. She wears a gown that "
        "seems woven from twilight itself - shifting between deep purple "
        "and absolute black. An aura of immense power radiates from her, "
        "making the air itself tremble.");
    addAlias("woman");
    addAlias("radiant woman");

    Gender("female");
    Race("deity");
    SetUpPersonaOfLevel("aeromancer", 80);

    addConversation(
        "/tutorial/temple/characters/seilyndria/sealConversation.c");

    registerEventHandler("revealName");
    registerEvent(this_object());
}

/////////////////////////////////////////////////////////////////////////////
public void revealName()
{
    Name("seilyndria");
    short("Seilyndria");
    addAlias("seilyndria");
}
