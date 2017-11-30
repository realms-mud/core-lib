//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string BaseEnvironment = "lib/environment/environment.c";
private string BaseElement = "lib/environment/environmentalElement.c";
private string currentSeason = "summer";
private string currentTimeOfDay = "noon";
private mapping elementList = ([]);

private string *validSeasons = ({ "winter", "spring", "summer", "autumn" });
private string *validTimesOfDay = ({ "midnight", "night", "dawn", "morning", "noon", "afternoon", "evening", "dusk" });

private string *entryMessages = ({ "you enter", "you have come across",
    "you emerge in", "you come upon", "entering the area, you see",
    "as you arrive, you gaze upon", "you have reached", "you see",
    "taking in your surroundings, you see", "you behold",
    "you survey your surroundings and see", });

private mapping numbersAsString = ([ 0:"no", 1:"one", 2:"two", 3:"three",
    4:"four", 5:"five", 6:"six", 7:"seven", 8:"eight", 9:"nine", 10:"ten",
    11:"eleven", 12:"twelve", 13:"thirteen", 14:"fourteen", 
    15:"fifteen", 16:"sixteen" ]);

/////////////////////////////////////////////////////////////////////////////
public nomask object getLocation(string location)
{
    object ret = 0;

    if (location && stringp(location) && location[0] != '/')
    {
        location = "/" + location;
    }

    if (location && stringp(location) && (file_size(location) > 0))
    {
        ret = load_object(location);

        if (!ret || (member(inherit_list(ret), BaseEnvironment) < 0) ||
            !ret->isValidEnvironment())
        {
            ret = 0;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object environmentalObject(string element)
{
    object ret = 0;

    if (element && stringp(element) && member(elementList, element) &&
        (file_size(elementList[element]) > 0))
    {
        ret = load_object(elementList[element]);
        if (member(inherit_list(ret), BaseElement) < 0)
        {
            ret = 0;
        }
        else
        {
            ret->Setup();
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int isValidEnvironmentItem(string element, string type)
{
    object environmentalObj = environmentalObject(element);
    return (environmentalObj && objectp(environmentalObj) &&
        environmentalObj->Name() && 
        (!type || (environmentalObj->Type() == type)));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidFeature(string element)
{
    return isValidEnvironmentItem(element, "feature");
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int registerElement(string location, string type)
{
    int ret = 0;

    if (location && stringp(location) && sizeof(location) &&
        (location[0] != '/'))
    {
        location = "/" + location;
    }

    if (file_size(location) > 0)
    {
        object element = load_object(location);
        element->Setup();

        if (element && objectp(element) &&
            (member(inherit_list(element), BaseElement) > -1) &&
            element->Name() && !member(elementList, element->Name()))
        {
            ret = 1;
            elementList[element->Name()] = location;

            if (type && stringp(type) &&
                (element->Type() != type))
            {
                ret = 0;
            }
        }
        else
        {
            ret = member(elementList, element->Name()) &&
                (location == elementList[element->Name()]);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canMakeMove(object user, object fromLocation, object toLocation)
{
    return (objectp(fromLocation) ? fromLocation->moveToIsAllowed(user, toLocation) : 1) &&
        objectp(toLocation) && toLocation->moveFromIsAllowed(user, fromLocation);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidType(string type)
{
    //TODO [236]: Finish this 
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidSeason(string season)
{
    return season && stringp(season) &&
        (member(validSeasons, season) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidTimeOfDay(string time)
{
    return time && stringp(time) &&
        (member(validTimesOfDay, time) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int sunlightIsVisible()
{
    return member(({ "midnight", "night" }), currentTimeOfDay) < 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string timeOfDay(string newTime)
{
    string ret = 0;
    if (newTime && stringp(newTime) &&
        (member(validTimesOfDay, newTime) > -1))
    {
        currentTimeOfDay = newTime;
    }
    return currentTimeOfDay;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string season(string newSeason)
{
    string ret = 0;
    if (newSeason && stringp(newSeason) && 
        (member(validSeasons, newSeason) > -1))
    {
        currentSeason = newSeason;
    }
    return currentSeason;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *timesOfDay()
{
    return validTimesOfDay + ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *seasons()
{
    return validSeasons + ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getEntryMessage()
{
    return entryMessages[random(sizeof(entryMessages))];
}

/////////////////////////////////////////////////////////////////////////////
public nomask string convertNumberToString(int number)
{
    string ret = "many";

    if (member(numbersAsString, number))
    {
        ret = numbersAsString[number];
    }
    return ret;
}
