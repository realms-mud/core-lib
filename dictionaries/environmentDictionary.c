//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/dictionaries/environment/locations.h"
#include "/lib/dictionaries/environment/times-of-day.h"
#include "/lib/dictionaries/environment/moon-phases.h"

private string BaseEnvironment = "lib/environment/environment.c";
private string BaseElement = "lib/environment/environmentalElement.c";
private string currentSeason = "summer";
private string currentTimeOfDay = "noon";
private string moonPhase = "new moon";

private int currentYear = 1;
private mapping elementList = ([]);

private string *validSeasons = ({ "winter", "spring", "summer", "autumn" });

private int currentTime = 660;
private int currentDayOfYear = 92;

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
public nomask int isValidLocation(mixed location)
{
    return mappingp(location) && member(location, "description") &&
        member(location, "x") && member(location, "y") && 
        member(location, "z") && member(location, "x-rotation") && 
        member(location, "y-rotation") && member(location, "z-rotation");
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getLocation(string location)
{
    mapping ret = 0;
    if (member(defaultLocations, location))
    {
        ret = defaultLocations[location] + ([]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getEnvironment(string location)
{
    object ret = 0;

    if (location && stringp(location) && location[0] != '/')
    {
        location = "/" + location;
    }

    if (location && stringp(location) && (file_size(location) > 0))
    {
        ret = load_object(location);

        if (!ret || (member(inherit_list(ret), BaseEnvironment) < 0))
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
public nomask int isEnvironmentOfType(object environment, string type)
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
        (member(m_indices(timesOfDay), time) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int sunlightIsVisible()
{
    return member(({ "midnight", "night", "late night" }), currentTimeOfDay) < 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string timeOfDay(string newTime)
{
    if (stringp(newTime) && member(timesOfDay, newTime))
    {
        currentTimeOfDay = newTime;
        currentTime = timesOfDay[newTime][currentSeason] - 60;
    }

    return currentTimeOfDay;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string currentDate()
{
    return sprintf("%02d:%02d on day %d of year %d",
        currentTime / 60, currentTime % 60, currentDayOfYear, currentYear);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string moonPhase()
{
    // Approximation is officially close enough...
    return moonPhases[(currentDayOfYear + (365 * currentYear)) % 28];
}

/////////////////////////////////////////////////////////////////////////////
public nomask int currentTime()
{
    return currentTime;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int currentDay()
{
    return currentDayOfYear;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int currentYear()
{
    return currentYear;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void calculateSeason()
{
    switch (currentDayOfYear)
    {
        case 0..91:
        {
            currentSeason = "spring";
            break;
        }
        case 92..182:
        {
            currentSeason = "summer";
            break;
        }
        case 183..273:
        {
            currentSeason = "autumn";
            break;
        }
        case 274..364:
        {
            currentSeason = "winter";
            break;
        }
        default:
        {
            currentYear++;
            currentDayOfYear = 0;
            currentSeason = "spring";
            break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setDay(int newDay)
{
    currentDayOfYear = newDay;
    calculateSeason();
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setYear(int value)
{
    currentYear = value;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void advanceTime(int amount)
{
    if (!amount)
    {
        currentTime++;
    }
    else
    {
        currentTime += amount;
    }

    if (currentTime >= 1440)
    {
        currentDayOfYear++;
        currentTime = 0;
        currentTimeOfDay = "midnight";
        calculateSeason();
    }
    else if(currentTime >= timesOfDay[currentTimeOfDay][currentSeason])
    {
        currentTimeOfDay = timesOfDay[currentTimeOfDay]["next"];
    }

    if (!amount)
    {
        call_out("advanceTime", 5);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string season(string newSeason)
{
    string ret = 0;
    if (newSeason && stringp(newSeason) && 
        (member(validSeasons, newSeason) > -1))
    {
        currentSeason = newSeason;
        switch (currentSeason)
        {
            case "spring":
            {
                currentDayOfYear = 0;
                break;
            }
            case "summer":
            {
                currentDayOfYear = 92;
                break;
            }
            case "autumn":
            {
                currentDayOfYear = 183;
                break;
            }
            case "winter":
            {
                currentDayOfYear = 274;
                break;
            }
        }
    }
    return currentSeason;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *timesOfDay()
{
    return m_indices(timesOfDay);
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

/////////////////////////////////////////////////////////////////////////////
public nomask int coordinatesValidForRegion(string region, int x, int y)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getRegion(string region)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        advanceTime();
    }
}
