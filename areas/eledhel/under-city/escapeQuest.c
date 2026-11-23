//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/quests/questItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("The Secret Ways of Eledhel");
    setType("primary");
    setDescription("Sendral has entrusted me with a route through "
        "the concealed passages beneath Eledhel.");

    addState("escape begun", "Sendral has shown me the concealed "
        "passage beneath the palace.");
    addState("under city", "I am moving through the sealed tunnels "
        "beneath Eledhel.");
    addState("justice reached", "I reached the Halls of Justice "
        "through the passage hidden behind its battle mural.");
    addState("escaped", "I have left Eledhel through the hidden "
        "cavern beyond the city.");

    addTransition("escape begun", "under city", "enteredUnderCity");
    addTransition("under city", "justice reached", "reachedJustice");
    addTransition("justice reached", "escaped", "reachedFoxDen");
    addFinalState("escaped", "success");
    setInitialState("escape begun");
}
