//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/quests/questItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void advanceState(object player, string state)
{
    questItem::advanceState(player, state);
    player->onStateChanged(this_object(), state);
}

/////////////////////////////////////////////////////////////////////////////
public void rewardLocalWork(object player)
{
    player->addExperience(100);
    tell_object(player, "You gain 100 experience for your work in Minlach.\n");
}

/////////////////////////////////////////////////////////////////////////////
protected void addResolution(string state, string description, string event)
{
    addState(state, description);
    addTransition("ready", state, event);
    addFinalState(state, "success");
    addEntryAction(state, "rewardLocalWork");
}
