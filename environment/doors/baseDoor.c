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

        string message = sprintf("##InitiatorName## ##Infinitive::try## to "
            "lock an already-locked %s.", elementName);

        if (!stringp(Key))
        {
            message = sprintf("##InitiatorName## ##Infinitive::try## to "
                "lock the %s but ##Infinitive::notice## that it has no "
                "lock.", elementName);
        }
        else if (!present_clone(Key, initiator))
        {
            message = sprintf("##InitiatorName## ##Infinitive::try## to "
                "lock the %s but ##Infinitive::do## not have the key.",
                elementName);
        }
        else if (!isLocked())
        {
            isCurrentlyLocked = 1;
            wasManipulated = 1;
            message = sprintf("##InitiatorName## ##Infinitive::lock## the "
                "%s.", elementName);
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
        string message = sprintf("##InitiatorName## ##Infinitive::try## to "
            "unlock an already-unlocked %s.", elementName);

        if (!stringp(Key))
        {
            message = sprintf("##InitiatorName## ##Infinitive::try## to "
                "unlock the %s but ##Infinitive::notice## that it has no "
                "lock.", elementName);
        }
        else if (!present_clone(Key, initiator))
        {
            message = sprintf("##InitiatorName## ##Infinitive::try## to "
                "unlock the %s but ##Infinitive::do## not have the key.",
                elementName);
        }
        else if (isLocked())
        {
            isCurrentlyLocked = 0;
            wasManipulated = 1;
            message = sprintf("##InitiatorName## ##Infinitive::unlock## "
                "the %s.", elementName);
        }
        messageParser->displayMessage(message, initiator, 0, "description",
            "environment");
    }
}

/////////////////////////////////////////////////////////////////////////////
public void displayLockedMessage(object initiator)
{
    messageParser->displayMessage(
        sprintf("##InitiatorName## ##Infinitive::try## to go through the "
            "%s, but it is locked.", elementName), 
        initiator, 0, "description", "environment", 1);
}

/////////////////////////////////////////////////////////////////////////////
public void displayMoveMessage(object initiator, string direction)
{
    messageParser->displayMessage(sprintf("##InitiatorName## "
        "##Infinitive::go## through the %s to the %s.", elementName, direction), 
        initiator, 0, "description", "environment", 1);
}

/////////////////////////////////////////////////////////////////////////////
public void displayCloseMessage(object initiator, object originalLocation)
{
    messageParser->displayMessage(
        sprintf("The %s closes.", elementName),
        initiator, 0, "description", "environment", 1, originalLocation);
}

/////////////////////////////////////////////////////////////////////////////
public void displayOpenMessage(object initiator)
{
    messageParser->displayMessage(
        sprintf("The %s opens and ##InitiatorName## ##Infinitive::enter##.",
            elementName),
        initiator, 0, "description", "environment", 1, 0, 1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void pickLock(object initiator)
{
    if (objectp(initiator))
    {
        string message = sprintf("##InitiatorName## ##Infinitive::try## to "
            "pick the lock of an already-unlocked %s.", elementName);

        if (isLocked(State))
        {
            if (initiator->getSkill("open lock") < pickLockLevel)
            {
                message = sprintf("##InitiatorName## ##Infinitive::try## to "
                    "pick the %s's lock but ##Infinitive::fail##.", elementName);
            }
            else
            {
                isCurrentlyLocked = 0;
                wasManipulated = 1;
                message = sprintf("##InitiatorName## ##Infinitive::pick## "
                    "the lock on the %s.", elementName);
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
