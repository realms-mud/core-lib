//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environmentalElement.c";

private string Key = 0;
private int isCurrentlyLocked = 0;
private int wasManipulated = 0;
private mapping whenLocked = ([]);
private int pickLockLevel = 5;

private object messageParser = load_object("/lib/core/messageParser.c");

/////////////////////////////////////////////////////////////////////////////
public string Type()
{
    return "door";
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void setKey(string key, int startUnlocked)
{
    if (environmentDictionary()->isValidKey(key))
    {
        Key = key;
        isCurrentlyLocked = !startUnlocked;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setPickLockLevel(int level)
{
    pickLockLevel = level;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs mapping setLockedBySeason(string season)
{
    mapping data = ([]);
    if (environmentDictionary()->isValidSeason(season))
    {
        data[season] = 1;
    }
    else
    {
        foreach(string item in environmentDictionary()->seasons())
        {
            data[item] = 1;
        }
    }
    return data;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs mapping setLockedTime(string period, string season)
{
    mapping data = ([]);
    if (environmentDictionary()->isValidTimeOfDay(period))
    {
        data[period] = setLockedBySeason(season);
    }
    else
    {
        foreach(string timeOfDay in environmentDictionary()->timesOfDay())
        {
            data[timeOfDay] = setLockedBySeason(season);
        }
    }
    return data;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void setWhenLockActive(string state, string period,
    string season)
{
    string *states = ({});
    if (state && (state != ""))
    {
        states = ({ state });
    }
    else
    {
        states = states();

        if (!sizeof(states))
        {
            states = ({ "default" });
        }
    }

    if (sizeof(states))
    {
        foreach(string stateItem in states)
        {
            whenLocked[stateItem] = setLockedTime(period, season);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int isLocked()
{
    int ret = isCurrentlyLocked;

    string timeOfDay = environmentDictionary()->timeOfDay();
    string season = environmentDictionary()->season();

    if (!wasManipulated && member(whenLocked, State) &&
        member(whenLocked[State], timeOfDay) &&
        member(whenLocked[State][timeOfDay], season))
    {
        ret = whenLocked[State][timeOfDay][season];
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void lock(object initiator)
{
    if (objectp(initiator))
    {
        object messageParser = load_object("/lib/core/messageParser.c");

        string message = message = "##InitiatorName## ##Infinitive::try## to "
            "lock an already-locked door.";

        if (!stringp(Key))
        {
            message = "##InitiatorName## ##Infinitive::try## to lock the door "
                "but ##Infinitive::notice## that it has no lock.";
        }
        else if (!present_clone(Key, initiator))
        {
            message = "##InitiatorName## ##Infinitive::try## to lock the door "
                "but ##Infinitive::do## not have the key.";
        }
        else if (!isLocked())
        {
            isCurrentlyLocked = 1;
            wasManipulated = 1;
            message = "##InitiatorName## ##Infinitive::lock## the door.";
        }
        messageParser->displayMessage(message, initiator, 0, "description",
            "environment");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void unlock(object initiator)
{
    if (objectp(initiator))
    {
        string message = message = "##InitiatorName## ##Infinitive::try## to "
            "unlock an already-unlocked door.";

        if (!stringp(Key))
        {
            message = "##InitiatorName## ##Infinitive::try## to unlock the door "
                "but ##Infinitive::notice## that it has no lock.";
        }
        else if (!present_clone(Key, initiator))
        {
            message = "##InitiatorName## ##Infinitive::try## to unlock the door "
                "but ##Infinitive::do## not have the key.";
        }
        else if (isLocked())
        {
            isCurrentlyLocked = 0;
            wasManipulated = 1;
            message = "##InitiatorName## ##Infinitive::unlock## the door.";
        }
        messageParser->displayMessage(message, initiator, 0, "description",
            "environment");
    }
}

/////////////////////////////////////////////////////////////////////////////
public void displayLockedMessage(object initiator)
{
    messageParser->displayMessage("##InitiatorName## ##Infinitive::try## "
        "to go through the door, but it is locked.", initiator, 0, 
        "description", "environment", 1);
}

/////////////////////////////////////////////////////////////////////////////
public void displayMoveMessage(object initiator, string direction)
{
    messageParser->displayMessage(sprintf("##InitiatorName## "
        "##Infinitive::go## through the door to the %s.", direction), 
        initiator, 0, "description", "environment", 1);
}

/////////////////////////////////////////////////////////////////////////////
public void displayCloseMessage(object initiator, object originalLocation)
{
    messageParser->displayMessage("The door closes.",
        initiator, 0, "description", "environment", 1, originalLocation);
}

/////////////////////////////////////////////////////////////////////////////
public void displayOpenMessage(object initiator)
{
    messageParser->displayMessage("The door opens and ##InitiatorName## "
        "##Infinitive::enter##.",
        initiator, 0, "description", "environment", 1, 0, 1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void pickLock(object initiator)
{
    if (objectp(initiator))
    {
        string message = message = "##InitiatorName## ##Infinitive::try## to "
            "pick the lock of an already-unlocked door.";

        if (isLocked(State))
        {
            if (initiator->getSkill("open lock") < pickLockLevel)
            {
                message = "##InitiatorName## ##Infinitive::try## to pick the door's "
                    "lock but ##Infinitive::fail##.";
            }
            else
            {
                isCurrentlyLocked = 0;
                wasManipulated = 1;
                message = "##InitiatorName## ##Infinitive::pick## the lock on the door.";
            }
        }

        messageParser->displayMessage(message, initiator, 0, "description",
            "environment");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void damageDoor(object initiator)
{

}
