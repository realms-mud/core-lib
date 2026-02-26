//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/quests/questItem.c";

/////////////////////////////////////////////////////////////////////////////
private void registerEventHandlers()
{
    registerEventHandler("startPatrol");
    registerEventHandler("returnToKeep");
    registerEventHandler("keepRavaged");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("The Fall of Argalen");
    setType("primary");
    setDescription("The player's journey begins at Argalen Keep, the "
        "ancestral seat of House Argalen.");

    addState("peaceful", "Argalen Keep stands as it always has - a "
        "modest but proud fortress overlooking the village of Argalen "
        "and the surrounding countryside.");

    addState("on patrol", "I have departed Argalen Keep on patrol. "
        "The roads to the northwest have been troubled of late.");
    addTransition("peaceful", "on patrol", "startPatrol");

    addState("returning", "I must return to Argalen Keep. Something "
        "terrible has happened.");
    addTransition("on patrol", "returning", "returnToKeep");

    addState("ravaged", "Argalen Keep has been ravaged by the undead. "
        "The village burns and the dead walk among the ruins of my home.");
    addTransition("returning", "ravaged", "keepRavaged");
    addFinalState("ravaged", "failure");

    setInitialState("peaceful");

    registerEventHandlers();
}

/////////////////////////////////////////////////////////////////////////////
void startPatrol(object player)
{
    notify("startPatrol", player);
}

/////////////////////////////////////////////////////////////////////////////
void returnToKeep(object player)
{
    notify("returnToKeep", player);
}

/////////////////////////////////////////////////////////////////////////////
void keepRavaged(object player)
{
    notify("keepRavaged", player);
}
