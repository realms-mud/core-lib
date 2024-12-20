//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
protected mapping descriptionData = ([ ]);
protected string elementName = 0;
protected string displayName = 0;
protected string State = "default";
protected int suppressAction = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string currentState(string newState)
{
    if (newState && stringp(newState))
    {
        State = newState;
    }
    return State;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string setupDescriptionForState(string state)
{
    if (!state)
    {
        state = "default";
    }

    if (!member(descriptionData, state))
    {
        descriptionData[state] = ([]);
    }
    return state;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *states()
{
    return m_indices(descriptionData) + ({});
}

/////////////////////////////////////////////////////////////////////////////
private nomask string parseSeasonDescription(string message, mapping data,
    int illuminationLevel)
{
    string ret = message;
    string season = getDictionary("environment")->season();
    if (member(data, season) && (illuminationLevel >= 7))
    {
        ret += data[season][random(sizeof(data[season]))];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string parseTimeOfDayDetails(string message, mapping data)
{
    string ret = message;
    string season = getDictionary("environment")->season();
    string timeOfDay = getDictionary("environment")->timeOfDay();
    if (member(data, timeOfDay) && member(data[timeOfDay], season))
    {
        ret += data[timeOfDay][season][random(sizeof(data[timeOfDay][season]))];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string parseWeatherDetails(string message, mapping data,
    int illuminationLevel)
{
    return message;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void suppressEntryMessage()
{
    suppressAction = 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int displayActionText()
{
    return !suppressAction;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string parseEntryAction(string message, mapping data)
{
    return !displayActionText() ? message : getDictionary("environment")->getEntryMessage() + " " +
        message + ".";
}

/////////////////////////////////////////////////////////////////////////////
private nomask string parseAdjectives(string message, mapping data, 
    int illuminationLevel)
{
    string ret = message;

    if (member(data, "adjectives") && sizeof(data["adjectives"]) &&
        sizeof(regexp(({ message}), "##Adjective##")))
    {
        ret = regreplace(ret, "##Adjective##( *)", 
            (illuminationLevel > 5) ?
            data["adjectives"][random(sizeof(data["adjectives"]))] + "\\1" : "", 1);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int displayWeatherDetails()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected int displayEntryMessage()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected string getDescriptionFromSet()
{
    return (member(descriptionData[State], "active light template") ?
        descriptionData[State]["active light template"] : "");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs string parseTemplate(string template, mapping data,
    int illuminationLevel)
{
    string ret = parseSeasonDescription(template, data, illuminationLevel);
    ret = parseTimeOfDayDetails(ret, data);

    if (displayWeatherDetails())
    {
        ret = parseWeatherDetails(ret, data, illuminationLevel);
    }
    if (displayEntryMessage())
    {
        ret = parseEntryAction(ret, data);
    }

    if (sizeof(regexp(({ template }), "##UseDescriptionSet##")))
    {
        ret = regreplace(ret, "##UseDescriptionSet##", 
            getDescriptionFromSet(), 1);
    }

    ret = parseAdjectives(ret, data, illuminationLevel);
    return ret;
}
