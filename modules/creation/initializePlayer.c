//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private object Player = 0;

private string *selectors = ({
    "/lib/modules/creation/genderSelector.c",
    "/lib/modules/creation/raceSelector.c",
    "/lib/modules/creation/subraceSelector.c",
    "/lib/modules/creation/attributeSelector.c",
    "/lib/modules/creation/skillsSelector.c"
});

/////////////////////////////////////////////////////////////////////////////
public nomask void onRestoreSucceeded(object caller)
{
    caller->unregisterEvent(this_object());
    move_object(caller, caller->savedLocation());
    destruct(this_object());
}

/////////////////////////////////////////////////////////////////////////////
private nomask void initiateSelector()
{
    if (sizeof(selectors) && Player)
    {
        string selector = selectors[0];
        selectors -= ({ selector });

        object selectorObj = clone_object(selector);
        move_object(selectorObj, Player);
        selectorObj->registerEvent(this_object());
        selectorObj->initiateSelector(Player);
    }
    else if (Player)
    {
        Player->hitPoints(Player->maxHitPoints());
        Player->spellPoints(Player->maxSpellPoints());
        Player->staminaPoints(Player->maxStaminaPoints());
        move_object(Player, "/room/city/central_park.c");
        Player->save();
        destruct(this_object());
    }
    else
    {
        destruct(this_object());
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onRestoreFailed(object caller)
{
    Player = caller;
    Player->hitPoints(30);
    Player->spellPoints(30);
    Player->staminaPoints(30);

    initiateSelector();
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    caller->cleanUp();
    initiateSelector();
}
