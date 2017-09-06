//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string BaseEnvironment = "lib/environment/environment.c";
private string currentSeason = "summer";
private string currentTimeOfDay = "day";

private string *validSeasons = ({ "winter", "spring", "summer", "autumn" });
private string *validTimesOfDay = ({ "midnight", "night", "dawn", "morning", "noon", "afternoon", "evening", "dusk" });

/////////////////////////////////////////////////////////////////////////////
public nomask object getLocation(string location)
{
    // The passed in value for trait must be a file containing a valid
    // trait object.
    object ret = 0;

    if (location && stringp(location) && location[0] != '/')
    {
        location = "/" + location;
    }

    if (location && stringp(location) && (file_size(location) > 0))
    {
        ret = load_object(location);
        if (ret && !ret->query("current state"))
        {
            ret->init();
        }

        if (!ret || (member(inherit_list(ret), BaseEnvironment) < 0) ||
            !ret->isValidEnvironment())
        {
            ret = 0;
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