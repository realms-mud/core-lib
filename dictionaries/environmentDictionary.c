//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/dictionaries/environment/locations.h"
#include "/lib/dictionaries/environment/times-of-day.h"
#include "/lib/dictionaries/environment/moon-phases.h"
#include "/lib/modules/secure/environment.h"

private string BaseEnvironment = "lib/environment/environment.c";
private string BaseElement = "lib/environment/environmentalElement.c";
private string currentSeason;
private string currentTimeOfDay;

private mapping elementList = ([]);

private string *validSeasons = ({ "winter", "spring", "summer", "autumn" });

private string *entryMessages = ({ "you enter", "you have come across",
    "you emerge in", "you come upon", "entering the area, you see",
    "as you arrive, you gaze upon", "you have reached", "you see",
    "taking in your surroundings, you see", "you behold",
    "you survey your surroundings and see", });

private mapping numbersAsString = ([ 0:"no", 1:"one", 2:"two", 3:"three",
    4:"four", 5:"five", 6:"six", 7:"seven", 8:"eight", 9:"nine", 10:"ten",
    11:"eleven", 12:"twelve", 13:"thirteen", 14:"fourteen", 
    15:"fifteen", 16:"sixteen" ]);

private object configuration =
    load_object("/lib/dictionaries/configurationDictionary.c");

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

    if (location && file_size(location) > 0)
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
public nomask int isValidMoonPhase(string phase)
{
    return phase && stringp(phase) &&
        (member(m_indices(moonLightLevel), phase) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string moonPhase()
{
    // Approximation is officially close enough...
    return moonPhases[(currentDayOfYear + (365 * currentYear)) % 28];
}

/////////////////////////////////////////////////////////////////////////////
private nomask int adjustLightingForWeather()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ambientLight()
{
    int ret = 10;
    if (member(({ "midnight", "night", "late night" }), currentTimeOfDay) > -1)
    {
        ret = moonLightLevel[moonPhase()];
    }
    else if (member(({ "dawn", "dusk" }), currentTimeOfDay) > -1)
    {
        ret = 7;
    }
    ret -= adjustLightingForWeather();

    return ret;
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
public nomask string timeOfDayMessage(string colorConfiguration)
{
    string ret = "";

    switch (currentTimeOfDay)
    {
        case "dawn":
        {
            ret = "The red/orange glow to the east beckons the new day.";
            break;
        }
        case "morning":
        {
            ret = sprintf("The sun is low in the eastern %s sky.", 
                currentSeason);
            break;
        }
        case "noon":
        {
            ret = sprintf("The sun is high in the %s sky.", 
                currentSeason);
            break;
        }
        case "afternoon":
        {
            ret = sprintf("The sun has begun to wester in the %s sky.",
                currentSeason);
            break;
        }
        case "evening":
        {
            ret = sprintf("The sun is low in the western %s sky.",
                currentSeason);
            break;
        }
        case "dusk":
        {
            ret = "The red/orange glow in the western sky signals the "
                "day's end.";
            break;
        }
        case "night":
        {
            ret = "A canopy of stars blankets the region.";
            string phase = moonPhase();

            if (phase != "new moon")
            {
                ret += sprintf(" The moon, a %s, is low in the eastern sky.",
                    phase);
            }
            break;
        }
        case "midnight":
        {
            ret = "A canopy of stars blankets the region.";
            string phase = moonPhase();

            if (phase != "new moon")
            {
                ret += sprintf(" The moon, a %s, is almost directly overhead.",
                    phase);
            }
            break;
        }
        case "late night":
        {
            ret = "A canopy of stars blankets the region.";
            string phase = moonPhase();

            if (phase != "new moon")
            {
                ret += sprintf(" The moon, a %s, is low in the western sky.",
                    phase);
            }
            break;
        }
    }
    return configuration->decorate(format(ret, 78),
        currentTimeOfDay, "environment", colorConfiguration);
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
        saveEnvironmentalData();
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
private nomask void calculateTimeOfDay()
{
    string *timeSlots = sort_array(m_indices(timesOfDay),
        (: $3[$1]["winter"] > $3[$2]["winter"] :), timesOfDay);

    foreach(string slot in timeSlots)
    {
        if (timesOfDay[slot][currentSeason] > currentTime)
        {
            currentTimeOfDay = slot;
            break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        loadEnvironmentalData();
        calculateSeason();
        calculateTimeOfDay();
        advanceTime();
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidKey(string key)
{
    int ret = stringp(key);
    if (ret)
    {
        if (file_size(key) > 0)
        {
            object keyObj = load_object(key);
            ret = member(inherit_list(keyObj), "lib/items/key.c") > -1;

            if (!ret)
            {
                raise_error(sprintf("ERROR in environment: '%s' is not a "
                    "valid key object.\n", key));
            }
        }
        else
        {
            raise_error(sprintf("ERROR in environment: '%s' is not a "
                "valid file.\n", key));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getDoor(string door)
{
    object ret = 0;
    if (file_size(door) > 0)
    {
        ret = clone_object(door);

        if (member(inherit_list(ret), "lib/environment/doors/baseDoor.c") < 0)
        {
            raise_error(sprintf("ERROR in environment.c: '%s' is not a "
                "valid door object.\n", door));
        }
    }
    else
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid file.\n", door));
    }
    return ret;
}
